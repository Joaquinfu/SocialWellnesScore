"""
gaze_estimator.py
=================
SWS Phase 2 — Node 1: Gaze Estimator

Theory
------
Uses MediaPipe face mesh iris landmarks (indices 468-477) published by
hri_face_detect, back-projects them to 3D using the pinhole camera model
and aligned depth from the RealSense D435, then computes a gaze direction
vector relative to the nose bridge (landmark 168) as face-center reference.

Back-projection formula (Hartley & Zisserman, 2004):
    X = (u - cx) * Z / fx
    Y = (v - cy) * Z / fy
    Z = aligned_depth[v, u] / 1000.0   # mm -> meters

Gaze vector:
    gaze_vec = iris_3d - nose_3d
    gaze_normalized = gaze_vec / |gaze_vec|

Score:
    score = clamp(-gaze_normalized.z, 0.0, 1.0)
    (negative Z = facing camera = direct gaze = score 1.0)

Publishes
---------
/sws/gaze_direction       geometry_msgs/Vector3   normalized 3D gaze vector
/sws/is_looking_at_robot  std_msgs/Bool           True if score > LOOK_THRESHOLD
/sws/gaze_score           std_msgs/Float32        0.0-1.0 wellness sub-score

Subscribes
----------
/camera/camera/aligned_depth_to_color/image_raw   sensor_msgs/Image (16UC1)
/camera/camera/color/camera_info                   sensor_msgs/CameraInfo

HRI data via HRIListener (ROS4HRI Python API):
    hri_listener.faces[id].facial_landmarks  -- 478 MediaPipe landmarks

Research references
-------------------
- MediaPipe Face Mesh: Kartynnik et al. (2019) arxiv.org/abs/1907.06724
- Pinhole model: Hartley & Zisserman, Multiple View Geometry (2004)
- Gaze as social signal: Hietanen (2018) Frontiers in Psychology
- Gaze in isolation detection: Takemoto et al. (2025) Frontiers in Psychology
  doi: 10.3389/fpsyg.2025.1507178

Author: Joaquin — DU REU 2026, Computer Vision and Social Robotics Lab
"""

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy
import numpy as np

from sensor_msgs.msg import Image, CameraInfo
from geometry_msgs.msg import Vector3
from std_msgs.msg import Bool, Float32
from cv_bridge import CvBridge

from hri import HRIListener


# ---------------------------------------------------------------------------
# MediaPipe Face Mesh landmark indices
# Source: developers.google.com/mediapipe/solutions/vision/face_landmarker
# ---------------------------------------------------------------------------
LEFT_IRIS  = [468, 469, 470, 471, 472]   # 5 points around left iris ring
RIGHT_IRIS = [473, 474, 475, 476, 477]   # 5 points around right iris ring
NOSE_BRIDGE = 168                          # midpoint between eyes on face surface

# Gaze score threshold above which we consider the person "looking at robot"
LOOK_THRESHOLD = 0.3


class GazeEstimator(Node):
    """
    ROS2 node that estimates gaze direction and publishes a social wellness
    sub-score based on how directly a person is looking at the robot.

    Rate: 10 Hz (timer-driven)
    """

    def __init__(self):
        super().__init__('gaze_estimator')

        # ------------------------------------------------------------------
        # Internal state
        # ------------------------------------------------------------------
        self.bridge       = CvBridge()
        self.depth_image  = None      # latest aligned depth frame (numpy)
        self.camera_info  = None      # camera intrinsics (stored once)
        self.fx = self.fy = self.cx = self.cy = None

        # ROS4HRI listener — gives us access to all detected faces
        self.hri_listener = HRIListener('gaze_hri_listener')

        # ------------------------------------------------------------------
        # QoS profile — BEST_EFFORT matches RealSense sensor QoS
        # ------------------------------------------------------------------
        sensor_qos = QoSProfile(
            depth=10,
            reliability=ReliabilityPolicy.BEST_EFFORT)

        # ------------------------------------------------------------------
        # Subscribers
        # ------------------------------------------------------------------
        self.create_subscription(
            Image,
            '/camera/camera/aligned_depth_to_color/image_raw',
            self._depth_cb,
            sensor_qos)

        self.create_subscription(
            CameraInfo,
            '/camera/camera/color/camera_info',
            self._info_cb,
            10)

        # ------------------------------------------------------------------
        # Publishers
        # ------------------------------------------------------------------
        self.pub_direction = self.create_publisher(
            Vector3,  '/sws/gaze_direction',      10)
        self.pub_looking   = self.create_publisher(
            Bool,     '/sws/is_looking_at_robot', 10)
        self.pub_score     = self.create_publisher(
            Float32,  '/sws/gaze_score',          10)

        # ------------------------------------------------------------------
        # Main loop timer — 10 Hz
        # ------------------------------------------------------------------
        self.create_timer(0.1, self._run)

        self.get_logger().info(
            'GazeEstimator ready. '
            'Waiting for /camera/camera/aligned_depth_to_color/image_raw '
            'and /camera/camera/color/camera_info ...')

    # -----------------------------------------------------------------------
    # Callbacks
    # -----------------------------------------------------------------------

    def _depth_cb(self, msg: Image):
        """Store latest aligned depth image as a numpy array (mm, uint16)."""
        self.depth_image = self.bridge.imgmsg_to_cv2(
            msg, desired_encoding='passthrough')

    def _info_cb(self, msg: CameraInfo):
        """
        Store camera intrinsics once on first message.
        K matrix layout (row-major):
            [fx,  0, cx]
            [ 0, fy, cy]
            [ 0,  0,  1]
        Indices: K[0]=fx, K[2]=cx, K[4]=fy, K[5]=cy
        """
        if self.camera_info is not None:
            return  # already stored

        self.camera_info = msg
        self.fx = msg.k[0]
        self.fy = msg.k[4]
        self.cx = msg.k[2]
        self.cy = msg.k[5]

        self.get_logger().info(
            f'Camera intrinsics loaded: '
            f'fx={self.fx:.1f} fy={self.fy:.1f} '
            f'cx={self.cx:.1f} cy={self.cy:.1f}')

    # -----------------------------------------------------------------------
    # Core math
    # -----------------------------------------------------------------------

    def _pixel_to_3d(self, u: float, v: float):
        """
        Back-project a 2D pixel (u, v) to a 3D camera-frame point (X, Y, Z).

        Uses a 3x3 median patch around the pixel for robustness against
        depth sensor noise and holes.

        Parameters
        ----------
        u, v : float
            Pixel coordinates in the color image frame.

        Returns
        -------
        np.ndarray [X, Y, Z] in meters, or None if depth is invalid.
        """
        if self.depth_image is None or self.camera_info is None:
            return None

        h, w = self.depth_image.shape
        ui, vi = int(round(u)), int(round(v))

        # Bounds check
        if not (0 <= ui < w and 0 <= vi < h):
            return None

        # 3x3 patch — median filters out holes and noise
        u0, u1 = max(0, ui - 1), min(w, ui + 2)
        v0, v1 = max(0, vi - 1), min(h, vi + 2)
        patch   = self.depth_image[v0:v1, u0:u1]
        valid   = patch[patch > 0]

        if len(valid) == 0:
            return None

        Z = float(np.median(valid)) / 1000.0  # mm → meters

        # Sanity check — ignore readings beyond 5m or under 0.1m
        if not (0.1 <= Z <= 5.0):
            return None

        # Pinhole back-projection
        X = (u - self.cx) * Z / self.fx
        Y = (v - self.cy) * Z / self.fy

        return np.array([X, Y, Z], dtype=np.float64)

    def _iris_center(self, landmarks, indices):
        """
        Average landmark positions to find the iris center pixel.

        Parameters
        ----------
        landmarks : list of landmark objects with .x, .y attributes
        indices   : list of int landmark indices

        Returns
        -------
        (u, v) tuple of floats, or None if any landmark is missing.
        """
        try:
            pts = [landmarks[i] for i in indices]
            u   = float(np.mean([p.x for p in pts]))
            v   = float(np.mean([p.y for p in pts]))
            return u, v
        except (IndexError, AttributeError):
            return None

    # -----------------------------------------------------------------------
    # Main loop
    # -----------------------------------------------------------------------

    def _run(self):
        """
        Called at 10 Hz. For each detected face:
        1. Get iris and nose bridge landmark pixels from hri_face_detect
        2. Back-project both to 3D using aligned depth + intrinsics
        3. Compute gaze vector (iris_3d - nose_3d), normalize it
        4. Derive score from -Z component (negative Z = facing camera)
        5. Publish direction, is_looking, and score
        """
        # No faces detected — publish zero score
        faces = self.hri_listener.faces
        self.get_logger().info(f'listener faces: {list(faces.keys())}', throttle_duration_sec=2.0)
        if not faces:
            self.pub_score.publish(Float32(data=0.0))
            self.pub_looking.publish(Bool(data=False))
            return

        # Process first detected face
        face_id, face = next(iter(faces.items()))

        # Check landmarks are available
        landmarks = getattr(face, 'facial_landmarks', None)
        if landmarks is None or len(landmarks) < 478:
            self.get_logger().debug(
                f'Face {face_id}: landmarks not yet available '
                f'(have {len(landmarks) if landmarks else 0}/478)',
                throttle_duration_sec=2.0)
            return

        # ---- Step 1: Get iris center pixels --------------------------------
        left_iris  = self._iris_center(landmarks, LEFT_IRIS)
        right_iris = self._iris_center(landmarks, RIGHT_IRIS)

        if left_iris is None or right_iris is None:
            return

        # Average both eyes for combined gaze origin
        iris_u = (left_iris[0]  + right_iris[0])  / 2.0
        iris_v = (left_iris[1]  + right_iris[1])  / 2.0

        # Nose bridge pixel
        nose_lm = landmarks[NOSE_BRIDGE]
        nose_u, nose_v = float(nose_lm.x), float(nose_lm.y)

        # ---- Step 2: Back-project to 3D ------------------------------------
        iris_3d = self._pixel_to_3d(iris_u, iris_v)
        nose_3d = self._pixel_to_3d(nose_u, nose_v)

        if iris_3d is None or nose_3d is None:
            self.get_logger().debug(
                'Depth lookup failed (holes in depth image)',
                throttle_duration_sec=2.0)
            return

        # ---- Step 3: Gaze vector -------------------------------------------
        gaze_vec = iris_3d - nose_3d
        norm     = float(np.linalg.norm(gaze_vec))

        if norm < 1e-6:
            return  # degenerate case

        gaze = gaze_vec / norm   # unit vector

        # ---- Step 4: Compute score ----------------------------------------
        # Camera Z-axis points INTO the scene (away from camera).
        # Person facing camera → gaze Z is negative → -gaze.z is positive.
        score   = float(np.clip(-gaze[2], 0.0, 1.0))
        looking = score > LOOK_THRESHOLD

        # ---- Step 5: Publish -----------------------------------------------
        dir_msg      = Vector3()
        dir_msg.x    = float(gaze[0])
        dir_msg.y    = float(gaze[1])
        dir_msg.z    = float(gaze[2])

        self.pub_direction.publish(dir_msg)
        self.pub_looking.publish(Bool(data=looking))
        self.pub_score.publish(Float32(data=score))

        self.get_logger().info(
            f'[{face_id}] '
            f'iris=({iris_u:.0f},{iris_v:.0f}) '
            f'depth={iris_3d[2]:.2f}m  '
            f'gaze=({gaze[0]:+.2f},{gaze[1]:+.2f},{gaze[2]:+.2f})  '
            f'score={score:.2f}  looking={looking}',
            throttle_duration_sec=1.0)


# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

def main(args=None):
    rclpy.init(args=args)
    node = GazeEstimator()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()

"""Head-orientation gaze for RYAN — from hri_face_detect's 70-point
facial landmarks, exposed by pyhri as {FacialLandmark enum: (x, y)}
with normalized 0-1 coordinates.

Principle: facing the camera, the nose sits centered between the ears;
head yaw slides it toward one side. Score = nose centeredness,
normalized by ear-to-ear width. Landmarks are matched BY ENUM NAME,
not index, so numbering conventions can't bite us again.

Publishes (the aggregator's expected contract):
  /sws/gaze_direction       geometry_msgs/Vector3  (x = yaw offset, -1..1)
  /sws/gaze_score           std_msgs/Float32       0.0 - 1.0
  /sws/is_looking_at_robot  std_msgs/Bool
"""
import numpy as np
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32, Bool
from geometry_msgs.msg import Vector3
from hri import HRIListener


class HeadGaze(Node):
    def __init__(self):
        super().__init__('head_gaze')

        self.declare_parameter('look_threshold', 0.6)
        # |yaw| at which score reaches 0. 0.5 = nose halfway to the ear.
        self.declare_parameter('yaw_tolerance', 0.5)

        self.hri_listener = HRIListener('head_gaze_hri_listener')

        self.pub_direction = self.create_publisher(Vector3,
                                                   '/sws/gaze_direction', 10)
        self.pub_score = self.create_publisher(Float32, '/sws/gaze_score', 10)
        self.pub_looking = self.create_publisher(Bool,
                                                 '/sws/is_looking_at_robot', 10)

        self._names_logged = False
        self.create_timer(0.1, self._run)
        self.get_logger().info('head_gaze up (70-landmark yaw, enum-keyed)')

    @staticmethod
    def _find(by_name, *needles):
        """First landmark whose enum name contains all needles."""
        for name, v in by_name.items():
            if all(n in name for n in needles):
                return v
        return None

    def _run(self):
        faces = self.hri_listener.faces
        if not faces:
            self.pub_score.publish(Float32(data=0.0))
            self.pub_looking.publish(Bool(data=False))
            return

        face_id, face = next(iter(faces.items()))
        pts = face.facial_landmarks
        if not pts:
            return

        by_name = {k.name: v for k, v in pts.items()}
        if not self._names_logged:
            self.get_logger().info(f'landmark names: {sorted(by_name)}')
            self._names_logged = True

        right = by_name.get('RIGHT_EAR')
        left = by_name.get('LEFT_EAR')
        nose = self._find(by_name, 'NOSE')
        if right is None or left is None or nose is None:
            self.get_logger().debug(f'{face_id}: key landmarks missing',
                                    throttle_duration_sec=2.0)
            return

        rx, lx, nx = float(right[0]), float(left[0]), float(nose[0])
        width = abs(lx - rx)
        if width < 1e-4:
            return
        center_x = (lx + rx) / 2.0
        yaw = (nx - center_x) / (width / 2.0)   # 0 centered, ±1 at an ear

        tol = self.get_parameter('yaw_tolerance').value
        score = float(np.clip(1.0 - abs(yaw) / tol, 0.0, 1.0))
        looking = score > self.get_parameter('look_threshold').value

        self.pub_direction.publish(Vector3(x=float(yaw), y=0.0, z=0.0))
        self.pub_score.publish(Float32(data=score))
        self.pub_looking.publish(Bool(data=looking))

        self.get_logger().info(
            f'[{face_id}] yaw={yaw:+.2f} score={score:.2f} looking={looking}',
            throttle_duration_sec=1.0)


def main(args=None):
    rclpy.init(args=args)
    node = HeadGaze()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()


if __name__ == '__main__':
    main()

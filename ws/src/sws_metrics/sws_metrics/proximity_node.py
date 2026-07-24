"""Proximity v2 for RYAN — REAL depth measurement: samples the D435's
aligned depth image at the detected face's ROI center (median over a
patch to survive depth holes). Replaces v1's TF/solvePnP estimate.

Interface fact (probed Jul 23): pyhri face.roi is a plain tuple
(x, y, width, height) in normalized 0-1 coordinates.

Publishes raw meters on /sws/distance; the aggregator owns Hall-zone
scoring. Nearest face wins.
"""
import numpy as np
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
from sensor_msgs.msg import Image
from hri import HRIListener

PATCH = 9  # median window half-size in px


class ProximityNode(Node):
    def __init__(self):
        super().__init__('proximity_node')

        self.hri_listener = HRIListener('proximity_hri_listener')
        self.depth = None
        self.create_subscription(
            Image, '/camera/camera/aligned_depth_to_color/image_raw',
            self.on_depth, 10)
        self.pub_dist = self.create_publisher(Float32, '/sws/distance', 10)

        self.create_timer(0.2, self._run)
        self.get_logger().info('proximity_node v2 up (depth-at-ROI)')

    def on_depth(self, msg):
        # 16UC1, millimeters. Manual decode (no cv_bridge dependency).
        self.depth = (np.frombuffer(msg.data, dtype=np.uint16)
                      .reshape(msg.height, msg.width))

    def _get_roi(self, face):
        r = getattr(face, 'roi', None)
        try:
            return r() if callable(r) else r
        except Exception:
            return None

    def _run(self):
        if self.depth is None:
            return
        faces = self.hri_listener.faces
        if not faces:
            return

        h, w = self.depth.shape
        best = None
        for face_id, face in faces.items():
            roi = self._get_roi(face)
            if roi is None:
                continue
            try:  # (x, y, width, height), normalized 0-1
                rx, ry, rw, rh = roi
                cu = int((rx + rw / 2.0) * w)
                cv = int((ry + rh / 2.0) * h)
            except (TypeError, ValueError):
                continue
            cu = int(np.clip(cu, PATCH, w - PATCH - 1))
            cv = int(np.clip(cv, PATCH, h - PATCH - 1))
            patch = self.depth[cv - PATCH:cv + PATCH, cu - PATCH:cu + PATCH]
            valid = patch[patch > 0]           # 0 = depth hole
            if valid.size < 10:
                continue
            d = float(np.median(valid)) / 1000.0
            if 0.15 < d < 8.0 and (best is None or d < best):
                best = d

        if best is not None:
            self.pub_dist.publish(Float32(data=best))
            self.get_logger().info(f'nearest face: {best:.2f} m',
                                   throttle_duration_sec=2.0)


def main(args=None):
    rclpy.init(args=args)
    node = ProximityNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()


if __name__ == '__main__':
    main()

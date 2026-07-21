"""Gaze/attention proxy for RYAN in senior-care deployment.

A face that is DETECTED and roughly CENTERED in RYAN's camera view is
counted as attending (frontal face detectors inherently lose turned-away
faces, so detection itself carries orientation information). Publishes
the fraction of recent time someone was attending.

New ROS2 pattern here: DYNAMIC subscriptions -- per-face ROI topics
appear/disappear with the people themselves, so this node creates and
destroys its own subscriptions at runtime.

Publishes:
  /sws/gaze_attention  (Float32)  attention ratio 0.0 - 1.0
"""
from collections import deque

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
from hri_msgs.msg import IdsList, NormalizedRegionOfInterest2D


class GazeAttention(Node):
    def __init__(self):
        super().__init__('gaze_attention')

        self.declare_parameter('window_sec', 60.0)
        # how far from image center (0.5) a face center may sit and still
        # count as "facing RYAN". 0.25 = middle half of the frame.
        self.declare_parameter('center_tolerance', 0.25)

        self.create_subscription(IdsList, '/humans/faces/tracked',
                                 self.on_faces, 10)
        self.ratio_pub = self.create_publisher(Float32,
                                               '/sws/gaze_attention', 10)

        self.roi_subs = {}      # face_id -> subscription (managed at runtime)
        self.last_roi = {}      # face_id -> latest ROI msg
        self.samples = deque()  # (timestamp, attending_bool)

        self.create_timer(1.0, self.compute)
        self.get_logger().info('gaze_attention up')

    def now(self):
        return self.get_clock().now().nanoseconds / 1e9

    def on_faces(self, msg):
        ids = set(msg.ids)

        # faces that just appeared: subscribe to their personal ROI topic.
        # default arg id=face_id pins the loop variable into the lambda.
        for face_id in ids - self.roi_subs.keys():
            topic = f'/humans/faces/{face_id}/roi'
            self.roi_subs[face_id] = self.create_subscription(
                NormalizedRegionOfInterest2D, topic,
                lambda m, id=face_id: self.on_roi(id, m), 10)

        # faces that vanished: clean up, or dead subscriptions accumulate.
        for face_id in set(self.roi_subs.keys()) - ids:
            self.destroy_subscription(self.roi_subs.pop(face_id))
            self.last_roi.pop(face_id, None)

    def on_roi(self, face_id, msg):
        self.last_roi[face_id] = msg   # record; timer interprets. As always.

    def compute(self):
        window = self.get_parameter('window_sec').value
        tol = self.get_parameter('center_tolerance').value

        # attending = ANY current face whose ROI center is near frame center.
        # Normalized coords (0..1) mean no camera-resolution handling needed.
        attending = False
        for roi in self.last_roi.values():
            cx = (roi.xmin + roi.xmax) / 2.0
            if abs(cx - 0.5) < tol:
                attending = True
                break

        self.samples.append((self.now(), attending))
        cutoff = self.now() - window
        while self.samples and self.samples[0][0] < cutoff:
            self.samples.popleft()

        ratio = sum(1 for _, a in self.samples if a) / len(self.samples)
        self.ratio_pub.publish(Float32(data=ratio))


def main(args=None):
    rclpy.init(args=args)
    node = GazeAttention()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()


if __name__ == '__main__':
    main()

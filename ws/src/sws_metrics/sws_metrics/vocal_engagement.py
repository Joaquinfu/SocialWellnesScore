"""Vocal engagement scaffold for RYAN in senior-care deployment.

Computes a talk-time ratio: over a rolling window, what fraction of
voice-activity (VAD) samples were 'speaking'. Input is a Bool stream on
/audio/vad -- synthetic for now; when RYAN's real mic pipeline exists,
remap that topic here and nothing else changes.

Why it matters for eldercare: presence and speech decouple as novelty
fades. Residents may still sit near RYAN (presence steady) while no
longer talking to it (this ratio falls). This node measures that gap.

Publishes:
  /sws/vocal_engagement  (Float32)  talk-time ratio, 0.0 - 1.0
"""
from collections import deque

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32, Bool


class VocalEngagement(Node):
    def __init__(self):
        super().__init__('vocal_engagement')

        # 300 s window: long enough that one exchange ("hello RYAN, play
        # music") registers meaningfully, short enough to track a session.
        self.declare_parameter('window_sec', 300.0)

        self.create_subscription(Bool, '/audio/vad', self.on_vad, 10)
        self.ratio_pub = self.create_publisher(Float32,
                                               '/sws/vocal_engagement', 10)

        # each entry: (timestamp, was_speaking). Storing ALL samples and
        # taking true/total makes the ratio independent of publish rate.
        self.samples = deque()

        self.create_timer(1.0, self.compute)
        self.get_logger().info('vocal_engagement up')

    def now(self):
        return self.get_clock().now().nanoseconds / 1e9

    def on_vad(self, msg):
        # subscriber just records; the timer interprets. Same split as
        # isolation_detect.
        self.samples.append((self.now(), msg.data))

    def compute(self):
        window = self.get_parameter('window_sec').value
        cutoff = self.now() - window

        # drop samples older than the window (same trim as interaction_freq)
        while self.samples and self.samples[0][0] < cutoff:
            self.samples.popleft()

        if not self.samples:
            # No VAD data at all (mic down, or nothing published yet).
            # Publish 0.0: "no evidence of engagement" -- and for the
            # aggregator, silence and no-data score the same for now.
            self.ratio_pub.publish(Float32(data=0.0))
            return

        speaking = sum(1 for _, s in self.samples if s)
        ratio = speaking / len(self.samples)
        self.ratio_pub.publish(Float32(data=ratio))


def main(args=None):
    rclpy.init(args=args)
    node = VocalEngagement()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()


if __name__ == '__main__':
    main()

"""Isolation detection for RYAN in senior-care deployment.

Tracks how long it has been since ANY face was present in front of the
robot, publishes that duration continuously, and raises a flag when it
exceeds a threshold. Rising isolation durations over weeks = the
novelty-decline trend made measurable.

Publishes:
  /sws/isolation_time  (Float32)  seconds since a face was last seen
  /sws/isolated        (Bool)     True once that exceeds threshold_sec
"""
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32, Bool
from hri_msgs.msg import IdsList


class IsolationDetect(Node):
    def __init__(self):
        super().__init__('isolation_detect')

        # 600 s = 10 min: realistic for an eldercare common room during
        # active hours. Tunable per facility (or per test) via ros2 param.
        self.declare_parameter('threshold_sec', 600.0)

        # Same input topic as interaction_freq — third different question
        # asked of the same data: "how long since anyone was here?"
        self.create_subscription(IdsList, '/humans/faces/tracked',
                                 self.on_faces, 10)

        self.time_pub = self.create_publisher(Float32,
                                              '/sws/isolation_time', 10)
        self.flag_pub = self.create_publisher(Bool, '/sws/isolated', 10)

        # Startup counts as "seen": right after boot we have no idea how
        # long it's been, so we don't alarm before the first real data.
        self.last_seen = self.now()
        self.prev_isolated = False   # for edge detection on our own output

        self.create_timer(1.0, self.compute)
        self.get_logger().info('isolation_detect up')

    def now(self):
        return self.get_clock().now().nanoseconds / 1e9

    def on_faces(self, msg):
        # ANY tracked face = presence. One resident or five, same meaning
        # for isolation purposes. Empty list = nobody -> clock keeps running.
        if msg.ids:
            self.last_seen = self.now()

    def compute(self):
        threshold = self.get_parameter('threshold_sec').value

        elapsed = self.now() - self.last_seen
        self.time_pub.publish(Float32(data=elapsed))

        isolated = elapsed > threshold
        self.flag_pub.publish(Bool(data=isolated))

        # Edge detection on our own flag: log only the TRANSITION, not the
        # state. Without this you'd get one log line per second, forever.
        if isolated != self.prev_isolated:
            if isolated:
                self.get_logger().warn(
                    f'ISOLATED: no face for {elapsed:.0f}s '
                    f'(threshold {threshold:.0f}s)')
            else:
                self.get_logger().info('contact restored')
            self.prev_isolated = isolated


def main(args=None):
    rclpy.init(args=args)
    node = IsolationDetect()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()


if __name__ == '__main__':
    main()

"""Interaction frequency — counts arrival events (face IDs newly appearing)
and publishes a rolling events-per-minute rate on /sws/interaction_freq."""
from collections import deque

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
from hri_msgs.msg import IdsList


class InteractionFreq(Node):
    def __init__(self):
        super().__init__('interaction_freq')

        # window for the rate; 120 s default so single events don't vanish instantly
        self.declare_parameter('window_sec', 120.0)

        self.create_subscription(IdsList, '/humans/faces/tracked',
                                 self.on_faces, 10)
        self.freq_pub = self.create_publisher(Float32,
                                              '/sws/interaction_freq', 10)

        self.prev_ids = set()      # state carried between callbacks
        self.events = deque()      # timestamps of arrival events

        self.create_timer(1.0, self.compute)
        self.get_logger().info('interaction_freq up')

    def now(self):
        return self.get_clock().now().nanoseconds / 1e9

    def on_faces(self, msg):
        ids = set(msg.ids)
        arrivals = ids - self.prev_ids        # set difference: IDs new this frame
        for face_id in arrivals:
            self.events.append(self.now())
            self.get_logger().info(f'arrival: {face_id}')
        self.prev_ids = ids

    def compute(self):
        window = self.get_parameter('window_sec').value
        cutoff = self.now() - window
        while self.events and self.events[0] < cutoff:
            self.events.popleft()

        # normalize to events per minute so the number is window-independent
        epm = len(self.events) * 60.0 / window
        self.freq_pub.publish(Float32(data=epm))


def main(args=None):
    rclpy.init(args=args)
    node = InteractionFreq()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()


if __name__ == '__main__':
    main()

"""SWS aggregator — subscribes to HRI signals, computes the Social Wellness
Score over a sliding window, publishes /sws/score, logs to CSV."""
import csv
import os
import time
from collections import deque

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32, Bool
from hri_msgs.msg import IdsList

WINDOW_SEC = 30.0  # sliding window length


class SwsAggregator(Node):
    def __init__(self):
        super().__init__('sws_aggregator')

        # --- tunable weights (must sum to ~1.0) ---
        self.declare_parameter('w_presence', 0.4)
        self.declare_parameter('w_proximity', 0.3)
        self.declare_parameter('w_gaze', 0.3)
        self.declare_parameter('log_dir', '/home/user/exchange/logs')

        # --- subscriptions: (type, topic, callback, queue) ---
        self.create_subscription(IdsList, '/humans/faces/tracked', self.on_faces, 10)
        self.create_subscription(Float32, '/sws/distance', self.on_distance, 10)
        self.create_subscription(Bool, '/sws/is_looking_at_robot', self.on_gaze, 10)

        self.score_pub = self.create_publisher(Float32, '/sws/score', 10)

        # --- sliding windows: deques of (timestamp, value) ---
        self.presence = deque()
        self.distance = deque()
        self.gaze = deque()

        # --- CSV log, one file per session ---
        log_dir = self.get_parameter('log_dir').value
        os.makedirs(log_dir, exist_ok=True)
        path = os.path.join(log_dir, time.strftime('sws_%Y%m%d_%H%M%S.csv'))
        self.csv_file = open(path, 'w', newline='')
        self.csv = csv.writer(self.csv_file)
        self.csv.writerow(['t_sec', 'presence', 'proximity', 'gaze', 'sws'])
        self.get_logger().info(f'logging to {path}')

        # compute + publish once per second
        self.create_timer(1.0, self.compute)

    # ---------- helpers ----------
    def now(self):
        return self.get_clock().now().nanoseconds / 1e9

    def push(self, dq, val):
        dq.append((self.now(), val))

    def trim(self, dq):
        cutoff = self.now() - WINDOW_SEC
        while dq and dq[0][0] < cutoff:
            dq.popleft()

    # ---------- subscription callbacks ----------
    def on_faces(self, msg):
        self.push(self.presence, 1.0 if msg.ids else 0.0)

    def on_distance(self, msg):
        self.push(self.distance, msg.data)

    def on_gaze(self, msg):
        self.push(self.gaze, 1.0 if msg.data else 0.0)

    # ---------- scoring ----------
    @staticmethod
    def proximity_score(d):
        """Hall's proxemic zones -> engagement score 0..1."""
        if d < 0.45:
            return 0.8   # intimate: very close, slightly penalized
        if d < 1.2:
            return 1.0   # personal: ideal engagement distance
        if d < 3.6:
            return 0.5   # social
        return 0.2       # public

    def compute(self):
        for dq in (self.presence, self.distance, self.gaze):
            self.trim(dq)

        p = (sum(v for _, v in self.presence) / len(self.presence)
             if self.presence else 0.0)
        prox = (sum(self.proximity_score(v) for _, v in self.distance)
                / len(self.distance) if self.distance else 0.0)
        g = (sum(v for _, v in self.gaze) / len(self.gaze)
             if self.gaze else 0.0)

        w_p = self.get_parameter('w_presence').value
        w_x = self.get_parameter('w_proximity').value
        w_g = self.get_parameter('w_gaze').value
        sws = 100.0 * (w_p * p + w_x * prox + w_g * g)

        self.score_pub.publish(Float32(data=sws))
        self.csv.writerow([f'{self.now():.1f}', f'{p:.2f}',
                           f'{prox:.2f}', f'{g:.2f}', f'{sws:.1f}'])
        self.csv_file.flush()
        self.get_logger().info(
            f'presence={p:.2f} prox={prox:.2f} gaze={g:.2f} -> SWS={sws:.1f}')


def main(args=None):
    rclpy.init(args=args)
    node = SwsAggregator()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.csv_file.close()
    node.destroy_node()


if __name__ == '__main__':
    main()

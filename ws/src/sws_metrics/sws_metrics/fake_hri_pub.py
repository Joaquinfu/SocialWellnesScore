"""Synthetic ROS4HRI publisher — simulates a person interacting with RYAN.

Lets every downstream SWS node be developed without the camera.
Scenarios are switchable live via a ROS2 parameter.
"""
import math
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32, Bool
from hri_msgs.msg import IdsList


class FakeHriPub(Node):
    def __init__(self):
        super().__init__('fake_hri_pub')

        # --- parameter: which scenario to simulate ---
        self.declare_parameter('scenario', 'near_engaged')
        # valid: absent | near_engaged | far_ignoring | intermittent

        # --- publishers (topic name, queue size) ---
        self.faces_pub = self.create_publisher(IdsList, '/humans/faces/tracked', 10)
        self.dist_pub  = self.create_publisher(Float32, '/sws/fake/distance', 10)
        self.gaze_pub  = self.create_publisher(Bool,    '/sws/fake/gaze_at_robot', 10)

        # --- timer: fire tick() at 6 Hz, matching the camera's USB2 rate ---
        self.timer = self.create_timer(1.0 / 6.0, self.tick)
        self.t = 0.0  # simulated clock, seconds

        self.get_logger().info('fake_hri_pub up — scenario: '
                               + self.get_parameter('scenario').value)

    def tick(self):
        self.t += 1.0 / 6.0
        scenario = self.get_parameter('scenario').value

        present, distance, gazing = self.simulate(scenario)

        faces = IdsList()
        faces.ids = ['fake_face_0'] if present else []
        self.faces_pub.publish(faces)

        if present:
            self.dist_pub.publish(Float32(data=distance))
            self.gaze_pub.publish(Bool(data=gazing))

    def simulate(self, scenario):
        """Return (person_present, distance_m, gazing_at_robot)."""
        if scenario == 'absent':
            return False, 0.0, False

        if scenario == 'near_engaged':
            # ~1.0 m, gently swaying, almost always looking at robot
            d = 1.0 + 0.15 * math.sin(self.t * 0.5)
            return True, d, (self.t % 10.0) > 1.0     # glances away 1s per 10s

        if scenario == 'far_ignoring':
            # ~3.5 m (social/public zone), rarely looks over
            d = 3.5 + 0.3 * math.sin(self.t * 0.2)
            return True, d, (self.t % 30.0) < 2.0     # 2s glance per 30s

        if scenario == 'intermittent':
            # walks in and out on a 60 s cycle: present 20 s, gone 40 s
            present = (self.t % 60.0) < 20.0
            d = 1.5 + 0.5 * math.sin(self.t * 0.3)
            return present, d, present and (self.t % 7.0) > 2.0

        self.get_logger().warn(f'unknown scenario "{scenario}", treating as absent')
        return False, 0.0, False


def main(args=None):
    rclpy.init(args=args)
    node = FakeHriPub()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()


if __name__ == '__main__':
    main()

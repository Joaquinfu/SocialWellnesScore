# Copyright (c) 2026 TODO. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import json

from rclpy.node import Node
from rclpy.action import ActionClient

from hri_actions_msgs.msg import Intent
from tts_msgs.action import TTS


class MissionController(Node):

    def __init__(self) -> None:
        super().__init__('app_emotion_mirror')

        self.get_logger().info("Initialising...")

        self._intents_sub = self.create_subscription(
            Intent,
            '/intents',
            self.on_intent,
            10)
        self.get_logger().info("Listening to %s topic" %
                               self._intents_sub.topic_name)

        # TTS action client — lets us make the robot speak
        self.tts = ActionClient(self, TTS, '/say')
        self.tts.wait_for_server()

    def __del__(self):
        self.destroy_subscription(self._intents_sub)

    def on_intent(self, msg) -> None:

        self.get_logger().info("Received an intent: %s" % msg.intent)

        data = json.loads(msg.data) if msg.data else {}
        source = msg.source
        modality = msg.modality
        confidence = msg.confidence
        priority_hint = msg.priority

        if msg.intent == Intent.RAW_USER_INPUT:
            self.get_logger().info(f"Processing input: {msg.intent}")

            # Send a spoken response
            goal = TTS.Goal()
            goal.input = "<set expression(happy)> Hello! I am the emotion mirroring robot! <set expression(neutral)>"
            self.tts.send_goal_async(goal)

        else:
            self.get_logger().warning("I don't know how to process intent "
                                      "<%s>!" % msg.intent)
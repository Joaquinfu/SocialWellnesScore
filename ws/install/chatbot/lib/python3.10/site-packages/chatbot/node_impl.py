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
from rclpy.lifecycle import Node
from rclpy.lifecycle import State
from rclpy.lifecycle import TransitionCallbackReturn
from rcl_interfaces.msg import ParameterDescriptor
from rclpy.action import ActionServer, GoalResponse

from chatbot_msgs.srv import GetResponse, ResetModel
from hri_actions_msgs.msg import Intent
from i18n_msgs.action import SetLocale
from i18n_msgs.srv import GetLocales

from diagnostic_msgs.msg import DiagnosticArray, DiagnosticStatus, KeyValue


class IntentExtractorImpl(Node):
    """
    Implementation of chatbot.

    This is the main class for the node. It is a ROS2  node that uses the
    lifecycle feature of ROS 2 to manage its states.

    The purpose of this node is to recognise *user intents* using a chatbot.
    This template is very simple, and should be used as a starting point to
    integrate your own chatbot system.
    """

    def __init__(self) -> None:
        """Construct the node."""
        super().__init__('intent_extractor_chatbot')

        # Declare ROS parameters. Should mimick the one listed in config/00-defaults.yaml
        self.declare_parameter(
          'my_parameter', "my_default_value.",
          ParameterDescriptor(description='Important parameter for my chatbot')
        )

        self.get_logger().info("Initialising...")

        self._get_response_srv = None
        self._reset_srv = None
        self._get_supported_locales_server = None
        self._set_default_locale_server = None

        self._timer = None
        self._diag_pub = None
        self._diag_timer = None

        self._nb_requests = 0

        self.get_logger().info('Chatbot chatbot started, but not yet configured.')

    def on_get_response(self, request: GetResponse.Request, response: GetResponse.Response):

        user_id = request.user_id
        input = request.input

        self.get_logger().info(f"input from {user_id}: {input}")
        self._nb_requests += 1

        # implement here the logic to process the natural text input
        #
        # You might want to:
        # - recognise and return the user intent (if any), and map it to the
        # Intent.msg semantics.
        # - return a suggested response to the user (if any)
        #
        # For now, we just try to recognise a greeting
        if "hello" in input.lower() or "hi" in input.lower():
            self.get_logger().warn("I think the user want to greet me. Sending a GREET intent")
            intent = Intent(intent=Intent.GREET,
                            source=user_id,
                            modality=Intent.MODALITY_SPEECH,
                            confidence=.8)
            suggested_response = "Hello! How can I help you?"
        else:
            self.get_logger().warn("Unable to recognise a particular intent! "
                                   "forwarding a 'RAW_USER_INPUT'")
            intent = Intent(intent=Intent.RAW_USER_INPUT,
                            source=user_id,
                            modality=Intent.MODALITY_SPEECH,
                            confidence=1.0,
                            data=json.dumps({"input": input}))
            suggested_response = "I'm sorry, I did not understand. " \
                                 "My basic chatbot is not very smart yet."

            suggested_response += " However, I can tell you about my last holidays:"
            suggested_response += [
                " I went to the beach and had a great time!",
                " I visited my family and we had a great dinner together.",
                " I stayed at home and watched movies all day.",
                " I went to the mountains and did some hiking.",
                " I went to the city and visited a museum."][self._nb_requests % 5]

        response.response = suggested_response
        response.intents = [intent]

        return response

    def on_reset(self, request: ResetModel.Request, response: ResetModel.Response):
        self.get_logger().info('Received reset request. Not implemented yet.')
        return response

    def on_get_supported_locales(self, request, response):
        response.locales = []  # list of supported locales; empty means any
        return response

    def on_set_default_locale_goal(self, goal_request):
        return GoalResponse.ACCEPT

    def on_set_default_locale_exec(self, goal_handle):
        """Change here the default locale of the chatbot."""
        result = SetLocale.Result()
        goal_handle.succeed()
        return result

    #################################
    #
    # Lifecycle transitions callbacks
    #
    def on_configure(self, state: State) -> TransitionCallbackReturn:

        # configure and start diagnostics publishing
        self._nb_requests = 0
        self._diag_pub = self.create_publisher(DiagnosticArray, '/diagnostics', 1)
        self._diag_timer = self.create_timer(1., self.publish_diagnostics)

        # start advertising supported locales
        self._get_supported_locales_server = self.create_service(
            GetLocales, "~/get_supported_locales", self.on_get_supported_locales)

        self._set_default_locale_server = ActionServer(
            self, SetLocale, "~/set_default_locale",
            goal_callback=self.on_set_default_locale_goal,
            execute_callback=self.on_set_default_locale_exec)

        self.get_logger().info("Chatbot chatbot is configured, but not yet active")
        return TransitionCallbackReturn.SUCCESS

    def on_activate(self, state: State) -> TransitionCallbackReturn:
        """
        Activate the node.

        You usually want to do the following in this state:
        - Create and start any timers performing periodic tasks
        - Start processing data, and accepting action goals, if any

        """
        self._get_response_srv = self.create_service(
            GetResponse, '/chatbot/get_response', self.on_get_response)
        self._reset_srv = self.create_service(
            ResetModel, '/chatbot/reset', self.on_reset)

        # Define a timer that fires every second to call the run function
        timer_period = 1  # in sec
        self._timer = self.create_timer(timer_period, self.run)

        self.get_logger().info("Chatbot chatbot is active and running")
        return super().on_activate(state)

    def on_deactivate(self, state: State) -> TransitionCallbackReturn:
        """Stop the timer to stop calling the `run` function (main task of your application)."""
        self.get_logger().info("Stopping chatbot...")

        self.destroy_timer(self._timer)
        self.destroy_service(self._get_response_srv)
        self.destroy_service(self._reset_srv)

        self.get_logger().info("Chatbot chatbot is stopped (inactive)")
        return super().on_deactivate(state)

    def on_shutdown(self, state: State) -> TransitionCallbackReturn:
        """
        Shutdown the node, after a shutting-down transition is requested.

        :return: The state machine either invokes a transition to the
            "finalized" state or stays in the current state depending on the
            return value.
            TransitionCallbackReturn.SUCCESS transitions to "finalized".
            TransitionCallbackReturn.FAILURE remains in current state.
            TransitionCallbackReturn.ERROR or any uncaught exceptions to
            "errorprocessing"
        """
        self.get_logger().info('Shutting down chatbot node.')
        self.destroy_timer(self._diag_timer)
        self.destroy_publisher(self._diag_pub)

        self.destroy_service(self._get_supported_locales_server)
        self._set_default_locale_server.destroy()

        self.get_logger().info("Chatbot chatbot finalized.")
        return TransitionCallbackReturn.SUCCESS

    #################################

    def publish_diagnostics(self):

        arr = DiagnosticArray()
        msg = DiagnosticStatus(
            level=DiagnosticStatus.OK,
            name="/intent_extractor_chatbot",
            message="chatbot chatbot is running",
            values=[
                KeyValue(key="Module name", value="chatbot"),
                KeyValue(key="Current lifecycle state",
                         value=self._state_machine.current_state[1]),
                KeyValue(key="# requests since start", value=str(self._nb_requests)),
            ],
        )

        arr.header.stamp = self.get_clock().now().to_msg()
        arr.status = [msg]
        self._diag_pub.publish(arr)

    def run(self) -> None:
        """
        Background task of the chatbot.

        For now, we do not need to do anything here, as the chatbot is
        event-driven, and the `on_user_input` callback is called when a new
        user input is received.
        """
        pass

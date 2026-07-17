import json
from ollama import Client

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

    def __init__(self) -> None:
        super().__init__('intent_extractor_chatbot')

        self.declare_parameter(
            'my_parameter', "my_default_value.",
            ParameterDescriptor(description='Important parameter'))

        self.get_logger().info("Initialising...")

        self._get_response_srv = None
        self._reset_srv = None
        self._get_supported_locales_server = None
        self._set_default_locale_server = None
        self._timer = None
        self._diag_pub = None
        self._diag_timer = None
        self._nb_requests = 0

        # Connect to Ollama running on Windows host
        self._ollama_client = Client("http://localhost:11434")

        # Conversation history — system prompt sets the robot's personality
        self.messages = [
            {
                "role": "system",
                "content": """
                    You are a helpful social robot assistant called RYAN.
                    You are deployed in an eldercare facility and help monitor
                    the social wellness of residents. You are warm, friendly,
                    and concise in your responses. Always respond in 1-2 sentences.
                """
            }
        ]

        self.get_logger().info('Chatbot started!')

    def on_get_response(self, request, response):

        user_id = request.user_id
        user_input = request.input

        self.get_logger().info(f"Input from {user_id}: {user_input}")
        self._nb_requests += 1

        # Add user message to history
        self.messages.append({"role": "user", "content": user_input})

        # Call Ollama
        llm_res = self._ollama_client.chat(
            messages=self.messages,
            model="llama3.2:1b"
        )

        content = llm_res.message.content
        self.get_logger().info(f"LLM response: {content}")

        # Add response to history
        self.messages.append({"role": "assistant", "content": content})

        response.response = content
        response.intents = []

        return response

    def on_reset(self, request, response):
        self.messages = self.messages[:1]  # keep system prompt
        self.get_logger().info('Conversation reset.')
        return response

    def on_get_supported_locales(self, request, response):
        response.locales = []
        return response

    def on_set_default_locale_goal(self, goal_request):
        return GoalResponse.ACCEPT

    def on_set_default_locale_exec(self, goal_handle):
        result = SetLocale.Result()
        goal_handle.succeed()
        return result

    def on_configure(self, state: State) -> TransitionCallbackReturn:
        self._nb_requests = 0
        self._diag_pub = self.create_publisher(DiagnosticArray, '/diagnostics', 1)
        self._diag_timer = self.create_timer(1., self.publish_diagnostics)
        self._get_supported_locales_server = self.create_service(
            GetLocales, "~/get_supported_locales", self.on_get_supported_locales)
        self._set_default_locale_server = ActionServer(
            self, SetLocale, "~/set_default_locale",
            goal_callback=self.on_set_default_locale_goal,
            execute_callback=self.on_set_default_locale_exec)
        return TransitionCallbackReturn.SUCCESS

    def on_activate(self, state: State) -> TransitionCallbackReturn:
        self._get_response_srv = self.create_service(
            GetResponse, '/chatbot/get_response', self.on_get_response)
        self._reset_srv = self.create_service(
            ResetModel, '/chatbot/reset', self.on_reset)
        self._timer = self.create_timer(1, self.run)
        self.get_logger().info("Chatbot active!")
        return super().on_activate(state)

    def on_deactivate(self, state: State) -> TransitionCallbackReturn:
        self.destroy_timer(self._timer)
        self.destroy_service(self._get_response_srv)
        self.destroy_service(self._reset_srv)
        return super().on_deactivate(state)

    def on_shutdown(self, state: State) -> TransitionCallbackReturn:
        self.destroy_timer(self._diag_timer)
        self.destroy_publisher(self._diag_pub)
        self.destroy_service(self._get_supported_locales_server)
        self._set_default_locale_server.destroy()
        return TransitionCallbackReturn.SUCCESS

    def publish_diagnostics(self):
        arr = DiagnosticArray()
        msg = DiagnosticStatus(
            level=DiagnosticStatus.OK,
            name="/intent_extractor_chatbot",
            message="Chatbot running",
            values=[
                KeyValue(key="Module", value="chatbot"),
                KeyValue(key="Requests", value=str(self._nb_requests)),
            ],
        )
        arr.header.stamp = self.get_clock().now().to_msg()
        arr.status = [msg]
        self._diag_pub.publish(arr)

    def run(self) -> None:
        pass
        
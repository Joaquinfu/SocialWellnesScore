// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from sample_skill_msgs:action/SkillControl.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "sample_skill_msgs/action/detail/skill_control__rosidl_typesupport_introspection_c.h"
#include "sample_skill_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "sample_skill_msgs/action/detail/skill_control__functions.h"
#include "sample_skill_msgs/action/detail/skill_control__struct.h"


// Include directives for member types
// Member `meta`
#include "std_skills/msg/meta.h"
// Member `meta`
#include "std_skills/msg/detail/meta__rosidl_typesupport_introspection_c.h"
// Member `skill_data`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void sample_skill_msgs__action__SkillControl_Goal__rosidl_typesupport_introspection_c__SkillControl_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sample_skill_msgs__action__SkillControl_Goal__init(message_memory);
}

void sample_skill_msgs__action__SkillControl_Goal__rosidl_typesupport_introspection_c__SkillControl_Goal_fini_function(void * message_memory)
{
  sample_skill_msgs__action__SkillControl_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember sample_skill_msgs__action__SkillControl_Goal__rosidl_typesupport_introspection_c__SkillControl_Goal_message_member_array[2] = {
  {
    "meta",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sample_skill_msgs__action__SkillControl_Goal, meta),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "skill_data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sample_skill_msgs__action__SkillControl_Goal, skill_data),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sample_skill_msgs__action__SkillControl_Goal__rosidl_typesupport_introspection_c__SkillControl_Goal_message_members = {
  "sample_skill_msgs__action",  // message namespace
  "SkillControl_Goal",  // message name
  2,  // number of fields
  sizeof(sample_skill_msgs__action__SkillControl_Goal),
  sample_skill_msgs__action__SkillControl_Goal__rosidl_typesupport_introspection_c__SkillControl_Goal_message_member_array,  // message members
  sample_skill_msgs__action__SkillControl_Goal__rosidl_typesupport_introspection_c__SkillControl_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  sample_skill_msgs__action__SkillControl_Goal__rosidl_typesupport_introspection_c__SkillControl_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sample_skill_msgs__action__SkillControl_Goal__rosidl_typesupport_introspection_c__SkillControl_Goal_message_type_support_handle = {
  0,
  &sample_skill_msgs__action__SkillControl_Goal__rosidl_typesupport_introspection_c__SkillControl_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sample_skill_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sample_skill_msgs, action, SkillControl_Goal)() {
  sample_skill_msgs__action__SkillControl_Goal__rosidl_typesupport_introspection_c__SkillControl_Goal_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_skills, msg, Meta)();
  if (!sample_skill_msgs__action__SkillControl_Goal__rosidl_typesupport_introspection_c__SkillControl_Goal_message_type_support_handle.typesupport_identifier) {
    sample_skill_msgs__action__SkillControl_Goal__rosidl_typesupport_introspection_c__SkillControl_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sample_skill_msgs__action__SkillControl_Goal__rosidl_typesupport_introspection_c__SkillControl_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__rosidl_typesupport_introspection_c.h"
// already included above
// #include "sample_skill_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__functions.h"
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__struct.h"


// Include directives for member types
// Member `result`
#include "std_skills/msg/result.h"
// Member `result`
#include "std_skills/msg/detail/result__rosidl_typesupport_introspection_c.h"
// Member `value`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void sample_skill_msgs__action__SkillControl_Result__rosidl_typesupport_introspection_c__SkillControl_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sample_skill_msgs__action__SkillControl_Result__init(message_memory);
}

void sample_skill_msgs__action__SkillControl_Result__rosidl_typesupport_introspection_c__SkillControl_Result_fini_function(void * message_memory)
{
  sample_skill_msgs__action__SkillControl_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember sample_skill_msgs__action__SkillControl_Result__rosidl_typesupport_introspection_c__SkillControl_Result_message_member_array[2] = {
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sample_skill_msgs__action__SkillControl_Result, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sample_skill_msgs__action__SkillControl_Result, value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sample_skill_msgs__action__SkillControl_Result__rosidl_typesupport_introspection_c__SkillControl_Result_message_members = {
  "sample_skill_msgs__action",  // message namespace
  "SkillControl_Result",  // message name
  2,  // number of fields
  sizeof(sample_skill_msgs__action__SkillControl_Result),
  sample_skill_msgs__action__SkillControl_Result__rosidl_typesupport_introspection_c__SkillControl_Result_message_member_array,  // message members
  sample_skill_msgs__action__SkillControl_Result__rosidl_typesupport_introspection_c__SkillControl_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  sample_skill_msgs__action__SkillControl_Result__rosidl_typesupport_introspection_c__SkillControl_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sample_skill_msgs__action__SkillControl_Result__rosidl_typesupport_introspection_c__SkillControl_Result_message_type_support_handle = {
  0,
  &sample_skill_msgs__action__SkillControl_Result__rosidl_typesupport_introspection_c__SkillControl_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sample_skill_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sample_skill_msgs, action, SkillControl_Result)() {
  sample_skill_msgs__action__SkillControl_Result__rosidl_typesupport_introspection_c__SkillControl_Result_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_skills, msg, Result)();
  if (!sample_skill_msgs__action__SkillControl_Result__rosidl_typesupport_introspection_c__SkillControl_Result_message_type_support_handle.typesupport_identifier) {
    sample_skill_msgs__action__SkillControl_Result__rosidl_typesupport_introspection_c__SkillControl_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sample_skill_msgs__action__SkillControl_Result__rosidl_typesupport_introspection_c__SkillControl_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__rosidl_typesupport_introspection_c.h"
// already included above
// #include "sample_skill_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__functions.h"
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__struct.h"


// Include directives for member types
// Member `feedback`
#include "std_skills/msg/feedback.h"
// Member `feedback`
#include "std_skills/msg/detail/feedback__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void sample_skill_msgs__action__SkillControl_Feedback__rosidl_typesupport_introspection_c__SkillControl_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sample_skill_msgs__action__SkillControl_Feedback__init(message_memory);
}

void sample_skill_msgs__action__SkillControl_Feedback__rosidl_typesupport_introspection_c__SkillControl_Feedback_fini_function(void * message_memory)
{
  sample_skill_msgs__action__SkillControl_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember sample_skill_msgs__action__SkillControl_Feedback__rosidl_typesupport_introspection_c__SkillControl_Feedback_message_member_array[1] = {
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sample_skill_msgs__action__SkillControl_Feedback, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sample_skill_msgs__action__SkillControl_Feedback__rosidl_typesupport_introspection_c__SkillControl_Feedback_message_members = {
  "sample_skill_msgs__action",  // message namespace
  "SkillControl_Feedback",  // message name
  1,  // number of fields
  sizeof(sample_skill_msgs__action__SkillControl_Feedback),
  sample_skill_msgs__action__SkillControl_Feedback__rosidl_typesupport_introspection_c__SkillControl_Feedback_message_member_array,  // message members
  sample_skill_msgs__action__SkillControl_Feedback__rosidl_typesupport_introspection_c__SkillControl_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  sample_skill_msgs__action__SkillControl_Feedback__rosidl_typesupport_introspection_c__SkillControl_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sample_skill_msgs__action__SkillControl_Feedback__rosidl_typesupport_introspection_c__SkillControl_Feedback_message_type_support_handle = {
  0,
  &sample_skill_msgs__action__SkillControl_Feedback__rosidl_typesupport_introspection_c__SkillControl_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sample_skill_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sample_skill_msgs, action, SkillControl_Feedback)() {
  sample_skill_msgs__action__SkillControl_Feedback__rosidl_typesupport_introspection_c__SkillControl_Feedback_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_skills, msg, Feedback)();
  if (!sample_skill_msgs__action__SkillControl_Feedback__rosidl_typesupport_introspection_c__SkillControl_Feedback_message_type_support_handle.typesupport_identifier) {
    sample_skill_msgs__action__SkillControl_Feedback__rosidl_typesupport_introspection_c__SkillControl_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sample_skill_msgs__action__SkillControl_Feedback__rosidl_typesupport_introspection_c__SkillControl_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__rosidl_typesupport_introspection_c.h"
// already included above
// #include "sample_skill_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__functions.h"
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "sample_skill_msgs/action/skill_control.h"
// Member `goal`
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void sample_skill_msgs__action__SkillControl_SendGoal_Request__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sample_skill_msgs__action__SkillControl_SendGoal_Request__init(message_memory);
}

void sample_skill_msgs__action__SkillControl_SendGoal_Request__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Request_fini_function(void * message_memory)
{
  sample_skill_msgs__action__SkillControl_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember sample_skill_msgs__action__SkillControl_SendGoal_Request__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sample_skill_msgs__action__SkillControl_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sample_skill_msgs__action__SkillControl_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sample_skill_msgs__action__SkillControl_SendGoal_Request__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Request_message_members = {
  "sample_skill_msgs__action",  // message namespace
  "SkillControl_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(sample_skill_msgs__action__SkillControl_SendGoal_Request),
  sample_skill_msgs__action__SkillControl_SendGoal_Request__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Request_message_member_array,  // message members
  sample_skill_msgs__action__SkillControl_SendGoal_Request__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  sample_skill_msgs__action__SkillControl_SendGoal_Request__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sample_skill_msgs__action__SkillControl_SendGoal_Request__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Request_message_type_support_handle = {
  0,
  &sample_skill_msgs__action__SkillControl_SendGoal_Request__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sample_skill_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sample_skill_msgs, action, SkillControl_SendGoal_Request)() {
  sample_skill_msgs__action__SkillControl_SendGoal_Request__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  sample_skill_msgs__action__SkillControl_SendGoal_Request__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sample_skill_msgs, action, SkillControl_Goal)();
  if (!sample_skill_msgs__action__SkillControl_SendGoal_Request__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    sample_skill_msgs__action__SkillControl_SendGoal_Request__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sample_skill_msgs__action__SkillControl_SendGoal_Request__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__rosidl_typesupport_introspection_c.h"
// already included above
// #include "sample_skill_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__functions.h"
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void sample_skill_msgs__action__SkillControl_SendGoal_Response__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sample_skill_msgs__action__SkillControl_SendGoal_Response__init(message_memory);
}

void sample_skill_msgs__action__SkillControl_SendGoal_Response__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Response_fini_function(void * message_memory)
{
  sample_skill_msgs__action__SkillControl_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember sample_skill_msgs__action__SkillControl_SendGoal_Response__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sample_skill_msgs__action__SkillControl_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sample_skill_msgs__action__SkillControl_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sample_skill_msgs__action__SkillControl_SendGoal_Response__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Response_message_members = {
  "sample_skill_msgs__action",  // message namespace
  "SkillControl_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(sample_skill_msgs__action__SkillControl_SendGoal_Response),
  sample_skill_msgs__action__SkillControl_SendGoal_Response__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Response_message_member_array,  // message members
  sample_skill_msgs__action__SkillControl_SendGoal_Response__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  sample_skill_msgs__action__SkillControl_SendGoal_Response__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sample_skill_msgs__action__SkillControl_SendGoal_Response__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Response_message_type_support_handle = {
  0,
  &sample_skill_msgs__action__SkillControl_SendGoal_Response__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sample_skill_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sample_skill_msgs, action, SkillControl_SendGoal_Response)() {
  sample_skill_msgs__action__SkillControl_SendGoal_Response__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!sample_skill_msgs__action__SkillControl_SendGoal_Response__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    sample_skill_msgs__action__SkillControl_SendGoal_Response__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sample_skill_msgs__action__SkillControl_SendGoal_Response__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "sample_skill_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers sample_skill_msgs__action__detail__skill_control__rosidl_typesupport_introspection_c__SkillControl_SendGoal_service_members = {
  "sample_skill_msgs__action",  // service namespace
  "SkillControl_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // sample_skill_msgs__action__detail__skill_control__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // sample_skill_msgs__action__detail__skill_control__rosidl_typesupport_introspection_c__SkillControl_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t sample_skill_msgs__action__detail__skill_control__rosidl_typesupport_introspection_c__SkillControl_SendGoal_service_type_support_handle = {
  0,
  &sample_skill_msgs__action__detail__skill_control__rosidl_typesupport_introspection_c__SkillControl_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sample_skill_msgs, action, SkillControl_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sample_skill_msgs, action, SkillControl_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sample_skill_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sample_skill_msgs, action, SkillControl_SendGoal)() {
  if (!sample_skill_msgs__action__detail__skill_control__rosidl_typesupport_introspection_c__SkillControl_SendGoal_service_type_support_handle.typesupport_identifier) {
    sample_skill_msgs__action__detail__skill_control__rosidl_typesupport_introspection_c__SkillControl_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)sample_skill_msgs__action__detail__skill_control__rosidl_typesupport_introspection_c__SkillControl_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sample_skill_msgs, action, SkillControl_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sample_skill_msgs, action, SkillControl_SendGoal_Response)()->data;
  }

  return &sample_skill_msgs__action__detail__skill_control__rosidl_typesupport_introspection_c__SkillControl_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__rosidl_typesupport_introspection_c.h"
// already included above
// #include "sample_skill_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__functions.h"
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void sample_skill_msgs__action__SkillControl_GetResult_Request__rosidl_typesupport_introspection_c__SkillControl_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sample_skill_msgs__action__SkillControl_GetResult_Request__init(message_memory);
}

void sample_skill_msgs__action__SkillControl_GetResult_Request__rosidl_typesupport_introspection_c__SkillControl_GetResult_Request_fini_function(void * message_memory)
{
  sample_skill_msgs__action__SkillControl_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember sample_skill_msgs__action__SkillControl_GetResult_Request__rosidl_typesupport_introspection_c__SkillControl_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sample_skill_msgs__action__SkillControl_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sample_skill_msgs__action__SkillControl_GetResult_Request__rosidl_typesupport_introspection_c__SkillControl_GetResult_Request_message_members = {
  "sample_skill_msgs__action",  // message namespace
  "SkillControl_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(sample_skill_msgs__action__SkillControl_GetResult_Request),
  sample_skill_msgs__action__SkillControl_GetResult_Request__rosidl_typesupport_introspection_c__SkillControl_GetResult_Request_message_member_array,  // message members
  sample_skill_msgs__action__SkillControl_GetResult_Request__rosidl_typesupport_introspection_c__SkillControl_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  sample_skill_msgs__action__SkillControl_GetResult_Request__rosidl_typesupport_introspection_c__SkillControl_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sample_skill_msgs__action__SkillControl_GetResult_Request__rosidl_typesupport_introspection_c__SkillControl_GetResult_Request_message_type_support_handle = {
  0,
  &sample_skill_msgs__action__SkillControl_GetResult_Request__rosidl_typesupport_introspection_c__SkillControl_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sample_skill_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sample_skill_msgs, action, SkillControl_GetResult_Request)() {
  sample_skill_msgs__action__SkillControl_GetResult_Request__rosidl_typesupport_introspection_c__SkillControl_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!sample_skill_msgs__action__SkillControl_GetResult_Request__rosidl_typesupport_introspection_c__SkillControl_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    sample_skill_msgs__action__SkillControl_GetResult_Request__rosidl_typesupport_introspection_c__SkillControl_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sample_skill_msgs__action__SkillControl_GetResult_Request__rosidl_typesupport_introspection_c__SkillControl_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__rosidl_typesupport_introspection_c.h"
// already included above
// #include "sample_skill_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__functions.h"
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "sample_skill_msgs/action/skill_control.h"
// Member `result`
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void sample_skill_msgs__action__SkillControl_GetResult_Response__rosidl_typesupport_introspection_c__SkillControl_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sample_skill_msgs__action__SkillControl_GetResult_Response__init(message_memory);
}

void sample_skill_msgs__action__SkillControl_GetResult_Response__rosidl_typesupport_introspection_c__SkillControl_GetResult_Response_fini_function(void * message_memory)
{
  sample_skill_msgs__action__SkillControl_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember sample_skill_msgs__action__SkillControl_GetResult_Response__rosidl_typesupport_introspection_c__SkillControl_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sample_skill_msgs__action__SkillControl_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sample_skill_msgs__action__SkillControl_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sample_skill_msgs__action__SkillControl_GetResult_Response__rosidl_typesupport_introspection_c__SkillControl_GetResult_Response_message_members = {
  "sample_skill_msgs__action",  // message namespace
  "SkillControl_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(sample_skill_msgs__action__SkillControl_GetResult_Response),
  sample_skill_msgs__action__SkillControl_GetResult_Response__rosidl_typesupport_introspection_c__SkillControl_GetResult_Response_message_member_array,  // message members
  sample_skill_msgs__action__SkillControl_GetResult_Response__rosidl_typesupport_introspection_c__SkillControl_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  sample_skill_msgs__action__SkillControl_GetResult_Response__rosidl_typesupport_introspection_c__SkillControl_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sample_skill_msgs__action__SkillControl_GetResult_Response__rosidl_typesupport_introspection_c__SkillControl_GetResult_Response_message_type_support_handle = {
  0,
  &sample_skill_msgs__action__SkillControl_GetResult_Response__rosidl_typesupport_introspection_c__SkillControl_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sample_skill_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sample_skill_msgs, action, SkillControl_GetResult_Response)() {
  sample_skill_msgs__action__SkillControl_GetResult_Response__rosidl_typesupport_introspection_c__SkillControl_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sample_skill_msgs, action, SkillControl_Result)();
  if (!sample_skill_msgs__action__SkillControl_GetResult_Response__rosidl_typesupport_introspection_c__SkillControl_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    sample_skill_msgs__action__SkillControl_GetResult_Response__rosidl_typesupport_introspection_c__SkillControl_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sample_skill_msgs__action__SkillControl_GetResult_Response__rosidl_typesupport_introspection_c__SkillControl_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "sample_skill_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers sample_skill_msgs__action__detail__skill_control__rosidl_typesupport_introspection_c__SkillControl_GetResult_service_members = {
  "sample_skill_msgs__action",  // service namespace
  "SkillControl_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // sample_skill_msgs__action__detail__skill_control__rosidl_typesupport_introspection_c__SkillControl_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // sample_skill_msgs__action__detail__skill_control__rosidl_typesupport_introspection_c__SkillControl_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t sample_skill_msgs__action__detail__skill_control__rosidl_typesupport_introspection_c__SkillControl_GetResult_service_type_support_handle = {
  0,
  &sample_skill_msgs__action__detail__skill_control__rosidl_typesupport_introspection_c__SkillControl_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sample_skill_msgs, action, SkillControl_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sample_skill_msgs, action, SkillControl_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sample_skill_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sample_skill_msgs, action, SkillControl_GetResult)() {
  if (!sample_skill_msgs__action__detail__skill_control__rosidl_typesupport_introspection_c__SkillControl_GetResult_service_type_support_handle.typesupport_identifier) {
    sample_skill_msgs__action__detail__skill_control__rosidl_typesupport_introspection_c__SkillControl_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)sample_skill_msgs__action__detail__skill_control__rosidl_typesupport_introspection_c__SkillControl_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sample_skill_msgs, action, SkillControl_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sample_skill_msgs, action, SkillControl_GetResult_Response)()->data;
  }

  return &sample_skill_msgs__action__detail__skill_control__rosidl_typesupport_introspection_c__SkillControl_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__rosidl_typesupport_introspection_c.h"
// already included above
// #include "sample_skill_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__functions.h"
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "sample_skill_msgs/action/skill_control.h"
// Member `feedback`
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void sample_skill_msgs__action__SkillControl_FeedbackMessage__rosidl_typesupport_introspection_c__SkillControl_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sample_skill_msgs__action__SkillControl_FeedbackMessage__init(message_memory);
}

void sample_skill_msgs__action__SkillControl_FeedbackMessage__rosidl_typesupport_introspection_c__SkillControl_FeedbackMessage_fini_function(void * message_memory)
{
  sample_skill_msgs__action__SkillControl_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember sample_skill_msgs__action__SkillControl_FeedbackMessage__rosidl_typesupport_introspection_c__SkillControl_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sample_skill_msgs__action__SkillControl_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sample_skill_msgs__action__SkillControl_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sample_skill_msgs__action__SkillControl_FeedbackMessage__rosidl_typesupport_introspection_c__SkillControl_FeedbackMessage_message_members = {
  "sample_skill_msgs__action",  // message namespace
  "SkillControl_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(sample_skill_msgs__action__SkillControl_FeedbackMessage),
  sample_skill_msgs__action__SkillControl_FeedbackMessage__rosidl_typesupport_introspection_c__SkillControl_FeedbackMessage_message_member_array,  // message members
  sample_skill_msgs__action__SkillControl_FeedbackMessage__rosidl_typesupport_introspection_c__SkillControl_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  sample_skill_msgs__action__SkillControl_FeedbackMessage__rosidl_typesupport_introspection_c__SkillControl_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sample_skill_msgs__action__SkillControl_FeedbackMessage__rosidl_typesupport_introspection_c__SkillControl_FeedbackMessage_message_type_support_handle = {
  0,
  &sample_skill_msgs__action__SkillControl_FeedbackMessage__rosidl_typesupport_introspection_c__SkillControl_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sample_skill_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sample_skill_msgs, action, SkillControl_FeedbackMessage)() {
  sample_skill_msgs__action__SkillControl_FeedbackMessage__rosidl_typesupport_introspection_c__SkillControl_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  sample_skill_msgs__action__SkillControl_FeedbackMessage__rosidl_typesupport_introspection_c__SkillControl_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sample_skill_msgs, action, SkillControl_Feedback)();
  if (!sample_skill_msgs__action__SkillControl_FeedbackMessage__rosidl_typesupport_introspection_c__SkillControl_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    sample_skill_msgs__action__SkillControl_FeedbackMessage__rosidl_typesupport_introspection_c__SkillControl_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sample_skill_msgs__action__SkillControl_FeedbackMessage__rosidl_typesupport_introspection_c__SkillControl_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

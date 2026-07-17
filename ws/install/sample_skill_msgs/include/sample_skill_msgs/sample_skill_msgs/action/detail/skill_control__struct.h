// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sample_skill_msgs:action/SkillControl.idl
// generated code does not contain a copyright notice

#ifndef SAMPLE_SKILL_MSGS__ACTION__DETAIL__SKILL_CONTROL__STRUCT_H_
#define SAMPLE_SKILL_MSGS__ACTION__DETAIL__SKILL_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'meta'
#include "std_skills/msg/detail/meta__struct.h"
// Member 'skill_data'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/SkillControl in the package sample_skill_msgs.
typedef struct sample_skill_msgs__action__SkillControl_Goal
{
  std_skills__msg__Meta meta;
  rosidl_runtime_c__String skill_data;
} sample_skill_msgs__action__SkillControl_Goal;

// Struct for a sequence of sample_skill_msgs__action__SkillControl_Goal.
typedef struct sample_skill_msgs__action__SkillControl_Goal__Sequence
{
  sample_skill_msgs__action__SkillControl_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sample_skill_msgs__action__SkillControl_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
#include "std_skills/msg/detail/result__struct.h"
// Member 'value'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/SkillControl in the package sample_skill_msgs.
typedef struct sample_skill_msgs__action__SkillControl_Result
{
  std_skills__msg__Result result;
  rosidl_runtime_c__String value;
} sample_skill_msgs__action__SkillControl_Result;

// Struct for a sequence of sample_skill_msgs__action__SkillControl_Result.
typedef struct sample_skill_msgs__action__SkillControl_Result__Sequence
{
  sample_skill_msgs__action__SkillControl_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sample_skill_msgs__action__SkillControl_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'feedback'
#include "std_skills/msg/detail/feedback__struct.h"

/// Struct defined in action/SkillControl in the package sample_skill_msgs.
typedef struct sample_skill_msgs__action__SkillControl_Feedback
{
  std_skills__msg__Feedback feedback;
} sample_skill_msgs__action__SkillControl_Feedback;

// Struct for a sequence of sample_skill_msgs__action__SkillControl_Feedback.
typedef struct sample_skill_msgs__action__SkillControl_Feedback__Sequence
{
  sample_skill_msgs__action__SkillControl_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sample_skill_msgs__action__SkillControl_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "sample_skill_msgs/action/detail/skill_control__struct.h"

/// Struct defined in action/SkillControl in the package sample_skill_msgs.
typedef struct sample_skill_msgs__action__SkillControl_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  sample_skill_msgs__action__SkillControl_Goal goal;
} sample_skill_msgs__action__SkillControl_SendGoal_Request;

// Struct for a sequence of sample_skill_msgs__action__SkillControl_SendGoal_Request.
typedef struct sample_skill_msgs__action__SkillControl_SendGoal_Request__Sequence
{
  sample_skill_msgs__action__SkillControl_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sample_skill_msgs__action__SkillControl_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/SkillControl in the package sample_skill_msgs.
typedef struct sample_skill_msgs__action__SkillControl_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} sample_skill_msgs__action__SkillControl_SendGoal_Response;

// Struct for a sequence of sample_skill_msgs__action__SkillControl_SendGoal_Response.
typedef struct sample_skill_msgs__action__SkillControl_SendGoal_Response__Sequence
{
  sample_skill_msgs__action__SkillControl_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sample_skill_msgs__action__SkillControl_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/SkillControl in the package sample_skill_msgs.
typedef struct sample_skill_msgs__action__SkillControl_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} sample_skill_msgs__action__SkillControl_GetResult_Request;

// Struct for a sequence of sample_skill_msgs__action__SkillControl_GetResult_Request.
typedef struct sample_skill_msgs__action__SkillControl_GetResult_Request__Sequence
{
  sample_skill_msgs__action__SkillControl_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sample_skill_msgs__action__SkillControl_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__struct.h"

/// Struct defined in action/SkillControl in the package sample_skill_msgs.
typedef struct sample_skill_msgs__action__SkillControl_GetResult_Response
{
  int8_t status;
  sample_skill_msgs__action__SkillControl_Result result;
} sample_skill_msgs__action__SkillControl_GetResult_Response;

// Struct for a sequence of sample_skill_msgs__action__SkillControl_GetResult_Response.
typedef struct sample_skill_msgs__action__SkillControl_GetResult_Response__Sequence
{
  sample_skill_msgs__action__SkillControl_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sample_skill_msgs__action__SkillControl_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__struct.h"

/// Struct defined in action/SkillControl in the package sample_skill_msgs.
typedef struct sample_skill_msgs__action__SkillControl_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  sample_skill_msgs__action__SkillControl_Feedback feedback;
} sample_skill_msgs__action__SkillControl_FeedbackMessage;

// Struct for a sequence of sample_skill_msgs__action__SkillControl_FeedbackMessage.
typedef struct sample_skill_msgs__action__SkillControl_FeedbackMessage__Sequence
{
  sample_skill_msgs__action__SkillControl_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sample_skill_msgs__action__SkillControl_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SAMPLE_SKILL_MSGS__ACTION__DETAIL__SKILL_CONTROL__STRUCT_H_

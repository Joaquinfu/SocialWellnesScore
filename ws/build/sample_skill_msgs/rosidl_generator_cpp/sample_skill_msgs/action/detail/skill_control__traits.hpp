// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sample_skill_msgs:action/SkillControl.idl
// generated code does not contain a copyright notice

#ifndef SAMPLE_SKILL_MSGS__ACTION__DETAIL__SKILL_CONTROL__TRAITS_HPP_
#define SAMPLE_SKILL_MSGS__ACTION__DETAIL__SKILL_CONTROL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sample_skill_msgs/action/detail/skill_control__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'meta'
#include "std_skills/msg/detail/meta__traits.hpp"

namespace sample_skill_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SkillControl_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: meta
  {
    out << "meta: ";
    to_flow_style_yaml(msg.meta, out);
    out << ", ";
  }

  // member: skill_data
  {
    out << "skill_data: ";
    rosidl_generator_traits::value_to_yaml(msg.skill_data, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SkillControl_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: meta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "meta:\n";
    to_block_style_yaml(msg.meta, out, indentation + 2);
  }

  // member: skill_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "skill_data: ";
    rosidl_generator_traits::value_to_yaml(msg.skill_data, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SkillControl_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace sample_skill_msgs

namespace rosidl_generator_traits
{

[[deprecated("use sample_skill_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sample_skill_msgs::action::SkillControl_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  sample_skill_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sample_skill_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const sample_skill_msgs::action::SkillControl_Goal & msg)
{
  return sample_skill_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<sample_skill_msgs::action::SkillControl_Goal>()
{
  return "sample_skill_msgs::action::SkillControl_Goal";
}

template<>
inline const char * name<sample_skill_msgs::action::SkillControl_Goal>()
{
  return "sample_skill_msgs/action/SkillControl_Goal";
}

template<>
struct has_fixed_size<sample_skill_msgs::action::SkillControl_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sample_skill_msgs::action::SkillControl_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<sample_skill_msgs::action::SkillControl_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
#include "std_skills/msg/detail/result__traits.hpp"

namespace sample_skill_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SkillControl_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
    out << ", ";
  }

  // member: value
  {
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SkillControl_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }

  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SkillControl_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace sample_skill_msgs

namespace rosidl_generator_traits
{

[[deprecated("use sample_skill_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sample_skill_msgs::action::SkillControl_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  sample_skill_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sample_skill_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const sample_skill_msgs::action::SkillControl_Result & msg)
{
  return sample_skill_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<sample_skill_msgs::action::SkillControl_Result>()
{
  return "sample_skill_msgs::action::SkillControl_Result";
}

template<>
inline const char * name<sample_skill_msgs::action::SkillControl_Result>()
{
  return "sample_skill_msgs/action/SkillControl_Result";
}

template<>
struct has_fixed_size<sample_skill_msgs::action::SkillControl_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sample_skill_msgs::action::SkillControl_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<sample_skill_msgs::action::SkillControl_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'feedback'
#include "std_skills/msg/detail/feedback__traits.hpp"

namespace sample_skill_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SkillControl_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SkillControl_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SkillControl_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace sample_skill_msgs

namespace rosidl_generator_traits
{

[[deprecated("use sample_skill_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sample_skill_msgs::action::SkillControl_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  sample_skill_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sample_skill_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const sample_skill_msgs::action::SkillControl_Feedback & msg)
{
  return sample_skill_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<sample_skill_msgs::action::SkillControl_Feedback>()
{
  return "sample_skill_msgs::action::SkillControl_Feedback";
}

template<>
inline const char * name<sample_skill_msgs::action::SkillControl_Feedback>()
{
  return "sample_skill_msgs/action/SkillControl_Feedback";
}

template<>
struct has_fixed_size<sample_skill_msgs::action::SkillControl_Feedback>
  : std::integral_constant<bool, has_fixed_size<std_skills::msg::Feedback>::value> {};

template<>
struct has_bounded_size<sample_skill_msgs::action::SkillControl_Feedback>
  : std::integral_constant<bool, has_bounded_size<std_skills::msg::Feedback>::value> {};

template<>
struct is_message<sample_skill_msgs::action::SkillControl_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "sample_skill_msgs/action/detail/skill_control__traits.hpp"

namespace sample_skill_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SkillControl_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SkillControl_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SkillControl_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace sample_skill_msgs

namespace rosidl_generator_traits
{

[[deprecated("use sample_skill_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sample_skill_msgs::action::SkillControl_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  sample_skill_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sample_skill_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const sample_skill_msgs::action::SkillControl_SendGoal_Request & msg)
{
  return sample_skill_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<sample_skill_msgs::action::SkillControl_SendGoal_Request>()
{
  return "sample_skill_msgs::action::SkillControl_SendGoal_Request";
}

template<>
inline const char * name<sample_skill_msgs::action::SkillControl_SendGoal_Request>()
{
  return "sample_skill_msgs/action/SkillControl_SendGoal_Request";
}

template<>
struct has_fixed_size<sample_skill_msgs::action::SkillControl_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<sample_skill_msgs::action::SkillControl_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<sample_skill_msgs::action::SkillControl_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<sample_skill_msgs::action::SkillControl_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<sample_skill_msgs::action::SkillControl_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace sample_skill_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SkillControl_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SkillControl_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SkillControl_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace sample_skill_msgs

namespace rosidl_generator_traits
{

[[deprecated("use sample_skill_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sample_skill_msgs::action::SkillControl_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  sample_skill_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sample_skill_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const sample_skill_msgs::action::SkillControl_SendGoal_Response & msg)
{
  return sample_skill_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<sample_skill_msgs::action::SkillControl_SendGoal_Response>()
{
  return "sample_skill_msgs::action::SkillControl_SendGoal_Response";
}

template<>
inline const char * name<sample_skill_msgs::action::SkillControl_SendGoal_Response>()
{
  return "sample_skill_msgs/action/SkillControl_SendGoal_Response";
}

template<>
struct has_fixed_size<sample_skill_msgs::action::SkillControl_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<sample_skill_msgs::action::SkillControl_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<sample_skill_msgs::action::SkillControl_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<sample_skill_msgs::action::SkillControl_SendGoal>()
{
  return "sample_skill_msgs::action::SkillControl_SendGoal";
}

template<>
inline const char * name<sample_skill_msgs::action::SkillControl_SendGoal>()
{
  return "sample_skill_msgs/action/SkillControl_SendGoal";
}

template<>
struct has_fixed_size<sample_skill_msgs::action::SkillControl_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<sample_skill_msgs::action::SkillControl_SendGoal_Request>::value &&
    has_fixed_size<sample_skill_msgs::action::SkillControl_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<sample_skill_msgs::action::SkillControl_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<sample_skill_msgs::action::SkillControl_SendGoal_Request>::value &&
    has_bounded_size<sample_skill_msgs::action::SkillControl_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<sample_skill_msgs::action::SkillControl_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<sample_skill_msgs::action::SkillControl_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<sample_skill_msgs::action::SkillControl_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace sample_skill_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SkillControl_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SkillControl_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SkillControl_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace sample_skill_msgs

namespace rosidl_generator_traits
{

[[deprecated("use sample_skill_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sample_skill_msgs::action::SkillControl_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  sample_skill_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sample_skill_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const sample_skill_msgs::action::SkillControl_GetResult_Request & msg)
{
  return sample_skill_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<sample_skill_msgs::action::SkillControl_GetResult_Request>()
{
  return "sample_skill_msgs::action::SkillControl_GetResult_Request";
}

template<>
inline const char * name<sample_skill_msgs::action::SkillControl_GetResult_Request>()
{
  return "sample_skill_msgs/action/SkillControl_GetResult_Request";
}

template<>
struct has_fixed_size<sample_skill_msgs::action::SkillControl_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<sample_skill_msgs::action::SkillControl_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<sample_skill_msgs::action::SkillControl_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__traits.hpp"

namespace sample_skill_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SkillControl_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SkillControl_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SkillControl_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace sample_skill_msgs

namespace rosidl_generator_traits
{

[[deprecated("use sample_skill_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sample_skill_msgs::action::SkillControl_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  sample_skill_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sample_skill_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const sample_skill_msgs::action::SkillControl_GetResult_Response & msg)
{
  return sample_skill_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<sample_skill_msgs::action::SkillControl_GetResult_Response>()
{
  return "sample_skill_msgs::action::SkillControl_GetResult_Response";
}

template<>
inline const char * name<sample_skill_msgs::action::SkillControl_GetResult_Response>()
{
  return "sample_skill_msgs/action/SkillControl_GetResult_Response";
}

template<>
struct has_fixed_size<sample_skill_msgs::action::SkillControl_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<sample_skill_msgs::action::SkillControl_Result>::value> {};

template<>
struct has_bounded_size<sample_skill_msgs::action::SkillControl_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<sample_skill_msgs::action::SkillControl_Result>::value> {};

template<>
struct is_message<sample_skill_msgs::action::SkillControl_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<sample_skill_msgs::action::SkillControl_GetResult>()
{
  return "sample_skill_msgs::action::SkillControl_GetResult";
}

template<>
inline const char * name<sample_skill_msgs::action::SkillControl_GetResult>()
{
  return "sample_skill_msgs/action/SkillControl_GetResult";
}

template<>
struct has_fixed_size<sample_skill_msgs::action::SkillControl_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<sample_skill_msgs::action::SkillControl_GetResult_Request>::value &&
    has_fixed_size<sample_skill_msgs::action::SkillControl_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<sample_skill_msgs::action::SkillControl_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<sample_skill_msgs::action::SkillControl_GetResult_Request>::value &&
    has_bounded_size<sample_skill_msgs::action::SkillControl_GetResult_Response>::value
  >
{
};

template<>
struct is_service<sample_skill_msgs::action::SkillControl_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<sample_skill_msgs::action::SkillControl_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<sample_skill_msgs::action::SkillControl_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "sample_skill_msgs/action/detail/skill_control__traits.hpp"

namespace sample_skill_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SkillControl_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SkillControl_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SkillControl_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace sample_skill_msgs

namespace rosidl_generator_traits
{

[[deprecated("use sample_skill_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sample_skill_msgs::action::SkillControl_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  sample_skill_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sample_skill_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const sample_skill_msgs::action::SkillControl_FeedbackMessage & msg)
{
  return sample_skill_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<sample_skill_msgs::action::SkillControl_FeedbackMessage>()
{
  return "sample_skill_msgs::action::SkillControl_FeedbackMessage";
}

template<>
inline const char * name<sample_skill_msgs::action::SkillControl_FeedbackMessage>()
{
  return "sample_skill_msgs/action/SkillControl_FeedbackMessage";
}

template<>
struct has_fixed_size<sample_skill_msgs::action::SkillControl_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<sample_skill_msgs::action::SkillControl_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<sample_skill_msgs::action::SkillControl_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<sample_skill_msgs::action::SkillControl_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<sample_skill_msgs::action::SkillControl_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<sample_skill_msgs::action::SkillControl>
  : std::true_type
{
};

template<>
struct is_action_goal<sample_skill_msgs::action::SkillControl_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<sample_skill_msgs::action::SkillControl_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<sample_skill_msgs::action::SkillControl_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // SAMPLE_SKILL_MSGS__ACTION__DETAIL__SKILL_CONTROL__TRAITS_HPP_

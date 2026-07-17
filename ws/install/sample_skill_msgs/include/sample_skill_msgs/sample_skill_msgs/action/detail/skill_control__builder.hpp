// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sample_skill_msgs:action/SkillControl.idl
// generated code does not contain a copyright notice

#ifndef SAMPLE_SKILL_MSGS__ACTION__DETAIL__SKILL_CONTROL__BUILDER_HPP_
#define SAMPLE_SKILL_MSGS__ACTION__DETAIL__SKILL_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sample_skill_msgs/action/detail/skill_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sample_skill_msgs
{

namespace action
{

namespace builder
{

class Init_SkillControl_Goal_skill_data
{
public:
  explicit Init_SkillControl_Goal_skill_data(::sample_skill_msgs::action::SkillControl_Goal & msg)
  : msg_(msg)
  {}
  ::sample_skill_msgs::action::SkillControl_Goal skill_data(::sample_skill_msgs::action::SkillControl_Goal::_skill_data_type arg)
  {
    msg_.skill_data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sample_skill_msgs::action::SkillControl_Goal msg_;
};

class Init_SkillControl_Goal_meta
{
public:
  Init_SkillControl_Goal_meta()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SkillControl_Goal_skill_data meta(::sample_skill_msgs::action::SkillControl_Goal::_meta_type arg)
  {
    msg_.meta = std::move(arg);
    return Init_SkillControl_Goal_skill_data(msg_);
  }

private:
  ::sample_skill_msgs::action::SkillControl_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::sample_skill_msgs::action::SkillControl_Goal>()
{
  return sample_skill_msgs::action::builder::Init_SkillControl_Goal_meta();
}

}  // namespace sample_skill_msgs


namespace sample_skill_msgs
{

namespace action
{

namespace builder
{

class Init_SkillControl_Result_value
{
public:
  explicit Init_SkillControl_Result_value(::sample_skill_msgs::action::SkillControl_Result & msg)
  : msg_(msg)
  {}
  ::sample_skill_msgs::action::SkillControl_Result value(::sample_skill_msgs::action::SkillControl_Result::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sample_skill_msgs::action::SkillControl_Result msg_;
};

class Init_SkillControl_Result_result
{
public:
  Init_SkillControl_Result_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SkillControl_Result_value result(::sample_skill_msgs::action::SkillControl_Result::_result_type arg)
  {
    msg_.result = std::move(arg);
    return Init_SkillControl_Result_value(msg_);
  }

private:
  ::sample_skill_msgs::action::SkillControl_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::sample_skill_msgs::action::SkillControl_Result>()
{
  return sample_skill_msgs::action::builder::Init_SkillControl_Result_result();
}

}  // namespace sample_skill_msgs


namespace sample_skill_msgs
{

namespace action
{

namespace builder
{

class Init_SkillControl_Feedback_feedback
{
public:
  Init_SkillControl_Feedback_feedback()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::sample_skill_msgs::action::SkillControl_Feedback feedback(::sample_skill_msgs::action::SkillControl_Feedback::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sample_skill_msgs::action::SkillControl_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::sample_skill_msgs::action::SkillControl_Feedback>()
{
  return sample_skill_msgs::action::builder::Init_SkillControl_Feedback_feedback();
}

}  // namespace sample_skill_msgs


namespace sample_skill_msgs
{

namespace action
{

namespace builder
{

class Init_SkillControl_SendGoal_Request_goal
{
public:
  explicit Init_SkillControl_SendGoal_Request_goal(::sample_skill_msgs::action::SkillControl_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::sample_skill_msgs::action::SkillControl_SendGoal_Request goal(::sample_skill_msgs::action::SkillControl_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sample_skill_msgs::action::SkillControl_SendGoal_Request msg_;
};

class Init_SkillControl_SendGoal_Request_goal_id
{
public:
  Init_SkillControl_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SkillControl_SendGoal_Request_goal goal_id(::sample_skill_msgs::action::SkillControl_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_SkillControl_SendGoal_Request_goal(msg_);
  }

private:
  ::sample_skill_msgs::action::SkillControl_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::sample_skill_msgs::action::SkillControl_SendGoal_Request>()
{
  return sample_skill_msgs::action::builder::Init_SkillControl_SendGoal_Request_goal_id();
}

}  // namespace sample_skill_msgs


namespace sample_skill_msgs
{

namespace action
{

namespace builder
{

class Init_SkillControl_SendGoal_Response_stamp
{
public:
  explicit Init_SkillControl_SendGoal_Response_stamp(::sample_skill_msgs::action::SkillControl_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::sample_skill_msgs::action::SkillControl_SendGoal_Response stamp(::sample_skill_msgs::action::SkillControl_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sample_skill_msgs::action::SkillControl_SendGoal_Response msg_;
};

class Init_SkillControl_SendGoal_Response_accepted
{
public:
  Init_SkillControl_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SkillControl_SendGoal_Response_stamp accepted(::sample_skill_msgs::action::SkillControl_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_SkillControl_SendGoal_Response_stamp(msg_);
  }

private:
  ::sample_skill_msgs::action::SkillControl_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::sample_skill_msgs::action::SkillControl_SendGoal_Response>()
{
  return sample_skill_msgs::action::builder::Init_SkillControl_SendGoal_Response_accepted();
}

}  // namespace sample_skill_msgs


namespace sample_skill_msgs
{

namespace action
{

namespace builder
{

class Init_SkillControl_GetResult_Request_goal_id
{
public:
  Init_SkillControl_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::sample_skill_msgs::action::SkillControl_GetResult_Request goal_id(::sample_skill_msgs::action::SkillControl_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sample_skill_msgs::action::SkillControl_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::sample_skill_msgs::action::SkillControl_GetResult_Request>()
{
  return sample_skill_msgs::action::builder::Init_SkillControl_GetResult_Request_goal_id();
}

}  // namespace sample_skill_msgs


namespace sample_skill_msgs
{

namespace action
{

namespace builder
{

class Init_SkillControl_GetResult_Response_result
{
public:
  explicit Init_SkillControl_GetResult_Response_result(::sample_skill_msgs::action::SkillControl_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::sample_skill_msgs::action::SkillControl_GetResult_Response result(::sample_skill_msgs::action::SkillControl_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sample_skill_msgs::action::SkillControl_GetResult_Response msg_;
};

class Init_SkillControl_GetResult_Response_status
{
public:
  Init_SkillControl_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SkillControl_GetResult_Response_result status(::sample_skill_msgs::action::SkillControl_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_SkillControl_GetResult_Response_result(msg_);
  }

private:
  ::sample_skill_msgs::action::SkillControl_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::sample_skill_msgs::action::SkillControl_GetResult_Response>()
{
  return sample_skill_msgs::action::builder::Init_SkillControl_GetResult_Response_status();
}

}  // namespace sample_skill_msgs


namespace sample_skill_msgs
{

namespace action
{

namespace builder
{

class Init_SkillControl_FeedbackMessage_feedback
{
public:
  explicit Init_SkillControl_FeedbackMessage_feedback(::sample_skill_msgs::action::SkillControl_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::sample_skill_msgs::action::SkillControl_FeedbackMessage feedback(::sample_skill_msgs::action::SkillControl_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sample_skill_msgs::action::SkillControl_FeedbackMessage msg_;
};

class Init_SkillControl_FeedbackMessage_goal_id
{
public:
  Init_SkillControl_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SkillControl_FeedbackMessage_feedback goal_id(::sample_skill_msgs::action::SkillControl_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_SkillControl_FeedbackMessage_feedback(msg_);
  }

private:
  ::sample_skill_msgs::action::SkillControl_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::sample_skill_msgs::action::SkillControl_FeedbackMessage>()
{
  return sample_skill_msgs::action::builder::Init_SkillControl_FeedbackMessage_goal_id();
}

}  // namespace sample_skill_msgs

#endif  // SAMPLE_SKILL_MSGS__ACTION__DETAIL__SKILL_CONTROL__BUILDER_HPP_

# generated from rosidl_generator_py/resource/_idl.py.em
# with input from sample_skill_msgs:action/SkillControl.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SkillControl_Goal(type):
    """Metaclass of message 'SkillControl_Goal'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('sample_skill_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'sample_skill_msgs.action.SkillControl_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__skill_control__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__skill_control__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__skill_control__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__skill_control__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__skill_control__goal

            from std_skills.msg import Meta
            if Meta.__class__._TYPE_SUPPORT is None:
                Meta.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SkillControl_Goal(metaclass=Metaclass_SkillControl_Goal):
    """Message class 'SkillControl_Goal'."""

    __slots__ = [
        '_meta',
        '_skill_data',
    ]

    _fields_and_field_types = {
        'meta': 'std_skills/Meta',
        'skill_data': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_skills', 'msg'], 'Meta'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_skills.msg import Meta
        self.meta = kwargs.get('meta', Meta())
        self.skill_data = kwargs.get('skill_data', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.meta != other.meta:
            return False
        if self.skill_data != other.skill_data:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def meta(self):
        """Message field 'meta'."""
        return self._meta

    @meta.setter
    def meta(self, value):
        if __debug__:
            from std_skills.msg import Meta
            assert \
                isinstance(value, Meta), \
                "The 'meta' field must be a sub message of type 'Meta'"
        self._meta = value

    @builtins.property
    def skill_data(self):
        """Message field 'skill_data'."""
        return self._skill_data

    @skill_data.setter
    def skill_data(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'skill_data' field must be of type 'str'"
        self._skill_data = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SkillControl_Result(type):
    """Metaclass of message 'SkillControl_Result'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('sample_skill_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'sample_skill_msgs.action.SkillControl_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__skill_control__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__skill_control__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__skill_control__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__skill_control__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__skill_control__result

            from std_skills.msg import Result
            if Result.__class__._TYPE_SUPPORT is None:
                Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SkillControl_Result(metaclass=Metaclass_SkillControl_Result):
    """Message class 'SkillControl_Result'."""

    __slots__ = [
        '_result',
        '_value',
    ]

    _fields_and_field_types = {
        'result': 'std_skills/Result',
        'value': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_skills', 'msg'], 'Result'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_skills.msg import Result
        self.result = kwargs.get('result', Result())
        self.value = kwargs.get('value', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.result != other.result:
            return False
        if self.value != other.value:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            from std_skills.msg import Result
            assert \
                isinstance(value, Result), \
                "The 'result' field must be a sub message of type 'Result'"
        self._result = value

    @builtins.property
    def value(self):
        """Message field 'value'."""
        return self._value

    @value.setter
    def value(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'value' field must be of type 'str'"
        self._value = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SkillControl_Feedback(type):
    """Metaclass of message 'SkillControl_Feedback'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('sample_skill_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'sample_skill_msgs.action.SkillControl_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__skill_control__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__skill_control__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__skill_control__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__skill_control__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__skill_control__feedback

            from std_skills.msg import Feedback
            if Feedback.__class__._TYPE_SUPPORT is None:
                Feedback.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SkillControl_Feedback(metaclass=Metaclass_SkillControl_Feedback):
    """Message class 'SkillControl_Feedback'."""

    __slots__ = [
        '_feedback',
    ]

    _fields_and_field_types = {
        'feedback': 'std_skills/Feedback',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_skills', 'msg'], 'Feedback'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_skills.msg import Feedback
        self.feedback = kwargs.get('feedback', Feedback())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.feedback != other.feedback:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def feedback(self):
        """Message field 'feedback'."""
        return self._feedback

    @feedback.setter
    def feedback(self, value):
        if __debug__:
            from std_skills.msg import Feedback
            assert \
                isinstance(value, Feedback), \
                "The 'feedback' field must be a sub message of type 'Feedback'"
        self._feedback = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SkillControl_SendGoal_Request(type):
    """Metaclass of message 'SkillControl_SendGoal_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('sample_skill_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'sample_skill_msgs.action.SkillControl_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__skill_control__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__skill_control__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__skill_control__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__skill_control__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__skill_control__send_goal__request

            from sample_skill_msgs.action import SkillControl
            if SkillControl.Goal.__class__._TYPE_SUPPORT is None:
                SkillControl.Goal.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SkillControl_SendGoal_Request(metaclass=Metaclass_SkillControl_SendGoal_Request):
    """Message class 'SkillControl_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'sample_skill_msgs/SkillControl_Goal',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sample_skill_msgs', 'action'], 'SkillControl_Goal'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from sample_skill_msgs.action._skill_control import SkillControl_Goal
        self.goal = kwargs.get('goal', SkillControl_Goal())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        if self.goal != other.goal:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if __debug__:
            from sample_skill_msgs.action._skill_control import SkillControl_Goal
            assert \
                isinstance(value, SkillControl_Goal), \
                "The 'goal' field must be a sub message of type 'SkillControl_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SkillControl_SendGoal_Response(type):
    """Metaclass of message 'SkillControl_SendGoal_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('sample_skill_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'sample_skill_msgs.action.SkillControl_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__skill_control__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__skill_control__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__skill_control__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__skill_control__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__skill_control__send_goal__response

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SkillControl_SendGoal_Response(metaclass=Metaclass_SkillControl_SendGoal_Response):
    """Message class 'SkillControl_SendGoal_Response'."""

    __slots__ = [
        '_accepted',
        '_stamp',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'stamp': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.accepted != other.accepted:
            return False
        if self.stamp != other.stamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

    @builtins.property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value


class Metaclass_SkillControl_SendGoal(type):
    """Metaclass of service 'SkillControl_SendGoal'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('sample_skill_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'sample_skill_msgs.action.SkillControl_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__skill_control__send_goal

            from sample_skill_msgs.action import _skill_control
            if _skill_control.Metaclass_SkillControl_SendGoal_Request._TYPE_SUPPORT is None:
                _skill_control.Metaclass_SkillControl_SendGoal_Request.__import_type_support__()
            if _skill_control.Metaclass_SkillControl_SendGoal_Response._TYPE_SUPPORT is None:
                _skill_control.Metaclass_SkillControl_SendGoal_Response.__import_type_support__()


class SkillControl_SendGoal(metaclass=Metaclass_SkillControl_SendGoal):
    from sample_skill_msgs.action._skill_control import SkillControl_SendGoal_Request as Request
    from sample_skill_msgs.action._skill_control import SkillControl_SendGoal_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SkillControl_GetResult_Request(type):
    """Metaclass of message 'SkillControl_GetResult_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('sample_skill_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'sample_skill_msgs.action.SkillControl_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__skill_control__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__skill_control__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__skill_control__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__skill_control__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__skill_control__get_result__request

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SkillControl_GetResult_Request(metaclass=Metaclass_SkillControl_GetResult_Request):
    """Message class 'SkillControl_GetResult_Request'."""

    __slots__ = [
        '_goal_id',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SkillControl_GetResult_Response(type):
    """Metaclass of message 'SkillControl_GetResult_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('sample_skill_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'sample_skill_msgs.action.SkillControl_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__skill_control__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__skill_control__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__skill_control__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__skill_control__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__skill_control__get_result__response

            from sample_skill_msgs.action import SkillControl
            if SkillControl.Result.__class__._TYPE_SUPPORT is None:
                SkillControl.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SkillControl_GetResult_Response(metaclass=Metaclass_SkillControl_GetResult_Response):
    """Message class 'SkillControl_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'sample_skill_msgs/SkillControl_Result',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sample_skill_msgs', 'action'], 'SkillControl_Result'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        from sample_skill_msgs.action._skill_control import SkillControl_Result
        self.result = kwargs.get('result', SkillControl_Result())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.status != other.status:
            return False
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'status' field must be an integer in [-128, 127]"
        self._status = value

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            from sample_skill_msgs.action._skill_control import SkillControl_Result
            assert \
                isinstance(value, SkillControl_Result), \
                "The 'result' field must be a sub message of type 'SkillControl_Result'"
        self._result = value


class Metaclass_SkillControl_GetResult(type):
    """Metaclass of service 'SkillControl_GetResult'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('sample_skill_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'sample_skill_msgs.action.SkillControl_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__skill_control__get_result

            from sample_skill_msgs.action import _skill_control
            if _skill_control.Metaclass_SkillControl_GetResult_Request._TYPE_SUPPORT is None:
                _skill_control.Metaclass_SkillControl_GetResult_Request.__import_type_support__()
            if _skill_control.Metaclass_SkillControl_GetResult_Response._TYPE_SUPPORT is None:
                _skill_control.Metaclass_SkillControl_GetResult_Response.__import_type_support__()


class SkillControl_GetResult(metaclass=Metaclass_SkillControl_GetResult):
    from sample_skill_msgs.action._skill_control import SkillControl_GetResult_Request as Request
    from sample_skill_msgs.action._skill_control import SkillControl_GetResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SkillControl_FeedbackMessage(type):
    """Metaclass of message 'SkillControl_FeedbackMessage'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('sample_skill_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'sample_skill_msgs.action.SkillControl_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__skill_control__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__skill_control__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__skill_control__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__skill_control__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__skill_control__feedback_message

            from sample_skill_msgs.action import SkillControl
            if SkillControl.Feedback.__class__._TYPE_SUPPORT is None:
                SkillControl.Feedback.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SkillControl_FeedbackMessage(metaclass=Metaclass_SkillControl_FeedbackMessage):
    """Message class 'SkillControl_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'sample_skill_msgs/SkillControl_Feedback',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sample_skill_msgs', 'action'], 'SkillControl_Feedback'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from sample_skill_msgs.action._skill_control import SkillControl_Feedback
        self.feedback = kwargs.get('feedback', SkillControl_Feedback())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        if self.feedback != other.feedback:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def feedback(self):
        """Message field 'feedback'."""
        return self._feedback

    @feedback.setter
    def feedback(self, value):
        if __debug__:
            from sample_skill_msgs.action._skill_control import SkillControl_Feedback
            assert \
                isinstance(value, SkillControl_Feedback), \
                "The 'feedback' field must be a sub message of type 'SkillControl_Feedback'"
        self._feedback = value


class Metaclass_SkillControl(type):
    """Metaclass of action 'SkillControl'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('sample_skill_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'sample_skill_msgs.action.SkillControl')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__skill_control

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from sample_skill_msgs.action import _skill_control
            if _skill_control.Metaclass_SkillControl_SendGoal._TYPE_SUPPORT is None:
                _skill_control.Metaclass_SkillControl_SendGoal.__import_type_support__()
            if _skill_control.Metaclass_SkillControl_GetResult._TYPE_SUPPORT is None:
                _skill_control.Metaclass_SkillControl_GetResult.__import_type_support__()
            if _skill_control.Metaclass_SkillControl_FeedbackMessage._TYPE_SUPPORT is None:
                _skill_control.Metaclass_SkillControl_FeedbackMessage.__import_type_support__()


class SkillControl(metaclass=Metaclass_SkillControl):

    # The goal message defined in the action definition.
    from sample_skill_msgs.action._skill_control import SkillControl_Goal as Goal
    # The result message defined in the action definition.
    from sample_skill_msgs.action._skill_control import SkillControl_Result as Result
    # The feedback message defined in the action definition.
    from sample_skill_msgs.action._skill_control import SkillControl_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from sample_skill_msgs.action._skill_control import SkillControl_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from sample_skill_msgs.action._skill_control import SkillControl_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from sample_skill_msgs.action._skill_control import SkillControl_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')

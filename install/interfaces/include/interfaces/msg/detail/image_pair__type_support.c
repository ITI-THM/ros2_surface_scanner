// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from interfaces:msg/ImagePair.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "interfaces/msg/detail/image_pair__rosidl_typesupport_introspection_c.h"
#include "interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "interfaces/msg/detail/image_pair__functions.h"
#include "interfaces/msg/detail/image_pair__struct.h"


// Include directives for member types
// Member `origin_img`
// Member `laser_img`
#include "sensor_msgs/msg/image.h"
// Member `origin_img`
// Member `laser_img`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ImagePair__rosidl_typesupport_introspection_c__ImagePair_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  interfaces__msg__ImagePair__init(message_memory);
}

void ImagePair__rosidl_typesupport_introspection_c__ImagePair_fini_function(void * message_memory)
{
  interfaces__msg__ImagePair__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ImagePair__rosidl_typesupport_introspection_c__ImagePair_message_member_array[2] = {
  {
    "origin_img",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interfaces__msg__ImagePair, origin_img),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "laser_img",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interfaces__msg__ImagePair, laser_img),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ImagePair__rosidl_typesupport_introspection_c__ImagePair_message_members = {
  "interfaces__msg",  // message namespace
  "ImagePair",  // message name
  2,  // number of fields
  sizeof(interfaces__msg__ImagePair),
  ImagePair__rosidl_typesupport_introspection_c__ImagePair_message_member_array,  // message members
  ImagePair__rosidl_typesupport_introspection_c__ImagePair_init_function,  // function to initialize message memory (memory has to be allocated)
  ImagePair__rosidl_typesupport_introspection_c__ImagePair_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ImagePair__rosidl_typesupport_introspection_c__ImagePair_message_type_support_handle = {
  0,
  &ImagePair__rosidl_typesupport_introspection_c__ImagePair_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces, msg, ImagePair)() {
  ImagePair__rosidl_typesupport_introspection_c__ImagePair_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  ImagePair__rosidl_typesupport_introspection_c__ImagePair_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  if (!ImagePair__rosidl_typesupport_introspection_c__ImagePair_message_type_support_handle.typesupport_identifier) {
    ImagePair__rosidl_typesupport_introspection_c__ImagePair_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ImagePair__rosidl_typesupport_introspection_c__ImagePair_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

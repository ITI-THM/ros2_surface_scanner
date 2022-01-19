// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from interfaces:msg/CameraCalibrationImgs.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "interfaces/msg/detail/camera_calibration_imgs__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void CameraCalibrationImgs_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) interfaces::msg::CameraCalibrationImgs(_init);
}

void CameraCalibrationImgs_fini_function(void * message_memory)
{
  auto typed_message = static_cast<interfaces::msg::CameraCalibrationImgs *>(message_memory);
  typed_message->~CameraCalibrationImgs();
}

size_t size_function__CameraCalibrationImgs__imgs(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CameraCalibrationImgs__imgs(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  return &member[index];
}

void * get_function__CameraCalibrationImgs__imgs(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  return &member[index];
}

void resize_function__CameraCalibrationImgs__imgs(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember CameraCalibrationImgs_message_member_array[1] = {
  {
    "imgs",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::Image>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interfaces::msg::CameraCalibrationImgs, imgs),  // bytes offset in struct
    nullptr,  // default value
    size_function__CameraCalibrationImgs__imgs,  // size() function pointer
    get_const_function__CameraCalibrationImgs__imgs,  // get_const(index) function pointer
    get_function__CameraCalibrationImgs__imgs,  // get(index) function pointer
    resize_function__CameraCalibrationImgs__imgs  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers CameraCalibrationImgs_message_members = {
  "interfaces::msg",  // message namespace
  "CameraCalibrationImgs",  // message name
  1,  // number of fields
  sizeof(interfaces::msg::CameraCalibrationImgs),
  CameraCalibrationImgs_message_member_array,  // message members
  CameraCalibrationImgs_init_function,  // function to initialize message memory (memory has to be allocated)
  CameraCalibrationImgs_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t CameraCalibrationImgs_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &CameraCalibrationImgs_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces::msg::CameraCalibrationImgs>()
{
  return &::interfaces::msg::rosidl_typesupport_introspection_cpp::CameraCalibrationImgs_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces, msg, CameraCalibrationImgs)() {
  return &::interfaces::msg::rosidl_typesupport_introspection_cpp::CameraCalibrationImgs_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

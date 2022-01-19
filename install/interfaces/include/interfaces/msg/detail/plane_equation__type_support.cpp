// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from interfaces:msg/PlaneEquation.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "interfaces/msg/detail/plane_equation__struct.hpp"
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

void PlaneEquation_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) interfaces::msg::PlaneEquation(_init);
}

void PlaneEquation_fini_function(void * message_memory)
{
  auto typed_message = static_cast<interfaces::msg::PlaneEquation *>(message_memory);
  typed_message->~PlaneEquation();
}

size_t size_function__PlaneEquation__plane_equation(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__PlaneEquation__plane_equation(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__PlaneEquation__plane_equation(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 4> *>(untyped_member);
  return &member[index];
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PlaneEquation_message_member_array[1] = {
  {
    "plane_equation",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(interfaces::msg::PlaneEquation, plane_equation),  // bytes offset in struct
    nullptr,  // default value
    size_function__PlaneEquation__plane_equation,  // size() function pointer
    get_const_function__PlaneEquation__plane_equation,  // get_const(index) function pointer
    get_function__PlaneEquation__plane_equation,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PlaneEquation_message_members = {
  "interfaces::msg",  // message namespace
  "PlaneEquation",  // message name
  1,  // number of fields
  sizeof(interfaces::msg::PlaneEquation),
  PlaneEquation_message_member_array,  // message members
  PlaneEquation_init_function,  // function to initialize message memory (memory has to be allocated)
  PlaneEquation_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PlaneEquation_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PlaneEquation_message_members,
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
get_message_type_support_handle<interfaces::msg::PlaneEquation>()
{
  return &::interfaces::msg::rosidl_typesupport_introspection_cpp::PlaneEquation_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces, msg, PlaneEquation)() {
  return &::interfaces::msg::rosidl_typesupport_introspection_cpp::PlaneEquation_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/PlaneEquation.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__PLANE_EQUATION__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__PLANE_EQUATION__BUILDER_HPP_

#include "interfaces/msg/detail/plane_equation__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_PlaneEquation_plane_equation
{
public:
  Init_PlaneEquation_plane_equation()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::msg::PlaneEquation plane_equation(::interfaces::msg::PlaneEquation::_plane_equation_type arg)
  {
    msg_.plane_equation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::PlaneEquation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::PlaneEquation>()
{
  return interfaces::msg::builder::Init_PlaneEquation_plane_equation();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__PLANE_EQUATION__BUILDER_HPP_

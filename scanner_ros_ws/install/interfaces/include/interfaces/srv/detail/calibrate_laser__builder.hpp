// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:srv/CalibrateLaser.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__CALIBRATE_LASER__BUILDER_HPP_
#define INTERFACES__SRV__DETAIL__CALIBRATE_LASER__BUILDER_HPP_

#include "interfaces/srv/detail/calibrate_laser__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::CalibrateLaser_Request>()
{
  return ::interfaces::srv::CalibrateLaser_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace interfaces


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_CalibrateLaser_Response_response
{
public:
  Init_CalibrateLaser_Response_response()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::CalibrateLaser_Response response(::interfaces::srv::CalibrateLaser_Response::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::CalibrateLaser_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::CalibrateLaser_Response>()
{
  return interfaces::srv::builder::Init_CalibrateLaser_Response_response();
}

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__CALIBRATE_LASER__BUILDER_HPP_

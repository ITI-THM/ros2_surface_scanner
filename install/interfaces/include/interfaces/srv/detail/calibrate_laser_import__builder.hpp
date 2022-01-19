// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:srv/CalibrateLaserImport.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__CALIBRATE_LASER_IMPORT__BUILDER_HPP_
#define INTERFACES__SRV__DETAIL__CALIBRATE_LASER_IMPORT__BUILDER_HPP_

#include "interfaces/srv/detail/calibrate_laser_import__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_CalibrateLaserImport_Request_file
{
public:
  Init_CalibrateLaserImport_Request_file()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::CalibrateLaserImport_Request file(::interfaces::srv::CalibrateLaserImport_Request::_file_type arg)
  {
    msg_.file = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::CalibrateLaserImport_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::CalibrateLaserImport_Request>()
{
  return interfaces::srv::builder::Init_CalibrateLaserImport_Request_file();
}

}  // namespace interfaces


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_CalibrateLaserImport_Response_message
{
public:
  explicit Init_CalibrateLaserImport_Response_message(::interfaces::srv::CalibrateLaserImport_Response & msg)
  : msg_(msg)
  {}
  ::interfaces::srv::CalibrateLaserImport_Response message(::interfaces::srv::CalibrateLaserImport_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::CalibrateLaserImport_Response msg_;
};

class Init_CalibrateLaserImport_Response_success
{
public:
  Init_CalibrateLaserImport_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CalibrateLaserImport_Response_message success(::interfaces::srv::CalibrateLaserImport_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_CalibrateLaserImport_Response_message(msg_);
  }

private:
  ::interfaces::srv::CalibrateLaserImport_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::CalibrateLaserImport_Response>()
{
  return interfaces::srv::builder::Init_CalibrateLaserImport_Response_success();
}

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__CALIBRATE_LASER_IMPORT__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/ScannerStatus.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__SCANNER_STATUS__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__SCANNER_STATUS__BUILDER_HPP_

#include "interfaces/msg/detail/scanner_status__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_ScannerStatus_is_scanner_active
{
public:
  Init_ScannerStatus_is_scanner_active()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::msg::ScannerStatus is_scanner_active(::interfaces::msg::ScannerStatus::_is_scanner_active_type arg)
  {
    msg_.is_scanner_active = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::ScannerStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::ScannerStatus>()
{
  return interfaces::msg::builder::Init_ScannerStatus_is_scanner_active();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__SCANNER_STATUS__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/ImagePair.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__IMAGE_PAIR__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__IMAGE_PAIR__BUILDER_HPP_

#include "interfaces/msg/detail/image_pair__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_ImagePair_laser_img
{
public:
  explicit Init_ImagePair_laser_img(::interfaces::msg::ImagePair & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::ImagePair laser_img(::interfaces::msg::ImagePair::_laser_img_type arg)
  {
    msg_.laser_img = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::ImagePair msg_;
};

class Init_ImagePair_origin_img
{
public:
  explicit Init_ImagePair_origin_img(::interfaces::msg::ImagePair & msg)
  : msg_(msg)
  {}
  Init_ImagePair_laser_img origin_img(::interfaces::msg::ImagePair::_origin_img_type arg)
  {
    msg_.origin_img = std::move(arg);
    return Init_ImagePair_laser_img(msg_);
  }

private:
  ::interfaces::msg::ImagePair msg_;
};

class Init_ImagePair_is_for_laser_calib
{
public:
  Init_ImagePair_is_for_laser_calib()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImagePair_origin_img is_for_laser_calib(::interfaces::msg::ImagePair::_is_for_laser_calib_type arg)
  {
    msg_.is_for_laser_calib = std::move(arg);
    return Init_ImagePair_origin_img(msg_);
  }

private:
  ::interfaces::msg::ImagePair msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::ImagePair>()
{
  return interfaces::msg::builder::Init_ImagePair_is_for_laser_calib();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__IMAGE_PAIR__BUILDER_HPP_

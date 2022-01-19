// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:srv/ImagePairRequest.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__IMAGE_PAIR_REQUEST__BUILDER_HPP_
#define INTERFACES__SRV__DETAIL__IMAGE_PAIR_REQUEST__BUILDER_HPP_

#include "interfaces/srv/detail/image_pair_request__struct.hpp"
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
auto build<::interfaces::srv::ImagePairRequest_Request>()
{
  return ::interfaces::srv::ImagePairRequest_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace interfaces


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_ImagePairRequest_Response_laser_img
{
public:
  explicit Init_ImagePairRequest_Response_laser_img(::interfaces::srv::ImagePairRequest_Response & msg)
  : msg_(msg)
  {}
  ::interfaces::srv::ImagePairRequest_Response laser_img(::interfaces::srv::ImagePairRequest_Response::_laser_img_type arg)
  {
    msg_.laser_img = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::ImagePairRequest_Response msg_;
};

class Init_ImagePairRequest_Response_origin_img
{
public:
  Init_ImagePairRequest_Response_origin_img()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImagePairRequest_Response_laser_img origin_img(::interfaces::srv::ImagePairRequest_Response::_origin_img_type arg)
  {
    msg_.origin_img = std::move(arg);
    return Init_ImagePairRequest_Response_laser_img(msg_);
  }

private:
  ::interfaces::srv::ImagePairRequest_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::ImagePairRequest_Response>()
{
  return interfaces::srv::builder::Init_ImagePairRequest_Response_origin_img();
}

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__IMAGE_PAIR_REQUEST__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/CameraCalibrationImgs.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__CAMERA_CALIBRATION_IMGS__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__CAMERA_CALIBRATION_IMGS__BUILDER_HPP_

#include "interfaces/msg/detail/camera_calibration_imgs__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_CameraCalibrationImgs_imgs
{
public:
  Init_CameraCalibrationImgs_imgs()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::msg::CameraCalibrationImgs imgs(::interfaces::msg::CameraCalibrationImgs::_imgs_type arg)
  {
    msg_.imgs = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::CameraCalibrationImgs msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::CameraCalibrationImgs>()
{
  return interfaces::msg::builder::Init_CameraCalibrationImgs_imgs();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__CAMERA_CALIBRATION_IMGS__BUILDER_HPP_

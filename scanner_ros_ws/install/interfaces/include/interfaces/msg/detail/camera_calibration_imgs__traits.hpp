// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:msg/CameraCalibrationImgs.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__CAMERA_CALIBRATION_IMGS__TRAITS_HPP_
#define INTERFACES__MSG__DETAIL__CAMERA_CALIBRATION_IMGS__TRAITS_HPP_

#include "interfaces/msg/detail/camera_calibration_imgs__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'imgs'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const interfaces::msg::CameraCalibrationImgs & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: imgs
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.imgs.size() == 0) {
      out << "imgs: []\n";
    } else {
      out << "imgs:\n";
      for (auto item : msg.imgs) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const interfaces::msg::CameraCalibrationImgs & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<interfaces::msg::CameraCalibrationImgs>()
{
  return "interfaces::msg::CameraCalibrationImgs";
}

template<>
inline const char * name<interfaces::msg::CameraCalibrationImgs>()
{
  return "interfaces/msg/CameraCalibrationImgs";
}

template<>
struct has_fixed_size<interfaces::msg::CameraCalibrationImgs>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interfaces::msg::CameraCalibrationImgs>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interfaces::msg::CameraCalibrationImgs>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__MSG__DETAIL__CAMERA_CALIBRATION_IMGS__TRAITS_HPP_

// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:msg/ImagePair.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__IMAGE_PAIR__TRAITS_HPP_
#define INTERFACES__MSG__DETAIL__IMAGE_PAIR__TRAITS_HPP_

#include "interfaces/msg/detail/image_pair__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'origin_img'
// Member 'laser_img'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const interfaces::msg::ImagePair & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: origin_img
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "origin_img:\n";
    to_yaml(msg.origin_img, out, indentation + 2);
  }

  // member: laser_img
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "laser_img:\n";
    to_yaml(msg.laser_img, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const interfaces::msg::ImagePair & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<interfaces::msg::ImagePair>()
{
  return "interfaces::msg::ImagePair";
}

template<>
inline const char * name<interfaces::msg::ImagePair>()
{
  return "interfaces/msg/ImagePair";
}

template<>
struct has_fixed_size<interfaces::msg::ImagePair>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::Image>::value> {};

template<>
struct has_bounded_size<interfaces::msg::ImagePair>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::Image>::value> {};

template<>
struct is_message<interfaces::msg::ImagePair>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__MSG__DETAIL__IMAGE_PAIR__TRAITS_HPP_

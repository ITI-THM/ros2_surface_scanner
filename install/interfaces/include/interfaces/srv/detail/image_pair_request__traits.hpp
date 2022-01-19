// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:srv/ImagePairRequest.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__IMAGE_PAIR_REQUEST__TRAITS_HPP_
#define INTERFACES__SRV__DETAIL__IMAGE_PAIR_REQUEST__TRAITS_HPP_

#include "interfaces/srv/detail/image_pair_request__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const interfaces::srv::ImagePairRequest_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const interfaces::srv::ImagePairRequest_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<interfaces::srv::ImagePairRequest_Request>()
{
  return "interfaces::srv::ImagePairRequest_Request";
}

template<>
inline const char * name<interfaces::srv::ImagePairRequest_Request>()
{
  return "interfaces/srv/ImagePairRequest_Request";
}

template<>
struct has_fixed_size<interfaces::srv::ImagePairRequest_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::srv::ImagePairRequest_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::srv::ImagePairRequest_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'origin_img'
// Member 'laser_img'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const interfaces::srv::ImagePairRequest_Response & msg,
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

inline std::string to_yaml(const interfaces::srv::ImagePairRequest_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<interfaces::srv::ImagePairRequest_Response>()
{
  return "interfaces::srv::ImagePairRequest_Response";
}

template<>
inline const char * name<interfaces::srv::ImagePairRequest_Response>()
{
  return "interfaces/srv/ImagePairRequest_Response";
}

template<>
struct has_fixed_size<interfaces::srv::ImagePairRequest_Response>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::Image>::value> {};

template<>
struct has_bounded_size<interfaces::srv::ImagePairRequest_Response>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::Image>::value> {};

template<>
struct is_message<interfaces::srv::ImagePairRequest_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::ImagePairRequest>()
{
  return "interfaces::srv::ImagePairRequest";
}

template<>
inline const char * name<interfaces::srv::ImagePairRequest>()
{
  return "interfaces/srv/ImagePairRequest";
}

template<>
struct has_fixed_size<interfaces::srv::ImagePairRequest>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaces::srv::ImagePairRequest_Request>::value &&
    has_fixed_size<interfaces::srv::ImagePairRequest_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaces::srv::ImagePairRequest>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaces::srv::ImagePairRequest_Request>::value &&
    has_bounded_size<interfaces::srv::ImagePairRequest_Response>::value
  >
{
};

template<>
struct is_service<interfaces::srv::ImagePairRequest>
  : std::true_type
{
};

template<>
struct is_service_request<interfaces::srv::ImagePairRequest_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaces::srv::ImagePairRequest_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__SRV__DETAIL__IMAGE_PAIR_REQUEST__TRAITS_HPP_

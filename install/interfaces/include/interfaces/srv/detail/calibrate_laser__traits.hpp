// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:srv/CalibrateLaser.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__CALIBRATE_LASER__TRAITS_HPP_
#define INTERFACES__SRV__DETAIL__CALIBRATE_LASER__TRAITS_HPP_

#include "interfaces/srv/detail/calibrate_laser__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const interfaces::srv::CalibrateLaser_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const interfaces::srv::CalibrateLaser_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<interfaces::srv::CalibrateLaser_Request>()
{
  return "interfaces::srv::CalibrateLaser_Request";
}

template<>
inline const char * name<interfaces::srv::CalibrateLaser_Request>()
{
  return "interfaces/srv/CalibrateLaser_Request";
}

template<>
struct has_fixed_size<interfaces::srv::CalibrateLaser_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::srv::CalibrateLaser_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::srv::CalibrateLaser_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

inline void to_yaml(
  const interfaces::srv::CalibrateLaser_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "response: ";
    value_to_yaml(msg.response, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const interfaces::srv::CalibrateLaser_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<interfaces::srv::CalibrateLaser_Response>()
{
  return "interfaces::srv::CalibrateLaser_Response";
}

template<>
inline const char * name<interfaces::srv::CalibrateLaser_Response>()
{
  return "interfaces/srv/CalibrateLaser_Response";
}

template<>
struct has_fixed_size<interfaces::srv::CalibrateLaser_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::srv::CalibrateLaser_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::srv::CalibrateLaser_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::CalibrateLaser>()
{
  return "interfaces::srv::CalibrateLaser";
}

template<>
inline const char * name<interfaces::srv::CalibrateLaser>()
{
  return "interfaces/srv/CalibrateLaser";
}

template<>
struct has_fixed_size<interfaces::srv::CalibrateLaser>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaces::srv::CalibrateLaser_Request>::value &&
    has_fixed_size<interfaces::srv::CalibrateLaser_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaces::srv::CalibrateLaser>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaces::srv::CalibrateLaser_Request>::value &&
    has_bounded_size<interfaces::srv::CalibrateLaser_Response>::value
  >
{
};

template<>
struct is_service<interfaces::srv::CalibrateLaser>
  : std::true_type
{
};

template<>
struct is_service_request<interfaces::srv::CalibrateLaser_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaces::srv::CalibrateLaser_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__SRV__DETAIL__CALIBRATE_LASER__TRAITS_HPP_

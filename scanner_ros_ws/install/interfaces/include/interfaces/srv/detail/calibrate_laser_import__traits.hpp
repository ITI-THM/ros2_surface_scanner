// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:srv/CalibrateLaserImport.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__CALIBRATE_LASER_IMPORT__TRAITS_HPP_
#define INTERFACES__SRV__DETAIL__CALIBRATE_LASER_IMPORT__TRAITS_HPP_

#include "interfaces/srv/detail/calibrate_laser_import__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const interfaces::srv::CalibrateLaserImport_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: file
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "file: ";
    value_to_yaml(msg.file, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const interfaces::srv::CalibrateLaserImport_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<interfaces::srv::CalibrateLaserImport_Request>()
{
  return "interfaces::srv::CalibrateLaserImport_Request";
}

template<>
inline const char * name<interfaces::srv::CalibrateLaserImport_Request>()
{
  return "interfaces/srv/CalibrateLaserImport_Request";
}

template<>
struct has_fixed_size<interfaces::srv::CalibrateLaserImport_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interfaces::srv::CalibrateLaserImport_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interfaces::srv::CalibrateLaserImport_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

inline void to_yaml(
  const interfaces::srv::CalibrateLaserImport_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const interfaces::srv::CalibrateLaserImport_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<interfaces::srv::CalibrateLaserImport_Response>()
{
  return "interfaces::srv::CalibrateLaserImport_Response";
}

template<>
inline const char * name<interfaces::srv::CalibrateLaserImport_Response>()
{
  return "interfaces/srv/CalibrateLaserImport_Response";
}

template<>
struct has_fixed_size<interfaces::srv::CalibrateLaserImport_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interfaces::srv::CalibrateLaserImport_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interfaces::srv::CalibrateLaserImport_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::CalibrateLaserImport>()
{
  return "interfaces::srv::CalibrateLaserImport";
}

template<>
inline const char * name<interfaces::srv::CalibrateLaserImport>()
{
  return "interfaces/srv/CalibrateLaserImport";
}

template<>
struct has_fixed_size<interfaces::srv::CalibrateLaserImport>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaces::srv::CalibrateLaserImport_Request>::value &&
    has_fixed_size<interfaces::srv::CalibrateLaserImport_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaces::srv::CalibrateLaserImport>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaces::srv::CalibrateLaserImport_Request>::value &&
    has_bounded_size<interfaces::srv::CalibrateLaserImport_Response>::value
  >
{
};

template<>
struct is_service<interfaces::srv::CalibrateLaserImport>
  : std::true_type
{
};

template<>
struct is_service_request<interfaces::srv::CalibrateLaserImport_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaces::srv::CalibrateLaserImport_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__SRV__DETAIL__CALIBRATE_LASER_IMPORT__TRAITS_HPP_

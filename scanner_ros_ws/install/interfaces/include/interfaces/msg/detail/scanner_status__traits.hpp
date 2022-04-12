// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:msg/ScannerStatus.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__SCANNER_STATUS__TRAITS_HPP_
#define INTERFACES__MSG__DETAIL__SCANNER_STATUS__TRAITS_HPP_

#include "interfaces/msg/detail/scanner_status__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const interfaces::msg::ScannerStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: is_scanner_active
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_scanner_active: ";
    value_to_yaml(msg.is_scanner_active, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const interfaces::msg::ScannerStatus & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<interfaces::msg::ScannerStatus>()
{
  return "interfaces::msg::ScannerStatus";
}

template<>
inline const char * name<interfaces::msg::ScannerStatus>()
{
  return "interfaces/msg/ScannerStatus";
}

template<>
struct has_fixed_size<interfaces::msg::ScannerStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::msg::ScannerStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::msg::ScannerStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__MSG__DETAIL__SCANNER_STATUS__TRAITS_HPP_

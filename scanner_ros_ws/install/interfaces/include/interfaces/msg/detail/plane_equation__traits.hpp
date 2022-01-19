// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:msg/PlaneEquation.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__PLANE_EQUATION__TRAITS_HPP_
#define INTERFACES__MSG__DETAIL__PLANE_EQUATION__TRAITS_HPP_

#include "interfaces/msg/detail/plane_equation__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const interfaces::msg::PlaneEquation & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: plane_equation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.plane_equation.size() == 0) {
      out << "plane_equation: []\n";
    } else {
      out << "plane_equation:\n";
      for (auto item : msg.plane_equation) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const interfaces::msg::PlaneEquation & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<interfaces::msg::PlaneEquation>()
{
  return "interfaces::msg::PlaneEquation";
}

template<>
inline const char * name<interfaces::msg::PlaneEquation>()
{
  return "interfaces/msg/PlaneEquation";
}

template<>
struct has_fixed_size<interfaces::msg::PlaneEquation>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::msg::PlaneEquation>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::msg::PlaneEquation>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__MSG__DETAIL__PLANE_EQUATION__TRAITS_HPP_

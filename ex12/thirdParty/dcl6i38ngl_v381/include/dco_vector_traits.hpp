/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#pragma once

namespace std {
template <class FLOAT_T, size_t VECTOR_SIZE>
struct numeric_limits<dco::vector_ns::vector_t<FLOAT_T, VECTOR_SIZE>> : std::numeric_limits<FLOAT_T> {
  static const bool is_specialized = true;
};
} // namespace std

namespace dco {
namespace vector_ns {
namespace traits {

template <class T> struct default_type_info {
  static const bool is_active_type = false;
  typedef T plain_t;
  static const bool is_arithmetic = std::is_arithmetic<plain_t>::value;
  static const bool is_floating_point = std::is_floating_point<plain_t>::value;
  static const bool vector_level = 0;
};

template <class T> struct type_info : default_type_info<T> {};
template <class T> struct type_info<T&> : type_info<T> {};
template <class T> struct type_info<T&&> : type_info<T> {};
template <class T> struct type_info<T const> : type_info<T> {};
template <class T> struct type_info<T const&> : type_info<T> {};

template <class AUGMENT1_T, class AUGMENT2_T> struct binary_augment_selector_t {
  static const bool is_valid = std::is_same<AUGMENT1_T, AUGMENT2_T>::value;
  typedef AUGMENT1_T return_augment_t;
};

template <class FLOAT_T, size_t VECTOR_SIZE>
struct default_vector_info : default_type_info<::dco::vector_ns::vector_t<FLOAT_T, VECTOR_SIZE>> {
  static const bool is_vector = true;
  typedef FLOAT_T vector_scalar_t;
  static const size_t vector_level = type_info<FLOAT_T>::vector_level + 1;
  static const size_t vector_size = VECTOR_SIZE;
  static const bool is_arithmetic = true;
};

template <size_t VECTOR_SIZE, class FLOAT_T>
struct type_info<::dco::vector_ns::vector_t<FLOAT_T, VECTOR_SIZE>> : default_vector_info<FLOAT_T, VECTOR_SIZE> {};
template <size_t VECTOR_SIZE, class FLOAT_T>
struct type_info<::dco::vector_ns::vector_t<FLOAT_T, VECTOR_SIZE>&> : default_vector_info<FLOAT_T, VECTOR_SIZE> {};
template <size_t VECTOR_SIZE, class FLOAT_T>
struct type_info<const ::dco::vector_ns::vector_t<FLOAT_T, VECTOR_SIZE>> : default_vector_info<FLOAT_T, VECTOR_SIZE> {};
template <size_t VECTOR_SIZE, class FLOAT_T>
struct type_info<const ::dco::vector_ns::vector_t<FLOAT_T, VECTOR_SIZE>&> : default_vector_info<FLOAT_T, VECTOR_SIZE> {
};

template <class T> struct passive_type_info : default_type_info<T> {
  static const bool is_vector = false;
  static const size_t vector_level = 0;
  static const size_t vector_size = 0;
  static const bool is_dco_passive = true;
};

#define DCO_DECLARE_VECTOR_PASSIVE_TYPE(TYPE)                                                                          \
  template <> struct type_info<TYPE> : passive_type_info<TYPE> {};                                                     \
  template <> struct type_info<const TYPE> : passive_type_info<TYPE> {};                                               \
  template <> struct type_info<TYPE&> : passive_type_info<TYPE> {};                                                    \
  template <> struct type_info<const TYPE&> : passive_type_info<TYPE> {};                                              \
  template <> struct type_info<TYPE&&> : passive_type_info<TYPE> {};                                                   \
  template <> struct type_info<const TYPE&&> : passive_type_info<TYPE> {};

DCO_DECLARE_VECTOR_PASSIVE_TYPE(float)
DCO_DECLARE_VECTOR_PASSIVE_TYPE(double)
DCO_DECLARE_VECTOR_PASSIVE_TYPE(long double)

DCO_DECLARE_VECTOR_PASSIVE_TYPE(int8_t)
DCO_DECLARE_VECTOR_PASSIVE_TYPE(int16_t)
DCO_DECLARE_VECTOR_PASSIVE_TYPE(int32_t)
DCO_DECLARE_VECTOR_PASSIVE_TYPE(int64_t)

DCO_DECLARE_VECTOR_PASSIVE_TYPE(uint8_t)
DCO_DECLARE_VECTOR_PASSIVE_TYPE(uint16_t)
DCO_DECLARE_VECTOR_PASSIVE_TYPE(uint32_t)
DCO_DECLARE_VECTOR_PASSIVE_TYPE(uint64_t)

} // namespace traits
} // namespace vector_ns
} // namespace dco

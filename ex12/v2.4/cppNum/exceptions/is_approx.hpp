#pragma once
#include <limits>
#include <cmath>
#include "ad.hpp"

/// Compare two values using a machine error.
template<typename T>
bool is_approx(const T val1, const T val2, T eps = std::numeric_limits<T>::epsilon()){
  T max_val = std::abs(val1)>std::abs(val2) ? std::abs(val1) : std::abs(val2);
  eps = max_val==0 ? eps : eps*max_val;
  return std::abs(val1-val2) <= eps;
}

/** Compare value with zero. Epsilon from numeric limits is used to compare two values
    near to one. **/
template<typename T>
bool is_approx_zero(const T val, T eps = std::numeric_limits<T>::epsilon()){
  return is_approx(T(1.0), T(1.0) + val, eps);
}

/// Function to compare value with zero for internal algorithmic differentiation structure
template<typename T>
bool is_approx_zero(const ad::internal::active_type<T, ad::internal::ts_data<T>> val){
  return is_approx_zero(val._value());
}

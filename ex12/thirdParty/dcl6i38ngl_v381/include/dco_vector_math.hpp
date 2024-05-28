/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#pragma once

#include "dco_vector_common.hpp"

namespace dco {
namespace vector_ns {
using std::abs;
using std::cosh;
using std::fabs;
using std::fmod;
using std::round;
using std::sinh;
using std::tanh;

using std::asin;
using std::asinh;
using std::atan;
using std::atan2;
using std::atanh;
using std::cos;
using std::exp;
using std::expm1;
using std::log10;
using std::log1p;
using std::sin;
using std::sqrt;
using std::tan;

using std::acos;
using std::acosh;
using std::erf;
using std::erfc;
using std::hypot;
using std::log;
using std::pow;

namespace math {

template <typename FLOAT1_T, typename FLOAT2_T> struct BOP_ADD {
  typedef decltype(std::declval<FLOAT1_T>() + std::declval<FLOAT2_T>()) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1, const FLOAT2_T& x2) noexcept { return x1 + x2; }
};

template <typename FLOAT1_T, typename FLOAT2_T> struct BOP_ATAN2 {
  typedef decltype(atan2(std::declval<FLOAT1_T>(), std::declval<FLOAT2_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1, const FLOAT2_T& x2) noexcept { return atan2(x1, x2); }
};

template <typename FLOAT1_T, typename FLOAT2_T> struct BOP_DIV {
  typedef decltype(std::declval<FLOAT1_T>() / std::declval<FLOAT2_T>()) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1, const FLOAT2_T& x2) noexcept { return x1 / x2; }
};

template <typename FLOAT1_T, typename FLOAT2_T> struct BOP_MUL {
  typedef decltype(std::declval<FLOAT1_T>() * std::declval<FLOAT2_T>()) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1, const FLOAT2_T& x2) noexcept { return x1 * x2; }
};

template <typename FLOAT1_T, typename FLOAT2_T> struct BOP_POW {
  typedef decltype(pow(std::declval<FLOAT1_T>(), std::declval<FLOAT2_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1, const FLOAT2_T& x2) noexcept { return pow(x1, x2); }
};

template <typename FLOAT1_T, typename FLOAT2_T> struct BOP_HYPOT {
  typedef decltype(hypot(std::declval<FLOAT1_T>(), std::declval<FLOAT2_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1, const FLOAT2_T& x2) noexcept { return hypot(x1, x2); }
};

template <typename FLOAT1_T, typename FLOAT2_T> struct BOP_SUB {
  typedef decltype(std::declval<FLOAT1_T>() - std::declval<FLOAT2_T>()) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1, const FLOAT2_T& x2) noexcept { return x1 - x2; }
};

template <typename FLOAT1_T, typename FLOAT2_T> struct BOP_MAX {
  typedef FLOAT1_T primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1, const FLOAT2_T& x2) noexcept {
    return x1 > x2 ? static_cast<primal_t>(x1) : static_cast<primal_t>(x2);
  }
};

template <typename FLOAT1_T, typename FLOAT2_T> struct BOP_MIN {
  typedef FLOAT1_T primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1, const FLOAT2_T& x2) noexcept {
    return x1 < x2 ? static_cast<primal_t>(x1) : static_cast<primal_t>(x2);
  }
};

template <typename FLOAT1_T> struct UOP_ACOS {
  typedef decltype(acos(std::declval<FLOAT1_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return acos(x1); }
};

template <typename FLOAT1_T> struct UOP_ASIN {
  typedef decltype(asin(std::declval<FLOAT1_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return asin(x1); }
};

template <typename FLOAT1_T> struct UOP_ATAN {
  typedef decltype(atan(std::declval<FLOAT1_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return atan(x1); }
};

template <typename FLOAT1_T> struct UOP_COS {
  typedef decltype(cos(std::declval<FLOAT1_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return cos(x1); }
};

template <typename FLOAT1_T> struct UOP_COSH {
  typedef decltype(cosh(std::declval<FLOAT1_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return cosh(x1); }
};

template <typename FLOAT1_T> struct UOP_EXP {
  typedef decltype(exp(std::declval<FLOAT1_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return exp(x1); }
};

template <typename FLOAT1_T> struct UOP_LOG {
  typedef decltype(log(std::declval<FLOAT1_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return log(x1); }
};

template <typename FLOAT1_T> struct UOP_ACOSH {
  typedef decltype(acosh(std::declval<FLOAT1_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return acosh(x1); }
};

template <typename FLOAT1_T> struct UOP_LOG10 {
  typedef decltype(log10(std::declval<FLOAT1_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return log10(x1); }
};

template <typename FLOAT1_T> struct UOP_LOG1P {
  typedef decltype(log1p(std::declval<FLOAT1_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return log1p(x1); }
};

template <typename FLOAT1_T> struct UOP_ERF {
  typedef decltype(erf(std::declval<FLOAT1_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return erf(x1); }
};

template <typename FLOAT1_T> struct UOP_ERFC {
  typedef decltype(erfc(std::declval<FLOAT1_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return erfc(x1); }
};

template <typename FLOAT1_T> struct UOP_ASINH {
  typedef decltype(asinh(std::declval<FLOAT1_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return asinh(x1); }
};

template <typename FLOAT1_T> struct UOP_ATANH {
  typedef decltype(atanh(std::declval<FLOAT1_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return atanh(x1); }
};

template <typename FLOAT1_T> struct UOP_EXPM1 {
  typedef decltype(expm1(std::declval<FLOAT1_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return expm1(x1); }
};

template <typename FLOAT1_T> struct UOP_ABS {
  typedef decltype(abs(std::declval<FLOAT1_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return abs(x1); }
};

template <typename FLOAT1_T> struct UOP_FABS {
  typedef decltype(fabs(std::declval<FLOAT1_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return fabs(x1); }
};

template <typename FLOAT1_T> struct UOP_MINUS {
  typedef decltype(-std::declval<FLOAT1_T>()) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return -x1; }
};

template <typename FLOAT1_T> struct UOP_PLUS {
  typedef FLOAT1_T primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return x1; }
};

template <typename FLOAT1_T> struct UOP_SIN {
  typedef decltype(sin(std::declval<FLOAT1_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return sin(x1); }
};

template <typename FLOAT1_T> struct UOP_SINH {
  typedef decltype(sinh(std::declval<FLOAT1_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return sinh(x1); }
};

template <typename FLOAT1_T> struct UOP_SQRT {
  typedef decltype(sqrt(std::declval<FLOAT1_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return sqrt(x1); }
};

template <typename FLOAT1_T> struct UOP_TAN {
  typedef decltype(tan(std::declval<FLOAT1_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return tan(x1); }
};

template <typename FLOAT1_T> struct UOP_TANH {
  typedef decltype(tanh(std::declval<FLOAT1_T>())) primal_t;
  DCO_VECTOR_INLINE static primal_t eval(const FLOAT1_T& x1) noexcept { return tanh(x1); }
};
} // namespace math
} // namespace vector_ns
} // namespace dco

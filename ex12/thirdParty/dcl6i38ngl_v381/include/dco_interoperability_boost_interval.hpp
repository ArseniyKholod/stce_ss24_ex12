/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#pragma once

#if defined(DCO_INTEROPERABILITY_BOOST_INTERVAL) && defined(DCO_CPP11)

#include "boost/numeric/interval.hpp"

#include "boost/numeric/interval/io.hpp"

namespace boost {
namespace numeric {

template <class T, class Policies>
inline typename dco::enable_if<!dco::is_same<T, int>::value, interval<T, Policies>>::type
operator*(const int& x, const interval<T, Policies>& y) {
  return static_cast<T>(x) * y;
}

template <class T, class Policies>
inline interval<T, Policies> pow(const interval<T, Policies>& x, const interval<T, Policies>& pwr) {
  assert(pwr.lower() == pwr.upper());
  if (pwr.lower() == 2)
    return square(x);
  return pow(x, pwr.lower());
}

template <class T, class Policies> inline interval<T, Policies> round(const interval<T, Policies>& x) {
  return interval<T, Policies>(floor(x.lower() + 0.5), floor(x.upper() + 0.5));
}

namespace interval_lib {
template <typename T, typename D>
struct rounding_control<dco::internal::active_type<T, D>> : detail::c99_rounding_control {
  typedef dco::internal::active_type<T, D> type;
  static type force_rounding(type const& r) {
    type r_ = r;
    return r_;
  }
  template <class U> static U to_int(const U& r) { return rint(dco::passive_value(r)); }
};

namespace constants {
#define BOOST_SPECIALIZE_CONSTANTS_FP(TYPE)                                                                            \
  template <> inline TYPE pi_lower<TYPE>() { return pi_lower<dco::mode<TYPE>::passive_t>(); }                          \
  template <> inline TYPE pi_upper<TYPE>() { return pi_upper<dco::mode<TYPE>::passive_t>(); }                          \
  template <> inline TYPE pi_half_lower<TYPE>() { return pi_half_lower<dco::mode<TYPE>::passive_t>(); }                \
  template <> inline TYPE pi_half_upper<TYPE>() { return pi_half_upper<dco::mode<TYPE>::passive_t>(); }                \
  template <> inline TYPE pi_twice_lower<TYPE>() { return pi_twice_lower<dco::mode<TYPE>::passive_t>(); }              \
  template <> inline TYPE pi_twice_upper<TYPE>() { return pi_twice_upper<dco::mode<TYPE>::passive_t>(); }

BOOST_SPECIALIZE_CONSTANTS_FP(dco::gt1s<float>::type)
BOOST_SPECIALIZE_CONSTANTS_FP(dco::gt1s<double>::type)
BOOST_SPECIALIZE_CONSTANTS_FP(dco::ga1s<float>::type)
BOOST_SPECIALIZE_CONSTANTS_FP(dco::ga1s<double>::type)
BOOST_SPECIALIZE_CONSTANTS_FP(dco::ga1sm<float>::type)
BOOST_SPECIALIZE_CONSTANTS_FP(dco::ga1sm<double>::type)
BOOST_SPECIALIZE_CONSTANTS_FP(dco::gt1s<dco::gt1s<float>::type>::type)
BOOST_SPECIALIZE_CONSTANTS_FP(dco::gt1s<dco::gt1s<double>::type>::type)
BOOST_SPECIALIZE_CONSTANTS_FP(dco::ga1s<dco::gt1s<float>::type>::type)
BOOST_SPECIALIZE_CONSTANTS_FP(dco::ga1s<dco::gt1s<double>::type>::type)
BOOST_SPECIALIZE_CONSTANTS_FP(dco::gt1s<dco::ga1s<float>::type>::type)
BOOST_SPECIALIZE_CONSTANTS_FP(dco::gt1s<dco::ga1s<double>::type>::type)
BOOST_SPECIALIZE_CONSTANTS_FP(dco::ga1sm<dco::gt1s<float>::type>::type)
BOOST_SPECIALIZE_CONSTANTS_FP(dco::ga1sm<dco::gt1s<double>::type>::type)
BOOST_SPECIALIZE_CONSTANTS_FP(dco::gt1s<dco::ga1sm<float>::type>::type)
BOOST_SPECIALIZE_CONSTANTS_FP(dco::gt1s<dco::ga1sm<double>::type>::type)

#undef BOOST_SPECIALIZE_CONSTANTS_FP
} // namespace constants
} // namespace interval_lib
} // namespace numeric
} // namespace boost

namespace dco {
namespace folding {
template <typename BOOST_BASE_TYPE, typename ROUNDING_POLICY>
struct is_zero_trait<boost::numeric::interval<BOOST_BASE_TYPE, ROUNDING_POLICY>> {
  static bool get(const boost::numeric::interval<BOOST_BASE_TYPE, ROUNDING_POLICY>& x) {
    return (boost::numeric::interval_lib::cereq(x, BOOST_BASE_TYPE(0)));
  }
};
} // namespace folding
} // namespace dco

#endif

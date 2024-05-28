// info@stce.rwth-aachen.de
#pragma once
#include "ad.hpp"

/// derivatives of f
struct derivative_t {
  /// first derivative of f wrt. x
  template<typename FUNCTION_T, typename T=double>
  static T dfdx(const T& x, const T &p) { 
    ad::tangent_t<T> x_ad=x, p_ad=p; 
    ad::derivative(x_ad)=1;
    ad::tangent_t<T> y_ad=FUNCTION_T::f(x_ad,p_ad);
    return ad::derivative(y_ad);
  }
  /// second derivative of f wrt. x
  template<typename FUNCTION_T, typename T=double>
  static T ddfdxx(const T& x, const T &p) {
    ad::tangent_t<T> x_ad=x, p_ad=p;
    ad::derivative(x_ad)=1;
    // second derivative computed as first derivative of first derivative
    ad::tangent_t<T> dydx_ad=derivative_t::dfdx<FUNCTION_T,ad::tangent_t<T>>(x_ad,p_ad);
    return ad::derivative(dydx_ad);
  }

}; 

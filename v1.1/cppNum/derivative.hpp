// info@stce.rwth-aachen.de
#pragma once

#include "ad.hpp"

/// host for static differentiation methods
struct derivative_t {
  /// first derivative of f wrt. x
  template<typename FUNCTION_T, typename T>
  static T dfdx(const T &x, const T &p) { 
    ad::tangent_t<T> x_ad=x, p_ad=p; 
    ad::derivative(x_ad)=1;
    ad::tangent_t<T> y_ad=FUNCTION_T::f(x_ad,p_ad);
    return ad::derivative(y_ad);
  }
}; 

// info@stce.rwth-aachen.de

#pragma once

#include <vector>
#include "ad.hpp"

///
struct derivative_t {
  template<typename FUNCTION_T, typename T=double, typename DATA_T=void>
  static T dfdx(const T& x_v, const T& p_v, const DATA_T* const data_p=nullptr) {
    ad::tangent_t<T> x=x_v, p=p_v;
    ad::derivative(x)=1;
    ad::tangent_t<T> y=FUNCTION_T::f(x,p,data_p);
    return ad::derivative(y);
  }
  template<typename FUNCTION_T, typename T=double, typename DATA_T=void>
  static T ddfdxx(const T& x_v, const T& p_v, const DATA_T* const data_p=nullptr) {
    ad::tangent_t<T> x=x_v, p=p_v;
    ad::derivative(x)=1;
    ad::tangent_t<T> dydx=derivative_t::dfdx<FUNCTION_T,ad::tangent_t<T>,DATA_T>(x,p,data_p);
    return ad::derivative(dydx);
  }
};

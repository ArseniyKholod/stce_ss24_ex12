// info@stce.rwth-aachen.de
#pragma once

#include "linearAlgebra.hpp"
#include "ad.hpp"

struct derivative_t {
  template<typename FUNCTION_T, typename T=double>
  static la::vector_t<T> dfdx(const la::vector_t<T>& x_v, const la::vector_t<T> &p_v) { 
    int n=x_v.size(), m=p_v.size();
    la::vector_t<ad::tangent_t<T>> x(n), p(m); 
    la::vector_t<T> dydx(n); 
    for (int i=0;i<n;++i) x(i)=x_v(i);
    for (int i=0;i<m;++i) p(i)=p_v(i);
    for (int i=0;i<n;++i) {
      ad::derivative(x(i))=1;
      ad::tangent_t<T> y=FUNCTION_T::f(x,p);
      dydx(i)=ad::derivative(y);
      ad::derivative(x(i))=0;
    }
    return dydx;
  }
  template<typename FUNCTION_T, typename T=double>
  static la::matrix_t<T> ddfdxx(const la::vector_t<T>& x_v, const la::vector_t<T>& p_v) { 
    int n=x_v.size(), m=p_v.size();
    la::vector_t<ad::tangent_t<T>> x(n), p(m); 
    la::matrix_t<T> ddydxx(n,n); 
    for (int i=0;i<n;++i) x(i)=x_v(i);
    for (int i=0;i<m;++i) p(i)=p_v(i);
    for (int i=0;i<n;++i) {
      ad::derivative(x(i))=1;
      la::vector_t<ad::tangent_t<T>> dydx=derivative_t::dfdx<FUNCTION_T,ad::tangent_t<T>>(x,p);
      for (int j=0;j<n;++j) ddydxx(j,i)=ad::derivative(dydx(j));
      ad::derivative(x(i))=0;
    }
    return ddydxx;
  }
  template<typename FUNCTION_T, typename T=double>
  static la::matrix_t<T> ddfdxp(const la::vector_t<T>& x_v, const la::vector_t<T>& p_v) { 
    int n=x_v.size(), m=p_v.size();
    la::vector_t<ad::tangent_t<T>> x(n), p(m); 
    la::matrix_t<T> ddydxp(n,m); 
    for (int i=0;i<n;++i) x(i)=x_v(i);
    for (int i=0;i<m;++i) p(i)=p_v(i);
    for (int i=0;i<m;++i) {
      ad::derivative(p(i))=1;
      la::vector_t<ad::tangent_t<T>> dydx=derivative_t::dfdx<FUNCTION_T,ad::tangent_t<T>>(x,p);
      for (int j=0;j<n;++j) ddydxp(j,i)=ad::derivative(dydx(j));
      ad::derivative(p(i))=0;
    }
    return ddydxp;
  }
}; 

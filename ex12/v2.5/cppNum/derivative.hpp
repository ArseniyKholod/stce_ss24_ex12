// info@stce.rwth-aachen.de
#pragma once

#include "linearAlgebra.hpp"
#include "ad.hpp"

struct derivative_t {
  template<typename FUNCTION_T, typename T=double, typename DATA_T=void>
  static la::vector_t<T> dfdx(const la::vector_t<T>& x_v, const la::vector_t<T> &p_v, const DATA_T* const data_p=nullptr) { 
    int n=x_v.size(), m=p_v.size();
    la::vector_t<ad::tangent_t<T>> x(n), p(m); 
    la::vector_t<T> dydx(n); 
    for (int i=0;i<n;++i) x(i)=x_v(i);
    for (int i=0;i<m;++i) p(i)=p_v(i);
    for (int i=0;i<n;++i) {
      ad::derivative(x(i))=1;
      ad::tangent_t<T> y=FUNCTION_T::f(x,p,data_p);
      dydx(i)=ad::derivative(y);
      ad::derivative(x(i))=0;
    }
    return dydx;
  }
  template<typename FUNCTION_T, typename T=double, typename DATA_T=void>
  static la::matrix_t<T> ddfdxx(const la::vector_t<T>& x_v, const la::vector_t<T>& p_v,  const DATA_T* const data_p=nullptr) { 
    int n=x_v.size(), m=p_v.size();
    la::vector_t<ad::tangent_t<T>> x(n), p(m); 
    la::matrix_t<T> ddydxx(n,n); 
    for (int i=0;i<n;++i) x(i)=x_v(i);
    for (int i=0;i<m;++i) p(i)=p_v(i);
    for (int i=0;i<n;++i) {
      ad::derivative(x(i))=1;
      la::vector_t<ad::tangent_t<T>> dydx=derivative_t::dfdx<FUNCTION_T,ad::tangent_t<T>,DATA_T>(x,p,data_p);
      for (int j=0;j<n;++j) ddydxx(j,i)=ad::derivative(dydx(j));
      ad::derivative(x(i))=0;
    }
    return ddydxx;
  }
  template<typename FUNCTION_T, typename T=double, typename DATA_T=void>
  static la::matrix_t<T> dFdx(const la::vector_t<T>& x_v, const la::vector_t<T>& p_v,  const DATA_T* const data_p=nullptr) { 
    int n=x_v.size(), m=p_v.size();
    la::vector_t<ad::tangent_t<T>> x(n), p(m); 
    la::matrix_t<T> drdx(n,n); 
    for (int i=0;i<n;++i) x(i)=x_v(i);
    for (int i=0;i<m;++i) p(i)=p_v(i);
    for (int i=0;i<n;++i) {
      ad::derivative(x(i))=1;
      la::vector_t<ad::tangent_t<T>> r=FUNCTION_T::F(x,p,data_p);
      for (int j=0;j<n;++j) drdx(j,i)=ad::derivative(r(j));
      ad::derivative(x(i))=0;
    }
    return drdx;
  }

}; 

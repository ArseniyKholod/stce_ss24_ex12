// info@stce.rwth-aachen.de
#pragma once

#include "linearAlgebra.hpp"
#include "ad.hpp"

struct derivative_t {
  template<typename FUNCTION_T, typename T>
  static la::matrix_t<T> dFdx(const la::vector_t<T>& x_v, const la::vector_t<T>& p_v) { 
    int n=x_v.size(), m=p_v.size();
    la::vector_t<ad::tangent_t<T>> x(n), p(m); 
    la::matrix_t<T> drdx(n,n); 
    for (int i=0;i<n;++i) x(i)=x_v(i);
    for (int i=0;i<m;++i) p(i)=p_v(i);
    for (int i=0;i<n;++i) {
      ad::derivative(x(i))=1;
      la::vector_t<ad::tangent_t<T>> r=FUNCTION_T::F(x,p);
      for (int j=0;j<n;++j) drdx(j,i)=ad::derivative(r(j));
      ad::derivative(x(i))=0;
    }
    return drdx;
  }

  template<typename FUNCTION_T, typename T>
  static la::matrix_t<T> dFdp(const la::vector_t<T>& x_v, const la::vector_t<T>& p_v) { 
    int n=x_v.size(), m=p_v.size();
    la::vector_t<ad::tangent_t<T>> x(n), p(m); 
    la::matrix_t<T> drdp(n,m); 
    for (int i=0;i<n;++i) x(i)=x_v(i);
    for (int i=0;i<m;++i) p(i)=p_v(i);
    for (int i=0;i<m;++i) {
      ad::derivative(p(i))=1;
      la::vector_t<ad::tangent_t<T>> r=FUNCTION_T::F(x,p);
      for (int j=0;j<n;++j) drdp(j,i)=ad::derivative(r(j));
      ad::derivative(p(i))=0;
    }
    return drdp;
  }

}; 

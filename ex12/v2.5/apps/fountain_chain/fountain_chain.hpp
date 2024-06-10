// info@stce.rwth-aachen.de
#pragma once
#include "cppNum/differentialSystem/system.hpp"
#include <cassert>

template<typename T>
la::vector_t<T> ds::system_t::G(const la::vector_t<T> &x, const la::vector_t<T> &p) {
  int n=x.size();
  assert(p.size()==2*n+2);
  assert(n>=2);
  la::vector_t<T> r(n);
  r(0)=(1/p(2))*(p(0)-p(3)*sqrt(2*p(1)*x(0)));
  for(int i=1; i<n; i++) r(i)=(1/p(2*i+2))*(p(2*i+1)*sqrt(2*p(1)*x(i-1))-p(2*i+3)*sqrt(2*p(1)*x(i)));
  return r;
}

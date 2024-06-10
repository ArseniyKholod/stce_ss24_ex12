// info@stce.rwth-aachen.de
#pragma once
#include "cppNum/differentialSystem/system.hpp"
#include <cassert>

template<typename T>
la::vector_t<T> ds::system_t::G(const la::vector_t<T> &x, const la::vector_t<T> &p) {
  int n=x.size();
  assert(p.size()==n*n);
  la::vector_t<T> r=la::vector_t<T>::Zero(n);
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      r(i)+=p(i*n+j)*x(j);
  return r;
}

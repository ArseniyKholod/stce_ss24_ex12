// info@stce.rwth-aachen.de
#pragma once
#include "cppNum/differentialSystem/system.hpp"
#include <cassert>

template<typename T>
la::vector_t<T> ds::system_t::G(const la::vector_t<T> &x, const la::vector_t<T> &p) {
  int n=x.size();
  assert(p.size()==n);
  la::vector_t<T> r(n);
  for(int i=0; i<n; i++) r(i)=p(i)*x(i);
  return r;
}


// info@stce.rwth-aachen.de
#pragma once
#include "cppNum/differentialSystem/system.hpp"
#include <cassert>

template<typename T>
la::vector_t<T> ds::system_t::G(const la::vector_t<T> &x, const la::vector_t<T> &p) {
  assert(x.size()==2&&p.size()==4);
  la::vector_t<T> r(2);
  r(0)=(p(0)-p(1)*x(1))*x(0);
  r(1)=-(p(2)-p(3)*x(0))*x(1);
  return r;
}

// info@stce.rwth-aachen.de
#include "cppNum/algebraicSystem/system.hpp"

template<typename T> 
la::vector_t<T> as::system_t::F(const la::vector_t<T> &x, const la::vector_t<T> &p) { 
  la::vector_t<T> r(2);
  r(0)=p(0)*exp(x(0)/p(1))+x(1);
  r(1)=p(0)*pow(x(0),3)+p(1)-x(1);
  return r;
}

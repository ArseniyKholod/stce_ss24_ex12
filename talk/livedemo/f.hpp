// info@stce.rwth-aachen.de
#pragma once
#include "cppNum/convexObjective/objective.hpp"
#include <cassert>
#include <cmath>

template<typename T> 
T co::objective_t::f(const la::vector_t<T> &x, const la::vector_t<T> &p) { 
  using namespace std;
  int n=x.size(); assert(n==2); assert(p.size()==0);
  T y=0.5*x(0)*x(0)+0.5*x(1)*x(1)+x(0)*x(1);
  return y;
}

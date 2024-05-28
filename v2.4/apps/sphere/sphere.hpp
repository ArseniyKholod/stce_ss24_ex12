// info@stce.rwth-aachen.de
#pragma once
#include "cppNum/convexObjective/objective.hpp"
#include <cassert>
#include <cmath>

template<typename T> 
T co::objective_t::f(const la::vector_t<T> &x, const la::vector_t<T> &p) { 
  using namespace std;
  int n=x.size(); assert(n>1); assert(p.size()==n);
  T y=0;
  for (int i=0;i<n;++i) y+=pow(p(i)*(sin(p(i))+x(i)),2);
  return y;
}

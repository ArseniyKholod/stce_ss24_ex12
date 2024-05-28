// info@stce.rwth-aachen.de
#include "cppNum/convexObjective/objective.hpp"
#include <cassert>
#include <cmath>

template<typename T> 
T co::objective_t::f(const T &x, const T &p) { 
  using namespace std;
  assert(x-sin(p)>0); return pow(log(x-sin(p)),2)+p;
}

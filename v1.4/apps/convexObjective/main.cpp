// info@stce.rwth-aachen.de
#include "apps/objectives/f1.hpp"
#include "cppNum/convexObjective/newton.hpp"
#include "cppNum/derivative.hpp"
#include <iostream>

int main() {
  using T=double;
  T p=0.5, x=1; co::newton_minimizer_t<T> minimizer(1e-7);
  x=minimizer.run(x,p);
  std::cout << "x=" << x << ", f(x)=" << co::objective_t::f(x,p) 
    << ", dfdx=" << derivative_t::dfdx<co::objective_t>(x,p) 
    << ", ddfdxx=" << derivative_t::ddfdxx<co::objective_t>(x,p) << std::endl;
  return 0;
}  

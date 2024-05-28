// info@stce.rwth-aachen.de
#include "apps/objectives/f1.hpp"
#include "cppNum/convexObjective/gradientDescent.hpp"
#include <limits>
#include <iostream>

int main() {
  using T=double;
  T p=0.5, x0=1; 
  T h=std::sqrt(std::sqrt(std::numeric_limits<T>::epsilon())*std::fabs(p));
  co::gradientDescent_minimizer_t<T> solver(1e-7);
  T x=solver.run(x0,p);
  std::cout << "f(" << x << ")=" << co::objective_t::f(x,p) << std::endl;
  T xm=solver.run(x0,p-h);
  T xp=solver.run(x0,p+h);
  std::cout << "dx/dp(" << x << ")=" << (xp-xm)/(2*h) << std::endl;
  std::cout << "ddx/dpp(" << x << ")=" << (xp-2*x+xm)/(h*h) << std::endl;
  xm=solver.run(x0-h,p);
  xp=solver.run(x0+h,p);
  std::cout << "dx/dx0(" << x << ")=" << (xp-xm)/(2*h) << std::endl;
  return 0;
}  

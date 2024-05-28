// info@stce.rwth-aachen.de
#include "cppNum/differentialEquation/equation.hpp"

template<typename T>
T de::equation_t::g(const T &x, const T &p) { return -p*x; }

#include "cppNum/differentialEquation/explicitEuler.hpp"
#include <cmath>
#include <limits>
#include <iostream>

int main() {
  using T=double;
  T p=0.5, x_in=1; 
  de::explicitEuler_integrator_t<T> integrator(1,100);
  T x=integrator.run(x_in,p);
  T h=std::sqrt(std::numeric_limits<T>::epsilon());
  T xp=integrator.run(x_in,p+h);
  std::cout << "dx/dp=" << (xp-x)/h << std::endl;
  xp=integrator.run(x_in+h,p);
  std::cout << "dx/dx^0=" << (xp-x)/h << std::endl;
  return 0;
}  

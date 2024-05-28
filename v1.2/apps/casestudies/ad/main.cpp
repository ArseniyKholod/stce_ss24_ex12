// info@stce.rwth-aachen.de
#include "cppNum/differentialEquation/equation.hpp"

template<typename T>
T de::equation_t::g(const T &x, const T &p) { return -p*x; }

#include "cppNum/differentialEquation/explicitEuler.hpp"
#include "ad.hpp"
#include <iostream>

int main() {
  using T=double;
  ad::tangent_t<T> p=0.5, x_in=1; // derivatives equal to zero
  de::explicitEuler_integrator_t<ad::tangent_t<T>> integrator(1,100);
  ad::derivative(p)=1;
  ad::tangent_t<T> x=integrator.run(x_in,p);
  std::cout << "dx/dp=" << ad::derivative(x) << std::endl;
  ad::derivative(p)=0; ad::derivative(x_in)=1;
  x=integrator.run(x_in,p);
  std::cout << "dx/dx^0=" << ad::derivative(x) << std::endl;
  return 0;
}  

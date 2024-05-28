// info@stce.rwth-aachen.de
#include "apps/equations/g1.hpp"
#include "cppNum/differentialEquation/implicitEuler.hpp"
#include "ad.hpp"
#include <iostream>

int main() {
  using T=ad::tangent_t<double>; 
  T p=0.5, x0=1, t_target=1; // derivatives initially equal to zero
  int number_of_timesteps=100;
  de::implicitEuler_integrator_t<T> integrator(t_target,number_of_timesteps);
  ad::derivative(p)=1; // seed p
  T x=integrator.run(x0,p);
  std::cout << "dx/dp=" << ad::derivative(x) << std::endl; // harvest dx/dp
  ad::derivative(p)=0; ad::derivative(x0)=1; // seed x0
  x=integrator.run(x0,p);
  std::cout << "dx/dx^0=" << ad::derivative(x) << std::endl; // harvest dx/dx0
  return 0;
}  

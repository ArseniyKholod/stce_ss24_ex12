// info@stce.rwth-aachen.de
#include "apps/equations/g1.hpp"
#include "cppNum/differentialEquation/implicitEuler.hpp"
#include <cmath>
#include <limits>
#include <iostream>

int main() {
  using T=double;
  T p=0.5, x0=1, t_target=1;
  int number_of_timesteps=100;
  de::implicitEuler_integrator_t<T> integrator(t_target,number_of_timesteps);
  T x=integrator.run(x0,p);
  T h=std::sqrt(std::numeric_limits<T>::epsilon());
  T xp=integrator.run(x0,p+h);
  std::cout << "dx/dp=" << (xp-x)/h << std::endl;
  xp=integrator.run(x0+h,p);
  std::cout << "dx/dx^0=" << (xp-x)/h << std::endl;
  return 0;
}  

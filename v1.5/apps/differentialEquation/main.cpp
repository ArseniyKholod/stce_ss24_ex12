// implement g
#include "apps/equations/g1.hpp"
#include "cppNum/differentialEquation/implicitEuler.hpp"
#include <iostream>

int main() {
  using T=double;
  // set x,p,t_end(=1), dt=t_end/m (m=100), accuracy=1e-8
  de::implicitEuler_integrator_t<T> integrator(1,100,1e-8); 
  T p=0.5, x=1;
  // run integrator
  x=integrator.run(x,p);
  // process result
  std::cout << "x=" << x << std::endl;
  return 0;
}


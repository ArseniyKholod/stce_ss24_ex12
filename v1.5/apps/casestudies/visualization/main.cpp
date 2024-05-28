// info@stce.rwth-aachen.de
#include "apps/equations/g1.hpp"
#include "cppNum/differentialEquation/implicitEuler.hpp"
#include <vector>
#include <iostream>

int main() {
  using T=double;
  T p=-0.1, x=1, t_target=10; int number_of_timesteps=20;
  // enable tracing
  bool trace=true;
  de::implicitEuler_integrator_t<T> integrator(t_target,number_of_timesteps,1e-7,trace);
  // record trace
  x=integrator.run(x,p);
  // write trace to file
  integrator.plot("implicitEuler_steps.plt");
  std::cout << "x=" << x << std::endl;
  return 0;
}  

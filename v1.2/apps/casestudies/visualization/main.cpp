// info@stce.rwth-aachen.de
#include "cppNum/differentialEquation/equation.hpp"

template<typename T>
T de::equation_t::g(const T &x, const T &p) {
  return -p*x; 
}

#include "cppNum/differentialEquation/explicitEuler.hpp"
#include <iostream>

int main() {
  using T=double;
  T p=0.5, x=1; 
  // enable tracing
  de::explicitEuler_integrator_t<T> integrator(1,100,true);
  // record trace
  x=integrator.run(x,p);
  // write trace to file
  integrator.plot("explicitEuler_steps.plt");
  std::cout << "x=" << x << std::endl;
  return 0;
}  

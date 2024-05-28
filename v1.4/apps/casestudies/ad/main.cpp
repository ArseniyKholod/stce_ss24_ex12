// info@stce.rwth-aachen.de
#include "apps/objectives/f1.hpp"
#include "cppNum/convexObjective/newton.hpp"
#include "ad.hpp"
#include <iostream>

int main() {
  using T=ad::tangent_t<ad::tangent_t<double>>;
  T p=0.5, x0=1; // derivatives initially equal to zero
  co::newton_minimizer_t<T> solver(1e-7);
  ad::derivative(ad::value(p))=1; // \tilde{p}
  ad::value(ad::derivative(p))=1; // \dot{p}
  T x=solver.run(x0,p);
  std::cout << "f(" << x << ")=" << co::objective_t::f(x,p) << std::endl;
  std::cout << "dx/dp(" << x << ")=" << ad::derivative(x) << std::endl;
  std::cout << "ddx/dpp(" << x << ")=" << ad::derivative(ad::derivative(x)) << std::endl;
  ad::derivative(p)=0; // ad::value(ad::derivative(p))=ad::derivative(ad::derivative(p))=0
  ad::derivative(x0)=1; // ad::value(ad::derivative(x0))=1; ad::derivative(ad::derivative(x0))=0
  x=solver.run(x0,p);
  std::cout << "dx/dx0(" << x << ")=" 
	  << ad::derivative(x) // ad::value(ad::derivative(x))
	  << std::endl;
  return 0;
}  

// info@stce.rwth-aachen.de
#include "cppNum/algebraicEquation/equation.hpp"
#include <cmath>

template<typename T> 
T ae::equation_t::f(const T &x, const T &p) { 
  using namespace std;
  return exp(-x)-p; 
}

#include "cppNum/algebraicEquation/newton.hpp"
#include "ad.hpp"
#include <iostream>

int main() {
  using T=ad::tangent_t<double>;
  T p=0.5, x=0; 
  ae::newton_solver_t<T> solver(1e-7);
  ad::derivative(p)=1;
  x=solver.run(x,p);
  std::cout << "dx/dp(" << x << ")=" << ad::derivative(x) << std::endl;
  return 0;
}  

// info@stce.rwth-aachen.de
#include "cppNum/algebraicEquation/equation.hpp"
#include <cmath>

// user-defined residual
template<typename T> 
T ae::equation_t::f(const T &x, const T &p) { 
  using namespace std; 
  return exp(-x)-p; 
}

#include "cppNum/algebraicEquation/newton.hpp"
#include <iostream>

int main() {
  // user-defined driver code
  using T=double;
  T p=0.5, x=0; ae::newton_solver_t<T> solver(1e-7);
  x=solver.run(x,p);
  std::cout << "f(" << x << ")=" << ae::equation_t::f(x,p) << std::endl;
  return 0;
}  

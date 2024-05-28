// info@stce.rwth-aachen.de
#include "cppNum/algebraicEquation/equation.hpp"
#include <cmath>

template<typename T> 
T ae::equation_t::f(const T &x, const T &p) { 
  using namespace std;
  return exp(-x)-p; 
}

#include "cppNum/algebraicEquation/newton.hpp"
#include <limits>
#include <iostream>

int main() {
  using T=double;
  T p=0.5, x=0; 
  ae::newton_solver_t<T> solver(1e-7);
  T h=std::sqrt(std::numeric_limits<T>::epsilon());
  T xm=solver.run(x,p-h); T xp=solver.run(x,p+h);
  x=solver.run(x,p); 
  std::cout << "dx/dp(" << x << ")=" << (xp-xm)/(h+h) << std::endl;
  return 0;
}  

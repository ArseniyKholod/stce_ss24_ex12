// info@stce.rwth-aachen.de
#include "cppNum/algebraicEquation/equation.hpp"
#include <vector>
#include <cmath>

template<typename T, typename DATA_T> 
T ae::equation_t::f(const T &x, const T &p, const DATA_T* const data) { 
  using namespace std; 
  return data->i*exp(-x)-p; 
}

#include "cppNum/algebraicEquation/newton.hpp"
#include <iostream>

int main() {
  using T=double;
  T x=0, p=0.5; 
  struct data_t { int i=1; } data;
  // default template argument ae::equation_t can be omitted
  ae::newton_solver_t<T,data_t,ae::equation_t> solver(1e-7,&data);
  x=solver.run(x,p);
  std::cout << "f(" << x << ")=" << ae::equation_t::f(x,p,&data) << std::endl;
  return 0;
}  

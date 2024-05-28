// info@stce.rwth-aachen.de
#include "intersection.hpp"
#include "cppNum/algebraicSystem/newton.hpp"
#include <iostream>

int main() {
  using T=double;
  using namespace std;
  const int np=2, nx=2;
  la::vector_t<T> p(np), x(nx); 
  p(0)=1; p(1)=-0.5; x(0)=1; x(1)=1; 
  as::newton_solver_t<T> solver(1e-7);
  x=solver.run(x,p);
  cout << "x=" << x.transpose() << endl;
  return 0;
}  

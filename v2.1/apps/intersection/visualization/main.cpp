// info@stce.rwth-aachen.de
#include "apps/intersection/intersection.hpp"
#include "cppNum/algebraicSystem/newton.hpp"

int main() {
  using T=double;
  const int np=2, nx=2;
  la::vector_t<T> p(np), x(nx); 
  p(0)=1; p(1)=-0.5; x(0)=1; x(1)=1; 
  as::newton_solver_t<T> solver(1e-7,true);
  x=solver.run(x,p);
  solver.plot("newton_steps.plt",0,1);
  return 0;
}  

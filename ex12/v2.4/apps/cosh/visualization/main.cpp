// info@stce.rwth-aachen.de
#include "apps/cosh/cosh.hpp"
#include "cppNum/convexObjective/newton.hpp"
#include "cppNum/linearAlgebra.hpp"

int main(int argc, char* argv[]) {
  using T=double;
  using solver=la::lu_solver_t<T>;
  assert(argc==2);
  int np=std::stoi(argv[1]), nx=np; 
  la::vector_t<T> p=la::vector_t<T>::Random(np); 
  la::vector_t<T> x=-4*la::vector_t<T>::Ones(nx); 
  co::newton_minimizer_t<T, solver> minimizer(1e-7,true);
  x=minimizer.run(x,p);
  minimizer.plot("steps.plt",0,1);
  return 0;
}  

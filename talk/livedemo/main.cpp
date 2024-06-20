// info@stce.rwth-aachen.de
#include "./f.hpp"
#include "cppNum/convexObjective/newton.hpp"
#include "cppNum/linearAlgebra.hpp"
#include "cppNum/derivative.hpp"
#include "cppNum/exceptions/cppNum_exception.hpp"
#include <iostream>

int main() {
  using T=double;
  using solver=la::lu_solver_t<T>;
  using namespace std;
  la::vector_t<T> p(0); 
  la::vector_t<T> x=-4*la::vector_t<T>::Ones(2); 
  co::newton_minimizer_t<T,solver> minimizer(1e-7);
  x=minimizer.run(x,p);
  return 0;
}  

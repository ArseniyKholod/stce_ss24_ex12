// info@stce.rwth-aachen.de
#include "apps/cosh/cosh.hpp"
#include "cppNum/convexObjective/newton.hpp"
#include "cppNum/linearAlgebra.hpp"
#include "cppNum/derivative.hpp"
#include "cppNum/exceptions/cppNum_exception.hpp"
#include <iostream>
#include <chrono>
#include <vector>

int main() {
  try{
    using T=double;
    using solver=la::lu_solver_t<T>;
    using namespace std;
    int n_start=1, n_stop=51, n_step=2;
    std::vector<T> time_measurements;
    for(int n=n_start; n<=n_stop; n+=n_step){
      int np=n, nx=np; 
      la::vector_t<T> p=2*la::vector_t<T>::Ones(np); 
      la::vector_t<T> x=-4*la::vector_t<T>::Ones(nx); 
      co::newton_minimizer_t<T,solver> minimizer(1e-7);
      for(int i=0; i<10; i++)
        x=minimizer.run(x,p);
    }
    
  }
  catch(cppNum_exception & e){
    std::cerr<<e.what()<<std::endl;
  }
  catch(...){
    std::cerr<<"Unknown exception"<<std::endl;
  }
  return 0;
}  

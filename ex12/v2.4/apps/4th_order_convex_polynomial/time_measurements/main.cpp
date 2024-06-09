// info@stce.rwth-aachen.de
#include "apps/4th_order_convex_polynomial/4th_order_convex_polynomial.hpp"
#include "cppNum/convexObjective/newton.hpp"
#include "cppNum/linearAlgebra.hpp"
#include "cppNum/derivative.hpp"
#include "cppNum/exceptions/cppNum_exception.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>

int main() {
  try{
    using T=double;
    using namespace std;
    int n_start=1, n_stop=81, n_step=4;
    std::vector<T> time_measurements;
    for(int n=n_start; n<=n_stop; n+=n_step){
      int np=n, nx=np; 
      la::vector_t<T> p=2*la::vector_t<T>::Ones(np); 
      la::vector_t<T> x=-4*la::vector_t<T>::Ones(nx); 
      co::newton_minimizer_t<T> minimizer(1e-7);
      auto start = std::chrono::high_resolution_clock::now();
      for(int i=0; i<5; i++)
        minimizer.run(x,p);
      auto stop = std::chrono::high_resolution_clock::now();
      time_measurements.push_back(std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count()/5.*0.000001);
    }
    std::ofstream out("time.plt");
    for(int i=0; n_start+i*n_step<=n_stop; i++)
      out<<n_start+i*n_step<<' '<<time_measurements[i]<<std::endl;
  }
  catch(cppNum_exception & e){
    std::cerr<<e.what()<<std::endl;
  }
  catch(...){
    std::cerr<<"Unknown exception"<<std::endl;
  }
  return 0;
}  

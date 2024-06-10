// info@stce.rwth-aachen.de
#include "apps/fountain_chain/fountain_chain.hpp"
#include "cppNum/differentialSystem/implicitEuler.hpp"
#include <iostream>
#include <cassert>
#include <chrono>
#include <fstream>

int main() {
  try{
    using T=double; using namespace std;
    int n_start=2, n_end=102, n_step=4, nx, np;
    std::ofstream out("time.plt");
    for(int i=0; n_start+n_step*i<=n_end; i++){
      nx=n_start+n_step*i;
      np=2*nx+2;
      la::vector_t<T> p=la::vector_t<T>::Zero(np), x=la::vector_t<T>::Zero(nx); 
      p(0)=1.;
      p(1)=9.81;
      for(int i=1; i<=nx; i++){
        p(2*i)=10.;
        p(2*i+1)=1.;
      }
      ds::implicitEuler_integrator_t<T> integrator(10.,100,1e-10);
      auto start=std::chrono::high_resolution_clock::now();
      x=integrator.run(x,p);
      auto stop=std::chrono::high_resolution_clock::now();
      out<<nx<<' '<<(std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count()*0.000001)<<endl;
    }
  }
  catch(ex::cppNum_exception &e){
    std::cerr<<e.what()<<std::endl;
  }
  catch(...){
    std::cerr<<"Unknown exception"<<std::endl;
  }
  return 0;
}  

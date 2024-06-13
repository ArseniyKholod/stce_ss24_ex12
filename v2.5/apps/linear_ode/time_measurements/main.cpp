// info@stce.rwth-aachen.de
#include "apps/linear_ode/linear_ode.hpp"
#include "cppNum/differentialSystem/implicitEuler.hpp"
#include <iostream>
#include <cassert>
#include <chrono>
#include <fstream>

int main() {
  using T=double; using namespace std;
  int n_start=10, n_end=50, n_step=4, nx, np;
  std::ofstream out("time.plt");
  for(int i=0; n_start+n_step*i<=n_end; i++){
    nx=n_start+n_step*i;
    np=nx*nx;
    la::vector_t<T> p=la::vector_t<T>::Zero(np), x=la::vector_t<T>::Ones(nx); 
    for(int i=2; i<nx; i++) p(i*nx+i)=-1.-double(i)/nx;
    p(0)=-1.; p(1)=-1.; p(nx)=1.; p(nx+1)=-1.;
    ds::implicitEuler_integrator_t<T> integrator(4.,100,1e-10);
    auto start=std::chrono::high_resolution_clock::now();
    x=integrator.run(x,p);
    auto stop=std::chrono::high_resolution_clock::now();
    out<<nx<<' '<<(std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count()*0.000001)<<endl;
  }
  return 0;
}  

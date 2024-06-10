// info@stce.rwth-aachen.de
#include "linear_ode.hpp"
#include "cppNum/differentialSystem/implicitEuler.hpp"
#include <iostream>
#include <cassert>

int main(int argc, char* argv[]) {
  try{
    assert(argc==2);
    using T=double; using namespace std;
    const int nx=stoi(argv[1]), np=nx*nx;
    assert(nx>=2);
    la::vector_t<T> p=la::vector_t<T>::Zero(np), x=la::vector_t<T>::Ones(nx); 
    for(int i=2; i<nx; i++) p(i*nx+i)=-1.-double(i)/nx;
    p(0)=-1.; p(1)=-1.; p(nx)=1.; p(nx+1)=-1.;
    ds::implicitEuler_integrator_t<T> integrator(4.,1000,1e-10);
    x=integrator.run(x,p);
    cout << "x=" << x.transpose() << endl;
  }
  catch(ex::cppNum_exception &e){
    std::cerr<<e.what()<<std::endl;
  }
  catch(...){
    std::cerr<<"Unknown exception"<<std::endl;
  }
  return 0;
}  

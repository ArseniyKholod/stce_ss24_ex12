// info@stce.rwth-aachen.de
#include "apps/fountain_chain/fountain_chain.hpp"
#include "cppNum/differentialSystem/implicitEuler.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  assert(argc==2);
  using T=double; using namespace std;
  const int nx=stoi(argv[1]), np=2*nx+2;
  assert(nx>=2);
  la::vector_t<T> p=la::vector_t<T>::Zero(np), x=la::vector_t<T>::Zero(nx);
  p(0)=1.;
  p(1)=9.81;
  for(int i=1; i<=nx; i++){
    p(2*i)=10.;
    p(2*i+1)=1.;
  }
  ds::implicitEuler_integrator_t<T> integrator(10.,100,1e-10, true);
  x=integrator.run(x,p);
  integrator.plot("steps.plt", 1);
  cout << "x=" << x.transpose() << endl;
  return 0;
}


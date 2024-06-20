// info@stce.rwth-aachen.de
#include "apps/linear_ode/linear_ode.hpp"
#include "cppNum/differentialSystem/implicitEuler.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  assert(argc==2);
  using T=double; using namespace std;
  const int nx=stoi(argv[1]), np=nx*nx;
  assert(nx>=2);
  la::vector_t<T> p=la::vector_t<T>::Zero(np), x=la::vector_t<T>::Ones(nx);
  for(int i=2; i<nx; i++) p(i*nx+i)=-1-double(i)/nx;
  p(0)=-1.; p(1)=-1.; p(nx)=1.; p(nx+1)=-1.;
  ds::implicitEuler_integrator_t<T> integrator(4.,100,1e-10, true);
  x=integrator.run(x,p);
  integrator.plot("steps.plt", 0);
  cout << "x=" << x.transpose() << endl;
  return 0;
}


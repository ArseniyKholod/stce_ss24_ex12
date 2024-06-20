// info@stce.rwth-aachen.de
#include "apps/linear_ode/linear_ode.hpp"
#include "ad.hpp"
#include "cppNum/differentialSystem/implicitEuler.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  assert(argc==2);
  using BT=double; using T=ad::tangent_t<BT>; using namespace std;
  const int nx=stoi(argv[1]), np=nx*nx;
  assert(nx>=2);
  la::vector_t<T> p=la::vector_t<T>::Zero(np), xs=la::vector_t<T>::Ones(nx), x(nx);
  for(int i=2; i<nx; i++) p(i*nx+i)=-1.-double(i)/nx;
  p(0)=-1.; p(1)=-1.; p(nx)=1.; p(nx+1)=-1.;
  ds::implicitEuler_integrator_t<T> integrator(4.,100,1e-10);
  for (int i=0;i<np;i++) {
    ad::derivative(p(i))=1;
    x=integrator.run(xs,p);
    for (int j=0;j<nx;j++) cout << ad::derivative(x(j)) << ' ' ;
    cout<<endl;
    ad::derivative(p(i))=0;
  }
  for (int i=0;i<nx;i++) {
    ad::derivative(xs(i))=1;
    x=integrator.run(xs,p);
    for (int j=0;j<nx;j++) cout << ad::derivative(x(j)) << ' ';
    cout<<endl;
    ad::derivative(xs(i))=0;
  }
  return 0;
}


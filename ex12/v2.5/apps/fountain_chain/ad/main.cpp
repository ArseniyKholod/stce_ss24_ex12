// info@stce.rwth-aachen.de
#include "apps/fountain_chain/fountain_chain.hpp"
#include "ad.hpp"
#include "cppNum/differentialSystem/implicitEuler.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  assert(argc==2);
  using BT=double; using T=ad::tangent_t<BT>; using namespace std;
  const int nx=stoi(argv[1]), np=2*nx+2;
  assert(nx>=2);
  la::vector_t<T> p=la::vector_t<T>::Zero(np), xs=la::vector_t<T>::Zero(nx), x(nx);
  p(0)=1.;
  p(1)=9.81;
  for(int i=1; i<=nx; i++){
    p(2*i)=10.;
    p(2*i+1)=1.;
  }
  ds::implicitEuler_integrator_t<T> integrator(10.,100,1e-10);
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


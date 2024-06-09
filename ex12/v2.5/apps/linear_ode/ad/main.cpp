// info@stce.rwth-aachen.de
#include "apps/lotkaVolterra/lotkaVolterra.hpp"
#include "ad.hpp"
#include "cppNum/differentialSystem/implicitEuler.hpp"
#include <iostream>

int main() {
  using BT=double; using T=ad::tangent_t<BT>; using namespace std;
  const int np=4, nx=2;
  la::vector_t<T> p(np), xs(nx), x(nx); 
  p(0)=1.1; p(1)=p(2)=0.4; p(3)=0.1; xs(0)=xs(1)=10;
  ds::implicitEuler_integrator_t<T> integrator(100,10000);
  for (int i=0;i<np;i++) {
    ad::derivative(p(i))=1;
    x=integrator.run(xs,p);
    cout << ad::derivative(x(0)) << ' ' << ad::derivative(x(1)) << endl;
    ad::derivative(p(i))=0;
  }
  for (int i=0;i<nx;i++) {
    ad::derivative(xs(i))=1;
    x=integrator.run(xs,p);
    cout << ad::derivative(x(0)) << ' ' << ad::derivative(x(1)) << endl;
    ad::derivative(xs(i))=0;
  }
  return 0;
}  

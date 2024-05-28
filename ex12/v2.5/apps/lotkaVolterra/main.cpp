// info@stce.rwth-aachen.de
#include "lotkaVolterra.hpp"
#include "cppNum/differentialSystem/implicitEuler.hpp"
#include <iostream>

int main() {
  using T=double; using namespace std;
  const int np=4, nx=2;
  la::vector_t<T> p(np), x(nx); 
  p(0)=1.1; p(1)=p(2)=0.4; p(3)=0.1; x(0)=x(1)=10;
  ds::implicitEuler_integrator_t<T> integrator(100,10000,1e-10);
  x=integrator.run(x,p);
  cout << "x=" << x.transpose() << endl;
  return 0;
}  

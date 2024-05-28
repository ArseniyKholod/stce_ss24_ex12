// info@stce.rwth-aachen.de
#include "apps/lotkaVolterra/lotkaVolterra.hpp"
#include "cppNum/differentialSystem/explicitEuler.hpp"

int main() {
  using T=double;
  const int np=4, nx=2;
  la::vector_t<T> p(np), x(nx); 
  p(0)=1.1; p(1)=p(2)=0.4; p(3)=0.1; x(0)=x(1)=10;
  ds::explicitEuler_integrator_t<T> integrator(100,10000,true);
  x=integrator.run(x,p);
  integrator.plot("prey.plt",0);
  integrator.plot("predators.plt",1);
  return 0;
}  

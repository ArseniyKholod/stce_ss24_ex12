// info@stce.rwth-aachen.de
#include "apps/intersection/intersection.hpp"
#include "cppNum/algebraicSystem/newton.hpp"
#include <iostream>

int main() {
  using BT=double;
  using T=ad::tangent_t<BT>;
  using namespace std;
  as::newton_solver_t<T> solver(1e-7);
  const int np=2, nx=2;
  la::vector_t<T> p(np), x(nx); 
  p(0)=1; p(1)=-0.5; x(0)=1; x(1)=1; 
  // algorithmic differentiation
  cout << "x_p^T (ad) =" << endl;
  for (int i=0;i<np;i++) {
    ad::derivative(p(i))=1;
    cout << ad::derivative(solver.run(x,p)(0)) << ' '
         << ad::derivative(solver.run(x,p)(1)) << endl;
    ad::derivative(p(i))=0; 
  }
  // symbolic differentiation (implicit function theorem)
  x=solver.run(x,p);
  cout << "x_p^T (sd) =" << endl
       << derivative_t::dFdx<as::system_t>(x,p).lu().solve(-derivative_t::dFdp<as::system_t>(x,p)).transpose() << endl;
  return 0;
}  

// info@stce.rwth-aachen.de
#include "apps/sphere/sphere.hpp"
#include "cppNum/convexObjective/newton.hpp"
#include "cppNum/linearAlgebra.hpp"
#include "cppNum/derivative.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  using BT=double;
  using namespace std;
  using T=ad::tangent_t<BT>;
  assert(argc==2); int np=stoi(argv[1]), nx=np; 
  la::vector_t<BT> p=la::vector_t<BT>::Random(np); 
{ // algorithmic differentiation 
  la::vector_t<T> p_t(np);
  for (int i=0;i<np;i++) p_t(i)=p(i);
  co::newton_minimizer_t<T> minimizer(1e-7);
  cout << "x_p (ad) =" << endl;
  for (int i=0;i<np;i++) {
    la::vector_t<T> x_t=-4*la::vector_t<T>::Ones(nx); 
    ad::derivative(p_t(i))=1;
    x_t=minimizer.run(x_t,p_t);
    for (int j=0;j<nx;j++) cout << ad::derivative(x_t(j)) << ' ';
    cout << endl;
    ad::derivative(p_t(i))=0;
  }
}  
{ // symbolic differentiation (implicit function theorem)
  la::vector_t<BT> x=-4*la::vector_t<BT>::Ones(nx); 
  co::newton_minimizer_t<BT> minimizer(1e-7);
  x=minimizer.run(x,p);
  cout << "x_p (sd) =" << endl;
  cout << derivative_t::ddfdxx<co::objective_t>(x,p).lu()
            .solve(-derivative_t::ddfdxp<co::objective_t>(x,p)) << endl;
}
  return 0;
}  

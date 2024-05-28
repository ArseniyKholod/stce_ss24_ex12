// info@stce.rwth-aachen.de
#include "apps/sphere/sphere.hpp"
#include "cppNum/convexObjective/gradientDescent.hpp"
#include "cppNum/linearAlgebra.hpp"
#include "cppNum/derivative.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  using T=double;
  using namespace std;
  assert(argc==2);
  int np=std::stoi(argv[1]), nx=np; 
  la::vector_t<T> p=la::vector_t<T>::Random(np); 
  la::vector_t<T> x=la::vector_t<T>::Random(nx); 
  co::gradientdescent_minimizer_t<T> minimizer(1e-7);
  x=minimizer.run(x,p);
  cout << "x=" << x.transpose() << "\nf(x)=" << co::objective_t::f(x,p) << endl
    << "||dfdx||=" << derivative_t::dfdx<co::objective_t>(x,p).norm() << endl
    << "spd(ddfdxx)=" << !(derivative_t::ddfdxx<co::objective_t>(x,p).llt().info()) << endl;
  return 0;
}  

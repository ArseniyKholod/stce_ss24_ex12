// info@stce.rwth-aachen.de
#include "apps/cosh/cosh.hpp"
#include "cppNum/convexObjective/newton.hpp"
#include "cppNum/linearAlgebra.hpp"
#include "cppNum/derivative.hpp"
#include "cppNum/exceptions/cppNum_exception.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  try{
    using T=double;
    using solver=la::lu_solver_t<T>;
    using namespace std;
    assert(argc==2);
    int np=std::stoi(argv[1]), nx=np; 
    la::vector_t<T> p=la::vector_t<T>::Random(np); 
    la::vector_t<T> x=-4*la::vector_t<T>::Ones(nx); 
    co::newton_minimizer_t<T,solver> minimizer(1e-7);
    x=minimizer.run(x,p);
    cout << "x=" << x.transpose() << "\nf(x)=" << co::objective_t::f(x,p) << endl
      << "||dfdx||=" << derivative_t::dfdx<co::objective_t>(x,p).norm() << endl
      << "spd(ddfdxx)=" << !(derivative_t::ddfdxx<co::objective_t>(x,p).llt().info()) << endl;
  }
  catch(const cppNum_exception & e){
    std::cerr<<e.what()<<std::endl;
  }
  catch(...){
    std::cerr<<"Unknown exception"<<std::endl;
  }
  return 0;
}  

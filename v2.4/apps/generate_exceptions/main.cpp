// info@stce.rwth-aachen.de
#include "apps/generate_exceptions/f.hpp"
#include "cppNum/convexObjective/newton.hpp"
#include "cppNum/linearAlgebra.hpp"
#include "cppNum/derivative.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  using T=double;
  using lu_solver=la::lu_solver_t<T>;
  using llt_solver=la::llt_solver_t<T>;
  using namespace std;
  assert(argc==2);
  switch(std::stoi(argv[1])){
  case 1://matrix and vector with different number of rows
  {
    int nb=4, n=3, m=3; 
    la::vector_t<T> b(nb);
    b << 1.,2.,3.,4.; 
    la::matrix_t<T> A(n, m);
    A << 1.,2.,3.,4.,5.,6.,7.,8.,9.;
    lu_solver::run(A,b); 
  }
    break;
  case 2://matrix and vector with different number of rows
  {
    int nb=4, n=3, m=3;
    la::vector_t<T> b(nb);
    b << 1.,2.,3.,4.;
    la::matrix_t<T> A(n, m);
    A << 1.,2.,3.,4.,5.,6.,7.,8.,9.;
    llt_solver::run(A,b);
  }
    break;
  case 3://matrix is not square
  {
    int nb=3, n=2, m=3;
    la::vector_t<T> b(nb);
    b << 1.,2.,3.;
    la::matrix_t<T> A(n, m);
    A << 1.,2.,3.,4.,5.,6.;
    lu_solver::run(A,b);
  }
    break;
  case 4://matrix is not square
  {
    int nb=3, n=2, m=3;
    la::vector_t<T> b(nb);
    b << 1.,2.,3.;
    la::matrix_t<T> A(n, m);
    A << 1.,2.,3.,4.,5.,6.;
    llt_solver::run(A,b);
  }
    break;
  case 5://singular matrix
  {
    int nb=2, n=2, m=2;
    la::vector_t<T> b(nb);
    b << 1.,2.;
    la::matrix_t<T> A(n, m);
    A << 2.,1.,2.,1.;
    std::cout<<lu_solver::run(A,b)<<std::endl;
  }
    break;
  case 6://singular matrix
  {
    int nb=2, n=2, m=2;
    la::vector_t<T> b(nb);
    b << 1.,2.;
    la::matrix_t<T> A(n, m);
    A << 2.,1.,2.,1.;
    llt_solver::run(A,b);
  }
    break;
  case 7://matrix is not spd
  {
    int nb=2, n=2, m=2;
    la::vector_t<T> b(nb);
    b << 1.,2.;
    la::matrix_t<T> A(n, m);
    A << 1.,0.,0.,-1.;
    llt_solver::run(A,b);
  }
    break;
  case 8://matrix is not spd
  {
    int nb=2, n=2, m=2;
    la::vector_t<T> b(nb);
    b << 1.,2.;
    la::matrix_t<T> A(n, m);
    A << 0.,-1.,1.,2.;
    llt_solver::run(A,b);
  }
    break;
  case 9://state outside range
  {
    int np=4, nx=4;
    la::vector_t<T> p=la::vector_t<T>::Random(np);
    la::vector_t<T> x=-4*la::vector_t<T>::Ones(nx);
    co::newton_minimizer_t<T> minimizer(1e-7,true);
    x=minimizer.run(x,p);
    minimizer.plot("steps.plt",0,5);
  }
    break;
  case 10://state outside range
  {
    int np=4, nx=4;
    la::vector_t<T> p=la::vector_t<T>::Random(np);
  la::vector_t<T> x=-4*la::vector_t<T>::Ones(nx);
  co::newton_minimizer_t<T> minimizer(1e-7,true);
  x=minimizer.run(x,p);
  minimizer.plot("steps.plt",5);
  }
    break;
  default:
    break;
  }
  return 0;
}  

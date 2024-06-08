// info@stce.rwth-aachen.de
#include "apps/generate_exceptions/f.hpp"
#include "cppNum/convexObjective/newton.hpp"
#include "cppNum/linearAlgebra.hpp"
#include "cppNum/derivative.hpp"
#include "cppNum/exceptions/cppNum_exception.hpp"
#include <iostream>

int main() {
  using T=double;
  using lu_solver=la::lu_solver_t<T>;
  using llt_solver=la::llt_solver_t<T>;
  using namespace std;
  //matrix and vector with different number of rows
  try{
    int nb=4, n=3, m=3; 
    la::vector_t<T> b(nb);
    b << 1.,2.,3.,4.; 
    la::matrix_t<T> A(n, m);
    A << 1.,2.,3.,4.,5.,6.,7.,8.,9.;
    lu_solver::run(A,b); 
  }
  catch(cppNum_exception & e){
    std::cerr<<e.what()<<std::endl;
  }
  catch(...){
    std::cerr<<"Unknown exception"<<std::endl;
  }
  try{
    int nb=4, n=3, m=3;
    la::vector_t<T> b(nb);
    b << 1.,2.,3.,4.;
    la::matrix_t<T> A(n, m);
    A << 1.,2.,3.,4.,5.,6.,7.,8.,9.;
    llt_solver::run(A,b);
  }
  catch(cppNum_exception & e){
    std::cerr<<e.what()<<std::endl;
  }
  catch(...){
    std::cerr<<"Unknown exception"<<std::endl;
  }
  //matrix is not square
  try{
    int nb=3, n=2, m=3;
    la::vector_t<T> b(nb);
    b << 1.,2.,3.;
    la::matrix_t<T> A(n, m);
    A << 1.,2.,3.,4.,5.,6.;
    lu_solver::run(A,b);
  }
  catch(cppNum_exception & e){
    std::cerr<<e.what()<<std::endl;
  }
  catch(...){
    std::cerr<<"Unknown exception"<<std::endl;
  }
  try{
    int nb=3, n=2, m=3;
    la::vector_t<T> b(nb);
    b << 1.,2.,3.;
    la::matrix_t<T> A(n, m);
    A << 1.,2.,3.,4.,5.,6.;
    llt_solver::run(A,b);
  }
  catch(cppNum_exception & e){
    std::cerr<<e.what()<<std::endl;
  }
  catch(...){
    std::cerr<<"Unknown exception"<<std::endl;
  }
  //singular matrix
  try{
    int nb=2, n=2, m=2;
    la::vector_t<T> b(nb);
    b << 1.,2.;
    la::matrix_t<T> A(n, m);
    A << 2.,1.,2.,1.;
    lu_solver::run(A,b);
  }
  catch(cppNum_exception & e){
    std::cerr<<e.what()<<std::endl;
  }
  catch(...){
    std::cerr<<"Unknown exception"<<std::endl;
  }
  try{
    int nb=2, n=2, m=2;
    la::vector_t<T> b(nb);
    b << 1.,2.;
    la::matrix_t<T> A(n, m);
    A << 2.,1.,2.,1.;
    llt_solver::run(A,b);
  }
  catch(cppNum_exception & e){
    std::cerr<<e.what()<<std::endl;
  }
  catch(...){
    std::cerr<<"Unknown exception"<<std::endl;
  }
  //matrix is not spd
  try{
    int nb=2, n=2, m=2;
    la::vector_t<T> b(nb);
    b << 1.,2.;
    la::matrix_t<T> A(n, m);
    A << 1.,0.,0.,-1.;
    llt_solver::run(A,b);
  }
  catch(cppNum_exception & e){
    std::cerr<<e.what()<<std::endl;
  }
  catch(...){
    std::cerr<<"Unknown exception"<<std::endl;
  }
  try{
    int nb=2, n=2, m=2;
    la::vector_t<T> b(nb);
    b << 1.,2.;
    la::matrix_t<T> A(n, m);
    A << 0.,-1.,1.,2.;
    llt_solver::run(A,b);
  }
  catch(cppNum_exception & e){
    std::cerr<<e.what()<<std::endl;
  }
  catch(...){
    std::cerr<<"Unknown exception"<<std::endl;
  }
  //state outside range
  try{
    int np=4, nx=4;
    la::vector_t<T> p=la::vector_t<T>::Random(np);
    la::vector_t<T> x=-4*la::vector_t<T>::Ones(nx);
    co::newton_minimizer_t<T> minimizer(1e-7,true);
    x=minimizer.run(x,p);
    minimizer.plot("steps.plt",0,5);
  }
  catch(cppNum_exception & e){
    std::cerr<<e.what()<<std::endl;
  }
  catch(...){
    std::cerr<<"Unknown exception"<<std::endl;
  }
  try{
    int np=4, nx=4;
    la::vector_t<T> p=la::vector_t<T>::Random(np);
    la::vector_t<T> x=-4*la::vector_t<T>::Ones(nx);
    co::newton_minimizer_t<T> minimizer(1e-7,true);
    x=minimizer.run(x,p);
    minimizer.plot("steps.plt",5);
  }
  catch(cppNum_exception & e){
    std::cerr<<e.what()<<std::endl;
  }
  catch(...){
    std::cerr<<"Unknown exception"<<std::endl;
  }

  return 0;
}  

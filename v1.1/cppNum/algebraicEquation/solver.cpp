#include "equation.hpp"
#include <fstream>

namespace ae {

  template<typename T>
  solver_t<T>::solver_t(const T& accuracy, bool trace) : approximation_t<T>(accuracy,trace) {}
  
  template<typename T>
  void solver_t<T>::plot(const std::string& filename) const {
    std::ofstream ofs(filename);
    for (const auto& state : _states)
      ofs << state << " 0\n" << state << ' ' << equation_t::f(state,_parameter) << std::endl;
    ofs.close();
  }

}

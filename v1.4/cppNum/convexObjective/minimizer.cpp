#include "objective.hpp"
#include <fstream>

namespace co {

  // constructor sets accuracy
  template<typename T>
  minimizer_t<T>::minimizer_t(const T& accuracy, bool trace) : approximation_t<T>(accuracy, trace) {}

  // writes record of iterations performed by minimizer to file with given name
  template<typename T>
  void minimizer_t<T>::plot(const std::string& filename) const {
    std::ofstream ofs(filename);
    for (const auto& state : _states)
      ofs << state << ' ' << objective_t::f(state,_parameter) << std::endl;
    ofs.close();
  }

}

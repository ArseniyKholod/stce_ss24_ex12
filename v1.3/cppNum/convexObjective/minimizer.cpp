#include "objective.hpp"
#include <fstream>

namespace co {

  template<typename T>
  minimizer_t<T>::minimizer_t(const T& accuracy, bool trace) : approximation_t<T>(accuracy), _trace(trace) {}

  template<typename T>
  void minimizer_t<T>::plot(const std::string& filename) const {
    std::ofstream ofs(filename);
    for (const auto& state : _states)
      ofs << state << ' ' << objective_t::f(state,_parameter) << std::endl;
    ofs.close();
  }

}

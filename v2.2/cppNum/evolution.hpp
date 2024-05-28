// info@stce.rwth-aachen.de
#pragma once

#include "iteration.hpp"

template<typename T>
class evolution_t : public iteration_t<T> {
  protected:
    using iteration_t<T>::_states;
    std::vector<T> _times;
    bool _trace;
  public:
    evolution_t(bool trace);
    void plot(const std::string& filename, int i) const;
};

#include <fstream>

template<typename T>
evolution_t<T>::evolution_t(bool trace) : _trace(trace) {}

template<typename T>
void evolution_t<T>::plot(const std::string& filename, int i) const {
  std::ofstream ofs(filename);
  assert(_states.size()==_times.size());
  for (size_t k=0; k<_times.size(); ++k)
    ofs << _times[k] << ' ' << _states[k](i) << std::endl;
}

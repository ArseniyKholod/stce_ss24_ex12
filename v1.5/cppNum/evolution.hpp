// info@stce.rwth-aachen.de
#pragma once
#include "iteration.hpp"
#include <vector>

template<typename T>
class evolution_t : public iteration_t<T> {
  protected:
    using iteration_t<T>::_states;
    std::vector<T> _times;
  public:
    void plot(const std::string&) const;
};

#include <fstream>
#include <cassert>

template<typename T>
void evolution_t<T>::plot(const std::string& fname) const {
  std::ofstream ofs(fname);
  assert(_states.size()==_times.size());
  for (size_t k=0; k<_times.size(); ++k)
    ofs << _times[k] << ' ' << _states[k] << std::endl;
}

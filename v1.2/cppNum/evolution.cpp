#include <fstream>
#include <cassert>

template<typename T>
evolution_t<T>::evolution_t(bool trace) : _trace(trace) {}

template<typename T>
void evolution_t<T>::plot(const std::string& filename) const {
  std::ofstream ofs(filename);
  assert(_states.size()==_times.size());
  for (size_t k=0; k<_times.size(); ++k) 
    ofs << _times[k] << ' ' << _states[k] << std::endl;
  ofs.close();
}

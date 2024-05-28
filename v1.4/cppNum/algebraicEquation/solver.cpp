#include <fstream>

namespace ae {

  template<typename T, typename EQUATION_T>
  solver_t<T,EQUATION_T>::solver_t(const T& accuracy, bool trace) 
    : approximation_t<T>(accuracy, trace) {}
 
  template<typename T, typename EQUATION_T>
  const std::vector<T>& solver_t<T,EQUATION_T>::get_states() const { return _states; }
  
  template<typename T, typename EQUATION_T>
  void solver_t<T,EQUATION_T>::plot(const std::string& filename) const {
    std::ofstream ofs(filename);
    for (const auto& state : _states)
      ofs << state << " 0\n" << state << ' ' 
          << EQUATION_T::f(state,_parameter) << std::endl;
    ofs.close();
  }

}

#include <fstream>

namespace ae {

  template<typename T, typename DATA_T, typename EQUATION_T>
  solver_t<T,DATA_T,EQUATION_T>::solver_t(const T& accuracy, bool trace, const DATA_T* const data_p) 
    : approximation_t<T>(accuracy), _trace(trace), _data_p(data_p) {}
  
  template<typename T, typename DATA_T, typename EQUATION_T>
  void solver_t<T,DATA_T,EQUATION_T>::plot(const std::string& fname) const {
    std::ofstream ofs(fname);
    for (const auto& state : _states)
      ofs << state << " 0\n" << state << ' ' 
          << EQUATION_T::f(state,_parameter,_data_p) << std::endl;
    ofs.close();
  }

}

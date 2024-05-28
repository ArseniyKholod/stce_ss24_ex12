namespace de {

  template<typename T>
  integrator_t<T>::integrator_t(const T& t_end, int number_of_steps, bool trace) 
    : evolution_t<T>(trace), _t_end(t_end), _number_of_steps(number_of_steps) {}

}

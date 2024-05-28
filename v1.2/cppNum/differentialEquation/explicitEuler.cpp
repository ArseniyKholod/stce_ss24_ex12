namespace de {

  template<typename T>
  explicitEuler_integrator_t<T>::explicitEuler_integrator_t(const T& t_end, int number_of_steps, bool trace) : integrator_t<T>(t_end,number_of_steps,trace) {}

  template<typename T>
  T explicitEuler_integrator_t<T>::run(T x, const T& p) {
    T t=0, dt=_t_end/_number_of_steps;
    if (_trace) { _states.push_back(x); _times.push_back(t); } 
    for (int i=0;i<_number_of_steps;++i) { 
      t+=dt;
      x+=dt*equation_t::g(x,p); 
      if (_trace) { _states.push_back(x); _times.push_back(t); }
    } 
    return x;
  }

}

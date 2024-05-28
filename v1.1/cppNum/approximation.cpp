template<typename T>
approximation_t<T>::approximation_t(const T& accuracy, bool trace) : iteration_t<T>(trace), _accuracy(accuracy) {}

/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#pragma once

#include "dco_configuration.hpp"

namespace dco {

struct dco_global_logging {

  static std::string id() { return "global"; }
};

inline std::string get_current_time();

enum log_level_enum {
  logDISABLED = -1,
  logERROR,
  logWARNING,
  logINFO,
  logDEBUG,
  logDEBUG1,
  logDEBUG2,
  logDEBUG3,
  logDEBUG4
};

template <typename log_env> class logging {
  log_level_enum _level;
  std::string _file;
  int _line;

public:
  DCO_ALWAYS_INLINE logging(log_level_enum level = logERROR, std::string file = "", int line = -1)
      : _level(level), _file(file), _line(line) {}

  DCO_ALWAYS_INLINE ~logging() {
    if (_line == -1)
      os << std::endl;
    else
      os << " : " << _file << ":" << _line << std::endl;

    if (DCO_LOG_MAX_LEVEL >= 0 && _level <= DCO_LOG_MAX_LEVEL && _level <= level() && stream()) {
      output(os.str());
    }
  }

  DCO_ALWAYS_INLINE std::ostringstream& get_stream() {
    os << "dco/c++ [" << log_env::id() << "] - " << get_current_time();
    os << " " << std::setw(7) << to_string(_level) << ": ";
    os << std::string(_level > logINFO ? _level - logINFO : 0, '\t');
    return os;
  }

public:
  static inline log_level_enum& level() {
    static log_level_enum reporting_level = static_cast<log_level_enum>(DCO_LOG_MAX_LEVEL);
    return reporting_level;
  }

  static inline std::string to_string(log_level_enum level) {
    static const char* const buffer[] = {"ERROR", "WARNING", "INFO", "DEBUG", "DEBUG1", "DEBUG2", "DEBUG3", "DEBUG4"};
    return buffer[level];
  }

  static inline log_level_enum from_string(const std::string& level) {
    if (level == "DEBUG4")
      return logDEBUG4;
    if (level == "DEBUG3")
      return logDEBUG3;
    if (level == "DEBUG2")
      return logDEBUG2;
    if (level == "DEBUG1")
      return logDEBUG1;
    if (level == "DEBUG")
      return logDEBUG;
    if (level == "INFO")
      return logINFO;
    if (level == "WARNING")
      return logWARNING;
    if (level == "ERROR")
      return logERROR;
    logging(logWARNING).get_stream() << "Unknown logging level '" << level << "'. Using INFO level as default.";
    return logINFO;
  }

  static inline FILE*& stream() {
    static FILE* pStream = stderr;
    return pStream;
  }

protected:
  std::ostringstream os;

private:
  logging(const logging&);
  logging& operator=(const logging&);

  static inline void output(const std::string& msg) {
    FILE* pStream = stream();
    if (!pStream)
      return;
    fprintf(pStream, "%s", msg.c_str());
    fflush(pStream);
  }
};

typedef logging<dco_global_logging> logger;

#define DCO_LOGL(level)                                                                                                \
  if (level > DCO_LOG_MAX_LEVEL) {                                                                                     \
  } else                                                                                                               \
    dco::logger(level, __FILE__, __LINE__).get_stream()
#define DCO_LOG(level)                                                                                                 \
  if (level > DCO_LOG_MAX_LEVEL) {                                                                                     \
  } else                                                                                                               \
    dco::logger(level).get_stream()

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
inline std::string get_current_time() {
  const size_t SIZE = 50;

  time_t ltime;
  time(&ltime);

  wchar_t wchar_result[SIZE];
  _wctime_s(wchar_result, SIZE, &ltime);

  std::wstring wstring_result(wchar_result);
  std::string result;
  for (std::wstring::iterator it = wstring_result.begin(); it != wstring_result.end(); ++it) {
    result += static_cast<char>(*it);
  }
  result.erase(std::remove(result.begin(), result.end(), '\n'), result.end());

  return result;
}
#else
inline std::string get_current_time() {
  char buffer[11];
  time_t t;
  time(&t);
  tm r;
  strftime(buffer, sizeof(buffer), "%X", localtime_r(&t, &r));
  struct timeval tv;
  gettimeofday(&tv, 0);
  char result[100] = {0};
  std::sprintf(result, "%s.%03ld", buffer, static_cast<long>(tv.tv_usec) / 1000);
  return result;
}
#endif

struct object_logger {
  const std::string _name;
  object_logger(std::string name) : _name(name) { DCO_LOG(logINFO) << "Creating " << _name; }
  ~object_logger() { DCO_LOG(logINFO) << "Removing " << _name; }
};

} // namespace dco

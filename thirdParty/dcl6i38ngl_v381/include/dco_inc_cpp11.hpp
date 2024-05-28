/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

namespace dco {
typedef index_t_DEFINE index_t;
typedef index_t DCO_TAPE_INT;
inline index_t& stce_9752(index_t& stce_9753) { return stce_9753; }
inline const index_t& stce_9752(const index_t& stce_9753) { return stce_9753; }
typedef index_t_DEFINE DCO_INTEGRAL_TAPE_INT;
static const bool stce_9754 = true;
static const bool HAS_TAPE_ACTIVITY_CHECK = true;
static const bool stce_9755 = true;
static const bool stce_9756 = false;
static const bool stce_9757 = true;
template <class stce_9758, class stce_9759 = stce_9758, class stce_9760 = stce_9758> struct types_config_t {
  typedef stce_9758 value_t;
  typedef stce_9759 stce_9761;
  typedef stce_9760 stce_9762;
};
} // namespace dco

namespace dco {
typedef unsigned long mem_long_t;
inline size_t get_allocation_size(size_t stce_9763);
struct memory_model {
  enum TYPE { stce_9764, BLOB_TAPE, BLOB_TAPE_SPLINT, CHUNK_TAPE, stce_9765, stce_9766, stce_9767, stce_9768 };
};
namespace internal {
template <class stce_9769, class stce_9770> struct active_type;
template <class stce_9769, class DATA_TYPE> struct stce_9771;
template <class stce_9769, class stce_9772, class stce_9773, typename = void> struct stce_9774;
template <class stce_9769, class stce_9775, class stce_9776, class stce_9773, typename = void> struct stce_9777;
template <class stce_9769, class stce_9775, class stce_9776, class stce_9773, typename = void> struct stce_9778;
template <class stce_9769, class stce_9775, class stce_9776, class stce_9773, typename = void> struct stce_9779;
template <typename stce_9780, typename enable_if = void> struct trait_value;
template <typename stce_9780, typename stce_9781 = void, typename enable_if = void> struct stce_9782;
template <typename stce_9780, typename stce_9781 = void, typename enable_if = void> struct stce_9783;
template <typename stce_9780, typename stce_9781 = void, typename enable_if = void> struct stce_9784;
template <typename stce_9780, typename enable_if = void> struct stce_9785;
template <typename stce_9780, typename enable_if = void> struct stce_9786;
template <typename stce_9780, typename enable_if = void> struct stce_9787;
template <enum memory_model::TYPE MEMORY_MODEL, class stce_9788,
          enum memory_model::TYPE stce_9789 = memory_model::stce_9764>
class tape;
template <typename stce_9790, typename stce_9791 = void> struct smart_tape_ptr_t;
template <typename stce_9780> struct stce_9792 {};
template <memory_model::TYPE MEMORY_MODEL, typename stce_9788, memory_model::TYPE stce_9789>
struct stce_9792<tape<MEMORY_MODEL, stce_9788, stce_9789>> {
  typedef typename stce_9788::stce_9761 type;
};
template <class stce_9793, typename stce_9794> class adjoint_vector_lazy;
template <class stce_9795> struct jacobian_preaccumulator_t;
} // namespace internal
template <typename stce_9780> struct mode;
enum stce_9796 { stce_9797, stce_9798, stce_9799, stce_9800, stce_9801, stce_9802, stce_9803, stce_9804 };
template <typename stce_9780> typename internal::stce_9786<stce_9780>::stce_9805 tape(const stce_9780&);
template <typename stce_9769> struct stce_9806 {
  typedef stce_9769 active_value_t;
  typedef stce_9769 value_t;
  typedef value_t scalar_value_t;
  typedef stce_9769 passive_t;
  typedef stce_9769 scalar_passive_t;
  static const int order = 0;
};
struct stce_9807 {
  using stce_9762 = double;
};
namespace vector_ns {
template <typename stce_9808, size_t stce_9809> struct alignas(alignof(stce_9808[stce_9809])) vector_t;
}
namespace folding {
template <typename stce_9780, typename enable_if = void> struct is_zero_trait;
template <typename stce_9780> bool is_zero(const stce_9780& stce_9810);
} // namespace folding
} // namespace dco

extern "C" {
extern int stce_1000002(int stce_9811 = false);
extern void* stce_1000001(size_t* stce_9812, int);
extern void* stce_999999(size_t, int);
extern DCO_INT32 stce_1000003(DCO_INT32* stce_9813);
extern DCO_INT64 stce_1000004(DCO_INT64* stce_9813);
extern void stce_1000000(void* stce_9814);
}
template <typename stce_9780> inline stce_9780 stce_9815(stce_9780& stce_9813);
template <> inline DCO_INT32 stce_9815<DCO_INT32>(DCO_INT32& stce_9813) { return stce_1000003(&stce_9813); }
template <> inline DCO_INT64 stce_9815<DCO_INT64>(DCO_INT64& stce_9813) { return stce_1000004(&stce_9813); }

namespace dco {
class exception {
public:
  template <typename stce_9816>
  static stce_9816 create(std::string stce_9817, std::string stce_9818 = "", int stce_9819 = 0) {
    std::stringstream stce_9820;
    stce_9820 << "--- dco/c++ --- " << stce_9817;
    if (stce_9818 != "")
      stce_9820 << " --- " << stce_9818 << ":" << stce_9819 << ".";
    DCO_LOG(dco::logERROR) << "EXCEPTION thrown: " << stce_9820.str();
    return stce_9816(stce_9820.str());
  }
  template <typename stce_9816>
  static stce_9816 stce_9821(std::string stce_9817, std::string stce_9818 = "", int stce_9819 = 0) {
    std::stringstream stce_9820;
    stce_9820 << "--- dco/c++ --- " << stce_9817;
    if (stce_9818 != "")
      stce_9820 << " --- " << stce_9818 << ":" << stce_9819 << ".";
    DCO_LOG(dco::logERROR) << "EXCEPTION thrown: " << stce_9820.str();
    return stce_9816();
  }
};
} // namespace dco
namespace dco {
template <memory_model::TYPE MEMORY_MODEL, class stce_9788, memory_model::TYPE stce_9789>
bool is_null(internal::tape<MEMORY_MODEL, stce_9788, stce_9789>* tape) {
  return (tape == NULL);
}
static unsigned int stce_9822 = 0xABCDE;
static unsigned int stce_9823(unsigned int* stce_9824, unsigned int stce_9825) {
  unsigned int stce_9826;
  stce_9826 = *stce_9824 & 1;
  *stce_9824 >>= 1;
  if (stce_9826 == 1)
    *stce_9824 = stce_9825;
  return *stce_9824;
}
static inline double stce_9827() {
  stce_9823(&stce_9822, 0xB4BCD35C);
  unsigned int stce_9828 = stce_9823(&stce_9822, 0xB4BCD35C);
  return double(stce_9828) / RAND_MAX;
}
template <class stce_9780> std::string type_name() {
  typedef typename std::remove_reference<stce_9780>::type stce_9829;
  std::unique_ptr<char, void (*)(void*)> stce_9830(
      abi::__cxa_demangle(typeid(stce_9829).name(), nullptr, nullptr, nullptr), std::free);
  std::string stce_9831 = stce_9830 != nullptr ? stce_9830.get() : typeid(stce_9829).name();
  if (std::is_const<stce_9829>::value)
    stce_9831 += " const";
  if (std::is_volatile<stce_9829>::value)
    stce_9831 += " volatile";
  if (std::is_lvalue_reference<stce_9780>::value)
    stce_9831 += "&";
  else if (std::is_rvalue_reference<stce_9780>::value)
    stce_9831 += "&&";
  return stce_9831;
}
namespace internal {
template <typename stce_9780, bool> struct stce_9832 {
  typedef stce_9780 type;
};
template <typename stce_9780> struct stce_9832<stce_9780, true> {
  typedef stce_9780& type;
};
} // namespace internal
namespace helper {
template <typename> struct stce_9833 {
  static constexpr bool value = false;
};
template <typename stce_9834, typename... stce_9835> void stce_9836(int64_t, stce_9834&&, stce_9835&&...) {
  static_assert(stce_9833<stce_9834>::value, "--- dco/c++ --- The user-supplied callable provided as an argument to "
                                             "interpret_adjoint*() has wrong interface.");
}
template <typename stce_9834, typename... stce_9835>
auto stce_9836(int, stce_9834&& stce_9837, stce_9835&&... stce_9838)
    -> decltype(stce_9837(std::forward<stce_9835>(stce_9838)...)) {
  stce_9837(stce_9838...);
}
static bool stce_9839 = true;
template <typename stce_9780> struct stce_9840 {
  static const bool stce_9753 = true;
};
template <typename stce_9780> struct type_identity {
  typedef stce_9780 type;
};
template <class stce_9841, const size_t stce_9842 = 1> struct valvec {
  static const size_t stce_9843 = stce_9842;
  typedef stce_9841 value_t;
  stce_9841 stce_9844[stce_9842];
  void stce_9845(const stce_9841& stce_9846) {
    for (size_t stce_9847 = 0; stce_9847 < stce_9842; ++stce_9847)
      stce_9844[stce_9847] = stce_9846;
  }
  template <typename stce_9780>
  valvec(const stce_9780& stce_9810, typename std::enable_if<std::is_fundamental<stce_9780>::value, int>::type = 0) {
    stce_9845(stce_9810);
  }
  template <typename stce_9780 = stce_9841>
  valvec(const stce_9841& stce_9810, typename std::enable_if<!std::is_fundamental<stce_9780>::value, int>::type = 0) {
    stce_9845(stce_9810);
  }
  valvec() { stce_9845(0); }
  stce_9841& operator[](const size_t stce_9813) { return stce_9844[stce_9813]; }
  const stce_9841& operator[](const size_t stce_9813) const { return stce_9844[stce_9813]; }
  valvec& operator=(const std::array<stce_9841, stce_9842>& stce_9848) {
    for (size_t stce_9847 = 0; stce_9847 < stce_9842; ++stce_9847)
      stce_9844[stce_9847] = stce_9848[stce_9847];
    return *this;
  }
  valvec& operator=(const std::vector<stce_9841>& stce_9848) {
    if (stce_9848.size() != stce_9842) {
      throw exception::create<std::runtime_error>("Assignment from std::vector not possible, non-matching sizes.",
                                                  "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/"
                                                  "dco_cpp_make_release/dco_cpp_dev/src/dco_helper.hpp",
                                                  151);
    }
    for (size_t stce_9847 = 0; stce_9847 < stce_9842; ++stce_9847)
      stce_9844[stce_9847] = stce_9848[stce_9847];
    return *this;
  }
  template <typename stce_9780>
  typename std::enable_if<std::is_fundamental<stce_9780>::value, valvec>::type& operator=(const stce_9780& stce_9848) {
    for (size_t stce_9847 = 0; stce_9847 < stce_9842; ++stce_9847)
      stce_9844[stce_9847] = stce_9848;
    return *this;
  }
  template <typename stce_9780 = stce_9841>
  typename std::enable_if<!std::is_fundamental<stce_9780>::value, valvec>::type& operator=(const stce_9841& stce_9848) {
    for (size_t stce_9847 = 0; stce_9847 < stce_9842; ++stce_9847)
      stce_9844[stce_9847] = stce_9848;
    return *this;
  }
  valvec& operator+=(const valvec& stce_9848) {
    for (size_t stce_9847 = 0; stce_9847 < stce_9842; ++stce_9847)
      stce_9844[stce_9847] += stce_9848.stce_9844[stce_9847];
    return *this;
  }
  valvec& operator+=(const std::array<stce_9841, stce_9842>& stce_9848) {
    for (size_t stce_9847 = 0; stce_9847 < stce_9842; ++stce_9847)
      stce_9844[stce_9847] += stce_9848[stce_9847];
    return *this;
  }
  valvec& operator+=(const std::vector<stce_9841>& stce_9848) {
    if (stce_9848.size() != stce_9842) {
      throw exception::create<std::runtime_error>("Increment with std::vector not possible, non-matching sizes.",
                                                  "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/"
                                                  "dco_cpp_make_release/dco_cpp_dev/src/dco_helper.hpp",
                                                  180);
    }
    for (size_t stce_9847 = 0; stce_9847 < stce_9842; ++stce_9847)
      stce_9844[stce_9847] += stce_9848[stce_9847];
    return *this;
  }
  operator std::array<stce_9841, stce_9842>() {
    std::array<stce_9841, stce_9842> stce_9849;
    for (size_t stce_9847 = 0; stce_9847 < stce_9842; ++stce_9847)
      stce_9849[stce_9847] = stce_9844[stce_9847];
    return stce_9849;
  }
  operator std::vector<stce_9841>() {
    std::vector<stce_9841> stce_9849(stce_9842);
    for (size_t stce_9847 = 0; stce_9847 < stce_9842; ++stce_9847)
      stce_9849[stce_9847] = stce_9844[stce_9847];
    return stce_9849;
  }
};
template <typename stce_9841, typename stce_9850, const size_t stce_9842>
bool operator==(valvec<stce_9841, stce_9842> const& stce_9851, valvec<stce_9850, stce_9842> const& stce_9852) {
  for (size_t stce_9847 = 0; stce_9847 < stce_9842; ++stce_9847) {
    if (stce_9851[stce_9847] != stce_9852[stce_9847]) {
      return false;
    }
  }
  return true;
}
template <typename stce_9841, typename stce_9850, const size_t stce_9842>
bool operator==(valvec<stce_9841, stce_9842> const& stce_9851, stce_9850 const& stce_9852) {
  for (size_t stce_9847 = 0; stce_9847 < stce_9842; ++stce_9847) {
    if (stce_9851[stce_9847] != stce_9852) {
      return false;
    }
  }
  return true;
}
template <class stce_9780> struct vecsize_info {
  static const size_t vecsize;
  typedef stce_9780 stce_9853;
};
template <class stce_9780> const size_t vecsize_info<stce_9780>::vecsize = 1;
template <class stce_9841, size_t stce_9842> struct vecsize_info<valvec<stce_9841, stce_9842>> {
  static const size_t vecsize;
  typedef stce_9841 stce_9853;
};
template <class stce_9841, size_t stce_9842>
const size_t vecsize_info<valvec<stce_9841, stce_9842>>::vecsize = stce_9842;
template <class stce_9841, size_t stce_9842>
static inline valvec<stce_9841, stce_9842> operator+(const valvec<stce_9841, stce_9842>& stce_9854,
                                                     const valvec<stce_9841, stce_9842>& stce_9855) {
  valvec<stce_9841, stce_9842> stce_9849;
  for (size_t stce_9847 = 0; stce_9847 < stce_9842; ++stce_9847)
    stce_9849.stce_9844[stce_9847] = stce_9854.stce_9844[stce_9847] + stce_9855.stce_9844[stce_9847];
  return stce_9849;
}
template <class stce_9841, size_t stce_9842>
static inline valvec<stce_9841, stce_9842> operator*(const valvec<stce_9841, stce_9842>& stce_9854,
                                                     const valvec<stce_9841, stce_9842>& stce_9855) {
  valvec<stce_9841, stce_9842> stce_9849;
  for (size_t stce_9847 = 0; stce_9847 < stce_9842; ++stce_9847)
    stce_9849.stce_9844[stce_9847] = stce_9854.stce_9844[stce_9847] * stce_9855.stce_9844[stce_9847];
  return stce_9849;
}
template <class stce_9841, class stce_9850, size_t stce_9842>
static inline valvec<stce_9841, stce_9842> operator*(const stce_9850& stce_9856,
                                                     const valvec<stce_9841, stce_9842>& stce_9857) {
  valvec<stce_9841, stce_9842> stce_9849;
  for (size_t stce_9847 = 0; stce_9847 < stce_9842; ++stce_9847)
    stce_9849.stce_9844[stce_9847] = static_cast<stce_9841>(stce_9857.stce_9844[stce_9847] * stce_9856);
  return stce_9849;
}
template <class stce_9841, class stce_9850, size_t stce_9842>
static inline valvec<stce_9841, stce_9842> operator*(const valvec<stce_9841, stce_9842>& stce_9854,
                                                     const stce_9850& stce_9855) {
  valvec<stce_9841, stce_9842> stce_9849;
  for (size_t stce_9847 = 0; stce_9847 < stce_9842; ++stce_9847)
    stce_9849.stce_9844[stce_9847] = static_cast<stce_9841>(stce_9854.stce_9844[stce_9847] * stce_9855);
  return stce_9849;
}
template <class stce_9841, size_t stce_9842>
static inline std::ostream& operator<<(std::ostream& out, const valvec<stce_9841, stce_9842>& stce_9810) {
  out << "(";
  for (size_t stce_9847 = 0; stce_9847 < stce_9842; ++stce_9847) {
    out << stce_9810.stce_9844[stce_9847];
    if (stce_9847 != stce_9842 - 1) {
      out << ";";
    }
  }
  out << ")";
  return out;
}
} // namespace helper
template <typename TYPE> class stce_9858 {
  const TYPE& stce_9780;

public:
  stce_9858(const TYPE& stce_9859) : stce_9780(stce_9859) {}
  template <typename stce_9860> stce_9860* create() const { return new stce_9860(stce_9780); }
};
template <> class stce_9858<void*> {
public:
  stce_9858(void* stce_9848) { (void)stce_9848; }
  template <typename stce_9860> stce_9860* create() const { return new stce_9860(); }
};
class stce_9861 {
  std::ofstream stce_9862;
  std::string stce_9863;
  std::string stce_9864;
  std::stringstream stce_9865;
  std::stringstream stce_9866;

public:
  stce_9861(const std::string& filename) : stce_9863("digraph {\n"), stce_9864("\n}\n") {
    stce_9865.clear();
    stce_9866.clear();
    stce_9862.open(filename.c_str());
  }
  void stce_9867(std::vector<index_t>& stce_9868, std::vector<index_t>& stce_9869, index_t stce_9870) {
    stce_9865 << stce_9870 + 1 << "[shape=box,label=\"(" << stce_9870 + 1 << ", ext. function)\",color=\"red\"]\n";
    for (std::vector<index_t>::iterator stce_9847 = stce_9868.begin(); stce_9847 != stce_9868.end(); ++stce_9847) {
      stce_9866 << *stce_9847 << " -> " << stce_9870 << "[label=\"unknown"
                << "\",color=\"red\"]\n";
    }
    for (std::vector<index_t>::iterator stce_9847 = stce_9869.begin(); stce_9847 != stce_9869.end(); ++stce_9847) {
      stce_9866 << stce_9870 << " -> " << *stce_9847 << "[label=\"unknown"
                << "\",color=\"red\"]\n";
    }
  }
  void stce_9871(index_t stce_9870) {
    if (stce_9870 == 0) {
      return;
    }
    stce_9865 << stce_9870 << "[shape=box,label=\"" << stce_9870 << "\", color=\"green\"]\n";
  }
  template <typename stce_9872> void stce_9871(index_t stce_9870, stce_9872 adjoint) {
    if (stce_9870 == 0) {
      return;
    }
    stce_9865 << stce_9870 << "[shape=box,label=\"(" << stce_9870 << ", " << adjoint << ")\", color=\"green\"]\n";
  }
  template <typename stce_9872> void stce_9873(index_t stce_9874, index_t stce_9875, stce_9872 stce_9876) {
    if (stce_9874 == 0 || stce_9875 == 0) {
      return;
    }
    stce_9866 << stce_9874 << " -> " << stce_9875 << "[label=\"" << stce_9876 << "\"]\n";
  }
  ~stce_9861() {
    stce_9862 << stce_9863;
    stce_9862 << stce_9865.str();
    stce_9862 << stce_9866.str();
    stce_9862 << stce_9864;
    stce_9862.close();
  }
};
template <bool stce_9877, class stce_9780, class stce_9834> struct stce_9878 {
  typedef stce_9780 type;
};
template <class stce_9780, class stce_9834> struct stce_9878<false, stce_9780, stce_9834> {
  typedef stce_9834 type;
};
template <bool stce_9877, typename stce_9780 = void> struct enable_if {};
template <typename stce_9780> struct enable_if<true, stce_9780> {
  typedef stce_9780 type;
};
template <class stce_9780, class stce_9879> struct is_same {
  static const bool value = false;
};
template <class stce_9780> struct is_same<stce_9780, stce_9780> {
  static const bool value = true;
};
template <typename stce_9780> struct type_identity {
  typedef stce_9780 type;
};
template <class stce_9780> struct remove_const {
  typedef stce_9780 type;
};
template <class stce_9780> struct remove_const<const stce_9780> {
  typedef stce_9780 type;
};
template <class stce_9780> struct remove_const<const stce_9780&> {
  typedef stce_9780& type;
};
template <class stce_9780> struct remove_const<const stce_9780&&> {
  typedef stce_9780&& type;
};
template <class stce_9780> struct stce_9880 {
  typedef stce_9780 type;
};
template <class stce_9780> struct stce_9880<stce_9780&> {
  typedef stce_9780 type;
};
template <class stce_9780> struct stce_9880<const stce_9780&> {
  typedef const stce_9780 type;
};
template <class stce_9780> struct stce_9880<stce_9780&&> {
  typedef stce_9780 type;
};
template <typename stce_9780> struct remove_all {
  typedef stce_9780 type;
};
template <typename stce_9780> struct remove_all<const stce_9780> {
  typedef typename remove_all<stce_9780>::type type;
};
template <typename stce_9780> struct remove_all<stce_9780 const&> {
  typedef typename remove_all<stce_9780>::type type;
};
template <typename stce_9780> struct remove_all<stce_9780&> {
  typedef typename remove_all<stce_9780>::type type;
};
template <typename stce_9780> struct remove_all<stce_9780 const*> {
  typedef typename remove_all<stce_9780>::type type;
};
template <typename stce_9780> struct remove_all<stce_9780*> {
  typedef typename remove_all<stce_9780>::type type;
};
template <typename stce_9780> struct remove_all<stce_9780&&> {
  typedef typename remove_all<stce_9780>::type type;
};
template <typename stce_9780> struct stce_9881 {
  enum { value = false };
};
template <typename stce_9780> struct stce_9881<stce_9780*> {
  enum { value = true };
};
template <typename stce_9882, typename stce_9883> struct stce_9884 {
  static const bool value = (stce_9882::order < stce_9883::order);
};
template <> struct stce_9884<void, void> {
  static const bool value = false;
};
static inline void* alloc(size_t size, bool stce_9885 = false) {
  return stce_999999(size, static_cast<int>(stce_9885));
}
static inline void dealloc(void* stce_9814) { stce_1000000(stce_9814); }
namespace folding {
template <class stce_9841, const size_t stce_9842> struct is_zero_trait<helper::valvec<stce_9841, stce_9842>> {
  static bool get(const helper::valvec<stce_9841, stce_9842>& stce_9810) {
    for (size_t stce_9847 = 0; stce_9847 < stce_9842; ++stce_9847) {
      if (!is_zero(stce_9810[stce_9847])) {
        return false;
      }
    }
    return true;
  }
};
} // namespace folding
} // namespace dco
namespace dco {
template <typename stce_9780, typename stce_9886 = void> struct trait_size_of;
template <typename stce_9780> mem_long_t size_of(const stce_9780& stce_9810) {
  return trait_size_of<stce_9780>::get(stce_9810);
}
template <typename stce_9780> mem_long_t size_of(const stce_9780& stce_9810, int stce_9887) {
  return trait_size_of<stce_9780>::get(stce_9810, stce_9887);
}
template <typename stce_9780, typename stce_9886> struct trait_size_of {
  static mem_long_t get(const stce_9780&) {
    if (helper::stce_9839) {
      throw dco::exception::create<std::runtime_error>(
          "You're trying to compute the size of the checkpoint, but a type (" + type_name<stce_9780>() +
          ") you checkpointed does not have a correct specialization:\n\n" +
          "template <typename T> struct trait_size_of {\n" + "   static mem_long_t get(const T&) { ... }\n" + "};\n\n");
    }
    return 0;
  }
};
template <memory_model::TYPE MEMORY_MODEL, class stce_9788, memory_model::TYPE stce_9789>
struct trait_size_of<dco::internal::tape<MEMORY_MODEL, stce_9788, stce_9789>*> {
  typedef dco::internal::tape<MEMORY_MODEL, stce_9788, stce_9789> tape_t;
  static mem_long_t get(const tape_t* tape, const int stce_9887 = tape_t::stce_9888) {
    return tape->stce_9889(stce_9887);
  }
};
template <typename stce_9790> struct trait_size_of<dco::internal::smart_tape_ptr_t<stce_9790>> {
  static mem_long_t get(dco::internal::smart_tape_ptr_t<stce_9790> const& tape,
                        const int stce_9887 = stce_9790::tape_t::stce_9888) {
    return tape->stce_9889(stce_9887);
  }
};
template <typename stce_9780> struct trait_size_of<std::vector<stce_9780>> {
  static mem_long_t get(const std::vector<stce_9780>& stce_9810) {
    return stce_9810.size() * sizeof(stce_9780) + sizeof(stce_9810);
  }
};
template <> struct trait_size_of<char> {
  static mem_long_t get(const char&) { return sizeof(char); }
};
template <> struct trait_size_of<wchar_t> {
  static mem_long_t get(const wchar_t&) { return sizeof(wchar_t); }
};
template <> struct trait_size_of<signed char> {
  static mem_long_t get(const signed char&) { return sizeof(signed char); }
};
template <> struct trait_size_of<short> {
  static mem_long_t get(const short&) { return sizeof(short); }
};
template <> struct trait_size_of<int> {
  static mem_long_t get(const int&) { return sizeof(int); }
};
template <> struct trait_size_of<long> {
  static mem_long_t get(const long&) { return sizeof(long); }
};
template <> struct trait_size_of<unsigned char> {
  static mem_long_t get(const unsigned char&) { return sizeof(unsigned char); }
};
template <> struct trait_size_of<unsigned short> {
  static mem_long_t get(const unsigned short&) { return sizeof(unsigned short); }
};
template <> struct trait_size_of<unsigned int> {
  static mem_long_t get(const unsigned int&) { return sizeof(unsigned int); }
};
template <> struct trait_size_of<unsigned long> {
  static mem_long_t get(const unsigned long&) { return sizeof(unsigned long); }
};
template <> struct trait_size_of<long long> {
  static mem_long_t get(const long long&) { return sizeof(long long); }
};
template <> struct trait_size_of<unsigned long long> {
  static mem_long_t get(const unsigned long long&) { return sizeof(unsigned long long); }
};
template <> struct trait_size_of<float> {
  static mem_long_t get(const float&) { return sizeof(float); }
};
template <> struct trait_size_of<double> {
  static mem_long_t get(const double&) { return sizeof(double); }
};
template <> struct trait_size_of<long double> {
  static mem_long_t get(const long double&) { return sizeof(long double); }
};
template <> struct trait_size_of<bool> {
  static mem_long_t get(const bool&) { return sizeof(bool); }
};
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_9890> struct stce_9891 {
  typedef stce_9890 type;
  typedef stce_9890& stce_9892;
  typedef const stce_9890 stce_9893;
};
template <typename stce_9780> struct stce_9891<std::vector<stce_9780>> {
  typedef std::vector<stce_9780>& type;
  typedef std::vector<stce_9780>& stce_9892;
  typedef std::vector<stce_9780> const& stce_9893;
};
template <stce_9796 stce_9894, typename stce_9780, typename stce_9895 = void> struct stce_9896 {};
template <typename stce_9780> struct stce_9896<stce_9797, stce_9780> {
  typedef typename dco::mode<stce_9780>::value_t value_t;
  typedef typename trait_value<stce_9780>::stce_9805 stce_9805;
  typedef typename trait_value<stce_9780>::stce_9897 stce_9897;
  stce_9805 get(stce_9780& stce_9810) { return trait_value<stce_9780>::value(stce_9810); };
  stce_9897 get(const stce_9780& stce_9810) const { return trait_value<stce_9780>::value(stce_9810); };
};
template <typename stce_9780> struct stce_9896<stce_9803, stce_9780> {
  typedef typename dco::mode<stce_9780>::passive_t value_t;
  typedef typename stce_9785<stce_9780>::stce_9805 stce_9805;
  typedef typename stce_9785<stce_9780>::stce_9897 stce_9897;
  stce_9805 get(stce_9780& stce_9810) { return stce_9785<stce_9780>::value(stce_9810); };
  stce_9897 get(const stce_9780& stce_9810) const { return stce_9785<stce_9780>::value(stce_9810); };
};
template <typename stce_9780> struct stce_9896<stce_9798, stce_9780> {
  typedef typename dco::mode<stce_9780>::derivative_t value_t;
  typedef typename stce_9782<stce_9780>::stce_9805 stce_9805;
  typedef typename stce_9782<stce_9780>::stce_9805 stce_9897;
  stce_9805 get(const stce_9780& stce_9810) const { return stce_9782<stce_9780>::value(stce_9810); };
};
template <typename stce_9780> struct stce_9896<stce_9804, stce_9780> {
  typedef typename stce_9787<stce_9780>::stce_9805 stce_9805;
  typedef typename stce_9787<stce_9780>::stce_9805 stce_9897;
  typedef typename stce_9880<stce_9805>::type value_t;
  stce_9805 get(const stce_9780& stce_9810) const { return stce_9787<stce_9780>::value(stce_9810); };
};
template <typename stce_9780, typename stce_9895> struct stce_9896<stce_9799, stce_9780, stce_9895> {
  typedef typename dco::mode<stce_9780>::derivative_t value_t;
  typedef typename stce_9782<stce_9780, stce_9895>::stce_9898 stce_9805;
  typedef typename stce_9782<stce_9780, stce_9895>::stce_9898 stce_9897;
  stce_9895* stce_9899;
  stce_9896(stce_9895* adjoints) : stce_9899(adjoints) {}
  auto get(stce_9780& stce_9810) -> decltype(stce_9782<stce_9780, stce_9895>::value(stce_9810, stce_9899)) {
    return stce_9782<stce_9780, stce_9895>::value(stce_9810, stce_9899);
  };
  auto get(const stce_9780& stce_9810) const -> decltype(stce_9782<stce_9780, stce_9895>::value(stce_9810, stce_9899)) {
    return stce_9782<stce_9780, stce_9895>::value(stce_9810, stce_9899);
  };
};
template <stce_9796 stce_9894, class stce_9780, typename stce_9890, typename stce_9781 = void>
struct stce_9900 : stce_9896<stce_9894, stce_9780, stce_9781> {
  typedef typename stce_9891<stce_9890>::type stce_9901;
  typedef typename stce_9891<stce_9890>::stce_9892 stce_9902;
  typedef typename stce_9891<stce_9890>::stce_9893 stce_9903;
  typedef stce_9896<stce_9894, stce_9780, stce_9781> stce_9904;
  typedef typename stce_9904::value_t value_t;
  stce_9901 stce_9905;
  stce_9900(stce_9903 stce_9857) : stce_9905(const_cast<stce_9902>(stce_9857)) {}
  stce_9900(stce_9903 stce_9857, stce_9781* stce_9906)
      : stce_9904(stce_9906), stce_9905(const_cast<stce_9902>(stce_9857)) {}
  stce_9900& operator=(const std::vector<value_t>& stce_9907) {
    for (size_t stce_9847 = 0; stce_9847 < stce_9905.size(); ++stce_9847) {
      stce_9904::get(stce_9905[stce_9847]) = stce_9907[stce_9847];
    }
    return *this;
  }
  stce_9900& operator+=(const std::vector<value_t>& stce_9907) {
    for (size_t stce_9847 = 0; stce_9847 < stce_9905.size(); ++stce_9847) {
      stce_9904::get(stce_9905[stce_9847]) += stce_9907[stce_9847];
    }
    return *this;
  }
  stce_9900& operator=(value_t const& stce_9907) {
    for (size_t stce_9847 = 0; stce_9847 < stce_9905.size(); ++stce_9847) {
      stce_9904::get(stce_9905[stce_9847]) = stce_9907;
    }
    return *this;
  }
  template <typename stce_9758,
            typename = typename std::enable_if<std::is_assignable<stce_9758&, value_t>::value>::type>
  operator std::vector<stce_9758>() const {
    std::vector<stce_9758> stce_9849(stce_9905.size());
    for (size_t stce_9847 = 0; stce_9847 < stce_9905.size(); ++stce_9847) {
      stce_9849[stce_9847] = stce_9904::get(stce_9905[stce_9847]);
    }
    return stce_9849;
  }
  typename stce_9904::stce_9805 operator[](size_t stce_9847) { return stce_9904::get(stce_9905[stce_9847]); }
  typename stce_9904::stce_9897 operator[](size_t stce_9847) const { return stce_9904::get(stce_9905[stce_9847]); }
  size_t size() const { return stce_9905.size(); }
};
} // namespace internal
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_9908> struct stce_9909 : public dco::mode<typename stce_9908::binary_t>::data_t {
  typedef stce_9908 mode_t;
  static const int gbcp_order = mode_t::gbcp_order;
  static const int order = mode_t::order;
  template <class stce_9910> DCO_ALWAYS_INLINE void stce_9911(stce_9910 const&) {}
  void clear() {}
  stce_9909() {}
  stce_9909(stce_9909 const&) : dco::mode<typename stce_9908::binary_t>::data_t() {}
  stce_9909& operator=(stce_9909 const&) { return *this; }
  index_t& _tape_index() const { return static_cast<const typename mode_t::type&>(*this).stce_9912._tape_index(); }
};
} // namespace internal
} // namespace dco
namespace dco {
template <typename stce_9780, typename stce_9879>
stce_9780& create_gbcp(stce_9879& stce_9913, typename enable_if<!stce_9881<stce_9780>::value, stce_9780>::type* = 0) {
  return reinterpret_cast<stce_9780&>(stce_9913);
}
template <typename stce_9780, typename stce_9879>
stce_9780 create_gbcp(stce_9879& stce_9913, typename enable_if<stce_9881<stce_9780>::value, stce_9780>::type* = 0) {
  return reinterpret_cast<stce_9780>(&stce_9913);
}
namespace internal {
template <typename stce_9780, typename enable_if = void> struct stce_9914 {
  static const bool value = false;
};
template <typename mode_t> struct stce_9914<stce_9909<mode_t>> {
  static const bool value = true;
};
template <typename stce_9780>
struct stce_9914<stce_9780, typename dco::enable_if<dco::mode<stce_9780>::is_dco_type>::type> {
  static const bool value = stce_9914<typename dco::mode<stce_9780>::data_t>::value;
};
template <typename stce_9780> struct is_gbcp_type {
  static const bool value = stce_9914<typename dco::remove_all<stce_9780>::type>::value;
};
template <typename stce_9780, int stce_9810> struct stce_9915;
template <typename stce_9780> struct stce_9915<stce_9780, 1> {
  typedef typename mode<stce_9780>::active_value_t& stce_9805;
  typedef const typename mode<stce_9780>::active_value_t& stce_9897;
  static stce_9805 value(stce_9780& at) { return at._value(); }
  static stce_9897 value(const stce_9780& at) { return at._value(); }
};
template <typename stce_9780, int stce_9810> struct stce_9915 {
  typedef typename stce_9915<typename mode<stce_9780>::active_value_t, stce_9810 - 1>::stce_9805 stce_9805;
  typedef typename stce_9915<typename mode<stce_9780>::active_value_t, stce_9810 - 1>::stce_9897 stce_9897;
  static stce_9805 value(stce_9780& at) {
    return stce_9915<typename mode<stce_9780>::active_value_t, stce_9810 - 1>::value(at._value());
  }
  static stce_9897 value(const stce_9780& at) {
    return stce_9915<typename mode<stce_9780>::active_value_t, stce_9810 - 1>::value(at._value());
  }
};
} // namespace internal
} // namespace dco
namespace dco {
template <typename stce_9780> inline typename internal::trait_value<stce_9780>::stce_9805 value(stce_9780& stce_9810) {
  return internal::trait_value<stce_9780>::value(stce_9810);
}
template <typename stce_9780>
inline typename internal::trait_value<stce_9780>::stce_9897 value(const stce_9780& stce_9810) {
  return internal::trait_value<stce_9780>::value(stce_9810);
}
namespace internal {
template <typename stce_9780, typename enable_if> struct trait_value {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef type& stce_9805;
  typedef const type& stce_9897;
  static inline stce_9805 value(type& value) { return value; }
  static inline stce_9897 value(const type& value) { return value; }
};
template <typename stce_9780>
struct trait_value<stce_9780,
                   typename dco::enable_if<dco::mode<stce_9780>::is_dco_type && !is_gbcp_type<stce_9780>::value &&
                                           !dco::mode<stce_9780>::is_intermediate_type>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::value_t& stce_9805;
  typedef typename dco::mode<type>::value_t const& stce_9897;
  static inline stce_9805 value(type& value) { return value._value(); }
  static inline stce_9897 value(const type& value) { return value._value(); }
};
template <typename stce_9780>
struct trait_value<stce_9780, typename dco::enable_if<!is_gbcp_type<stce_9780>::value &&
                                                      dco::mode<stce_9780>::is_intermediate_type>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::value_t const& stce_9805;
  typedef typename dco::mode<type>::value_t const& stce_9897;
  static inline stce_9805 value(type& value) { return value._value(); }
  static inline stce_9897 value(const type& value) { return value._value(); }
};
template <typename stce_9780>
struct trait_value<stce_9780, typename dco::enable_if<is_gbcp_type<stce_9780>::value>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::value_t& stce_9805;
  typedef typename dco::mode<type>::value_t const& stce_9897;
  static inline stce_9805 value(type& stce_9916) { return dco::value(stce_9916._value()); }
  static inline stce_9897 value(const type& stce_9916) { return dco::value(stce_9916._value()); }
};
template <typename stce_9780>
struct trait_value<std::vector<stce_9780>, typename dco::enable_if<dco::mode<stce_9780>::is_dco_type>::type> {
  typedef std::vector<stce_9780> stce_9901;
  typedef stce_9900<stce_9797, stce_9780, stce_9901> stce_9805;
  typedef const stce_9900<stce_9797, stce_9780, stce_9901> stce_9897;
  static inline stce_9805 value(stce_9901& stce_9857) { return stce_9805(stce_9857); }
  static inline stce_9897 value(const stce_9901& stce_9857) { return stce_9897(stce_9857); }
};
template <stce_9796 stce_9894, class stce_9780, typename stce_9917, typename stce_9918>
struct trait_value<stce_9900<stce_9894, stce_9780, stce_9917, stce_9918>, void> {
  typedef stce_9900<stce_9894, stce_9780, stce_9917, stce_9918> stce_9901;
  typedef stce_9900<stce_9797, typename stce_9901::value_t, stce_9901> stce_9805;
  typedef stce_9900<stce_9797, typename stce_9901::value_t, stce_9901> stce_9897;
  static inline stce_9805 value(const stce_9901& stce_9857) { return stce_9805(stce_9857); }
};
} // namespace internal
} // namespace dco

namespace dco {
template <typename stce_9780>
inline typename internal::stce_9785<stce_9780>::stce_9805 passive_value(stce_9780& stce_9810) {
  return internal::stce_9785<stce_9780>::value(stce_9810);
}
template <typename stce_9780>
inline typename internal::stce_9785<stce_9780>::stce_9897 passive_value(const stce_9780& stce_9810) {
  return internal::stce_9785<stce_9780>::value(stce_9810);
}
namespace internal {
template <typename stce_9780, typename enable_if> struct stce_9785 {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef type& stce_9805;
  typedef type const& stce_9897;
  static inline stce_9805 value(type& value) { return value; }
  static inline stce_9897 value(const type& value) { return value; }
};
template <typename stce_9780>
struct stce_9785<stce_9780, typename dco::enable_if<dco::mode<stce_9780>::is_dco_type &&
                                                    !dco::mode<stce_9780>::is_intermediate_type>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::active_value_t active_value_t;
  typedef typename dco::mode<type>::value_t value_t;
  typedef typename dco::mode<type>::passive_t passive_t;
  typedef passive_t& stce_9805;
  typedef passive_t const& stce_9897;
  static inline stce_9805 value(type& value) { return stce_9785<value_t>::value(dco::value(value)); }
  static inline stce_9897 value(const type& value) { return stce_9785<value_t>::value(dco::value(value)); }
};
template <typename stce_9780>
struct stce_9785<stce_9780, typename dco::enable_if<dco::mode<stce_9780>::is_intermediate_type>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::active_value_t active_value_t;
  typedef typename dco::mode<type>::value_t value_t;
  typedef typename dco::mode<type>::passive_t passive_t;
  typedef passive_t const& stce_9805;
  typedef passive_t const& stce_9897;
  static inline stce_9805 value(type& value) { return stce_9785<value_t>::value(dco::value(value)); }
  static inline stce_9897 value(const type& value) { return stce_9785<value_t>::value(dco::value(value)); }
};
template <typename stce_9780>
struct stce_9785<std::vector<stce_9780>, typename dco::enable_if<!dco::mode<stce_9780>::is_dco_type>::type> {
  typedef std::vector<stce_9780> stce_9901;
  typedef stce_9901& stce_9805;
  typedef const stce_9901& stce_9897;
  static inline stce_9805 value(stce_9901& value) { return value; }
  static inline stce_9897 value(const stce_9901& value) { return value; }
};
template <typename stce_9780>
struct stce_9785<std::vector<stce_9780>, typename dco::enable_if<dco::mode<stce_9780>::is_dco_type>::type> {
  typedef std::vector<stce_9780> stce_9901;
  typedef stce_9900<stce_9803, stce_9780, stce_9901> stce_9805;
  typedef const stce_9900<stce_9803, stce_9780, stce_9901> stce_9897;
  static inline stce_9805 value(stce_9901& stce_9857) { return stce_9805(stce_9857); }
  static inline stce_9897 value(const stce_9901& stce_9857) { return stce_9897(stce_9857); }
};
template <stce_9796 stce_9894, class stce_9780, typename stce_9917, typename stce_9918>
struct stce_9785<stce_9900<stce_9894, stce_9780, stce_9917, stce_9918>, void> {
  typedef stce_9900<stce_9894, stce_9780, stce_9917, stce_9918> stce_9901;
  typedef stce_9900<stce_9803, typename stce_9901::value_t, stce_9901> stce_9805;
  typedef stce_9900<stce_9803, typename stce_9901::value_t, stce_9901> stce_9897;
  static inline stce_9805 value(const stce_9901& stce_9857) { return stce_9805(stce_9857); }
};
} // namespace internal
} // namespace dco

namespace dco {
namespace internal {
struct interpretation_settings {
  bool reset;
  bool stce_9919;
  interpretation_settings(bool stce_9920 = false, bool stce_9921 = false) : reset(stce_9920), stce_9919(stce_9921) {}
};
} // namespace internal
} // namespace dco

namespace dco {
template <class stce_9760> struct adjoint_vector_abstract;
template <typename stce_9760> struct stce_9922 {
  adjoint_vector_abstract<stce_9760>& adjoints;
  index_t stce_9813;
  stce_9922(adjoint_vector_abstract<stce_9760>& adjoints, index_t stce_9813)
      : adjoints(adjoints), stce_9813(stce_9813) {}
  operator stce_9760() const { return adjoints._read_adjoint(stce_9813); }
  template <typename stce_9780> stce_9922& operator+=(stce_9780 const& stce_9923) {
    adjoints._increment_adjoint(stce_9813, stce_9923);
    return *this;
  }
};
template <class stce_9760> struct adjoint_vector_abstract {
  virtual ~adjoint_vector_abstract(){};
  stce_9922<stce_9760> stce_9924(const index_t stce_9813) { return stce_9922<stce_9760>(*this, stce_9813); }
  virtual stce_9760 _read_adjoint(const index_t stce_9813) = 0;
  virtual void _increment_adjoint(const index_t stce_9813, const stce_9760& stce_9925) = 0;
};
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_9926> class stce_9927 {
protected:
  stce_9926& stce_9928;

public:
  stce_9927(stce_9926& stce_9929) : stce_9928(stce_9929) {}
  stce_9926& stce_9929() { return stce_9928; }
};
} // namespace internal
} // namespace dco

namespace dco {
class tape_options {
private:
  size_t stce_9930, stce_9931;
  bool stce_9932;
  std::string stce_9933;
  bool stce_9934;
  bool stce_9935;

public:
  tape_options()
      : stce_9930(128 * 1024 * 1024), stce_9931(0), stce_9932(false), stce_9933("dco_tape_data.bin"), stce_9934(false),
        stce_9935(false) {}
  bool operator==(const tape_options& stce_9936) {
    return stce_9930 == stce_9936.stce_9930 && stce_9931 == stce_9936.stce_9931 && stce_9932 == stce_9936.stce_9932 &&
           stce_9934 == stce_9936.stce_9934 && stce_9933 == stce_9936.stce_9933 && stce_9935 == stce_9936.stce_9935;
  }
  bool operator!=(const tape_options& stce_9936) { return !operator==(stce_9936); }
  index_t chunk_size() const {
    if (helper::stce_9839) {
      throw dco::exception::create<std::runtime_error>("chunk_size removed; use chunk_size_in_byte() instead");
    }
    return -1;
  }
  size_t chunk_size_in_byte() const { return stce_9930; }
  size_t& chunk_size_in_byte() { return stce_9930; }
  void set_chunk_size_in_byte(mem_long_t size) {
    if (static_cast<double>(size) / static_cast<double>(std::numeric_limits<size_t>::max()) > 1.0) {
      DCO_LOG(logWARNING) << "set_chunk_size: requesting too much memory for your system (size_t too small). Resetting "
                             "to std::numeric_limits<size_t>::max()";
      stce_9930 = std::numeric_limits<size_t>::max();
    } else {
      stce_9930 = static_cast<size_t>(size);
    }
  }
  void set_chunk_size_in_kbyte(double size) { set_chunk_size_in_byte(1024 * static_cast<mem_long_t>(size)); }
  void set_chunk_size_in_mbyte(double size) { set_chunk_size_in_kbyte(1024. * size); }
  void set_chunk_size_in_gbyte(double size) { set_chunk_size_in_mbyte(1024. * size); }
  size_t blob_size_in_byte() const { return stce_9931; }
  size_t& blob_size_in_byte() { return stce_9931; }
  void set_blob_size_in_byte(mem_long_t size) {
    if (static_cast<double>(size) / static_cast<double>(std::numeric_limits<size_t>::max()) > 1.0) {
      DCO_LOG(logWARNING) << "set_blob_size: requesting too much memory for your system (size_t too small). Resetting "
                             "to std::numeric_limits<size_t>::max()";
      stce_9931 = std::numeric_limits<size_t>::max();
    } else {
      stce_9931 = static_cast<size_t>(size);
    }
  }
  void set_blob_size_in_kbyte(double size) { set_blob_size_in_byte(1024 * static_cast<mem_long_t>(size)); }
  void set_blob_size_in_mbyte(double size) { set_blob_size_in_kbyte(1024. * size); }
  void set_blob_size_in_gbyte(double size) { set_blob_size_in_mbyte(1024. * size); }
  bool& deallocation_on_reset() { return stce_9932; }
  const bool& deallocation_on_reset() const { return stce_9932; }
  std::string& filename() { return stce_9933; }
  const std::string& filename() const { return stce_9933; }
  bool& write_to_file() { return stce_9934; }
  bool write_to_file() const { return stce_9934; }
  bool& alloc_use_huge_pages() { return stce_9935; }
  bool alloc_use_huge_pages() const { return stce_9935; }
};
} // namespace dco
namespace dco {
namespace internal {
template <class stce_9760, typename stce_9926> class adjoint_vector_lazy : public stce_9927<stce_9926> {
  typedef stce_9927<stce_9926> stce_9937;

public:
  typedef typename helper::vecsize_info<stce_9760>::stce_9853 stce_9938;
  typedef stce_9760 stce_9762;

protected:
  std::vector<stce_9762> stce_9899;
  index_t stce_9939;
  index_t stce_9940;
  index_t stce_9941;
  int stce_9942;
  tape_options stce_9943;

public:
  typedef stce_9762 value_t;
  void init() {}
  adjoint_vector_lazy(index_t size, stce_9926& tape, tape_options stce_9944)
      : stce_9937(tape), stce_9899(0), stce_9939(0), stce_9940(0), stce_9941(size), stce_9942(0), stce_9943(stce_9944) {
  }
  DCO_ALWAYS_INLINE ~adjoint_vector_lazy() {}
  index_t size() const { return stce_9941; }
  bool stce_9945(index_t stce_9946) const { return stce_9939 > stce_9946; }
  mem_long_t stce_9947() const { return static_cast<mem_long_t>(stce_9940) * sizeof(stce_9762); }
  stce_9762& operator[](index_t stce_9813) { return stce_9899[stce_9813]; }
  stce_9762 operator[](index_t stce_9813) const { return stce_9899[stce_9813]; }
  void stce_9948(typename stce_9926::iterator& stce_9828) {
    (*this)[stce_9828->arg()] += static_cast<stce_9762>(stce_9828->pval() * (*this)[stce_9828.index()]);
  }
  void resize(index_t stce_9949) {
    DCO_LOG(logDEBUG2) << "Resizing internal adjoint vector to " << stce_9949;
    if (stce_9949 < stce_9941) {
      stce_9950(stce_9941, stce_9949 - 1);
    }
    stce_9941 = stce_9949;
  }
  void stce_9951(index_t stce_9949) {
    if (stce_9949 <= stce_9939) {
      return;
    }
    if (++stce_9942 % 100 == 0) {
      DCO_LOG(logWARNING) << "dco_adjoint_vector: resizing adjoint vector quite often (#=" << stce_9942
                          << ") -- might have severe performance impact (reallocation / initialization / copy)";
    }
    stce_9899.resize(static_cast<size_t>(stce_9949));
    stce_9939 = stce_9949;
    stce_9940 = static_cast<index_t>(stce_9899.capacity());
  }
  void stce_9952(index_t stce_9813) { stce_9951(stce_9813); }
  stce_9762 at(index_t stce_9813) const { return stce_9945(stce_9813) ? stce_9899[stce_9813] : 0; }
  stce_9762& at(const index_t stce_9813) {
    stce_9951(stce_9813 + 1);
    return stce_9899[stce_9813];
  }
  void stce_9950(index_t stce_9874, index_t stce_9875) {
    if (stce_9874 < stce_9875) {
      std::swap(stce_9874, stce_9875);
    }
    if (!stce_9945(stce_9875)) {
      return;
    }
    stce_9951(stce_9941);
    for (index_t stce_9847 = std::min(stce_9874, stce_9941 - 1); stce_9847 > stce_9875; --stce_9847) {
      stce_9899[stce_9847] = 0;
    }
  }
  void stce_9953() { stce_9951(stce_9941); }
  auto begin() -> decltype(stce_9899.begin()) { return stce_9899.begin(); }
  auto end() -> decltype(stce_9899.end()) { return stce_9899.end(); }
};
} // namespace internal
} // namespace dco

namespace dco {
template <class stce_9926, class stce_9760, int stce_9954 = -1>
struct adjoint_vector : dco::adjoint_vector_abstract<typename stce_9926::tape_t::stce_9762>,
                        public internal::stce_9927<stce_9926> {
  static const size_t vecsize = stce_9954 < 0 ? static_cast<size_t>(-stce_9954) : static_cast<size_t>(stce_9954);
  typedef internal::stce_9927<stce_9926> stce_9937;

public:
  typedef dco::helper::valvec<stce_9760, vecsize> value_t;
  typedef stce_9760 adjoint_real_t;
  typedef stce_9760 stce_9938;
  typedef typename stce_9926::stce_9762 stce_9762;

private:
  std::vector<value_t> stce_9899;
  index_t stce_9955;

public:
  int stce_9956;
  void init() {}
  adjoint_vector(stce_9926* tape) : stce_9937(*tape), stce_9955(0), stce_9956(0) {}
  virtual ~adjoint_vector() {}
  template <class stce_9795> value_t& derivative(const stce_9795& stce_9957) {
    stce_9958();
    const index_t stce_9813 = stce_9957._tape_index();
    return stce_9899[stce_9813];
  }
  void interpret_adjoint() {
    typename stce_9926::iterator stce_9875 = stce_9937::stce_9929().start();
    internal::interpretation_settings stce_9959;
    stce_9960(stce_9937::stce_9929().current(), stce_9875, stce_9959);
  }
  void interpret_adjoint_to(const typename stce_9926::iterator& stce_9875) {
    internal::interpretation_settings stce_9959;
    if (stce_9875 > stce_9937::stce_9929().current())
      throw dco::exception::create<std::runtime_error>("adjoint interpretation: from < to.",
                                                       "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/"
                                                       "dco_cpp_make_release/dco_cpp_dev/src/dco_adjoint_vector.hpp",
                                                       59);
    else
      stce_9960(stce_9937::stce_9929().current(), stce_9875, stce_9959);
  }
  void interpret_adjoint_from(const typename stce_9926::iterator& stce_9874) {
    typename stce_9926::iterator stce_9875 = stce_9937::stce_9929().start();
    assert(!(stce_9874 < stce_9875));
    typename internal::interpretation_settings stce_9959;
    stce_9960(stce_9874, stce_9875, stce_9959);
  }
  void interpret_adjoint_from_to(const typename stce_9926::iterator& stce_9874,
                                 const typename stce_9926::iterator& stce_9875) {
    typename internal::interpretation_settings stce_9959;
    if (stce_9875 > stce_9874)
      throw dco::exception::create<std::runtime_error>("adjoint interpretation: from < to.",
                                                       "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/"
                                                       "dco_cpp_make_release/dco_cpp_dev/src/dco_adjoint_vector.hpp",
                                                       75);
    else
      stce_9960(stce_9874, stce_9875, stce_9959);
  }
  void interpret_adjoint_and_zero_adjoints_to(const typename stce_9926::iterator& stce_9875) {
    typename stce_9926::iterator stce_9874(stce_9937::stce_9929().current());
    typename internal::interpretation_settings stce_9959;
    stce_9959.reset = false;
    stce_9959.stce_9919 = true;
    stce_9960(stce_9874, stce_9875, stce_9959);
  }
  void interpret_adjoint_and_zero_adjoints_from_to(const typename stce_9926::iterator& stce_9874,
                                                   const typename stce_9926::iterator& stce_9875) {
    typename internal::interpretation_settings stce_9959;
    stce_9959.reset = false;
    stce_9959.stce_9919 = true;
    stce_9960(stce_9874, stce_9875, stce_9959);
  }
  void zero_adjoints() {
    typename stce_9926::iterator stce_9875 = stce_9937::stce_9929().start();
    stce_9961(stce_9937::stce_9929().current(), stce_9875);
  }
  void zero_adjoints_to(const typename stce_9926::iterator& stce_9875) {
    stce_9961(stce_9937::stce_9929().current(), stce_9875);
  }
  void zero_adjoints_from(const typename stce_9926::iterator& stce_9874) {
    typename stce_9926::iterator stce_9875 = stce_9937::stce_9929().start();
    stce_9961(stce_9874, stce_9875);
  }
  void zero_adjoints_from_to(const typename stce_9926::iterator& stce_9874,
                             const typename stce_9926::iterator& stce_9875) {
    stce_9961(stce_9874, stce_9875);
  }
  value_t& operator[](index_t stce_9813) { return stce_9899[stce_9813]; }
  value_t at(index_t stce_9813) const { return (stce_9813 < stce_9955) ? stce_9899[stce_9813] : 0; }
  value_t& at(index_t stce_9813) {
    stce_9952(stce_9813);
    return stce_9899[stce_9813];
  }
  void stce_9952(index_t stce_9813) { stce_9958(stce_9813 + 1); }
  void stce_9948(typename stce_9926::iterator& stce_9828) {
    (*this)[stce_9828->arg()] += stce_9828->pval() * (*this)[stce_9828.index()];
  }
  value_t& stce_9962(const index_t stce_9813) { return stce_9899[stce_9813]; }
  stce_9760& stce_9962(const index_t stce_9813, int stce_9963) { return stce_9899[stce_9813][stce_9963]; }
  template <class stce_9964>
  void _increment_adjoint(const index_t& stce_9813, const stce_9964& stce_9965, const value_t& stce_9925) {
    stce_9899[stce_9813] += (stce_9965 * stce_9925);
  }
  virtual typename stce_9926::stce_9762 _read_adjoint(const index_t stce_9813) {
    return static_cast<typename stce_9926::stce_9762>(stce_9962(stce_9813)[stce_9956]);
  }
  virtual void _increment_adjoint(const index_t stce_9813, const typename stce_9926::stce_9762& stce_9925) {
    stce_9899[stce_9813][stce_9956] += static_cast<adjoint_real_t>(stce_9925);
  }
  void stce_9961(const typename stce_9926::iterator& stce_9874, const typename stce_9926::iterator& stce_9875) {
    stce_9950(stce_9874.index(), stce_9875.index());
  }
  void stce_9950(index_t stce_9874, index_t stce_9875) {
    if (stce_9874 < stce_9875) {
      std::swap(stce_9874, stce_9875);
    }
    if (stce_9899.size() == 0) {
      return;
    }
    for (index_t stce_9847 = stce_9875 + 1; stce_9847 <= stce_9874; stce_9847++) {
      stce_9899[stce_9847] = 0;
    }
  }
  void stce_9960(const typename stce_9926::iterator& stce_9874, const typename stce_9926::iterator& stce_9875,
                 typename internal::interpretation_settings stce_9959) {
    stce_9958();
    stce_9937::stce_9929().stce_9966(*this, *this, stce_9874, stce_9875, stce_9959, [](dco::index_t, value_t) {});
  }
  void stce_9958(index_t stce_9967 = -1) {
    index_t stce_9968;
    if (stce_9967 != -1)
      stce_9968 = stce_9967;
    else
      stce_9968 = stce_9937::stce_9929().current().index() + 1;
    if (static_cast<size_t>(stce_9968) > stce_9899.size()) {
      stce_9955 = stce_9968;
      stce_9899.resize(static_cast<size_t>(stce_9955));
    }
  }
  auto begin() -> decltype(stce_9899.begin()) { return stce_9899.begin(); }
  auto end() -> decltype(stce_9899.end()) { return stce_9899.end(); }
};
} // namespace dco
namespace dco {
template <typename stce_9780>
inline typename internal::stce_9782<stce_9780>::stce_9805 derivative(const stce_9780& stce_9810) {
  return internal::stce_9782<stce_9780>::value(stce_9810);
}
template <typename stce_9780, typename stce_9781>
inline auto derivative(const stce_9780& stce_9810, stce_9781& adjoints)
    -> decltype(internal::stce_9782<stce_9780, stce_9781>::value(stce_9810, &adjoints)) {
  return internal::stce_9782<stce_9780, stce_9781>::value(stce_9810, &adjoints);
}
namespace internal {
template <typename stce_9780, typename stce_9781, typename enable_if> struct stce_9782 {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef type stce_9805;
  static inline stce_9805 value(const type&) { return type(); }
  static inline stce_9805 value(const type&, stce_9781*) { return type(); }
};
template <typename stce_9780>
struct stce_9782<
    stce_9780, void,
    typename dco::enable_if<dco::mode<stce_9780>::is_dco_type &&
                            !(dco::mode<stce_9780>::is_adjoint_type && dco::mode<stce_9780>::is_tangent_type) &&
                            !is_gbcp_type<stce_9780>::value>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::derivative_t& stce_9805;
  static inline stce_9805 value(type const& value) { return value.stce_9969(); }
};
template <typename stce_9780>
struct stce_9782<
    stce_9780, void,
    typename dco::enable_if<(dco::mode<stce_9780>::is_adjoint_type && dco::mode<stce_9780>::is_tangent_type) &&
                            !is_gbcp_type<stce_9780>::value>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::derivative_t& stce_9805;
  template <typename stce_9879 = stce_9780> static inline stce_9805 value(type const&) {
    static_assert(!helper::stce_9840<stce_9879>::stce_9753,
                  "Please use dco::tangent or dco::adjoint for this data type. dco::derivative is ambiguous.");
    static typename std::remove_reference<stce_9805>::type stce_9970;
    return stce_9970;
  }
};
template <typename stce_9780>
struct stce_9782<stce_9780, void,
                 typename dco::enable_if<(is_gbcp_type<stce_9780>::value && dco::mode<stce_9780>::order > 0)>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::value_t& stce_9805;
  static inline stce_9805 value(const type& value) { return dco::derivative(value._value()); }
};
template <typename stce_9780>
struct stce_9782<stce_9780, void,
                 typename dco::enable_if<(is_gbcp_type<stce_9780>::value && dco::mode<stce_9780>::order == 0)>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::value_t stce_9805;
  static inline stce_9805 value(const type&) { return stce_9805(); }
};
template <typename stce_9780, typename stce_9971, typename stce_9972, int stce_9973>
struct stce_9782<stce_9780, adjoint_vector<stce_9971, stce_9972, stce_9973>,
                 typename dco::enable_if<(stce_9973 == -1)>::type> {
  typedef adjoint_vector<stce_9971, stce_9972, stce_9973> stce_9918;
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef stce_9972& stce_9898;
  static inline stce_9898 value(const type& value, stce_9918* adjoints) { return adjoints->derivative(value)[0]; }
};
template <typename stce_9780, typename stce_9971, typename stce_9972, int stce_9973>
struct stce_9782<stce_9780, adjoint_vector<stce_9971, stce_9972, stce_9973>,
                 typename dco::enable_if<(stce_9973 > 0)>::type> {
  typedef adjoint_vector<stce_9971, stce_9972, stce_9973> stce_9918;
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename stce_9918::value_t& stce_9898;
  static inline stce_9898 value(const type& value, stce_9918* adjoints) { return adjoints->derivative(value); }
};
template <typename stce_9780, typename stce_9760, typename stce_9926>
struct stce_9782<stce_9780, adjoint_vector_lazy<stce_9760, stce_9926>> {
  typedef adjoint_vector_lazy<stce_9760, stce_9926> stce_9918;
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef stce_9760& stce_9898;
  static inline stce_9898 value(const type& value, stce_9918* adjoints) {
    return (*adjoints)[value.data()._tape_index()];
  }
};
template <typename stce_9780, typename stce_9760> struct stce_9782<stce_9780, adjoint_vector_abstract<stce_9760>> {
  typedef adjoint_vector_abstract<stce_9760> stce_9918;
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef stce_9760& stce_9898;
  static inline auto value(const type& value, stce_9918* adjoints)
      -> decltype(adjoints->stce_9924(value.data()._tape_index())) {
    return adjoints->stce_9924(value.data()._tape_index());
  }
};
template <typename stce_9780>
struct stce_9782<std::vector<stce_9780>, void, typename dco::enable_if<!dco::mode<stce_9780>::is_dco_type>::type> {
  typedef std::vector<stce_9780> stce_9901;
  typedef stce_9901 stce_9805;
  static inline stce_9805 value(const stce_9901& value) { return stce_9805(value.size(), 0.0); }
};
template <typename stce_9780>
struct stce_9782<std::vector<stce_9780>, void, typename dco::enable_if<dco::mode<stce_9780>::is_dco_type>::type> {
  typedef std::vector<stce_9780> stce_9901;
  typedef stce_9900<stce_9798, stce_9780, stce_9901> stce_9805;
  static inline stce_9805 value(const stce_9901& stce_9857) { return stce_9805(stce_9857); }
};
template <typename stce_9780, typename stce_9971, typename stce_9972, int stce_9973>
struct stce_9782<std::vector<stce_9780>, adjoint_vector<stce_9971, stce_9972, stce_9973>,
                 typename dco::enable_if<(stce_9973 == -1)>::type> {
  typedef adjoint_vector<stce_9971, stce_9972, stce_9973> stce_9918;
  typedef std::vector<stce_9780> stce_9901;
  typedef stce_9900<stce_9798, stce_9780, stce_9901> stce_9805;
  typedef stce_9900<stce_9799, stce_9780, stce_9901, stce_9918> stce_9898;
  static inline stce_9805 value(const stce_9901& stce_9857) { return stce_9805(stce_9857); }
  static inline stce_9898 value(const stce_9901& stce_9857, stce_9918* adjoints) {
    return stce_9898(stce_9857, adjoints);
  }
};
template <typename stce_9780, typename stce_9760>
struct stce_9782<std::vector<stce_9780>, adjoint_vector_abstract<stce_9760>> {
  typedef adjoint_vector_abstract<stce_9760> stce_9918;
  typedef std::vector<stce_9780> stce_9901;
  typedef stce_9900<stce_9798, stce_9780, stce_9901> stce_9805;
  typedef stce_9900<stce_9799, stce_9780, stce_9901, stce_9918> stce_9898;
  static inline stce_9805 value(const stce_9901& stce_9857) { return stce_9805(stce_9857); }
  static inline stce_9898 value(const stce_9901& stce_9857, stce_9918* adjoints) {
    return stce_9898(stce_9857, adjoints);
  }
};
template <stce_9796 stce_9894, class stce_9780, typename stce_9917, typename stce_9918>
struct stce_9782<stce_9900<stce_9894, stce_9780, stce_9917, stce_9918>, void> {
  typedef stce_9900<stce_9894, stce_9780, stce_9917, stce_9918> stce_9901;
  typedef stce_9900<stce_9798, typename stce_9901::value_t, stce_9901> stce_9805;
  static inline stce_9805 value(const stce_9901& stce_9857) { return stce_9805(stce_9857); }
};
} // namespace internal
} // namespace dco

namespace dco {
template <typename stce_9780>
inline typename internal::stce_9784<stce_9780>::stce_9805 adjoint(const stce_9780& stce_9810) {
  return internal::stce_9784<stce_9780>::value(stce_9810);
}
template <typename stce_9780, typename stce_9781>
inline auto adjoint(const stce_9780& stce_9810, stce_9781& adjoints)
    -> decltype(internal::stce_9784<stce_9780, stce_9781>::value(stce_9810, &adjoints)) {
  return internal::stce_9784<stce_9780, stce_9781>::value(stce_9810, &adjoints);
}
namespace internal {
template <typename stce_9780, typename stce_9781, typename enable_if> struct stce_9784 {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef type stce_9805;
  static inline stce_9805 value(const type&) { return type(); }
  static inline stce_9805 value(const type&, stce_9781*) { return type(); }
};
template <typename stce_9780>
struct stce_9784<
    stce_9780, void,
    typename dco::enable_if<dco::mode<stce_9780>::is_adjoint_type && !is_gbcp_type<stce_9780>::value>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::derivative_t& stce_9805;
  static inline stce_9805 value(type const& value) { return value._adjoint(); }
};
template <typename stce_9780>
struct stce_9784<
    stce_9780, void,
    typename dco::enable_if<!dco::mode<stce_9780>::is_adjoint_type && !is_gbcp_type<stce_9780>::value>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::derivative_t stce_9805;
  template <typename stce_9879 = stce_9780> static inline stce_9805 value(type const&) {
    static_assert(!helper::stce_9840<stce_9879>::stce_9753, "dco::adjoint called on a non-adjoint data type.");
    static stce_9805 stce_9970;
    return stce_9970;
  }
};
template <typename stce_9780>
struct stce_9784<stce_9780, void,
                 typename dco::enable_if<(is_gbcp_type<stce_9780>::value && dco::mode<stce_9780>::order > 0)>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::value_t& stce_9805;
  static inline stce_9805 value(const type& value) { return dco::adjoint(value._value()); }
};
template <typename stce_9780>
struct stce_9784<stce_9780, void,
                 typename dco::enable_if<(is_gbcp_type<stce_9780>::value && dco::mode<stce_9780>::order == 0)>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::value_t stce_9805;
  static inline stce_9805 value(const type&) { return stce_9805(); }
};
template <typename stce_9780, typename stce_9971, typename stce_9972, int stce_9973>
struct stce_9784<stce_9780, adjoint_vector<stce_9971, stce_9972, stce_9973>,
                 typename dco::enable_if<(stce_9973 == -1)>::type> {
  typedef adjoint_vector<stce_9971, stce_9972, stce_9973> stce_9918;
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef stce_9972& stce_9898;
  static inline stce_9898 value(const type& value, stce_9918* adjoints) { return adjoints->adjoint(value)[0]; }
};
template <typename stce_9780, typename stce_9971, typename stce_9972, int stce_9973>
struct stce_9784<stce_9780, adjoint_vector<stce_9971, stce_9972, stce_9973>,
                 typename dco::enable_if<(stce_9973 > 0)>::type> {
  typedef adjoint_vector<stce_9971, stce_9972, stce_9973> stce_9918;
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename stce_9918::value_t& stce_9898;
  static inline stce_9898 value(const type& value, stce_9918* adjoints) { return adjoints->adjoint(value); }
};
template <typename stce_9780, typename DERIVATIVE_T, typename stce_9926>
struct stce_9784<stce_9780, adjoint_vector_lazy<DERIVATIVE_T, stce_9926>> {
  typedef adjoint_vector_lazy<DERIVATIVE_T, stce_9926> stce_9918;
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef DERIVATIVE_T& stce_9898;
  static inline stce_9898 value(const type& value, stce_9918* adjoints) {
    return (*adjoints)[value.data()._tape_index()];
  }
};
template <typename stce_9780, typename DERIVATIVE_T>
struct stce_9784<stce_9780, adjoint_vector_abstract<DERIVATIVE_T>> {
  typedef adjoint_vector_abstract<DERIVATIVE_T> stce_9918;
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef DERIVATIVE_T& stce_9898;
  static inline auto value(const type& value, stce_9918* adjoints)
      -> decltype(adjoints->stce_9924(value.data()._tape_index())) {
    return adjoints->stce_9924(value.data()._tape_index());
  }
};
template <typename stce_9780>
struct stce_9784<std::vector<stce_9780>, void, typename dco::enable_if<!dco::mode<stce_9780>::is_adjoint_type>::type> {
  typedef std::vector<stce_9780> stce_9901;
  typedef stce_9901 stce_9805;
  static inline stce_9805 value(const stce_9901& value) { return stce_9805(value.size(), 0.0); }
};
template <typename stce_9780>
struct stce_9784<std::vector<stce_9780>, void, typename dco::enable_if<dco::mode<stce_9780>::is_adjoint_type>::type> {
  typedef std::vector<stce_9780> stce_9901;
  typedef stce_9900<stce_9801, stce_9780, stce_9901> stce_9805;
  static inline stce_9805 value(const stce_9901& stce_9857) { return stce_9805(stce_9857); }
};
template <typename stce_9780, typename stce_9971, typename stce_9972, int stce_9973>
struct stce_9784<std::vector<stce_9780>, adjoint_vector<stce_9971, stce_9972, stce_9973>,
                 typename dco::enable_if<(stce_9973 == -1)>::type> {
  typedef adjoint_vector<stce_9971, stce_9972, stce_9973> stce_9918;
  typedef std::vector<stce_9780> stce_9901;
  typedef stce_9900<stce_9801, stce_9780, stce_9901> stce_9805;
  typedef stce_9900<stce_9802, stce_9780, stce_9901, stce_9918> stce_9898;
  static inline stce_9805 value(const stce_9901& stce_9857) { return stce_9805(stce_9857); }
  static inline stce_9898 value(const stce_9901& stce_9857, stce_9918* adjoints) {
    return stce_9898(stce_9857, adjoints);
  }
};
template <typename stce_9780, typename DERIVATIVE_T>
struct stce_9784<std::vector<stce_9780>, adjoint_vector_abstract<DERIVATIVE_T>> {
  typedef adjoint_vector_abstract<DERIVATIVE_T> stce_9918;
  typedef std::vector<stce_9780> stce_9901;
  typedef stce_9900<stce_9801, stce_9780, stce_9901> stce_9805;
  typedef stce_9900<stce_9802, stce_9780, stce_9901, stce_9918> stce_9898;
  static inline stce_9805 value(const stce_9901& stce_9857) { return stce_9805(stce_9857); }
  static inline stce_9898 value(const stce_9901& stce_9857, stce_9918* adjoints) {
    return stce_9898(stce_9857, adjoints);
  }
};
template <stce_9796 stce_9974, class stce_9780, typename stce_9917, typename stce_9918>
struct stce_9784<stce_9900<stce_9974, stce_9780, stce_9917, stce_9918>, void> {
  typedef stce_9900<stce_9974, stce_9780, stce_9917, stce_9918> stce_9901;
  typedef stce_9900<stce_9801, typename stce_9901::value_t, stce_9901> stce_9805;
  static inline stce_9805 value(const stce_9901& stce_9857) { return stce_9805(stce_9857); }
};
} // namespace internal
} // namespace dco

namespace dco {
template <typename stce_9780>
inline typename internal::stce_9783<stce_9780>::stce_9805 tangent(const stce_9780& stce_9810) {
  return internal::stce_9783<stce_9780>::value(stce_9810);
}
namespace internal {
template <typename stce_9780, typename stce_9781, typename enable_if> struct stce_9783 {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef type stce_9805;
  static inline stce_9805 value(const type&) { return type(); }
  static inline stce_9805 value(const type&, stce_9781*) { return type(); }
};
template <typename stce_9780>
struct stce_9783<
    stce_9780, void,
    typename dco::enable_if<dco::mode<stce_9780>::is_tangent_type && !is_gbcp_type<stce_9780>::value>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::derivative_t& stce_9805;
  static inline stce_9805 value(type const& value) { return value.stce_9975(); }
};
template <typename stce_9780>
struct stce_9783<
    stce_9780, void,
    typename dco::enable_if<!dco::mode<stce_9780>::is_tangent_type && !is_gbcp_type<stce_9780>::value>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::derivative_t stce_9805;
  template <typename stce_9879 = stce_9780> static inline stce_9805 value(type const&) {
    static_assert(!helper::stce_9840<stce_9879>::stce_9753, "dco::tangent called on a non-tangent data type.");
    static stce_9805 stce_9970;
    return stce_9970;
  }
};
template <typename stce_9780>
struct stce_9783<stce_9780, void,
                 typename dco::enable_if<(is_gbcp_type<stce_9780>::value && dco::mode<stce_9780>::order > 0)>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::value_t& stce_9805;
  static inline stce_9805 value(const type& value) { return dco::tangent(value._value()); }
};
template <typename stce_9780>
struct stce_9783<stce_9780, void,
                 typename dco::enable_if<(is_gbcp_type<stce_9780>::value && dco::mode<stce_9780>::order == 0)>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::value_t stce_9805;
  static inline stce_9805 value(const type&) { return stce_9805(); }
};
template <typename stce_9780>
struct stce_9783<std::vector<stce_9780>, void, typename dco::enable_if<!dco::mode<stce_9780>::is_tangent_type>::type> {
  typedef std::vector<stce_9780> stce_9901;
  typedef stce_9901 stce_9805;
  static inline stce_9805 value(const stce_9901& value) { return stce_9805(value.size(), 0.0); }
};
template <typename stce_9780>
struct stce_9783<std::vector<stce_9780>, void, typename dco::enable_if<dco::mode<stce_9780>::is_dco_type>::type> {
  typedef std::vector<stce_9780> stce_9901;
  typedef stce_9900<stce_9800, stce_9780, stce_9901> stce_9805;
  static inline stce_9805 value(const stce_9901& stce_9857) { return stce_9805(stce_9857); }
};
template <stce_9796 stce_9976, class stce_9780, typename stce_9917, typename stce_9918>
struct stce_9783<stce_9900<stce_9976, stce_9780, stce_9917, stce_9918>, void> {
  typedef stce_9900<stce_9976, stce_9780, stce_9917, stce_9918> stce_9901;
  typedef stce_9900<stce_9800, typename stce_9901::value_t, stce_9901> stce_9805;
  static inline stce_9805 value(const stce_9901& stce_9857) { return stce_9805(stce_9857); }
};
} // namespace internal
} // namespace dco

namespace dco {
template <typename stce_9780> typename internal::stce_9786<stce_9780>::stce_9805 tape(const stce_9780& stce_9810) {
  return internal::stce_9786<stce_9780>::value(stce_9810);
}
template <typename stce_9780>
typename internal::stce_9787<stce_9780>::stce_9805 tape_index(const stce_9780& stce_9810) {
  return internal::stce_9787<stce_9780>::value(stce_9810);
}
namespace internal {
template <typename stce_9780, typename enable_if> struct stce_9786 {
  typedef typename dco::mode<stce_9780>::tape_t* stce_9805;
  static stce_9805 value(const stce_9780&) { return nullptr; }
};
template <typename stce_9780>
struct stce_9786<stce_9780, typename dco::enable_if<dco::mode<stce_9780>::is_adjoint_type>::type> {
  typedef typename dco::mode<stce_9780>::tape_t* stce_9805;
  static stce_9805 value(const stce_9780& value) { return value.tape(); }
};
template <typename stce_9780>
struct stce_9786<std::vector<stce_9780>, typename dco::enable_if<dco::mode<stce_9780>::is_adjoint_type>::type> {
  typedef typename dco::mode<stce_9780>::tape_t* stce_9805;
  static stce_9805 value(const std::vector<stce_9780>& value) {
    stce_9805 tape = 0;
    for (size_t stce_9847 = 0; stce_9847 < value.size(); stce_9847++) {
      if (stce_9786<stce_9780>::value(value[stce_9847]) != 0) {
        tape = stce_9786<stce_9780>::value(value[stce_9847]);
        break;
      }
    }
    return tape;
  }
};
template <typename stce_9780, typename enable_if> struct stce_9787 {
  typedef index_t stce_9805;
  static index_t value(const stce_9780&) { return 0; }
};
template <typename stce_9780>
struct stce_9787<stce_9780, typename dco::enable_if<dco::mode<stce_9780>::is_adjoint_type>::type> {
  typedef index_t& stce_9805;
  static stce_9805 value(const stce_9780& value) { return value._tape_index(); }
};
template <typename stce_9780>
struct stce_9787<std::vector<stce_9780>, typename dco::enable_if<dco::mode<stce_9780>::is_dco_type>::type> {
  typedef std::vector<stce_9780> stce_9901;
  typedef stce_9900<stce_9804, stce_9780, stce_9901> stce_9805;
  typedef const stce_9900<stce_9804, stce_9780, stce_9901> stce_9897;
  static inline stce_9805 value(stce_9901& stce_9857) { return stce_9805(stce_9857); }
  static inline stce_9897 value(const stce_9901& stce_9857) { return stce_9897(stce_9857); }
};
} // namespace internal
} // namespace dco

namespace dco {
namespace folding {
template <typename stce_9780, typename enable_if> struct is_zero_trait {
  static bool get(const stce_9780& stce_9810) { return stce_9810 == 0; }
};
template <typename stce_9780> bool is_zero(const stce_9780& stce_9810) {
  return is_zero_trait<stce_9780>::get(stce_9810);
}
template <typename stce_9780>
struct is_zero_trait<stce_9780, typename dco::enable_if<dco::mode<stce_9780>::is_tangent_type>::type> {
  static bool get(const stce_9780& stce_9810) { return is_zero(value(stce_9810)) && is_zero(derivative(stce_9810)); }
};
template <typename stce_9780>
struct is_zero_trait<stce_9780, typename dco::enable_if<dco::mode<stce_9780>::is_adjoint_type>::type> {
  static bool get(const stce_9780& stce_9810) { return is_zero(value(stce_9810)) && !tape_index(stce_9810); }
};
} // namespace folding
} // namespace dco

namespace dco {
template <typename stce_9820, typename... stce_9977>
int fprintf(stce_9820& stream, char const* stce_9978, stce_9977&&... stce_9979) {
  return ::fprintf(stream, stce_9978, dco::passive_value(stce_9979)...);
}
template <typename... stce_9977> int printf(char const* const stce_9978, stce_9977&&... stce_9979) {
  return ::printf(stce_9978, dco::passive_value(stce_9979)...);
}
template <typename... stce_9977> int sprintf(char* stream, char const* stce_9978, stce_9977&&... stce_9979) {
  return ::sprintf(stream, stce_9978, dco::passive_value(stce_9979)...);
}
namespace stce_9980 {
inline void init() {}
template <typename stce_9780, typename... stce_9977>
typename dco::enable_if<!dco::mode<typename std::remove_pointer<stce_9780>::type>::is_dco_type>::type
init(stce_9780&, stce_9977&... stce_9979);
template <typename stce_9780, typename... stce_9977>
typename dco::enable_if<dco::mode<typename std::remove_pointer<stce_9780>::type>::is_dco_type>::type
init(stce_9780& stce_9810, stce_9977&... stce_9979) {
  *stce_9810 = 0;
  init(stce_9979...);
}
template <typename stce_9780, typename... stce_9977>
typename dco::enable_if<!dco::mode<typename std::remove_pointer<stce_9780>::type>::is_dco_type>::type
init(stce_9780&, stce_9977&... stce_9979) {
  init(stce_9979...);
}
} // namespace stce_9980
template <typename stce_9820, typename... stce_9977>
int sscanf(stce_9820& stream, char const* stce_9978, stce_9977&&... stce_9979) {
  stce_9980::init(stce_9979...);
  return ::sscanf(stream, stce_9978, &dco::passive_value(*stce_9979)...);
}
template <typename stce_9820, typename... stce_9977>
int fscanf(stce_9820& stream, char const* stce_9978, stce_9977&&... stce_9979) {
  stce_9980::init(stce_9979...);
  return ::fscanf(stream, stce_9978, &dco::passive_value(*stce_9979)...);
}
} // namespace dco

namespace dco {
namespace internal {
template <memory_model::TYPE memory_model, typename stce_9981, memory_model::TYPE stce_9982 = memory_model::stce_9764>
class stce_9983 {};
} // namespace internal
} // namespace dco
namespace dco {
namespace internal {
template <class stce_9984>
struct jacobian_preaccumulator_t : adjoint_vector_abstract<typename dco::mode<stce_9984>::stce_9985> {
  typedef typename dco::mode<stce_9984>::stce_9985 stce_9762;
  typedef stce_9762 stce_9938;
  typedef typename dco::mode<stce_9984>::tape_t tape_t;
  typedef typename tape_t::iterator_t stce_9986;
  typedef typename tape_t::edge_inserter stce_9987;
  tape_t* const stce_9988;
  stce_9986 stce_9989;
  index_t stce_9990;
  typedef adjoint_vector_lazy<stce_9762, tape_t> vector_t;
  vector_t stce_9899;
  bool stce_9991;
  bool stce_9992;
  std::map<index_t, stce_9762> stce_9993;
  void init() {}
  typedef stce_9983<memory_model::BLOB_TAPE, tape_t> stce_9901;
  typedef typename stce_9901::edge_inserter stce_9994;
  typedef typename stce_9901::iterator stce_9995;
  stce_9901* stce_9928;
  stce_9994* stce_9996;
  typedef typename stce_9984::data_t stce_9997;
  std::vector<stce_9997*> stce_9998;
  index_t stce_9956;
  bool& merge_edges() { return stce_9992; }
  jacobian_preaccumulator_t(tape_t* const tape)
      : stce_9988(tape), stce_9899(0, *tape, tape->stce_9944()), stce_9992(false), stce_9928(0), stce_9996(0),
        stce_9956(0) {
    if (stce_9988) {
      stce_9989 = stce_9988->get_position();
      stce_9990 = stce_9989.index();
      stce_9991 = true;
    } else {
      stce_9991 = false;
    }
  }
  ~jacobian_preaccumulator_t() {
    if (stce_9991)
      this->finish();
    if (stce_9928)
      delete stce_9928;
  }
  void start() {
    if (stce_9988) {
      stce_9989 = stce_9988->get_position();
      stce_9990 = stce_9989.index();
      stce_9991 = true;
    } else {
      stce_9991 = false;
    }
  }
  void stce_9999(stce_9984& stce_9810) {
    if (!dco::tape_index(stce_9810))
      return;
    if (dco::tape_index(stce_9810) && dco::tape_index(stce_9810) <= stce_9990) {
      throw dco::exception::create<std::runtime_error>("jacobian_preaccumulator_t: registering output, which is indeed "
                                                       "an input (was alive already before starting point).");
    }
    stce_9998.push_back(&static_cast<stce_9997&>(stce_9810));
  }
  void register_output(stce_9984& stce_9810) {
    if (stce_9988) {
      stce_9999(stce_9810);
    }
  }
  void register_output(std::vector<stce_9984>& stce_9810) {
    if (stce_9988) {
      stce_9998.reserve(stce_9998.size() + stce_9810.size());
      for (size_t stce_9847 = 0; stce_9847 < stce_9810.size(); ++stce_9847) {
        stce_9999(stce_9810[stce_9847]);
      }
    }
  }
  void finish() {
    if (!stce_9991)
      return;
    stce_9991 = false;
    if (!stce_9988)
      return;
    if (!stce_9998.size()) {
      stce_9988->reset_to(stce_9989);
      return;
    }
    const stce_9986 stce_10000 = stce_9988->get_position();
    const index_t stce_10001 = stce_10000.index() - stce_9989.index();
    stce_9899.resize(stce_10001 + 1);
    const index_t stce_10002 = stce_9988->size(stce_10000, stce_9989);
    const index_t stce_10003 = stce_10002 * (1 + static_cast<index_t>(stce_9998.size()));
    if (stce_9928)
      delete stce_9928;
    tape_options stce_10004;
    stce_10004.blob_size_in_byte() = stce_10003 * stce_9901::entry::size_of();
    stce_9928 = new stce_9901(stce_10004, *stce_9988);
    stce_9928->current_ref().index() = stce_10000.index();
    stce_9899.stce_9953();
    for (typename std::vector<stce_9997*>::iterator stce_10005 = stce_9998.begin(); stce_10005 != stce_9998.end();
         ++stce_10005) {
      stce_9997& stce_9828 = **stce_10005;
      if (stce_9828._tape_index() == 0)
        continue;
      stce_9899.stce_9950(stce_10001 - 1, 0);
      stce_9962(stce_9828._tape_index()) = 1.0;
      stce_9996 = new stce_9994(stce_9928->current_ref());
      if (stce_9992) {
        stce_9993.clear();
      }
      stce_9988->stce_9966(*this, *this, stce_10000, stce_9989, interpretation_settings(false, true),
                           [](index_t, typename tape_t::stce_9762) {});
      if (stce_9992) {
        for (typename std::map<index_t, stce_9762>::const_iterator stce_10006 = stce_9993.cbegin();
             stce_10006 != stce_9993.cend(); ++stce_10006) {
          stce_9996->insert(stce_10006->first, stce_10006->second);
        }
      }
      delete stce_9996;
    }
    stce_9988->reset_to(stce_9989);
    stce_9995 stce_10007 = stce_9928->current();
    for (typename std::vector<stce_9997*>::reverse_iterator stce_10005 = stce_9998.rbegin();
         stce_10005 != stce_9998.rend(); ++stce_10005) {
      stce_9987 stce_10008(stce_9988->current_ref());
      for (;; --stce_10007) {
        stce_10008.insert(stce_10007->arg(), stce_10007->pval());
        if (stce_10007->stce_10009())
          break;
      }
      --stce_10007;
      (*stce_10005)->_tape_index() = stce_10008.index();
    }
    stce_9998.clear();
  }
  stce_9762& stce_9962(const index_t stce_9813) { return stce_9899[stce_9813 - stce_9990]; }
  template <class stce_9964>
  void _increment_adjoint(const index_t& stce_9813, const stce_9964& stce_9965, const stce_9762& stce_9925) {
    _increment_adjoint(stce_9813, stce_9965 * stce_9925);
  }
  void stce_9950(index_t stce_9874, index_t stce_9875) { stce_9899.stce_9950(stce_9874, stce_9875); }
  void stce_9952(index_t stce_9813) { stce_9899.stce_9952(stce_9813 - stce_9990); }
  stce_9762& operator[](const index_t stce_9813) { return stce_9899[stce_9813 - stce_9990]; }
  template <typename iterator_t> void stce_9948(iterator_t& stce_9828) {
    _increment_adjoint(stce_9828->arg(), stce_9828->pval() * (*this)[stce_9828.index()]);
  }
  virtual stce_9762 _read_adjoint(const index_t stce_9813) { return stce_9899[stce_9813 - stce_9990]; }
  virtual void _increment_adjoint(const index_t stce_9813, const stce_9762& stce_9925) {
    if (stce_9925 == 0)
      return;
    if (stce_9813 <= stce_9990) {
      if (stce_9992 == false) {
        stce_9996->insert(stce_9813, stce_9925);
      } else {
        stce_9993[stce_9813] += stce_9925;
      }
    } else {
      stce_9962(stce_9813) += stce_9925;
    }
  }
};
template <> struct jacobian_preaccumulator_t<void> {
  jacobian_preaccumulator_t(void*) {}
  void start() {}
  template <typename stce_9780> void register_output(const stce_9780&) {}
  void finish() {}
};
} // namespace internal
} // namespace dco

namespace dco {
namespace helper {
template <typename, typename stce_10010> struct stce_10011 {
  stce_10011(stce_10010*) {}
  template <typename stce_9780> void register_input(const stce_9780&) {}
  template <typename stce_9780> void register_output(const stce_9780&) {}
};
} // namespace helper
} // namespace dco

namespace dco {
namespace helper {
template <typename stce_10012> class stce_10013 {
  template <memory_model::TYPE, typename, memory_model::TYPE> friend class internal::tape;
  typedef typename stce_10012::stce_9938 stce_9762;

protected:
  stce_10012* stce_10014;

public:
  virtual ~stce_10013() {}
  dco::adjoint_vector_abstract<stce_9762>* _adjoint_vector;

public:
  void set_tape(stce_10012* stce_10015) {
    if (stce_10014 != 0) {
      return;
    } else {
      stce_10014 = stce_10015;
    }
  }
  void stce_10016() {}
  inline stce_10012* get_tape() { return stce_10014; }
  stce_10013() : stce_10014(0) {}
  virtual void stce_10017(stce_9861& stce_9862, index_t stce_9870) {
    (void)stce_9862;
    (void)stce_9870;
  }
  virtual mem_long_t size_in_byte() { return sizeof(stce_10012); }
};
} // namespace helper
} // namespace dco

namespace dco {
namespace helper {
template <class stce_10018, class stce_10012> class stce_10019 : public stce_10013<stce_10012> {
private:
  class stce_10020 {
  public:
    virtual ~stce_10020(){};
    virtual mem_long_t size_in_byte() = 0;
    virtual void stce_10021(const std::string&, const std::string&){};
  };
  template <typename stce_10022> class stce_10023 : public stce_10020 {
  public:
    const stce_10022 _data;
    stce_10023(const stce_10022& stce_10024) : _data(stce_10024) {}
    const stce_10022& stce_10025() const { return _data; }
  };
  template <typename stce_10022> class stce_10026 : public stce_10023<stce_10022> {
  public:
    stce_10026(stce_10022 data) : stce_10023<stce_10022>(data) {}
    virtual ~stce_10026() {}
    virtual mem_long_t size_in_byte() { return size_of(stce_10023<stce_10022>::_data); }
    virtual void stce_10021(const std::string& stce_10027, const std::string& stce_10028) {
      if (false && IS_DEBUG && stce_10028 != stce_10027) {
        std::stringstream stce_10029;
        stce_10029 << "read_data error: tried to read " << stce_10027 << " instead of " << stce_10028 << "!";
        throw dco::exception::create<std::runtime_error>(stce_10029.str());
      }
    }
  };
  template <typename stce_10022> class stce_10030 : public stce_10023<stce_10022*> {
  public:
    const index_t stce_10031;
    stce_10030(const stce_10022* data, index_t stce_10032)
        : stce_10023<stce_10022*>(new stce_10022[size_t(stce_10032)]), stce_10031(stce_10032) {
      for (index_t stce_9847 = 0; stce_9847 < stce_10032; ++stce_9847)
        this->_data[stce_9847] = data[stce_9847];
    }
    stce_10030(const stce_10022* data, const index_t stce_9923, const index_t stce_10032)
        : stce_10023<stce_10022*>(new stce_10022[stce_9752(stce_10032)]), stce_10031(stce_10032) {
      for (index_t stce_9847 = 0, stce_9813 = 0; stce_9847 < stce_10032; ++stce_9847, stce_9813 += stce_9923)
        this->_data[stce_9847] = data[stce_9813];
    }
    virtual ~stce_10030() { delete[] this->_data; }
    virtual mem_long_t size_in_byte() { return stce_10031 * static_cast<index_t>(sizeof(stce_10022)); }
    virtual void stce_10021(const std::string& stce_10027, const std::string& stce_10028) {
      (void)stce_10027;
      (void)stce_10028;
      if (false && IS_DEBUG && stce_10028 + "*" != stce_10027) {
        std::stringstream stce_10029;
        stce_10029 << "read_data error: tried to read " << stce_10027 << " instead of " << stce_10028 << "!";
        throw dco::exception::create<std::runtime_error>(stce_10029.str());
      }
    }
  };
  index_t stce_10033;
  std::vector<stce_10020*> stce_10034;
  std::vector<std::string> stce_10035;

protected:
  virtual ~stce_10019() {
    for (size_t stce_9847 = 0; stce_9847 < stce_10034.size(); stce_9847++)
      delete stce_10034[stce_9847];
    stce_10034.clear();
  }

public:
  stce_10019() : stce_10013<stce_10012>(), stce_10033(0) {}
  virtual mem_long_t size_in_byte() {
    mem_long_t stce_9820 = stce_10013<stce_10012>::size_in_byte();
    for (size_t stce_9847 = 0; stce_9847 < stce_10034.size(); stce_9847++) {
      stce_9820 += stce_10034[stce_9847]->size_in_byte();
    }
    stce_9820 += stce_10034.size() * sizeof(stce_10020*);
    stce_9820 += stce_10035.size() * sizeof(std::string);
    return stce_9820;
  }
  template <typename stce_10022> void write_data(const stce_10022& stce_10036) {
    stce_10034.push_back(new stce_10026<stce_10022>(stce_10036));
    if (IS_DEBUG)
      stce_10035.push_back(type_name<stce_10022>());
  }
  template <typename stce_10022> void write_data(const stce_10022* const stce_10036, const index_t stce_10032) {
    stce_10034.push_back(new stce_10030<stce_10022>(stce_10036, stce_10032));
    if (IS_DEBUG)
      stce_10035.push_back(type_name<stce_10022>());
  }
  template <typename stce_10022>
  void write_data(const stce_10022* const& stce_10036, const index_t stce_9923, const index_t stce_10032) {
    stce_10034.push_back(new stce_10030<stce_10022>(stce_10036, stce_9923, stce_10032));
    if (IS_DEBUG) {
      stce_10035.push_back(type_name<stce_10022>());
    }
  }
  template <typename stce_10022> const stce_10022& read_data() {
    const stce_10022& stce_10036 = static_cast<stce_10023<stce_10022>*>(stce_10034[stce_10033])->stce_10025();
    if (IS_DEBUG)
      stce_10034[stce_10033]->stce_10021(type_name<stce_10022>(), stce_10035.at(stce_10033));
    ++stce_10033;
    if (stce_10033 == static_cast<index_t>(stce_10034.size()))
      stce_10033 = 0;
    return stce_10036;
  }
};
} // namespace helper
} // namespace dco

namespace dco {
namespace helper {
template <class stce_10018, class stce_10012>
class stce_10037 : public stce_10019<stce_10018, stce_10012>,
                   public stce_10011<stce_10012, stce_10037<stce_10018, stce_10012>> {
  typedef stce_10011<stce_10012, stce_10037> stce_10038;
  bool stce_10039;

protected:
  std::vector<index_t> stce_9868;
  std::vector<index_t> stce_9869;
  size_t stce_10040;
  size_t stce_10041;

public:
  stce_10012*& tape() { return this->stce_10014; }
  virtual mem_long_t size_in_byte() {
    mem_long_t stce_9820 = stce_10019<stce_10018, stce_10012>::size_in_byte();
    stce_9820 += stce_9868.size() * sizeof(index_t);
    stce_9820 += stce_9869.size() * sizeof(index_t);
    stce_9820 += 2 * sizeof(index_t);
    return stce_9820;
  }
  size_t stce_10042() { return stce_9868.size(); }
  size_t stce_10043() { return stce_9869.size(); }
  void stce_10016() { stce_10039 = true; }
  void stce_10017(stce_9861& stce_9862, index_t stce_9870) {
    stce_9862.stce_9867(stce_9868, stce_9869, stce_9870 - static_cast<index_t>(stce_9869.size()) - 1);
  }

public:
  void stce_10044(const stce_10018& stce_9810) {
    if ((stce_9810.tape() != 0) && (this->stce_10014 != stce_9810.tape()))
      throw dco::exception::create<std::runtime_error>("impossible binding tape - wrong tape in variable!");
    if (this->stce_10039 == true) {
      throw dco::exception::create<std::runtime_error>(
          "Input registration required, but callback already inserted; please check ordering.");
    }
  }
  void stce_10045() {
    if (this->stce_10014 == NULL) {
      throw dco::exception::create<std::runtime_error>("Output registration required, but no tape available.");
    }
    if (this->stce_10039 == true) {
      throw dco::exception::create<std::runtime_error>(
          "Output registration required, but callback already inserted; please check ordering.");
    }
  }

protected:
  ~stce_10037() {
    if (IS_DEBUG && stce_10040 != 0) {
      DCO_LOG(dco::logERROR) << "not all input adjoints incremented in external adjoint object.";
    }
    if (IS_DEBUG && stce_10041 != 0) {
      DCO_LOG(dco::logERROR) << "not all output adjoints read in external adjoint object.";
    }
  }

public:
  stce_10037(const std::pair<size_t, size_t>& stce_10046)
      : stce_10019<stce_10018, stce_10012>(), stce_10038(this), stce_10039(false), stce_10040(0), stce_10041(0) {
    stce_9868.reserve(stce_10046.first);
    stce_9869.reserve(stce_10046.second);
  }
  stce_10037()
      : stce_10019<stce_10018, stce_10012>(), stce_10038(this), stce_10039(false), stce_10040(0), stce_10041(0) {}
  typename stce_10018::VALUE_TYPE register_input(const stce_10018& stce_9810) {
    stce_10044(stce_9810);
    const index_t stce_9813 = stce_9810._tape_index();
    stce_9868.push_back(stce_9813);
    stce_10038::register_input(stce_9810);
    return stce_9810._value();
  }
  void register_input(const stce_10018* const stce_9810, typename stce_10018::VALUE_TYPE* stce_10047,
                      const size_t stce_10032) {
    stce_9868.reserve(stce_9868.size() + stce_10032);
    for (size_t stce_9847 = 0; stce_9847 < stce_10032; ++stce_9847) {
      stce_10044(stce_9810[stce_9847]);
      const index_t stce_9813 = stce_9810[stce_9847]._tape_index();
      stce_9868.push_back(stce_9813);
      stce_10047[stce_9847] = stce_9810[stce_9847]._value();
      stce_10038::register_input(stce_9810[stce_9847]);
    }
  }
  void register_input(const std::vector<stce_10018>& stce_9810,
                      std::vector<typename stce_10018::VALUE_TYPE>& stce_10047) {
    assert(stce_9810.size() == stce_10047.size());
    register_input(&(stce_9810[0]), &(stce_10047[0]), stce_9810.size());
  }
  std::vector<typename stce_10018::VALUE_TYPE> register_input(const std::vector<stce_10018>& stce_9810) {
    std::vector<typename stce_10018::VALUE_TYPE> stce_10047(stce_9810.size());
    register_input(stce_9810, stce_10047);
    return stce_10047;
  }
  void register_output(stce_10018* stce_10048, const size_t stce_10032) {
    register_output(NULL, stce_10048, stce_10032);
  }
  void register_output(const typename stce_10018::VALUE_TYPE* const stce_10049, stce_10018* stce_10048,
                       const size_t stce_10032) {
    stce_10045();
    stce_9869.reserve(stce_9869.size() + stce_10032);
    for (size_t stce_9847 = 0; stce_9847 < stce_10032; ++stce_9847) {
      if (stce_10049) {
        stce_10048[stce_9847] = stce_10049[stce_9847];
      }
      this->stce_10014->register_variable(stce_10048[stce_9847]);
      stce_9869.push_back(stce_10048[stce_9847]._tape_index());
      stce_10038::register_output(stce_10048[stce_9847]);
    }
  }
  void register_output(const std::vector<typename stce_10018::VALUE_TYPE>& stce_10049,
                       std::vector<stce_10018>& stce_10048) {
    assert(stce_10049.size() == stce_10048.size());
    register_output(&(stce_10049[0]), &(stce_10048[0]), stce_10049.size());
  }
  std::vector<stce_10018> register_output(const std::vector<typename stce_10018::VALUE_TYPE>& stce_10049) {
    std::vector<stce_10018> stce_10048(stce_10049.size());
    register_output(stce_10049, stce_10048);
    return stce_10048;
  }
  void register_output(std::vector<stce_10018>& stce_10048) { register_output(&(stce_10048[0]), stce_10048.size()); }
  stce_10018 register_output(const typename stce_10018::VALUE_TYPE& stce_10050, stce_10012* tape = NULL) {
    stce_10018 stce_10051;
    if (tape != NULL) {
      if (this->stce_10014 != NULL && this->stce_10014 != tape) {
        throw dco::exception::create<std::runtime_error>(
            "impossible binding output in external function (register_output) - tape of inputs and outputs differ!");
      }
      this->stce_10014 = tape;
    }
    stce_10045();
    stce_10051 = stce_10050;
    this->stce_10014->register_variable(stce_10051);
    stce_9869.push_back(stce_10051._tape_index());
    stce_10038::register_output(stce_10051);
    return stce_10051;
  }
  inline typename dco::mode<stce_10018>::stce_9985 get_output_adjoint() {
    size_t stce_9813 = stce_10041;
    stce_10041++;
    if (stce_10041 == stce_9869.size())
      stce_10041 = 0;
    typename dco::mode<stce_10018>::stce_9985 back = this->_adjoint_vector->_read_adjoint(stce_9869[stce_9813]);
    return back;
  }
  void get_output_adjoint(typename stce_10018::VALUE_TYPE* stce_9814, const size_t stce_10032) {
    for (size_t stce_9847 = 0; stce_9847 < stce_10032; ++stce_9847) {
      stce_9814[stce_9847] = get_output_adjoint();
    }
  }
  void get_output_adjoint(std::vector<typename stce_10018::VALUE_TYPE>& stce_9814) {
    assert(stce_9814.size());
    get_output_adjoint(&(stce_9814[0]), stce_9814.size());
  }
  void increment_input_adjoint(const typename stce_10018::VALUE_TYPE* const stce_9925, const size_t stce_10032) {
    for (size_t stce_9847 = 0; stce_9847 < stce_10032; ++stce_9847) {
      this->_adjoint_vector->_increment_adjoint(stce_9868[stce_10040 + stce_9847], stce_9925[stce_9847]);
    }
    stce_10040 += stce_10032;
    if (stce_10040 == stce_9868.size())
      stce_10040 = 0;
  }
  void increment_input_adjoint(const std::vector<typename stce_10018::VALUE_TYPE>& stce_9925) {
    assert(stce_9925.size() != 0);
    increment_input_adjoint(&(stce_9925[0]), stce_9925.size());
  }
  bool stce_10052() { return (stce_10040 == 0); }
  bool stce_10053() { return (stce_10041 == 0); }
  void increment_input_adjoint(const typename dco::mode<stce_10018>::stce_9985& stce_9925) {
    size_t stce_9813 = stce_10040;
    stce_10040++;
    if (stce_10040 == stce_9868.size())
      stce_10040 = 0;
    this->_adjoint_vector->_increment_adjoint(stce_9868[stce_9813], stce_9925);
  }
};
} // namespace helper
} // namespace dco

namespace dco {
namespace ACM {
template <class stce_10012, class stce_10054> struct baseclass : dco::helper::stce_10013<stce_10012> {
private:
  std::vector<stce_10054*> stce_10055;
  std::vector<stce_10054*> stce_10056;
  std::vector<index_t> stce_10057;
  std::vector<index_t> stce_10058;
  std::vector<void*> _data;
  int stce_10059;

public:
  typedef stce_10054 active_t;
  typedef stce_10012 tape_t;
  baseclass(tape_t* tape) : stce_10059(0) { this->set_tape(tape); }
  size_t register_input(stce_10054& stce_9810) {
    size_t stce_9849 = stce_10055.size();
    stce_10055.push_back(&stce_9810);
    stce_10058.push_back(stce_9810._tape_index());
    return stce_9849;
  }
  size_t register_input(std::vector<stce_10054>& stce_10060) {
    size_t stce_9849 = stce_10055.size();
    for (int stce_9847 = 0; stce_9847 < stce_10060.size(); ++stce_9847) {
      const stce_10054& stce_10061 = stce_10060[stce_9847];
      this->register_input(stce_10061);
    }
    return stce_9849;
  }
  size_t register_output(stce_10054& stce_9810) {
    if (stce_9810._tape_index() == 0) {
      this->get_tape()->register_variable(stce_9810);
    }
    size_t stce_9849 = stce_10056.size();
    stce_10056.push_back(&stce_9810);
    stce_10057.push_back(stce_9810._tape_index());
    return stce_9849;
  }
  int register_output(std::vector<stce_10054>& stce_10060) {
    int stce_9849 = stce_10056.size();
    for (int stce_9847 = 0; stce_9847 < stce_10060.size(); ++stce_9847) {
      if (stce_10060[stce_9847]._tape_index() == 0) {
        this->get_tape()->register_variable(stce_10060[stce_9847]);
      }
      stce_10057.push_back(stce_10060[stce_9847]._tape_index());
      stce_10056.push_back(&stce_10060[stce_9847]);
    }
    return stce_9849;
  }
  template <typename stce_9780> int write_data(const stce_9780& data) {
    stce_9780* stce_10062 = new stce_9780(data);
    int stce_9849 = _data.size();
    _data.push_back(stce_10062);
    return stce_9849;
  }
  template <typename stce_9780> const stce_9780& read_data(const int stce_10063 = -1) {
    int stce_9813 = 0;
    if (stce_10063 == -1) {
      stce_9813 = stce_10059 % _data.size();
      stce_10059++;
    }
    void* stce_10064 = _data[stce_9813];
    return *static_cast<stce_9780*>(stce_10064);
  }
  size_t stce_10065() { return stce_10055.size(); }
  size_t stce_10066() { return stce_10055.size(); }
  typename stce_10054::VALUE_TYPE& input_value(const int stce_9813) { return stce_10055[stce_9813]->_value(); }
  typename stce_10054::VALUE_TYPE& output_value(const int stce_9813) { return stce_10056[stce_9813]->_value(); }
  typename dco::mode<stce_10054>::stce_9985& input_adjoint(const int stce_9813) {
    return this->get_tape()->_adjoint(stce_10058[stce_9813]);
  }
  typename dco::mode<stce_10054>::stce_9985& output_adjoint(const int stce_9813) {
    return this->get_tape()->_adjoint(stce_10057[stce_9813]);
  }
  virtual void evaluate_primal() { std::cout << "WARNING: you need to implement evaluate_primal!!!!\n"; }
  virtual void evaluate_augmented_primal() {
    std::cout << "WARNING: you need to implement evaluate_augmented_primal!!!!\n";
  }
  virtual void evaluate_adjoint() { std::cout << "WARNING: you need to implement evaluate_adjoint!!!!\n"; }
};
template <class stce_10012, class stce_10054> static void stce_10067(baseclass<stce_10012, stce_10054>* stce_10068) {
  stce_10068->evaluate_adjoint();
}
} // namespace ACM
} // namespace dco
namespace dco {
namespace stce_10069 {
template <class stce_10070> struct stce_10071 {
  std::vector<stce_10070*> stce_10055;
  std::vector<stce_10070*> stce_10056;
  std::vector<void*> _data;
  int stce_10059;
  stce_10071() : stce_10059(0) {}
  virtual ~stce_10071() {}
  template <typename stce_9780> int write_data(const stce_9780& data) {
    stce_9780* stce_10062 = new stce_9780(data);
    int stce_9849 = _data.size();
    _data.push_back(stce_10062);
    return stce_9849;
  }
  template <typename stce_9780> const stce_9780& read_data(const int stce_10063 = -1) {
    int stce_9813 = 0;
    if (stce_10063 == -1) {
      stce_9813 = stce_10059 % _data.size();
      stce_10059++;
    }
    void* stce_10064 = _data[stce_9813];
    return *static_cast<stce_9780*>(stce_10064);
  }
  size_t stce_10065() { return stce_10055.size(); }
  size_t stce_10066() { return stce_10056.size(); }
  stce_10070& input_value(const int stce_9813) { return *stce_10055[stce_9813]; }
  stce_10070& output_value(const int stce_9813) { return *stce_10056[stce_9813]; }
  virtual void evaluate_primal() { std::cout << "WARNING: you need to implement evaluate_primal!!!!\n"; }
};
template <class stce_10070> struct stce_10072 : stce_10071<stce_10070> {
  int register_input(stce_10070& stce_9810) {
    int stce_9849 = this->stce_10055.size();
    this->stce_10055.push_back(&stce_9810);
    return stce_9849;
  }
  int register_input(std::vector<stce_10070>& stce_10060) {
    int stce_9849 = this->stce_10055.size();
    for (int stce_9847 = 0; stce_9847 < stce_10060.size(); ++stce_9847) {
      const stce_10070& stce_10061 = stce_10060[stce_9847];
      this->register_input(stce_10061);
    }
    return stce_9849;
  }
  int register_output(stce_10070& stce_9810) {
    int stce_9849 = this->stce_10056.size();
    this->stce_10056.push_back(&stce_9810);
    return stce_9849;
  }
  int register_output(std::vector<stce_10070>& stce_10060) {
    int stce_9849 = this->stce_10056.size();
    for (int stce_9847 = 0; stce_9847 < stce_10060.size(); ++stce_9847) {
      register_output(stce_10060[stce_9847]);
    }
    return stce_9849;
  }
};
template <class stce_10012, class stce_10054>
struct stce_10073 : public dco::helper::stce_10013<stce_10012>, public stce_10071<stce_10054> {
private:
  std::vector<index_t> stce_10057;
  std::vector<index_t> stce_10058;

public:
  typedef stce_10054 active_t;
  typedef stce_10012 tape_t;
  stce_10073(tape_t* tape) { this->set_tape(tape); }
  stce_10054& stce_10074(const int stce_9813) { return *(this->stce_10055[stce_9813]); }
  stce_10054& stce_10075(const int stce_9813) { return *(this->stce_10056[stce_9813]); }
  typename stce_10054::VALUE_TYPE& input_value(const int stce_9813) { return this->stce_10055[stce_9813]->_value(); }
  typename stce_10054::VALUE_TYPE& output_value(const int stce_9813) { return this->stce_10056[stce_9813]->_value(); }
  typename dco::mode<stce_10054>::stce_9985& input_adjoint(const int stce_9813) {
    return this->get_tape()->_adjoint(stce_10058[stce_9813]);
  }
  typename dco::mode<stce_10054>::stce_9985& output_adjoint(const int stce_9813) {
    return this->get_tape()->_adjoint(stce_10057[stce_9813]);
  }
  int register_input(stce_10054& stce_9810) {
    int stce_9849 = this->stce_10055.size();
    this->stce_10055.push_back(&stce_9810);
    this->stce_10058.push_back(stce_9810._tape_index());
    return stce_9849;
  }
  int register_input(std::vector<stce_10054>& stce_10060) {
    int stce_9849 = this->stce_10055.size();
    for (int stce_9847 = 0; stce_9847 < stce_10060.size(); ++stce_9847) {
      const stce_10054& stce_10061 = stce_10060[stce_9847];
      this->register_input(stce_10061);
    }
    return stce_9849;
  }
  int register_output(stce_10054& stce_9810) {
    if (stce_9810._tape_index() == 0) {
      this->get_tape()->register_variable(stce_9810);
    }
    int stce_9849 = this->stce_10056.size();
    this->stce_10056.push_back(&stce_9810);
    this->stce_10057.push_back(stce_9810._tape_index());
    return stce_9849;
  }
  int register_output(std::vector<stce_10054>& stce_10060) {
    int stce_9849 = this->stce_10056.size();
    for (int stce_9847 = 0; stce_9847 < stce_10060.size(); ++stce_9847) {
      if (stce_10060[stce_9847]._tape_index() == 0) {
        this->get_tape()->register_variable(stce_10060[stce_9847]);
      }
      this->stce_10057.push_back(stce_10060[stce_9847]._tape_index());
      this->stce_10056.push_back(&stce_10060[stce_9847]);
    }
    return stce_9849;
  }
  virtual void evaluate_augmented_primal() {
    std::cout << "WARNING: you need to implement evaluate_augmented_primal!!!!\n";
  }
  virtual void evaluate_adjoint() { std::cout << "WARNING: you need to implement evaluate_adjoint!!!!\n"; }
};
template <class stce_10012, class stce_10054> static void stce_10067(stce_10073<stce_10012, stce_10054>* stce_10068) {
  stce_10068->evaluate_adjoint();
}
} // namespace stce_10069
} // namespace dco

namespace dco {
namespace internal {
template <class stce_10054> class stce_10076 {
private:
  typedef typename dco::mode<stce_10054>::tape_t tape_t;
  typedef typename tape_t::stce_9761 stce_9761;
  typedef typename tape_t::edge_inserter edge_inserter;
  stce_10054& stce_10077;
  edge_inserter stce_9996;
  stce_10076(const stce_10076&);

public:
  stce_10076(stce_10054& stce_10078) : stce_10077(stce_10078), stce_9996(stce_10078.tape()->current_ref()) {}
  template <typename stce_9795> void put(const stce_9795& stce_9810, const stce_9761& stce_9965) {
    index_t stce_10079 = stce_9810._tape_index();
    if (!HAS_TAPE_ACTIVITY_CHECK || stce_10079 != 0) {
      bool stce_10080 = (stce_9996.index() == 0);
      stce_9996.insert(stce_10079, stce_9965);
      stce_10077._tape_index() = stce_9996.index();
      if (stce_10080)
        stce_10077.stce_10081(stce_10077._value(), stce_9827());
    }
  }
};
} // namespace internal
} // namespace dco

namespace dco {
namespace internal {
template <class stce_9790> struct stce_10082 {
  typedef typename stce_9790::tape_t::stce_9762 derivative_t;

protected:
  mutable index_t stce_10083;

public:
  stce_10082() : stce_10083(0) {}
  DCO_STRONG_INLINE stce_10082(const stce_10082& stce_10084) : stce_10083(stce_10084.stce_10083) {}
  DCO_STRONG_INLINE stce_10082& operator=(const stce_10082& stce_9810) {
    stce_10083 = stce_9810.stce_10083;
    return *this;
  }
  void clear() { stce_10083 = 0; }
  derivative_t& stce_9969() const { return _adjoint(); }
  derivative_t& _adjoint() const {
    if (IS_DEBUG && !stce_9790::global_tape)
      throw dco::exception::create<std::runtime_error>(
          "Tape not created yet. Please use tape_t::create() before accessing derivative components of adjoint types.");
    return stce_9790::global_tape->_adjoint(stce_10083);
  }
  void stce_10085(const derivative_t& stce_9848) const {
    if (IS_DEBUG && !stce_9790::global_tape)
      throw dco::exception::create<std::runtime_error>(
          "Tape not created yet. Please use tape_t::create() before accessing derivative components of adjoint types.");
    stce_9790::global_tape->_adjoint(stce_10083) = stce_9848;
  }
  bool _is_registered() const { return stce_10083 == 0 ? false : true; }
  index_t& _tape_index() const { return stce_10083; }
  template <class stce_10070> DCO_STRONG_INLINE void stce_10081(const stce_10070&, const double&) {}
  template <typename stce_10086>
  static DCO_STRONG_INLINE void register_variable(stce_10086& stce_9810, index_t index, typename stce_9790::tape_t*) {
    if (IS_DEBUG && !stce_9790::global_tape) {
      throw dco::exception::create<std::runtime_error>("Global tape not yet created (is NULL).");
    }
    stce_9810.stce_10083 = index;
  }
  static typename stce_9790::tape_t* tape() { return stce_9790::global_tape; }
  void set_tape(typename stce_9790::tape_t*) {}
};
} // namespace internal
} // namespace dco

namespace dco {
namespace internal {
struct stce_10087 {
  template <class stce_10088, class stce_10089>
  static auto stce_10090(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() == stce_10092._value()) {
    return stce_10091._value() == stce_10092._value();
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10093(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() == stce_10092) {
    return stce_10091._value() == stce_10092;
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10094(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091 == stce_10092._value()) {
    return stce_10091 == stce_10092._value();
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10095(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() != stce_10092._value()) {
    return stce_10091._value() != stce_10092._value();
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10096(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() != stce_10092) {
    return stce_10091._value() != stce_10092;
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10097(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091 != stce_10092._value()) {
    return stce_10091 != stce_10092._value();
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10098(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() < stce_10092._value()) {
    return stce_10091._value() < stce_10092._value();
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10099(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() < stce_10092) {
    return stce_10091._value() < stce_10092;
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10100(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091 < stce_10092._value()) {
    return stce_10091 < stce_10092._value();
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10101(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() <= stce_10092._value()) {
    return stce_10091._value() <= stce_10092._value();
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10102(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() <= stce_10092) {
    return stce_10091._value() <= stce_10092;
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10103(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091 <= stce_10092._value()) {
    return stce_10091 <= stce_10092._value();
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10104(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() > stce_10092._value()) {
    return stce_10091._value() > stce_10092._value();
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10105(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() > stce_10092) {
    return stce_10091._value() > stce_10092;
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10106(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091 > stce_10092._value()) {
    return stce_10091 > stce_10092._value();
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10107(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() >= stce_10092._value()) {
    return stce_10091._value() >= stce_10092._value();
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10108(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() >= stce_10092) {
    return stce_10091._value() >= stce_10092;
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10109(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091 >= stce_10092._value()) {
    return stce_10091 >= stce_10092._value();
  }
};
template <class stce_10110, stce_10110*& stce_9988> struct stce_10111 {
  template <class stce_10088, class stce_10089>
  static bool stce_10090(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9849 = stce_10091._value() == stce_10092._value();
    const bool stce_10112 = stce_10091.stce_10113(0) == stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091.stce_10113(1) == stce_10092.stce_10113(1);
    stce_9988->stce_10115("compare_AA", stce_9849, stce_10112, stce_10114);
    return stce_9849;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10093(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9849 = stce_10091._value() == stce_10092;
    const bool stce_10112 = stce_10091.stce_10113(0) == stce_10092;
    const bool stce_10114 = stce_10091.stce_10113(1) == stce_10092;
    stce_9988->stce_10115("compare_AP", stce_9849, stce_10112, stce_10114);
    return stce_9849;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10094(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9849 = stce_10091 == stce_10092._value();
    const bool stce_10112 = stce_10091 == stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091 == stce_10092.stce_10113(1);
    stce_9988->stce_10115("compare_PA", stce_9849, stce_10112, stce_10114);
    return stce_9849;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10095(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9849 = stce_10091._value() != stce_10092._value();
    const bool stce_10112 = stce_10091.stce_10113(0) != stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091.stce_10113(1) != stce_10092.stce_10113(1);
    stce_9988->stce_10115("compare_AA", stce_9849, stce_10112, stce_10114);
    return stce_9849;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10096(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9849 = stce_10091._value() != stce_10092;
    const bool stce_10112 = stce_10091.stce_10113(0) != stce_10092;
    const bool stce_10114 = stce_10091.stce_10113(1) != stce_10092;
    stce_9988->stce_10115("compare_AP", stce_9849, stce_10112, stce_10114);
    return stce_9849;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10097(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9849 = stce_10091 != stce_10092._value();
    const bool stce_10112 = stce_10091 != stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091 != stce_10092.stce_10113(1);
    stce_9988->stce_10115("compare_PA", stce_9849, stce_10112, stce_10114);
    return stce_9849;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10098(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9849 = stce_10091._value() < stce_10092._value();
    const bool stce_10112 = stce_10091.stce_10113(0) < stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091.stce_10113(1) < stce_10092.stce_10113(1);
    stce_9988->stce_10115("compare_AA", stce_9849, stce_10112, stce_10114);
    return stce_9849;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10099(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9849 = stce_10091._value() < stce_10092;
    const bool stce_10112 = stce_10091.stce_10113(0) < stce_10092;
    const bool stce_10114 = stce_10091.stce_10113(1) < stce_10092;
    stce_9988->stce_10115("compare_AP", stce_9849, stce_10112, stce_10114);
    return stce_9849;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10100(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9849 = stce_10091 < stce_10092._value();
    const bool stce_10112 = stce_10091 < stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091 < stce_10092.stce_10113(1);
    stce_9988->stce_10115("compare_PA", stce_9849, stce_10112, stce_10114);
    return stce_9849;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10101(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9849 = stce_10091._value() <= stce_10092._value();
    const bool stce_10112 = stce_10091.stce_10113(0) <= stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091.stce_10113(1) <= stce_10092.stce_10113(1);
    stce_9988->stce_10115("compare_AA", stce_9849, stce_10112, stce_10114);
    return stce_9849;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10102(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9849 = stce_10091._value() <= stce_10092;
    const bool stce_10112 = stce_10091.stce_10113(0) <= stce_10092;
    const bool stce_10114 = stce_10091.stce_10113(1) <= stce_10092;
    stce_9988->stce_10115("compare_AP", stce_9849, stce_10112, stce_10114);
    return stce_9849;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10103(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9849 = stce_10091 <= stce_10092._value();
    const bool stce_10112 = stce_10091 <= stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091 <= stce_10092.stce_10113(1);
    stce_9988->stce_10115("compare_PA", stce_9849, stce_10112, stce_10114);
    return stce_9849;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10104(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9849 = stce_10091._value() > stce_10092._value();
    const bool stce_10112 = stce_10091.stce_10113(0) > stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091.stce_10113(1) > stce_10092.stce_10113(1);
    stce_9988->stce_10115("compare_AA", stce_9849, stce_10112, stce_10114);
    return stce_9849;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10105(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9849 = stce_10091._value() > stce_10092;
    const bool stce_10112 = stce_10091.stce_10113(0) > stce_10092;
    const bool stce_10114 = stce_10091.stce_10113(1) > stce_10092;
    stce_9988->stce_10115("compare_AP", stce_9849, stce_10112, stce_10114);
    return stce_9849;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10106(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9849 = stce_10091 > stce_10092._value();
    const bool stce_10112 = stce_10091 > stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091 > stce_10092.stce_10113(1);
    stce_9988->stce_10115("compare_PA", stce_9849, stce_10112, stce_10114);
    return stce_9849;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10107(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9849 = stce_10091._value() >= stce_10092._value();
    const bool stce_10112 = stce_10091.stce_10113(0) >= stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091.stce_10113(1) >= stce_10092.stce_10113(1);
    stce_9988->stce_10115("compare_AA", stce_9849, stce_10112, stce_10114);
    return stce_9849;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10108(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9849 = stce_10091._value() >= stce_10092;
    const bool stce_10112 = stce_10091.stce_10113(0) >= stce_10092;
    const bool stce_10114 = stce_10091.stce_10113(1) >= stce_10092;
    stce_9988->stce_10115("compare_AP", stce_9849, stce_10112, stce_10114);
    return stce_9849;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10109(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9849 = stce_10091 >= stce_10092._value();
    const bool stce_10112 = stce_10091 >= stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091 >= stce_10092.stce_10113(1);
    stce_9988->stce_10115("compare_PA", stce_9849, stce_10112, stce_10114);
    return stce_9849;
  }
};
} // namespace internal
} // namespace dco

namespace dco {
namespace folding {
template <class stce_10116> class stce_10117 {
public:
  typedef typename stce_10116::stce_9762 stce_9762;
  typedef typename stce_10116::stce_9761 stce_9761;
  typedef typename stce_10116::edge_inserter stce_10118;
  stce_10117(stce_10116* tape) : stce_10119(1), stce_9996(tape->current_ref()) {}
  template <class stce_10120, typename stce_9759> DCO_ALWAYS_INLINE stce_10120& stce_10121(stce_9759 const& pval) {
    stce_10119 *= static_cast<stce_9761>(pval);
    return static_cast<stce_10120&>(*this);
  }
  DCO_ALWAYS_INLINE stce_9761& pval() { return stce_10119; }
  DCO_ALWAYS_INLINE index_t index() const { return stce_9996.index(); }
  template <class stce_10086> DCO_ALWAYS_INLINE void insert(stce_10086 const& stce_9810) {
    const index_t stce_10122 = stce_9810._tape_index();
    if (!HAS_TAPE_ACTIVITY_CHECK || stce_10122 != 0) {
      if (!stce_9755 || !is_zero(stce_10119)) {
        stce_9996.insert(stce_10122, stce_10119);
      }
    }
  }

protected:
  stce_9761 stce_10119;

private:
  stce_10117();
  stce_10117(stce_10117& stce_9936);
  stce_10118 stce_9996;
};
template <class stce_10116> class stce_10123 : public stce_10117<stce_10116> {
  typedef typename stce_10116::stce_9762 stce_9762;
  typedef typename stce_10116::edge_inserter stce_10118;

public:
  stce_10123(stce_10116* tape) : stce_10117<stce_10116>(tape), stce_10124(0) {}
  template <class stce_10086> DCO_ALWAYS_INLINE void insert(stce_10086 stce_9810) {
    stce_10117<stce_10116>::insert(stce_9810);
    stce_10124 += this->stce_10119 * stce_9810.stce_9975;
  }
  stce_9762 tangent() const { return stce_10124; }

private:
  stce_10123();
  stce_10123(stce_10123& stce_9936);
  stce_9762 stce_10124;
};
template <class stce_10125, class stce_9758, class stce_10126>
DCO_ALWAYS_INLINE void interpret(const dco::internal::active_type<stce_9758, stce_10126>& stce_9810,
                                 stce_10125& stce_10127) {
  stce_10127.insert(stce_9810);
}
template <class stce_10125, class stce_9758, class stce_10128, class stce_10129, class stce_10130>
DCO_ALWAYS_INLINE void
interpret(const dco::internal::stce_9777<stce_9758, stce_10128, stce_10129, stce_10130>& stce_9810,
          stce_10125& stce_10127) {
  typename stce_10125::stce_9761 stce_10131 = stce_10127.pval();
  interpret<stce_10125>(stce_9810.stce_10132, stce_10127.template stce_10121<stce_10125>(stce_9810.stce_10133()));
  stce_10127.pval() = stce_10131;
  interpret<stce_10125>(stce_9810.stce_10134, stce_10127.template stce_10121<stce_10125>(stce_9810.stce_10135()));
}
template <class stce_10125, class stce_9758, class stce_10136, class stce_10130>
DCO_ALWAYS_INLINE void interpret(const dco::internal::stce_9774<stce_9758, stce_10136, stce_10130>& stce_9810,
                                 stce_10125& stce_10127) {
  interpret<stce_10125>(stce_9810.stce_10137, stce_10127.template stce_10121<stce_10125>(stce_9810.pval()));
}
template <class stce_10125, class stce_9758, class stce_10128, class stce_10129, class stce_10130>
DCO_ALWAYS_INLINE void
interpret(const dco::internal::stce_9778<stce_9758, stce_10128, stce_10129, stce_10130>& stce_9810,
          stce_10125& stce_10127) {
  interpret<stce_10125>(stce_9810.stce_10132, stce_10127.template stce_10121<stce_10125>(stce_9810.stce_10133()));
}
template <class stce_10125, class stce_9758, class stce_10128, class stce_10129, class stce_10130>
DCO_ALWAYS_INLINE void
interpret(const dco::internal::stce_9779<stce_9758, stce_10128, stce_10129, stce_10130>& stce_9810,
          stce_10125& stce_10127) {
  interpret<stce_10125>(stce_9810.stce_10134, stce_10127.template stce_10121<stce_10125>(stce_9810.stce_10135()));
}
template <class stce_10116> class stce_10138 {
public:
  stce_10138() : stce_9988(0) {}
  template <class stce_10086> DCO_ALWAYS_INLINE void insert(stce_10086 stce_9810) {
    if (stce_9810.tape())
      stce_9988 = stce_9810.tape();
  }
  stce_10116* tape() const { return stce_9988; }

private:
  stce_10138(stce_10138& stce_9936);
  stce_10116* stce_9988;
};
template <class stce_9758, class stce_10128, class stce_10129, class stce_10130, class stce_10116>
DCO_ALWAYS_INLINE void
interpret(const dco::internal::stce_9777<stce_9758, stce_10128, stce_10129, stce_10130>& stce_9810,
          stce_10138<stce_10116>& stce_10127) {
  interpret(stce_9810.stce_10132, stce_10127);
  if (stce_10127.tape()) {
    if (IS_DEBUG) {
      stce_10116* tape = stce_10127.tape();
      interpret(stce_9810.stce_10134, stce_10127);
      if (tape != stce_10127.tape()) {
        throw dco::exception::create<std::runtime_error>(
            "multiple tape error: different tapes on right-hand side of statement",
            "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/dco_cpp_make_release/dco_cpp_dev/src/"
            "dco_folding.hpp",
            143);
      }
    }
    return;
  }
  interpret(stce_9810.stce_10134, stce_10127);
}
template <class stce_9758, class stce_10136, class stce_10130, class stce_10116>
DCO_ALWAYS_INLINE void interpret(const dco::internal::stce_9774<stce_9758, stce_10136, stce_10130>& stce_9810,
                                 stce_10138<stce_10116>& stce_10127) {
  interpret(stce_9810.stce_10137, stce_10127);
}
template <class stce_9758, class stce_10128, class stce_10129, class stce_10130, class stce_10116>
DCO_ALWAYS_INLINE void
interpret(const dco::internal::stce_9778<stce_9758, stce_10128, stce_10129, stce_10130>& stce_9810,
          stce_10138<stce_10116>& stce_10127) {
  interpret(stce_9810.stce_10132, stce_10127);
}
template <class stce_9758, class stce_10128, class stce_10129, class stce_10130, class stce_10116>
DCO_ALWAYS_INLINE void
interpret(const dco::internal::stce_9779<stce_9758, stce_10128, stce_10129, stce_10130>& stce_9810,
          stce_10138<stce_10116>& stce_10127) {
  interpret(stce_9810.stce_10134, stce_10127);
}
} // namespace folding
} // namespace dco
namespace dco {
namespace internal {
template <typename stce_9790> class stce_10139 : public stce_10082<stce_9790> {
  typedef stce_10082<stce_9790> stce_10140;

public:
  typedef stce_9790 mode_t;
  typedef stce_10087 stce_10141;
  typedef typename stce_9790::tape_t tape_t;
  typedef typename tape_t::stce_9762 derivative_t;
  stce_10139() {}
  DCO_STRONG_INLINE stce_10139(const stce_10139& stce_10084) : stce_10140(stce_10084) {}
  DCO_STRONG_INLINE stce_10139& operator=(const stce_10139& stce_9810) {
    stce_10140::operator=(static_cast<const stce_10140&>(stce_9810));
    return *this;
  }
  template <class stce_9910> DCO_ALWAYS_INLINE void stce_9911(const stce_9910& stce_10142) {
    if (!stce_9790::global_tape || !stce_9790::global_tape->is_active()) {
      this->clear();
      return;
    }
    using namespace folding;
    stce_10117<tape_t> stce_10143(stce_9790::global_tape);
    interpret(stce_10142, stce_10143);
    this->stce_10083 = stce_10143.index();
  }
};
} // namespace internal
} // namespace dco
namespace dco {
template <typename stce_9780, typename stce_9759 = stce_9780, typename stce_9760 = stce_9759,
          memory_model::TYPE MEMORY_MODEL = DCO_TAPE_MEMORY_MODEL>
class ga1s {
  typedef types_config_t<stce_9780, stce_9759, stce_9760> stce_10144;

public:
  static const memory_model::TYPE TAPE_MODEL = MEMORY_MODEL;
  typedef ga1s mode_t;
  typedef dco::internal::stce_10139<ga1s> data_t;
  typedef typename stce_10144::value_t value_t;
  typedef value_t scalar_value_t;
  typedef typename stce_10144::value_t active_value_t;
  typedef typename stce_10144::stce_9762 derivative_t;
  typedef derivative_t stce_9985;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::active_type<value_t, data_t> type;
  typedef type active_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = true;
  static const bool is_tangent_type = false;
  static const bool stce_10145 = false;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
  typedef internal::tape<TAPE_MODEL, stce_10144> tape_t;
  static DCOi_THREAD_LOCAL tape_t* global_tape;
  typedef typename internal::stce_10076<type> local_gradient_t;
  typedef dco::helper::stce_10013<tape_t> callback_object_t;
  typedef dco::helper::stce_10019<type, tape_t> userdata_object_t;
  typedef dco::helper::stce_10037<type, tape_t> external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<type> jacobian_preaccumulator_t;
};
template <class stce_9780, class stce_9759, class stce_9760, memory_model::TYPE MEMORY_MODEL>
DCOi_THREAD_LOCAL typename ga1s<stce_9780, stce_9759, stce_9760, MEMORY_MODEL>::tape_t*
    ga1s<stce_9780, stce_9759, stce_9760, MEMORY_MODEL>::global_tape = 0;
} // namespace dco
namespace dco {
typedef ga1s<double> a1w;
typedef double w_rtype;
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_9790> class stce_10146 {
public:
  typedef typename stce_9790::tape_t tape_t;

private:
  mutable index_t stce_10083;
  mutable tape_t* stce_10147;

public:
  typedef stce_9790 mode_t;
  typedef stce_10087 stce_10141;
  typedef typename tape_t::stce_9762 derivative_t;
  stce_10146() : stce_10083(0), stce_10147(0) {}
  DCO_STRONG_INLINE stce_10146& operator=(const stce_10146& stce_9810) {
    stce_10083 = stce_9810.stce_10083;
    stce_10147 = stce_9810.stce_10147;
    return *this;
  }
  DCO_STRONG_INLINE stce_10146(const stce_10146& stce_10084)
      : stce_10083(stce_10084.stce_10083), stce_10147(stce_10084.stce_10147) {}
  void clear() {
    stce_10083 = 0;
    stce_10147 = 0;
  }
  derivative_t& stce_9969() const { return _adjoint(); }
  derivative_t& _adjoint() const {
    static derivative_t stce_9970 = static_cast<derivative_t>(0);
    if (stce_10147 == 0) {
      stce_9970 = 0;
      return stce_9970;
    } else {
      return stce_10147->_adjoint(stce_10083);
    }
  }
  void stce_10085(const derivative_t& stce_9848) const {
    if (stce_10147 != 0)
      stce_10147->_adjoint(stce_10083) = stce_9848;
  }
  bool _is_registered() const { return stce_10083 == 0 ? false : true; }
  index_t& _tape_index() const { return stce_10083; }
  template <typename stce_10070> DCO_STRONG_INLINE void stce_10081(const stce_10070&, const double&) {}
  template <typename stce_10086>
  static DCO_STRONG_INLINE void register_variable(stce_10086& stce_9810, index_t index, tape_t* tape) {
    stce_9810.stce_10147 = tape;
    stce_9810.stce_10083 = index;
  }
  tape_t* tape() const { return stce_10147; }
  void set_tape(tape_t* stce_9780) { stce_10147 = stce_9780; }
  template <class stce_9910> DCO_ALWAYS_INLINE void stce_9911(const stce_9910& stce_10142) {
    using namespace folding;
    stce_10138<tape_t> stce_10138;
    interpret(stce_10142, stce_10138);
    tape_t* stce_10148 = stce_10138.tape();
    if (!stce_10148 || !stce_10148->is_active()) {
      clear();
      return;
    }
    stce_10117<tape_t> stce_10143(stce_10148);
    interpret(stce_10142, stce_10143);
    stce_10083 = stce_10143.index();
    stce_10147 = stce_10148;
  }
};
} // namespace internal
} // namespace dco
namespace dco {
template <class stce_9780, class stce_9759 = stce_9780, class stce_9760 = stce_9759,
          memory_model::TYPE MEMORY_MODEL = DCO_TAPE_MEMORY_MODEL>
class ga1sm {
  typedef types_config_t<stce_9780, stce_9759, stce_9760> stce_10144;

public:
  static const memory_model::TYPE TAPE_MODEL = MEMORY_MODEL;
  typedef ga1sm mode_t;
  typedef dco::internal::stce_10146<ga1sm> data_t;
  typedef typename stce_10144::value_t value_t;
  typedef typename stce_10144::value_t active_value_t;
  typedef value_t scalar_value_t;
  typedef typename stce_10144::stce_9762 derivative_t;
  typedef derivative_t stce_9985;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::active_type<value_t, data_t> type;
  typedef type active_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = true;
  static const bool is_tangent_type = false;
  static const bool stce_10145 = false;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
  typedef internal::tape<TAPE_MODEL, stce_10144> tape_t;
  typedef typename internal::stce_10076<type> local_gradient_t;
  typedef dco::helper::stce_10013<tape_t> callback_object_t;
  typedef dco::helper::stce_10019<type, tape_t> userdata_object_t;
  typedef dco::helper::stce_10037<type, tape_t> external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<type> jacobian_preaccumulator_t;
};
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_9790> struct data_g {
  typedef stce_9790 mode_t;
  typedef stce_10087 stce_10141;
  typedef typename mode_t::derivative_t derivative_t;
};
} // namespace internal
} // namespace dco
namespace dco {
template <typename stce_9780> class gvalue {
public:
  typedef internal::data_g<gvalue> data_t;
  typedef typename std::decay<stce_9780>::type type;
  typedef type active_value_t;
  typedef type active_t;
  typedef type value_t;
  typedef value_t scalar_value_t;
  typedef type passive_t;
  typedef type scalar_passive_t;
  typedef void derivative_t;
  typedef void stce_9985;
  typedef stce_9807 tape_t;
  typedef void local_gradient_t;
  typedef void local_gradient_with_activity_t;
  typedef void external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<void> jacobian_preaccumulator_t;
  static const bool is_dco_type = false;
  static const bool is_adjoint_type = false;
  static const bool is_tangent_type = false;
  static const bool stce_10145 = false;
  static const int order = 0;
  static const size_t p1f_size = 0;
  static tape_t* global_tape;
};
template <typename stce_9780> typename gvalue<stce_9780>::tape_t* gvalue<stce_9780>::global_tape = 0;
} // namespace dco
namespace dco {
template <typename stce_9780> struct mode : public dco::gvalue<stce_9780> {
  static const bool is_intermediate_type = false;
};
template <typename stce_9769, typename stce_9770>
struct mode<internal::active_type<stce_9769, stce_9770>> : public stce_9770::mode_t {
  static const bool is_intermediate_type = false;
};
template <typename stce_9769, typename stce_9770>
struct mode<internal::active_type<stce_9769, stce_9770> const> : public stce_9770::mode_t {
  static const bool is_intermediate_type = false;
};
template <typename stce_9769, typename stce_9770>
struct mode<internal::active_type<stce_9769, stce_9770>&> : public stce_9770::mode_t {
  static const bool is_intermediate_type = false;
};
template <typename stce_9769, typename stce_9770>
struct mode<internal::active_type<stce_9769, stce_9770> const&> : public stce_9770::mode_t {
  static const bool is_intermediate_type = false;
};
template <typename stce_9769, typename stce_9770>
struct mode<internal::active_type<stce_9769, stce_9770>&&> : public stce_9770::mode_t {
  static const bool is_intermediate_type = false;
};
template <typename stce_9780, typename stce_10010, typename stce_10149>
struct mode<internal::stce_9774<stce_9780, stce_10010, stce_10149>>
    : public internal::stce_9774<stce_9780, stce_10010, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <typename stce_9780, typename stce_10010, typename stce_10149>
struct mode<internal::stce_9774<stce_9780, stce_10010, stce_10149> const>
    : public internal::stce_9774<stce_9780, stce_10010, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <typename stce_9780, typename stce_10010, typename stce_10149>
struct mode<internal::stce_9774<stce_9780, stce_10010, stce_10149>&>
    : public internal::stce_9774<stce_9780, stce_10010, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <typename stce_9780, typename stce_10010, typename stce_10149>
struct mode<internal::stce_9774<stce_9780, stce_10010, stce_10149> const&>
    : public internal::stce_9774<stce_9780, stce_10010, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <typename stce_9780, typename stce_10010, typename stce_10149>
struct mode<internal::stce_9774<stce_9780, stce_10010, stce_10149>&&>
    : public internal::stce_9774<stce_9780, stce_10010, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10150, class stce_10151, class stce_10149>
struct mode<internal::stce_9777<stce_9780, stce_10150, stce_10151, stce_10149>>
    : public internal::stce_9777<stce_9780, stce_10150, stce_10151, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10150, class stce_10151, class stce_10149>
struct mode<internal::stce_9777<stce_9780, stce_10150, stce_10151, stce_10149> const>
    : public internal::stce_9777<stce_9780, stce_10150, stce_10151, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10150, class stce_10151, class stce_10149>
struct mode<internal::stce_9777<stce_9780, stce_10150, stce_10151, stce_10149>&>
    : public internal::stce_9777<stce_9780, stce_10150, stce_10151, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10150, class stce_10151, class stce_10149>
struct mode<internal::stce_9777<stce_9780, stce_10150, stce_10151, stce_10149> const&>
    : public internal::stce_9777<stce_9780, stce_10150, stce_10151, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10150, class stce_10151, class stce_10149>
struct mode<internal::stce_9777<stce_9780, stce_10150, stce_10151, stce_10149>&&>
    : public internal::stce_9777<stce_9780, stce_10150, stce_10151, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10010, class stce_9877, class stce_10149>
struct mode<internal::stce_9778<stce_9780, stce_10010, stce_9877, stce_10149>>
    : public internal::stce_9778<stce_9780, stce_10010, stce_9877, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10010, class stce_9877, class stce_10149>
struct mode<internal::stce_9778<stce_9780, stce_10010, stce_9877, stce_10149> const>
    : public internal::stce_9778<stce_9780, stce_10010, stce_9877, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10010, class stce_9877, class stce_10149>
struct mode<internal::stce_9778<stce_9780, stce_10010, stce_9877, stce_10149>&>
    : public internal::stce_9778<stce_9780, stce_10010, stce_9877, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10010, class stce_9877, class stce_10149>
struct mode<internal::stce_9778<stce_9780, stce_10010, stce_9877, stce_10149> const&>
    : public internal::stce_9778<stce_9780, stce_10010, stce_9877, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10010, class stce_9877, class stce_10149>
struct mode<internal::stce_9778<stce_9780, stce_10010, stce_9877, stce_10149>&&>
    : public internal::stce_9778<stce_9780, stce_10010, stce_9877, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10010, class stce_9877, class stce_10149>
struct mode<internal::stce_9779<stce_9780, stce_10010, stce_9877, stce_10149>>
    : public internal::stce_9779<stce_9780, stce_10010, stce_9877, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10010, class stce_9877, class stce_10149>
struct mode<internal::stce_9779<stce_9780, stce_10010, stce_9877, stce_10149> const>
    : public internal::stce_9779<stce_9780, stce_10010, stce_9877, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10010, class stce_9877, class stce_10149>
struct mode<internal::stce_9779<stce_9780, stce_10010, stce_9877, stce_10149>&>
    : public internal::stce_9779<stce_9780, stce_10010, stce_9877, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10010, class stce_9877, class stce_10149>
struct mode<internal::stce_9779<stce_9780, stce_10010, stce_9877, stce_10149> const&>
    : public internal::stce_9779<stce_9780, stce_10010, stce_9877, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10010, class stce_9877, class stce_10149>
struct mode<internal::stce_9779<stce_9780, stce_10010, stce_9877, stce_10149>&&>
    : public internal::stce_9779<stce_9780, stce_10010, stce_9877, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9769, class DATA_TYPE>
struct mode<internal::stce_9771<stce_9769, DATA_TYPE>> : public DATA_TYPE::mode_t {
  static const bool is_intermediate_type = true;
};
} // namespace dco

namespace std {
template <typename stce_9780, typename stce_10152, typename stce_10153, typename stce_10154, typename stce_10155>
struct common_type<stce_9780, dco::internal::stce_9777<stce_10152, stce_10153, stce_10154, stce_10155>> {
  using type =
      typename std::common_type<typename dco::mode<stce_9780>::type, typename dco::mode<stce_10153>::type>::type;
};
template <typename stce_9780, typename stce_10152, typename stce_10150, typename stce_10155>
struct common_type<stce_9780, dco::internal::stce_9774<stce_10152, stce_10150, stce_10155>> {
  using type =
      typename std::common_type<typename dco::mode<stce_9780>::type, typename dco::mode<stce_10150>::type>::type;
};
template <typename stce_9780, typename stce_10152, typename stce_10150, typename stce_10151, typename stce_10155>
struct common_type<stce_9780, dco::internal::stce_9778<stce_10152, stce_10150, stce_10151, stce_10155>> {
  using type =
      typename std::common_type<typename dco::mode<stce_9780>::type, typename dco::mode<stce_10150>::type>::type;
};
template <typename stce_9780, typename stce_10152, typename stce_10150, typename stce_10151, typename stce_10155>
struct common_type<stce_9780, dco::internal::stce_9779<stce_10152, stce_10150, stce_10151, stce_10155>> {
  using type =
      typename std::common_type<typename dco::mode<stce_9780>::type, typename dco::mode<stce_10151>::type>::type;
};
template <typename stce_9780, typename stce_10152, typename stce_10153, typename stce_10154, typename stce_10155>
struct common_type<dco::internal::stce_9777<stce_10152, stce_10153, stce_10154, stce_10155,
                                            typename enable_if<!dco::mode<stce_9780>::is_dco_type>::type>,
                   stce_9780> {
  using type = typename std::common_type<stce_9780, typename dco::mode<stce_10153>::type>::type;
};
template <typename stce_9780, typename stce_10152, typename stce_10150, typename stce_10155>
struct common_type<dco::internal::stce_9774<stce_10152, stce_10150, stce_10155,
                                            typename enable_if<!dco::mode<stce_9780>::is_dco_type>::type>,
                   stce_9780> {
  using type = typename std::common_type<stce_9780, typename dco::mode<stce_10150>::type>::type;
};
template <typename stce_9780, typename stce_10152, typename stce_10150, typename stce_10151, typename stce_10155>
struct common_type<dco::internal::stce_9778<stce_10152, stce_10150, stce_10151, stce_10155,
                                            typename enable_if<!dco::mode<stce_9780>::is_dco_type>::type>,
                   stce_9780> {
  using type = typename std::common_type<stce_9780, typename dco::mode<stce_10150>::type>::type;
};
template <typename stce_9780, typename stce_10152, typename stce_10150, typename stce_10151, typename stce_10155>
struct common_type<dco::internal::stce_9779<stce_10152, stce_10150, stce_10151, stce_10155,
                                            typename enable_if<!dco::mode<stce_9780>::is_dco_type>::type>,
                   stce_9780> {
  using type = typename std::common_type<stce_9780, typename dco::mode<stce_10151>::type>::type;
};
} // namespace std
namespace dco {
template <typename stce_9780, typename stce_10156 = stce_9780> struct dco_type_constructable_from {
  const static bool value = false;
};
template <typename stce_9780> struct dco_explicit_type_cast_to {
  const static bool value = false;
};
} // namespace dco
namespace dco {
namespace internal {
template <class stce_9769> struct stce_10157 {
  const stce_9769 stce_9912;
  stce_10157(stce_9769 const& value) : stce_9912(value) {}
  inline const stce_9769& _value() const { return stce_9912; }
  template <typename TYPE, typename stce_10158 = typename enable_if<dco_explicit_type_cast_to<TYPE>::value>::type>
  explicit operator TYPE() {
    return static_cast<TYPE>(_value());
  }
};
template <class stce_9769, class DATA_TYPE> struct stce_9771 : public stce_10157<stce_9769> {
  stce_9771(const stce_9769& value) : stce_10157<stce_9769>(value) {}
  template <typename stce_9780 = DATA_TYPE>
  DCO_STRONG_INLINE
  operator typename dco::enable_if<is_gbcp_type<stce_9780>::value,
                                   typename stce_9915<stce_9771, stce_9780::gbcp_order>::stce_9897>::type() const {
    return stce_9915<stce_9771, stce_9780::gbcp_order>::value(*this);
  }
};
template <class stce_9769, class stce_9772, class stce_9773, typename>
struct stce_9774 : public stce_9771<stce_9769, typename stce_9772::data_t> {
  const stce_9772 DCO_TEMPORARY_REFORCOPY stce_10137;
  typedef typename stce_9772::data_t data_t;
  typedef typename data_t::mode_t::value_t VALUE_TYPE;
  typedef typename data_t::mode_t::passive_t stce_10159;
  explicit stce_9774(const stce_9772& arg)
      : stce_9771<stce_9769, data_t>(stce_9773::stce_10160(arg._value())), stce_10137(arg) {}
  inline const stce_9769 stce_10113(const int stce_9813) const {
    return stce_9773::stce_10160(stce_10137.stce_10113(stce_9813));
  }
  inline const stce_9769 pval() const { return stce_9773::stce_10161(this->_value(), stce_10137._value()); }
};
template <class stce_9769, class stce_9775, class stce_9776, class stce_9773, typename>
struct stce_9777 : public stce_9771<stce_9769, typename stce_9775::data_t> {
  const stce_9775 DCO_TEMPORARY_REFORCOPY stce_10132;
  const stce_9776 DCO_TEMPORARY_REFORCOPY stce_10134;
  typedef typename stce_9775::data_t data_t;
  typedef typename data_t::mode_t::value_t VALUE_TYPE;
  typedef typename data_t::mode_t::passive_t stce_10159;
  explicit stce_9777(const stce_9775& stce_10162, const stce_9776& stce_10163)
      : stce_9771<stce_9769, data_t>(stce_9773::stce_10160(stce_10162._value(), stce_10163._value())),
        stce_10132(stce_10162), stce_10134(stce_10163) {}
  inline const stce_9769 stce_10133() const {
    return stce_9773::stce_10164(this->_value(), stce_10132._value(), stce_10134._value());
  }
  inline const stce_9769 stce_10135() const {
    return stce_9773::stce_10165(this->_value(), stce_10132._value(), stce_10134._value());
  }
  inline const stce_9769 stce_10113(const int stce_9813) const {
    return stce_9773::stce_10160(stce_10132.stce_10113(stce_9813), stce_10134.stce_10113(stce_9813));
  }
};
template <class stce_9769, class stce_9775, class stce_9776, class stce_9773, typename>
struct stce_9778 : public stce_9771<stce_9769, typename stce_9775::data_t> {
  const stce_9775 DCO_TEMPORARY_REFORCOPY stce_10132;
  const stce_9776 stce_10134;
  typedef typename stce_9775::data_t data_t;
  typedef typename data_t::mode_t::value_t VALUE_TYPE;
  typedef typename data_t::mode_t::passive_t stce_10159;
  explicit stce_9778(const stce_9775& stce_10162, const stce_9776& stce_10163)
      : stce_9771<stce_9769, data_t>(stce_9773::stce_10160(stce_10162._value(), stce_10163)), stce_10132(stce_10162),
        stce_10134(stce_10163) {}
  inline const stce_9769 stce_10113(const int stce_9813) const {
    return stce_9773::stce_10160(stce_10132.stce_10113(stce_9813), stce_10134);
  }
  inline const stce_9769 stce_10133() const {
    return stce_9773::stce_10164(this->stce_9912, stce_10132._value(), stce_10134);
  }
};
template <class stce_9769, class stce_9775, class stce_9776, class stce_9773, typename>
struct stce_9779 : public stce_9771<stce_9769, typename stce_9776::data_t> {
  const stce_9775 stce_10132;
  const stce_9776 DCO_TEMPORARY_REFORCOPY stce_10134;
  typedef typename stce_9776::data_t data_t;
  typedef typename data_t::mode_t::value_t VALUE_TYPE;
  typedef typename data_t::mode_t::passive_t stce_10159;
  explicit stce_9779(const stce_9775& stce_10162, const stce_9776& stce_10163)
      : stce_9771<stce_9769, data_t>(stce_9773::stce_10160(stce_10162, stce_10163._value())), stce_10132(stce_10162),
        stce_10134(stce_10163) {}
  inline const stce_9769 stce_10113(const int stce_9813) const {
    return stce_9773::stce_10160(stce_10132, stce_10134.stce_10113(stce_9813));
  }
  inline const stce_9769 stce_10135() const {
    return stce_9773::stce_10165(this->stce_9912, stce_10132, stce_10134._value());
  }
};
} // namespace internal
} // namespace dco
namespace dco {
namespace internal {
template <typename stce_9780> struct passive_value_type_of {
  typedef stce_9780 TYPE;
};
template <typename stce_9780> class stce_10166 {
protected:
  stce_9780 stce_9912;

public:
  stce_10166() : stce_9912(0.0) {}
  template <typename stce_9879> stce_10166(const stce_9879& stce_9810) : stce_9912(stce_9810) {}
};
template <class stce_9769, class stce_9770> struct active_type : private stce_10166<stce_9769>, public stce_9770 {
  typedef stce_10166<stce_9769> stce_10167;
  using stce_10167::stce_9912;

public:
  typedef stce_9770 data_t;
  typedef typename data_t::mode_t::value_t VALUE_TYPE;
  typedef typename data_t::mode_t::passive_t stce_10159;
  typedef typename data_t::mode_t::scalar_passive_t stce_10168;

private:
  typedef typename data_t::mode_t::scalar_value_t stce_10169;

public:
  DCO_STRONG_INLINE const stce_9769& _value() const { return stce_9912; }
  stce_9770 const& data() const { return *static_cast<stce_9770 const*>(this); }
  stce_9770& data() { return *static_cast<stce_9770*>(this); }
  DCO_STRONG_INLINE stce_9769& _value() { return stce_9912; }
  DCO_STRONG_INLINE const stce_9769 stce_10113(const int stce_9813) const {
    return stce_9770::stce_10113(stce_9912, stce_9813);
  }
  DCO_STRONG_INLINE active_type() : stce_10167(static_cast<stce_9769>(0.0)) {}
  DCO_STRONG_INLINE active_type(const active_type& stce_10084)
      : stce_10167(stce_10084.stce_9912), stce_9770(stce_10084) {}
  template <typename stce_9780 = stce_9770>
  DCO_STRONG_INLINE
  operator typename dco::enable_if<is_gbcp_type<stce_9780>::value,
                                   typename stce_9915<active_type, stce_9780::gbcp_order>::stce_9897>::type() const {
    return stce_9915<active_type, stce_9780::gbcp_order>::value(*this);
  }
  template <typename stce_9780 = stce_9770>
  DCO_STRONG_INLINE
  operator typename dco::enable_if<is_gbcp_type<stce_9780>::value,
                                   typename stce_9915<active_type, stce_9780::gbcp_order>::stce_9805>::type() {
    return stce_9915<active_type, stce_9780::gbcp_order>::value(*this);
  }
  template <typename stce_9879, typename stce_9780 = stce_9770>
  DCO_STRONG_INLINE typename dco::enable_if<
      (dco::mode<stce_9879>::order > 0 && dco::internal::is_gbcp_type<stce_9780>::value &&
       dco::is_same<typename stce_9780::mode_t::active_t, typename dco::mode<stce_9879>::active_t>::value),
      active_type>::type&
  operator=(const stce_9879& stce_10142) {
    stce_9912 = stce_10142;
    return *this;
  }
  template <typename stce_9879, typename stce_9780 = stce_9770>
  DCO_STRONG_INLINE
  active_type(const stce_9879& stce_9753,
              typename dco::enable_if<
                  (dco::mode<stce_9879>::order > 0 && dco::internal::is_gbcp_type<stce_9780>::value &&
                   dco::is_same<typename stce_9780::mode_t::active_t, typename dco::mode<stce_9879>::active_t>::value),
                  void*>::type = NULL)
      : stce_10167(stce_9753) {}
  template <typename TYPE>
  DCO_STRONG_INLINE active_type(const TYPE& stce_9753, typename dco_type_constructable_from<TYPE>::type* = 0)
      : stce_10167(stce_9753) {}
  template <typename TYPE, typename stce_9780 = stce_9770,
            typename stce_10170 = typename enable_if<!is_gbcp_type<stce_9780>::value>::type,
            typename stce_10158 = typename enable_if<dco_explicit_type_cast_to<TYPE>::value>::type>
  explicit operator TYPE() const {
    return static_cast<TYPE>(_value());
  }
  template <typename TYPE>
  DCO_STRONG_INLINE active_type(
      const TYPE& stce_9753,
      typename dco::enable_if<stce_9884<typename TYPE::data_t::mode_t, typename data_t::mode_t>::value, void*>::type =
          NULL)
      : stce_10167(stce_9753) {}
  DCO_STRONG_INLINE active_type(const stce_10159& stce_9753) : stce_10167(stce_9753) {}
  template <typename scalar_passive_t>
  DCO_STRONG_INLINE active_type(const scalar_passive_t& stce_9753,
                                typename dco::enable_if<!dco::is_same<stce_10159, scalar_passive_t>::value &&
                                                            dco::is_same<stce_10168, scalar_passive_t>::value,
                                                        void*>::type = NULL)
      : stce_10167(stce_9753) {}
  DCO_STRONG_INLINE active_type& operator=(const active_type& stce_9810) {
    stce_9770::operator=(static_cast<const stce_9770&>(stce_9810));
    stce_9912 = stce_9810.stce_9912;
    return *this;
  }
  DCO_STRONG_INLINE active_type& operator=(const stce_10159& stce_10142) {
    this->stce_9912 = stce_10142;
    this->clear();
    return *this;
  }
  template <typename scalar_passive_t>
  DCO_STRONG_INLINE typename dco::enable_if<!dco::is_same<stce_10159, scalar_passive_t>::value &&
                                                dco::is_same<stce_10168, scalar_passive_t>::value,
                                            active_type>::type&
  operator=(const scalar_passive_t& stce_10142) {
    this->stce_9912 = stce_10142;
    this->clear();
    return *this;
  }
  template <class stce_10171, class stce_10172>
  DCO_STRONG_INLINE typename dco::enable_if<stce_9884<typename stce_10172::mode_t, typename data_t::mode_t>::value,
                                            active_type>::type&
  operator=(const active_type<stce_10171, stce_10172>& stce_10142) {
    stce_9912 = stce_10142;
    this->clear();
    return *this;
  }
  template <typename TYPE>
  DCO_STRONG_INLINE typename dco_type_constructable_from<TYPE, active_type>::type& operator=(const TYPE& stce_9753) {
    stce_9912 = stce_9753;
    this->clear();
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE
  active_type(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    this->stce_9911(stce_9810);
    this->stce_9912 = stce_9810.stce_9912;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    this->stce_9911(stce_9810);
    this->stce_9912 = stce_9810.stce_9912;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE
  active_type(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    this->stce_9911(stce_9810);
    this->stce_9912 = stce_9810.stce_9912;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    this->stce_9911(stce_9810);
    this->stce_9912 = stce_9810.stce_9912;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE
  active_type(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    this->stce_9911(stce_9810);
    this->stce_9912 = stce_9810.stce_9912;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    this->stce_9911(stce_9810);
    this->stce_9912 = stce_9810.stce_9912;
    return *this;
  }
  template <class stce_10136, class stce_10130>
  DCO_ALWAYS_INLINE active_type(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9810) {
    this->stce_9911(stce_9810);
    this->stce_9912 = stce_9810.stce_9912;
  }
  template <class stce_10136, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9810) {
    this->stce_9911(stce_9810);
    this->stce_9912 = stce_9810.stce_9912;
    return *this;
  }
  template <typename stce_9879, typename stce_9780 = stce_9770>
  DCO_ALWAYS_INLINE typename enable_if<
      (dco::mode<stce_9879>::order > 0 && dco::internal::is_gbcp_type<stce_9780>::value &&
       dco::is_same<typename stce_9780::mode_t::active_t, typename dco::mode<stce_9879>::active_t>::value),
      active_type>::type&
  operator+=(const stce_9879& stce_9810) {
    *this = *this + stce_9810;
    return *this;
  }
  template <class stce_10172>
  DCO_ALWAYS_INLINE active_type& operator+=(const active_type<stce_9769, stce_10172>& stce_9810) {
    *this = *this + stce_9810;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator+=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    *this = *this + stce_9810;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator+=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    *this = *this + stce_9810;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator+=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    *this = *this + stce_9810;
    return *this;
  }
  template <class stce_10136, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator+=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9810) {
    *this = *this + stce_9810;
    return *this;
  }
  DCO_ALWAYS_INLINE active_type& operator+=(const VALUE_TYPE& stce_9810) {
    this->_value() += stce_9810;
    return *this;
  }
  template <typename stce_9879, typename stce_9780 = stce_9770>
  DCO_ALWAYS_INLINE typename enable_if<
      (dco::mode<stce_9879>::order > 0 && dco::internal::is_gbcp_type<stce_9780>::value &&
       dco::is_same<typename stce_9780::mode_t::active_t, typename dco::mode<stce_9879>::active_t>::value),
      active_type>::type&
  operator-=(const stce_9879& stce_9810) {
    *this = *this - stce_9810;
    return *this;
  }
  template <class stce_10172>
  DCO_ALWAYS_INLINE active_type& operator-=(const active_type<stce_9769, stce_10172>& stce_9810) {
    *this = *this - stce_9810;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator-=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    *this = *this - stce_9810;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator-=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    *this = *this - stce_9810;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator-=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    *this = *this - stce_9810;
    return *this;
  }
  template <class stce_10136, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator-=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9810) {
    *this = *this - stce_9810;
    return *this;
  }
  DCO_ALWAYS_INLINE active_type& operator-=(const VALUE_TYPE& stce_9810) {
    this->_value() -= stce_9810;
    return *this;
  }
  template <typename stce_9879, typename stce_9780 = stce_9770>
  DCO_ALWAYS_INLINE typename enable_if<
      (dco::mode<stce_9879>::order > 0 && dco::internal::is_gbcp_type<stce_9780>::value &&
       dco::is_same<typename stce_9780::mode_t::active_t, typename dco::mode<stce_9879>::active_t>::value),
      active_type>::type&
  operator*=(const stce_9879& stce_9810) {
    *this = *this * stce_9810;
    return *this;
  }
  template <class stce_10172>
  DCO_ALWAYS_INLINE active_type& operator*=(const active_type<stce_9769, stce_10172>& stce_9810) {
    *this = *this * stce_9810;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator*=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    *this = *this * stce_9810;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator*=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    *this = *this * stce_9810;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator*=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    *this = *this * stce_9810;
    return *this;
  }
  template <class stce_10136, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator*=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9810) {
    *this = *this * stce_9810;
    return *this;
  }
  DCO_STRONG_INLINE active_type& operator*=(const VALUE_TYPE& stce_9810) {
    *this = *this * stce_9810;
    return *this;
  }
  template <typename stce_9879, typename stce_9780 = stce_9770>
  DCO_ALWAYS_INLINE typename enable_if<
      (dco::mode<stce_9879>::order > 0 && dco::internal::is_gbcp_type<stce_9780>::value &&
       dco::is_same<typename stce_9780::mode_t::active_t, typename dco::mode<stce_9879>::active_t>::value),
      active_type>::type&
  operator/=(const stce_9879& stce_9810) {
    *this = *this / stce_9810;
    return *this;
  }
  template <class stce_10172>
  DCO_ALWAYS_INLINE active_type& operator/=(const active_type<stce_9769, stce_10172>& stce_9810) {
    *this = *this / stce_9810;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator/=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    *this = *this / stce_9810;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator/=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    *this = *this / stce_9810;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator/=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    *this = *this / stce_9810;
    return *this;
  }
  template <class stce_10136, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator/=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9810) {
    *this = *this / stce_9810;
    return *this;
  }
  DCO_STRONG_INLINE active_type& operator/=(const VALUE_TYPE& stce_9810) {
    *this = *this / stce_9810;
    return *this;
  }
  DCO_STRONG_INLINE active_type& operator++() {
    ++this->stce_9912;
    return *this;
  }
  DCO_STRONG_INLINE active_type& operator--() {
    --this->stce_9912;
    return *this;
  }
  DCO_STRONG_INLINE active_type operator++(int) {
    active_type stce_9849(*this);
    ++this->stce_9912;
    return stce_9849;
  }
  DCO_STRONG_INLINE active_type operator--(int) {
    active_type stce_9849(*this);
    --this->stce_9912;
    return stce_9849;
  }
};
template <class stce_9769, class stce_9770> struct passive_value_type_of<active_type<stce_9769, stce_9770>> {
  typedef typename passive_value_type_of<stce_9769>::TYPE TYPE;
};
} // namespace internal
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_10173, typename stce_10174>
void assign_from_interop(stce_10173& stce_9875, stce_10174 const& stce_9874) {
  if (sizeof(stce_10173) > sizeof(stce_10174)) {
    throw dco::exception::create<std::runtime_error>("Internal: Using iterator interop type, which is too small.");
  }
  std::memcpy(reinterpret_cast<void*>(&stce_9875), &stce_9874, sizeof(stce_10173));
}
template <typename stce_10173, typename stce_10174>
static void assign_to_interop(stce_10173 const& stce_9874, stce_10174& stce_9875) {
  if (sizeof(stce_10173) > sizeof(stce_10174)) {
    throw dco::exception::create<std::runtime_error>("Internal: Using iterator interop type, which is too small.");
  }
  std::memcpy(&stce_9875, reinterpret_cast<void const*>(&stce_9874), sizeof(stce_10173));
}
} // namespace internal
} // namespace dco
namespace dco {
namespace internal {
template <class stce_9981, memory_model::TYPE stce_10175>
class stce_9983<memory_model::BLOB_TAPE_SPLINT, stce_9981, stce_10175> : public stce_9927<stce_9981>, object_logger {
  typedef stce_9927<stce_9981> stce_9937;

public:
  typedef typename stce_9792<stce_9981>::type stce_10176;
  enum stce_10177 { stce_10178, stce_10179 };
  struct entry {
    stce_10176* stce_10180;
    index_t* stce_10181;
    DCO_ALWAYS_INLINE entry(stce_10176* stce_10182, index_t* stce_10183)
        : stce_10180(stce_10182), stce_10181(stce_10183){};
    DCO_ALWAYS_INLINE index_t arg() {
      return (*stce_10181 < 0) ? std::abs(stce_9752(*stce_10181)) - 1 : stce_9752(*stce_10181);
    }
    DCO_ALWAYS_INLINE stce_10176& pval() { return *stce_10180; }
    DCO_ALWAYS_INLINE stce_10176 pval() const { return *stce_10180; }
    DCO_ALWAYS_INLINE bool stce_10009() { return *stce_10181 < 0; }
    DCO_ALWAYS_INLINE static bool stce_10009(index_t* stce_10184) { return *stce_10184 < 0; }
    DCO_ALWAYS_INLINE static index_t stce_10185(index_t stce_10079) { return -stce_10079 - 1; }
    static size_t size_of() { return sizeof(stce_10176) + sizeof(index_t); }
    bool operator>=(entry const& stce_9936) const { return stce_10180 >= stce_9936.stce_10180; }
  };
  class iterator {
  public:
    index_t stce_10186;
    entry stce_10187;
    template <typename stce_10174> void assign_from_interop(stce_10174 const& stce_9874) {
      internal::assign_from_interop(*this, stce_9874);
    }
    template <typename stce_10174> void assign_to_interop(stce_10174& stce_9875) const {
      internal::assign_to_interop(*this, stce_9875);
    }
    DCO_ALWAYS_INLINE const entry* operator->() const { return &stce_10187; }
    DCO_ALWAYS_INLINE entry* operator->() { return &stce_10187; }
    DCO_ALWAYS_INLINE const entry& operator*() const { return stce_10187; }
    DCO_ALWAYS_INLINE entry& operator*() { return stce_10187; }
    DCO_ALWAYS_INLINE void stce_10188() {
      stce_10187.stce_10180++;
      stce_10187.stce_10181--;
      if (stce_9754 && static_cast<void*>(stce_10187.stce_10180) >= static_cast<void*>(stce_10187.stce_10181)) {
        throw dco::exception::create<std::runtime_error>(
            "Blob tape (splint) container overflow. Allocate bigger blob or use chunk tape container instead.");
      }
    }
    DCO_ALWAYS_INLINE index_t stce_10189() { return ++stce_10186; }
    DCO_ALWAYS_INLINE explicit iterator() : stce_10186(-1), stce_10187(NULL, NULL) {}
    DCO_ALWAYS_INLINE explicit iterator(stce_10176* stce_10182, index_t* stce_10183, index_t index = index_t(-1))
        : stce_10186(index), stce_10187(stce_10182, stce_10183) {}
    DCO_ALWAYS_INLINE index_t index() const { return stce_10186; }
    DCO_ALWAYS_INLINE index_t& index() { return stce_10186; }
    bool stce_10009() const { return entry::stce_10009(stce_10187.stce_10181); }
    DCO_ALWAYS_INLINE void operator--() {
      if (entry::stce_10009(stce_10187.stce_10181))
        stce_10186--;
      stce_10187.stce_10180--;
      stce_10187.stce_10181++;
    }
    DCO_ALWAYS_INLINE iterator operator--(int) {
      iterator stce_10029(*this);
      operator--();
      return stce_10029;
    }
    DCO_ALWAYS_INLINE bool operator==(const iterator& stce_9936) const {
      return stce_10187.stce_10180 == stce_9936.stce_10187.stce_10180;
    }
    DCO_ALWAYS_INLINE bool operator!=(const iterator& stce_9936) const { return !operator==(stce_9936); }
    DCO_ALWAYS_INLINE bool operator<(const iterator& stce_9936) const {
      return stce_10187.stce_10180 < stce_9936.stce_10187.stce_10180;
    }
    DCO_ALWAYS_INLINE bool operator>=(const iterator& stce_9936) const { return !operator<(stce_9936); }
    DCO_ALWAYS_INLINE bool operator>(const iterator& stce_9936) const {
      return stce_10187.stce_10180 > stce_9936.stce_10187.stce_10180;
    }
    DCO_ALWAYS_INLINE bool operator<=(const iterator& stce_9936) const { return !operator>(stce_9936); }
  };
  class edge_inserter {
    iterator& stce_10190;
    index_t stce_10186;

  public:
    edge_inserter(iterator& current) : stce_10190(current), stce_10186(0) {}
    iterator& current() { return stce_10190; }
    edge_inserter& operator=(edge_inserter stce_9936) {
      swap(stce_9936);
      return *this;
    }
    index_t index() const { return stce_10186; }
    void swap(edge_inserter& stce_9936) {
      std::swap(stce_10190, stce_9936.stce_10190);
      std::swap(stce_10186, stce_9936.stce_10186);
    }
    DCO_ALWAYS_INLINE_IF_AGRESSIVE void insert(const index_t& stce_10079, const stce_10176& pval) {
      if (IS_DEBUG && stce_10190.index() < stce_10079) {
        throw dco::exception::create<std::runtime_error>(
            "DCO_DEBUG: tape index of read variable bigger than current progvarcounter.");
      }
      if (stce_10186 == 0) {
        stce_10190.stce_10188();
        new (stce_10190.stce_10187.stce_10180) stce_10176(pval);
        new (stce_10190.stce_10187.stce_10181) index_t(entry::stce_10185(stce_10079));
        stce_10186 = stce_10190.stce_10189();
        DCO_LOG(logDEBUG2) << "inserting first entry, index now = " << stce_10186 << "; pval = " << pval
                           << ", target = " << stce_10079;
        return;
      }
      if (stce_9756 && stce_10079 == *(stce_10190.stce_10187.stce_10181)) {
        *(stce_10190.stce_10187.stce_10180) += pval;
        return;
      }
      stce_10190.stce_10188();
      new (stce_10190.stce_10187.stce_10180) stce_10176(pval);
      new (stce_10190.stce_10187.stce_10181) index_t(stce_10079);
    }

  private:
    edge_inserter(const edge_inserter& stce_9936);
  };

protected:
  void init(tape_options const& stce_9944, index_t stce_10191 = 0) {
    stce_9943 = stce_9944;
    size_t stce_10192;
    if (stce_9944.write_to_file())
      stce_10192 = stce_9944.blob_size_in_byte();
    else
      stce_10192 = get_allocation_size(stce_9944.blob_size_in_byte());
    size_t stce_10193 = stce_10192 / entry::size_of();
    DCO_LOG(logDEBUG1) << "BLOB SPLINT container: user requested allocation size = " << stce_10192
                       << "; size of element = " << entry::size_of() << "; max elements in memory = " << stce_10193;
    if (static_cast<double>(stce_10193) / static_cast<double>(std::numeric_limits<DCO_INTEGRAL_TAPE_INT>::max()) >
        1.0) {
      stce_10193 = std::numeric_limits<index_t>::max();
      DCO_LOG(logDEBUG1)
          << "BLOB SPLINT container: too many elements requested for currently used index_t. Setting to: "
          << stce_10193 * 1.e-6 << "M elements";
    }
    index_t stce_10194 = static_cast<index_t>(stce_10193);
    size_t stce_10195 = stce_10194 * entry::size_of();
    DCO_LOG(logDEBUG) << "BLOB SPLINT container: trying allocation for = " << stce_10195 / 1024 << "K ~=~ "
                      << stce_9752(stce_10194) * 1.e-6 << "M elements";
    stce_9928 = stce_1000001(&stce_10195, stce_9944.alloc_use_huge_pages());
    if (!stce_9928) {
      std::string stce_10196 = "";
      if (stce_9944.alloc_use_huge_pages()) {
        stce_10196 =
            " You are using huge pages; have you prepared your system correspondingly (see documentation as well)?";
      }
      throw dco::exception::create<std::runtime_error>("Could not allocate memory. Use environment variables "
                                                       "(DCO_MEM_RATIO, DCO_MAX_ALLOCATION) and see documentation." +
                                                       stce_10196);
    }
    stce_10194 = static_cast<index_t>(stce_10195 / entry::size_of());
    DCO_LOG(logINFO) << "BLOB SPLINT container: actually allocated size = " << stce_10195 / 1024 << "K ~=~ "
                     << stce_9752(stce_10194) * 1.e-6 << "M elements";
    stce_10197 = static_cast<stce_10176*>(stce_9928);
    stce_10198 = static_cast<index_t*>(stce_9928) + stce_10195 / sizeof(index_t) - 1;
    stce_10190 = iterator(stce_10197, stce_10198, stce_10191);
    stce_10199 = iterator(stce_10197, stce_10198, stce_10191);
    stce_10200 = iterator(stce_10197 + stce_9752(stce_10194) - 1, stce_10198 - stce_9752(stce_10194) + 1,
                          std::numeric_limits<index_t>::max());
    if (static_cast<std::size_t>(reinterpret_cast<char*>(stce_10198) - reinterpret_cast<char*>(stce_10197)) <
        entry::size_of()) {
      dco::dealloc(stce_9928);
      throw dco::exception::create<std::runtime_error>(
          "Blob/chunk size too small. Use bigger blob/chunk size (at least " + std::to_string(entry::size_of()) +
          " bytes).");
    }
    new (stce_10190.stce_10187.stce_10180) stce_10176(static_cast<stce_10176>(0.0));
    new (stce_10190.stce_10187.stce_10181) index_t(entry::stce_10185(0));
  }

public:
  DCO_ALWAYS_INLINE explicit stce_9983(tape_options const& stce_9944, stce_9981& tape)
      : stce_9937(tape), object_logger("BLOB SPLINT container"), stce_9928(0), stce_10197(0), stce_10198(0),
        stce_10190(), stce_10199(), stce_10200(), stce_10201(stce_10179) {
    assert(stce_10175 != memory_model::stce_9768);
    init(stce_9944);
  }
  DCO_ALWAYS_INLINE explicit stce_9983(iterator& stce_9828, stce_9981& tape)
      : stce_9937(tape), object_logger("BLOB SPLINT container"), stce_9928(0), stce_10197(0), stce_10198(0),
        stce_10190(stce_9828), stce_10199(), stce_10200(), stce_10201(stce_10179) {
    assert(stce_10175 == memory_model::stce_9768);
  }
  DCO_ALWAYS_INLINE explicit stce_9983(stce_9983& stce_9874, stce_10177 stce_10202)
      : stce_9937(stce_9874), object_logger("BLOB SPLINT container"), stce_9928(0), stce_10197(0), stce_10198(0),
        stce_10190(), stce_10199(), stce_10200(), stce_10201(stce_10202) {
    if (stce_10202 == stce_10178) {
      stce_9928 = stce_9874.stce_9928;
      stce_10197 = stce_9874.stce_10197;
      stce_10198 = stce_9874.stce_10198;
      stce_10190 = iterator(stce_9874.stce_10197, stce_9874.stce_10198, stce_9874.current().index());
      stce_10199 = stce_10190;
      stce_10200 = stce_9874.stce_10200;
    } else {
      init(stce_9874.stce_9944());
    }
  }
  DCO_ALWAYS_INLINE ~stce_9983() {
    if (stce_10201 == stce_10179) {
      dco::dealloc(stce_9928);
    }
  }
  iterator start() { return stce_10199; }
  iterator start() const { return stce_10199; }
  iterator end() { return stce_10200; }
  iterator end() const { return stce_10200; }
  iterator rend() { return start(); }
  iterator current() const { return stce_10190; }
  iterator current() { return stce_10190; }
  iterator& current_ref() { return stce_10190; }
  iterator& insert_ref() { return stce_10190; }
  iterator rbegin() const { return current(); }
  bool empty() const { return stce_10190 == start(); }
  index_t size(const iterator& stce_9874, const iterator& stce_9875) const {
    if (stce_9874 < stce_9875)
      throw dco::exception::create<std::runtime_error>("size from < to");
    return static_cast<index_t>(stce_9874->stce_10180 - stce_9875->stce_10180);
  }
  index_t size(iterator stce_9874) const { return size(stce_9874, start()); }
  index_t size() const { return size(current(), start()); }
  index_t stce_10203() const { return size(stce_10200, start()); }
  size_t size_in_byte() const { return size(current(), start()) * entry::size_of(); }
  size_t stce_10204() const { return size(stce_10200, start()) * entry::size_of(); }
  void erase(const iterator& stce_10184) {
    if (!stce_10197)
      return;
    if (stce_10184 > stce_10200)
      throw dco::exception::create<std::runtime_error>("pos behind stack!");
    if (stce_10184 > stce_10190)
      throw dco::exception::create<std::runtime_error>("reset to position out of tape!");
    stce_10190 = stce_10184;
  }
  void erase() { stce_10190 = stce_10199; }
  void stce_10205(const iterator&) {}
  void stce_10206() {}
  index_t stce_10207() const { return stce_10190.index() + 1; }
  void stce_10208(stce_9983 const* const stce_9936) { current_ref().index() = stce_9936->current().index(); }
  tape_options stce_9944() const { return stce_9943; }
  char* stce_10209() { return reinterpret_cast<char*>(stce_9928); }
  long stce_10210() { return std::abs(reinterpret_cast<char*>(stce_10197) - reinterpret_cast<char*>(stce_10198)); }

private:
  stce_9983(const stce_9983& stce_9936);
  void* stce_9928;
  stce_10176* stce_10197;
  index_t* stce_10198;

protected:
  typename stce_9832<iterator, stce_10175 == memory_model::stce_9768>::type stce_10190;
  iterator stce_10199;
  iterator stce_10200;
  tape_options stce_9943;
  stce_10177 stce_10201;
};
} // namespace internal
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_9981, memory_model::TYPE stce_10175>
class stce_9983<memory_model::BLOB_TAPE, stce_9981, stce_10175> : public stce_9927<stce_9981>, public object_logger {
  typedef stce_9927<stce_9981> stce_9937;
  typedef stce_9981 tape_t;

public:
  typedef typename stce_9792<stce_9981>::type stce_10176;
  enum stce_10177 { stce_10178, stce_10179 };
  struct entry {
    index_t stce_10137;
    stce_10176 stce_10119;

  public:
    static size_t size_of() { return sizeof(entry); }
    entry(index_t arg = 0, stce_10176 const& pval = stce_10176(0.)) : stce_10137(arg), stce_10119(pval) {}
    DCO_STRONG_INLINE index_t arg() const {
      return (stce_10137 < 0) ? std::abs(stce_9752(stce_10137)) - 1 : stce_9752(stce_10137);
    }
    DCO_STRONG_INLINE static index_t stce_10185(const index_t& arg) { return -arg - 1; }
    DCO_STRONG_INLINE bool stce_10009() const { return stce_10137 < 0; }
    DCO_STRONG_INLINE void stce_10211(const stce_10176& stce_9923) { stce_10119 += stce_9923; }
    DCO_STRONG_INLINE stce_10176 pval() const { return stce_10119; }
  };
  class iterator {
    entry* stce_10212;
    index_t stce_10186;
    entry const* stce_10213;

  public:
    template <class stce_10214> void assign_to_interop(stce_10214& stce_10005) const {
      assert(sizeof(iterator) <= sizeof(stce_10214));
      std::memcpy(&stce_10005, this, sizeof(iterator));
    }
    template <class stce_10214> void assign_from_interop(const stce_10214& stce_10005) {
      assert(sizeof(iterator) <= sizeof(stce_10214));
      std::memcpy(static_cast<void*>(this), &stce_10005, sizeof(iterator));
    }
    void stce_10215(index_t stce_9813) { stce_10186 = stce_9813; }
    void stce_10188() {
      stce_10212++;
      if (stce_10212 > stce_10213) {
        throw dco::exception::create<std::runtime_error>(
            "Blob tape container overflow. Allocate bigger blob or use chunk tape container instead.");
      }
    }
    index_t index() const { return stce_10186; }
    index_t& index() { return stce_10186; }
    index_t stce_10189() { return ++stce_10186; }
    void stce_10216(entry const* end) { stce_10213 = end; }
    explicit iterator(entry* stce_10184 = 0, index_t index = index_t(-1)) : stce_10212(stce_10184), stce_10186(index) {}
    void operator--() {
      if (stce_10212->stce_10009())
        stce_10186--;
      stce_10212--;
    }
    bool stce_10009() const { return stce_10212->stce_10009(); }
    iterator operator--(int) {
      iterator stce_10029(*this);
      operator--();
      return stce_10029;
    }
    entry* operator*() { return stce_10212; }
    entry* operator->() { return stce_10212; }
    entry* operator*() const { return stce_10212; }
    entry* operator->() const { return stce_10212; }
    bool operator==(const iterator& stce_9936) const { return stce_10212 == stce_9936.stce_10212; }
    bool operator!=(const iterator& stce_9936) const { return !operator==(stce_9936); }
    bool operator<(const iterator& stce_9936) const { return stce_10212 < stce_9936.stce_10212; }
    bool operator>=(const iterator& stce_9936) const { return !operator<(stce_9936); }
    bool operator>(const iterator& stce_9936) const { return stce_10212 > stce_9936.stce_10212; }
    bool operator<=(const iterator& stce_9936) const { return !operator>(stce_9936); }
    friend std::ostream& operator<<(std::ostream& stce_10217, const iterator& stce_10005) {
      stce_10217 << "(" << stce_10005.stce_10212 << ":" << stce_10005.stce_10186 << ")";
      return stce_10217;
    }
  };
  class edge_inserter {
    iterator& stce_10190;
    index_t stce_10186;

  public:
    edge_inserter(iterator& current) : stce_10190(current), stce_10186(0) {}
    iterator& current() { return stce_10190; }
    edge_inserter& operator=(edge_inserter stce_9936) {
      swap(stce_9936);
      return *this;
    }
    index_t index() const { return stce_10186; }
    void swap(edge_inserter& stce_9936) {
      std::swap(stce_10190, stce_9936.stce_10190);
      std::swap(stce_10186, stce_9936.stce_10186);
    }
    DCO_ALWAYS_INLINE_IF_AGRESSIVE void insert(const index_t& stce_10079, const stce_10176& pval) {
      if (IS_DEBUG && stce_10190.index() < stce_10079) {
        throw dco::exception::create<std::runtime_error>(
            "DCO_DEBUG: tape index of read variable bigger than current progvarcounter.");
      }
      if (stce_10186 == 0) {
        stce_10190.stce_10188();
        new (*stce_10190) entry(entry::stce_10185(stce_10079), pval);
        stce_10186 = stce_10190.stce_10189();
        return;
      }
      if (stce_9756 && stce_10079 == stce_10190->arg()) {
        stce_10190->stce_10211(pval);
        return;
      }
      stce_10190.stce_10188();
      new (*stce_10190) entry(stce_10079, pval);
    }

  private:
    edge_inserter(const edge_inserter& stce_9936);
  };
  explicit stce_9983(stce_9983& stce_9874, stce_10177 stce_10202)
      : stce_9937(stce_9874), object_logger("BLOB container"), stce_9928(0), stce_10190(), stce_10199(), stce_10200(),
        stce_10201(stce_10202), stce_9943(stce_9874.stce_9943) {
    if (stce_10202 == stce_10178) {
      stce_9928 = stce_9874.stce_9928;
      stce_10190 = iterator(stce_9928, stce_9874.current().index());
      stce_10199 = stce_10190;
      stce_10200 = stce_9874.stce_10200;
      stce_10190.stce_10216(*stce_10200);
    } else if (stce_10202 == stce_10179) {
      index_t stce_10193 = allocate(stce_9943);
      stce_10190 = iterator(stce_9928, (stce_9874.current().index()));
      stce_10199 = iterator(stce_9928, (stce_9874.current().index()));
      stce_10200 = iterator(stce_9928 + static_cast<DCO_INTEGRAL_TAPE_INT>(stce_10193) - 1,
                            std::numeric_limits<DCO_INTEGRAL_TAPE_INT>::max());
      stce_10190.stce_10216(*stce_10200);
      if (*stce_10200 - *stce_10199 < 1) {
        std::stringstream stce_10218;
        stce_10218 << 2 * sizeof(entry);
        dco::dealloc(stce_9928);
        throw dco::exception::create<std::runtime_error>(
            "Blob/chunk size too small. Use bigger blob/chunk size [at least " + stce_10218.str() + " bytes].");
      }
      new (*stce_10190) entry(entry::stce_10185(0));
    }
  }
  index_t allocate(const tape_options& stce_9944) {
    size_t stce_10195 = get_allocation_size(stce_9944.blob_size_in_byte());
    stce_9928 = static_cast<entry*>(stce_1000001(&stce_10195, stce_9944.alloc_use_huge_pages()));
    if (!stce_9928) {
      throw dco::exception::stce_9821<std::bad_alloc>("Could not allocate memory. Use environment variables "
                                                      "(DCO_MEM_RATIO, DCO_MAX_ALLOCATION) and see documentation.");
    }
    size_t stce_10219 = stce_10195 / entry::size_of();
    if (static_cast<double>(stce_10219) / static_cast<double>(std::numeric_limits<DCO_INTEGRAL_TAPE_INT>::max()) >
        1.0) {
      stce_10219 = std::numeric_limits<index_t>::max();
    }
    index_t stce_10193 = static_cast<index_t>(stce_10219);
    DCO_LOG(logINFO) << "BLOB container; size = " << stce_9944.blob_size_in_byte() << "b ~=~ "
                     << stce_9944.blob_size_in_byte() / entry::size_of() << "elements";
    DCO_LOG(logINFO) << "BLOB container; tried allocation size = " << stce_10195 << "b ~=~ "
                     << stce_10195 / entry::size_of() << "elements";
    DCO_LOG(logDEBUG) << "sizeof(entry) = " << sizeof(entry) << " == " << entry::size_of();
    return stce_10193;
  }
  void init(tape_options const& stce_9944) {
    index_t stce_10193 = allocate(stce_9944);
    stce_10190 = iterator(stce_9928, 0);
    stce_10199 = iterator(stce_9928, 0);
    stce_10200 = iterator(stce_9928 + static_cast<DCO_INTEGRAL_TAPE_INT>(stce_10193) - 1,
                          std::numeric_limits<DCO_INTEGRAL_TAPE_INT>::max());
    stce_10190.stce_10216(*stce_10200);
    if (*stce_10200 - *stce_10199 < 1) {
      std::stringstream stce_10218;
      stce_10218 << 2 * sizeof(entry);
      dco::dealloc(stce_9928);
      throw dco::exception::create<std::runtime_error>(
          "Blob/chunk size too small. Use bigger blob/chunk size (at least " + stce_10218.str() + " bytes).");
    }
    new (*stce_10190) entry(entry::stce_10185(0));
  }
  DCO_ALWAYS_INLINE explicit stce_9983(tape_options const& stce_9944, tape_t& tape)
      : stce_9937(tape), object_logger("BLOB container"), stce_9928(0), stce_10190(), stce_10199(), stce_10200(),
        stce_10201(stce_10179), stce_9943(stce_9944) {
    assert(stce_10175 != memory_model::stce_9768);
    init(stce_9944);
  }
  DCO_ALWAYS_INLINE explicit stce_9983(iterator& stce_9828, tape_t& tape)
      : stce_9937(tape), object_logger("BLOB container"), stce_9928(0), stce_10190(stce_9828), stce_10199(),
        stce_10200(), stce_10201(stce_10179), stce_9943(tape.stce_9944()) {
    assert(stce_10175 == memory_model::stce_9768);
  }
  DCO_ALWAYS_INLINE ~stce_9983() {
    if (stce_10201 == stce_10179)
      dco::dealloc(stce_9928);
  }
  char* stce_10209() { return reinterpret_cast<char*>(stce_9928); }
  long stce_10210() { return size() * sizeof(entry); }
  iterator current() const { return stce_10190; }
  iterator current() { return stce_10190; }
  iterator& insert_ref() { return stce_10190; }
  iterator& current_ref() { return stce_10190; }
  iterator start() { return stce_10199; }
  iterator start() const { return stce_10199; }
  iterator end() { return stce_10200; }
  iterator end() const { return stce_10200; }
  iterator rend() { return start(); }
  iterator rbegin() const { return current(); }
  bool empty() const { return stce_10190 == start(); }
  index_t size(const iterator& stce_9874, const iterator& stce_9875) const {
    if (stce_9874 < stce_9875)
      throw dco::exception::create<std::runtime_error>("size from < to");
    return static_cast<index_t>(*stce_9874 - *stce_9875);
  }
  tape_options stce_9944() const { return stce_9943; }
  index_t size(iterator stce_9874) const { return size(stce_9874, start()); }
  index_t size() const { return size(current(), start()); }
  index_t stce_10203() const { return size(stce_10200, start()); }
  size_t size_in_byte() const { return size(current(), start()) * sizeof(entry); }
  size_t stce_10204() const { return size(stce_10200, start()) * sizeof(entry); }
  void erase(const iterator& stce_10184) {
    if (!stce_9928)
      return;
    if (IS_DEBUG && stce_10184 > stce_10200)
      throw dco::exception::create<std::runtime_error>("pos behind stack!");
    if (stce_10184 > stce_10190)
      throw dco::exception::create<std::runtime_error>("reset to position out of tape!");
    stce_10190 = stce_10184;
    stce_10190.stce_10216(*stce_10200);
  }
  void erase() {
    if (!stce_9928)
      return;
    stce_10190 = stce_10199;
    stce_10190.stce_10216(*stce_10200);
  }
  void stce_10205(const iterator&) {}
  void stce_10206() {}
  index_t stce_10207() { return stce_10190.index() + 1; }

private:
  stce_9983(const stce_9983& stce_9936);
  entry* stce_9928;
  typename stce_9832<iterator, stce_10175 == memory_model::stce_9768>::type stce_10190;
  iterator stce_10199;
  iterator stce_10200;
  stce_10177 stce_10201;
  tape_options stce_9943;
};
} // namespace internal
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_9981, typename stce_10220> class stce_10221 : public stce_10220 {
  using stce_10222 = stce_10220;
  using tape_t = stce_9981;

public:
  using iterator_t = typename stce_10222::iterator;
  using stce_10223 = typename stce_10222::edge_inserter;
  using stce_10224 = typename stce_10222::entry;

private:
  index_t stce_10225;
  tape_options stce_9943;
  bool stce_10226;
  stce_10221 *stce_10227, *stce_10228;
  index_t stce_10229;
  static void stce_10230(const std::string& stce_10231, char* data, long size) {
    DCO_LOG(logDEBUG1) << "save_data_to_file: bytes to write = " << size << ", fname = " << stce_10231;
    std::ofstream out(stce_10231.c_str(), std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
    if (!out.is_open())
      throw dco::exception::create<std::runtime_error>("Could not open file, perhaps index corruption?");
    if (!out.good())
      throw dco::exception::create<std::runtime_error>("File could be opened, but got corrupted afterwards.");
    out.write(data, size);
    if (!out.good())
      throw dco::exception::create<std::runtime_error>("Reading the chunk failed, container corrupted.");
    out.close();
  }
  static index_t stce_10232(const std::string& stce_10231, char* data) {
    struct stat stce_10233;
    if (stat(stce_10231.c_str(), &stce_10233) == -1)
      throw dco::exception::create<std::runtime_error>("Could not check file size, perhaps index corruption?");
    index_t size = static_cast<index_t>(stce_10233.st_size);
    std::ifstream in(stce_10231.c_str(), std::ios_base::in | std::ios_base::binary);
    if (!in.is_open())
      throw dco::exception::create<std::runtime_error>("Could not open file, perhaps index corruption?");
    if (!in.good())
      throw dco::exception::create<std::runtime_error>("File could be opened, but got corrupted afterwards.");
    in.read(data, size);
    if (!in.good())
      throw dco::exception::create<std::runtime_error>("Reading the chunk failed, container corrupted.");
    in.close();
    return size;
  }

public:
  std::string stce_10234() {
    std::stringstream stce_10231;
    stce_10231 << stce_9943.filename() << '.' << stce_10225;
    return stce_10231.str();
  }
  DCO_ALWAYS_INLINE stce_10221(stce_10221* stce_10235, typename stce_10222::stce_10177 stce_10236)
      : stce_10222(*stce_10235, stce_10236), stce_10225(stce_10235->stce_10225 + 1), stce_9943(stce_10235->stce_9944()),
        stce_10226(true), stce_10227(stce_10235), stce_10228(0), stce_10229(-1) {}
  DCO_ALWAYS_INLINE stce_10221(tape_options stce_9944, tape_t& tape)
      : stce_10222(stce_9944, tape), stce_10225(0), stce_9943(stce_9944), stce_10226(true), stce_10227(0),
        stce_10228(0), stce_10229(-1) {}
  void stce_10237() {
    if (stce_9943.write_to_file()) {
      DCO_LOG(logDEBUG1) << "wake_up: Waking up chunk " << stce_10225 << " | " << &this->stce_9929()
                         << " from sleep (reading from file).";
      stce_10232(stce_10234(), this->stce_10209());
      DCO_LOG(logDEBUG3) << "wake_up: current partial = " << this->current()->pval();
      stce_10238(true);
    } else {
      DCO_LOG(logDEBUG1) << "wake_up: waking already awake chunk " << stce_10225 << " | " << &this->stce_9929();
    }
  }
  void sleep() {
    DCO_LOG(logDEBUG1) << "sleep: chunk " << stce_10225 << " | " << this->stce_10209() << " dirty = " << stce_10239();
    if (stce_9943.write_to_file() && stce_10239()) {
      if (!stce_10240()) {
        throw dco::exception::create<std::runtime_error>("Internal error: Writing chunk, which is not awake.");
      }
      const long stce_10241 = this->stce_10210();
      char* data = this->stce_10209();
      DCO_LOG(logDEBUG1) << "sleep: writing chunk " << stce_10225 << " | " << data << " | " << stce_10241;
      DCO_LOG(logDEBUG3) << "sleep: current partial = " << this->current()->pval();
      stce_10230(stce_10234(), data, stce_10241);
      stce_10242();
    } else {
      if (!stce_10239()) {
        DCO_LOG(logDEBUG1) << "sleep: not writing data for chunk: " << stce_10225;
      }
    }
    stce_10238(false);
  }
  void stce_10243(stce_10221* stce_10244) {
    if (!stce_10240()) {
      DCO_LOG(logDEBUG1) << "activate: chunk " << stce_10225 << " not awake yet.";
      stce_10221* stce_10245 = stce_10244;
      while (stce_10245 && !stce_10245->stce_10240()) {
        stce_10245 = stce_10245->stce_10235();
      }
      if (!stce_10245) {
        stce_10245 = stce_10244;
      }
      while (stce_10245 && !stce_10245->stce_10240()) {
        stce_10245 = stce_10245->stce_10246();
      }
      if (stce_10245) {
        DCO_LOG(logDEBUG1) << "activate: currently awake " << stce_10245->stce_10225;
        stce_10245->sleep();
      }
      stce_10237();
    }
  }
  DCO_ALWAYS_INLINE ~stce_10221() {
    if (stce_9944().write_to_file())
      std::remove(stce_10234().c_str());
  }
  index_t size(const iterator_t& stce_9874, const iterator_t& stce_9875) const {
    return stce_10222::size(stce_9874, stce_9875);
  }
  index_t size(iterator_t stce_9874) const { return stce_10222::size(stce_9874, this->start()); }
  index_t size() const { return stce_10222::size(this->current(), this->start()); }
  index_t stce_10203() const {
    if (!stce_10240())
      return 0;
    return stce_10222::stce_10203();
  }
  size_t size_in_byte() const { return stce_10222::size(this->current(), this->start()) * stce_10224::size_of(); }
  size_t stce_10204() const {
    if (!stce_10240()) {
      return 0;
    }
    return stce_10222::stce_10203() * stce_10224::size_of();
  }
  tape_options stce_9944() const { return stce_9943; }
  bool stce_10240() const { return stce_10226; }
  void stce_10238(bool stce_10247) { stce_10226 = stce_10247; }
  void stce_10242() { stce_10229 = size(); }
  void stce_10248() { stce_10229 = -1; }
  bool stce_10239() { return stce_10229 != size(); }
  index_t id() const { return stce_10225; }
  stce_10221*& stce_10235() { return stce_10227; }
  stce_10221*& stce_10246() { return stce_10228; }
  stce_10221 const* stce_10235() const { return stce_10227; }
  stce_10221 const* stce_10246() const { return stce_10228; }
};
} // namespace internal
} // namespace dco
namespace dco {
namespace internal {
template <typename stce_9981, memory_model::TYPE stce_10175>
class stce_9983<memory_model::CHUNK_TAPE, stce_9981, stce_10175> : public stce_9927<stce_9981>, object_logger {
  using tape_t = stce_9981;
  using stce_10249 = stce_9927<tape_t>;
  using stce_10250 = stce_9983<memory_model::BLOB_TAPE_SPLINT, tape_t>;
  using stce_10221 = typename internal::stce_10221<tape_t, stce_10250>;
  using stce_10251 = typename stce_10221::iterator_t;

public:
  using stce_10176 = typename stce_9792<tape_t>::type;
  using entry = typename stce_10250::entry;

public:
  class iterator : private stce_10251 {
    stce_10221* stce_10252;

  public:
    using stce_10251::operator->;
    using stce_10251::index;
    using stce_10251::stce_10009;
    using stce_10251::stce_10189;
    stce_10221* stce_10253() const { return stce_10252; }
    stce_10221*& stce_10253() { return stce_10252; }
    stce_10251& stce_10254() { return *this; }
    stce_10251 const& stce_10254() const { return *this; }
    template <typename stce_10174> void assign_from_interop(stce_10174 const& stce_9874) {
      internal::assign_from_interop(*this, stce_9874);
    }
    template <typename stce_10174> void assign_to_interop(stce_10174& stce_9875) const {
      internal::assign_to_interop(*this, stce_9875);
    }
    explicit iterator() : stce_10251(), stce_10252() {}
    explicit iterator(stce_10251 const& stce_10005, stce_10221* stce_10253)
        : stce_10251(stce_10005), stce_10252(stce_10253) {}
    explicit iterator(stce_10221* stce_10253) : stce_10251(stce_10253->current()), stce_10252(stce_10253) {}
    iterator(const iterator& stce_9936) : stce_10251(stce_9936), stce_10252(stce_9936.stce_10252) {}
    iterator& operator=(const iterator& stce_10084) {
      stce_10251::operator=(stce_10084);
      stce_10252 = stce_10084.stce_10252;
      return *this;
    }
    void operator--() {
      stce_10251::operator--();
      if (stce_10252->start() == *this && stce_10252->id() > 0) {
        stce_10252 = stce_10252->stce_10235();
        stce_10252->stce_10243(stce_10252->stce_10246());
        stce_10251::operator=(stce_10252->current());
      }
    }
    iterator operator--(int) {
      iterator stce_10029(*this);
      operator--();
      return stce_10029;
    }
    bool operator==(iterator const& stce_9936) const {
      return stce_10251::operator==(stce_9936) && stce_10252 == stce_9936.stce_10252;
    }
    bool operator!=(iterator const& stce_9936) const { return !operator==(stce_9936); }
    bool operator<(iterator const& stce_9936) const {
      return stce_10252 == stce_9936.stce_10252 ? this->stce_10254() < stce_9936.stce_10254()
                                                : this->index() < stce_9936.index();
    }
    bool operator>=(iterator const& stce_9936) const { return !operator<(stce_9936); }
    bool operator>(iterator const& stce_9936) const {
      return stce_10252 == stce_9936.stce_10252 ? this->stce_10254() > stce_9936.stce_10254()
                                                : this->index() > stce_9936.index();
    }
    bool operator<=(iterator const& stce_9936) const { return !operator>(stce_9936); }
  };
  class edge_inserter : public stce_10221::stce_10223 {
    stce_10221*& stce_10255;
    stce_10251 stce_10200;

  public:
    DCO_ALWAYS_INLINE edge_inserter(iterator& stce_9828)
        : stce_10221::stce_10223(stce_9828.stce_10254()), stce_10255(stce_9828.stce_10253()),
          stce_10200(stce_10255->end()) {}
    DCO_ALWAYS_INLINE_IF_AGRESSIVE void insert(const index_t& stce_10079, const stce_10176& pval) {
      if (*this->current() >= *stce_10200) {
        DCO_LOG(logDEBUG1) << "insert: chunk full, updating current and getting next.";
        stce_10255->current_ref() = this->current();
        stce_10256(stce_10255);
        index_t index = this->current().index();
        this->current() = stce_10255->current();
        this->current().index() = index;
        stce_10200 = stce_10255->end();
      }
      stce_10221::stce_10223::insert(stce_10079, pval);
    }

  private:
    edge_inserter(const edge_inserter& stce_9936);
  };
  void init(tape_options const& stce_9944) {
    tape_options stce_10257 = stce_9944;
    stce_10257.blob_size_in_byte() = stce_9944.chunk_size_in_byte();
    stce_10258 = new stce_10221(stce_10257, stce_10249::stce_9929());
    stce_10190 = iterator(stce_10258);
  }
  explicit stce_9983(tape_options const& stce_9944, tape_t& tape)
      : stce_10249(tape), object_logger("CHUNK container (w/ options)"), stce_10258(0), stce_10190() {
    assert(stce_10175 != memory_model::stce_9768);
    init(stce_9944);
  }
  explicit DCO_ALWAYS_INLINE stce_9983(iterator& stce_9828, tape_t& tape)
      : stce_10249(tape), object_logger("CHUNK container (w/ options)"), stce_10258(0), stce_10190(stce_9828) {
    assert(stce_10175 == memory_model::stce_9768);
  }
  DCO_ALWAYS_INLINE ~stce_9983() {
    stce_10221* stce_10005 = stce_10258;
    while (stce_10005) {
      stce_10221* stce_10259 = stce_10005;
      stce_10005 = stce_10005->stce_10246();
      delete stce_10259;
    }
  }
  static void stce_10256(stce_10221*& stce_9828) {
    DCO_LOG(logDEBUG1) << "Current chunk: id = " << stce_9828->id() << ", raw data = " << stce_9828->stce_10209()
                       << "; current iterator: index = " << stce_9828->current().index();
    if (stce_9828->stce_9944().write_to_file()) {
      stce_9828->sleep();
      stce_9828->stce_10246() = new stce_10221(stce_9828, stce_10221::stce_10178);
    } else {
      if (!stce_9828->stce_10246()) {
        stce_9828->stce_10246() = new stce_10221(stce_9828, stce_10221::stce_10179);
      }
    }
    stce_9828 = stce_9828->stce_10246();
    DCO_LOG(logDEBUG1) << "New chunk: id = " << stce_9828->id() << ", raw data = " << stce_9828->stce_10209()
                       << "; current iterator: index = " << stce_9828->current().index();
  }
  iterator start() const { return iterator(stce_10258->start(), stce_10258); }
  iterator& current_ref() { return stce_10190; }
  iterator& insert_ref() { return stce_10190; }
  iterator current() const { return stce_10190; }
  bool empty() const { return current() == start(); }
  index_t size(const iterator& stce_9874, const iterator& stce_9875) const {
    assert(stce_9874 >= stce_9875);
    stce_10221* stce_10253 = stce_9874.stce_10253();
    if (stce_10253 == stce_9875.stce_10253()) {
      return stce_10253->size(stce_9874.stce_10254(), stce_9875.stce_10254());
    }
    index_t size = stce_10253->size(stce_9874.stce_10254());
    stce_10253 = stce_10253->stce_10235();
    while (stce_10253 && stce_10253 != stce_9875.stce_10253()) {
      DCO_LOG(logDEBUG2) << "size: Adding " << stce_10253->size() << " => size = " << size;
      size += stce_10253->size();
      stce_10253 = stce_10253->stce_10235();
    }
    size += stce_10253->size(stce_10253->end(), stce_9875.stce_10254());
    return size;
  }
  index_t size(iterator stce_9874) const { return size(stce_9874, start()); }
  index_t size() const { return size(current(), start()); }
  mem_long_t size_in_byte() const { return size(current(), start()) * stce_10221::stce_10224::size_of(); }
  index_t stce_10203() const {
    index_t size = 0;
    if (!stce_10258) {
      return size;
    }
    for (stce_10221* stce_10253 = stce_10258; stce_10253 != NULL; stce_10253 = stce_10253->stce_10246()) {
      size += stce_10253->stce_10203();
    }
    return size;
  }
  mem_long_t stce_10204() const {
    mem_long_t size = 0;
    if (!stce_10258) {
      return size;
    }
    for (stce_10221* stce_10253 = stce_10258; stce_10253 != NULL; stce_10253 = stce_10253->stce_10246()) {
      size += stce_10253->stce_10204();
    }
    return size;
  }
  void erase(const iterator& stce_10184) {
    if (stce_10184 > current()) {
      throw dco::exception::create<std::invalid_argument>("erase: Given position outside of tape.");
    }
    stce_10190.stce_10253()->current_ref() = stce_10190.stce_10254();
    DCO_LOG(logDEBUG1) << "Erase chunk tape...";
    stce_10190.stce_10253() = stce_10184.stce_10253();
    stce_10190.stce_10253()->stce_10243(stce_10258);
    stce_10190.stce_10253()->stce_10248();
    stce_10221* stce_10005 = stce_10184.stce_10253()->stce_10246();
    if (stce_10190.stce_10253()->stce_9944().write_to_file() ||
        stce_10190.stce_10253()->stce_9944().deallocation_on_reset()) {
      stce_10190.stce_10253()->stce_10246() = nullptr;
      while (stce_10005) {
        stce_10221* stce_10259 = stce_10005;
        stce_10005 = stce_10005->stce_10246();
        delete stce_10259;
      }
    } else {
      while (stce_10005) {
        stce_10005->erase();
        stce_10005->stce_10248();
        stce_10005 = stce_10005->stce_10246();
      }
    }
    stce_10190.stce_10253()->erase(stce_10184.stce_10254());
    stce_10190.stce_10254() = stce_10190.stce_10253()->current();
  }
  void stce_10205(iterator& stce_9828) {
    DCO_LOG(logDEBUG1) << "Chunk tape: Prepare interpretation; activate: " << stce_9828.stce_10253()->id()
                       << ", is awake = " << stce_9828.stce_10253()->stce_10240() << ".";
    stce_10190.stce_10253()->current_ref() = stce_10190.stce_10254();
    stce_9828.stce_10253()->stce_10243(stce_10258);
    stce_10190.stce_10254() = stce_10190.stce_10253()->current_ref();
  }
  void stce_10206() {
    DCO_LOG(logDEBUG1) << "Chunk tape: Prepare recording.";
    stce_10190.stce_10253()->current_ref() = stce_10190.stce_10254();
    stce_10190.stce_10253()->stce_10243(stce_10258);
    stce_10190.stce_10254() = stce_10190.stce_10253()->current_ref();
  }
  index_t stce_10207() { return current().index() + 1; }
  void stce_10208(stce_9983 const* const stce_9936) { current_ref().index() = stce_9936->current().index(); }

private:
  stce_10221* stce_10258;
  typename stce_9832<iterator, stce_10175 == memory_model::stce_9768>::type stce_10190;
};
} // namespace internal
} // namespace dco

namespace dco {
namespace internal {
template <class stce_9981>
class stce_9983<memory_model::stce_9767, stce_9981> : public stce_9983<memory_model::CHUNK_TAPE, stce_9981> {
  typedef stce_9981 tape_t;

public:
  typedef typename stce_9792<stce_9981>::type stce_10176;
  typedef stce_9983<memory_model::CHUNK_TAPE, stce_9981> stce_10260;
  typedef typename stce_10260::entry entry;
  typedef typename stce_10260::edge_inserter edge_inserter;
  typedef typename stce_10260::iterator iterator;
  bool stce_10261, stce_10262, stce_10263, stce_10264;
  double stce_10265, stce_10266, stce_10267;
  std::vector<index_t> stce_10268;
  std::vector<stce_10176> stce_10269;
  std::vector<const void*> stce_10270;
  index_t stce_10271, stce_10272;
  struct stce_10273 {
    static std::string id() { return " gtas "; }
  };
  typedef logging<stce_10273> logger;
  explicit stce_9983(tape_options stce_9944, stce_9981& tape)
      : stce_10260(stce_9944, tape), stce_10261(false), stce_10262(false), stce_10263(false), stce_10264(false),
        stce_10265(1e-6), stce_10266(1e-6), stce_10267(0.0), stce_10271(0), stce_10272(-1) {}
  void stce_10274(log_level_enum level) {
    if (stce_10264 && level <= dco::logWARNING) {
      throw dco::exception::create<std::runtime_error>("Warning occured.");
    }
  }
  void stce_10275() {
    if (stce_10272 == stce_10271) {
      stce_10271++;
      throw dco::exception::create<std::runtime_error>("Event counter reached.");
    }
    stce_10271++;
  };
  void stce_10276(stce_10176 tangent, double stce_10277) {
    if (stce_10263) {
      double stce_10278 = ::fabs(tangent - stce_10277);
      log_level_enum stce_10279 = dco::logWARNING;
      if (stce_10278 < stce_10265) {
        stce_10279 = dco::logINFO;
      }
      logger(stce_10279).get_stream() << stce_10271 << ": fd vs. tangent check";
      logger(stce_10279).get_stream() << " delta = " << stce_10278 << " tangent = " << tangent
                                      << " finite differences = " << stce_10277;
      stce_10274(stce_10279);
    }
  }
  void stce_10280(double stce_10281, double stce_10282, double stce_10283) {
    const double stce_10284 = ::fabs(stce_10281 - stce_10282);
    const double stce_10285 = ::fabs(stce_10281 - stce_10283);
    log_level_enum stce_10279 = dco::logWARNING;
    if (stce_10284 < stce_10266) {
      stce_10279 = dco::logINFO;
    }
    logger(stce_10279).get_stream() << stce_10271 << ": Tangent/adjoint identity check:";
    logger(stce_10279).get_stream() << " tangent vs. adjoint = " << stce_10284;
    logger(stce_10279).get_stream() << "  <x_(1),x^(1)> = " << stce_10281;
    logger(stce_10279).get_stream() << "  <y_(1),y^(1)> = " << stce_10282;
    stce_10274(stce_10279);
    stce_10279 = dco::logWARNING;
    if (stce_10285 < stce_10265) {
      stce_10279 = dco::logINFO;
    }
    logger(stce_10279).get_stream() << " finite differences vs. adjoint = " << stce_10285;
    logger(stce_10279).get_stream() << "  <y_(1),y_{FD}^(1)> = " << stce_10283;
    stce_10274(stce_10279);
  }
  void stce_10286(const iterator& stce_9875) {
    assert(stce_10260::start() == stce_9875);
    stce_10260::stce_10286(stce_9875);
    stce_10268.clear();
    stce_10269.clear();
    stce_10270.clear();
    stce_10267 = 0;
  }
  void stce_10115(std::string stce_10287, const bool stce_9849, const bool stce_10112, const bool stce_10114) {
    if (!stce_10261) {
      stce_10275();
      return;
    }
    log_level_enum stce_10279 = dco::logWARNING;
    if (stce_9849 == stce_10112 && stce_9849 == stce_10114) {
      stce_10279 = dco::logINFO;
    }
    logger(stce_10279).get_stream() << stce_10271 << ": Branch check:" << stce_10287 << std::boolalpha
                                    << " at current value returns " << stce_9849 << ", at minus h " << stce_10112
                                    << ", and at plus h " << stce_10114;
    stce_10274(stce_10279);
    stce_10275();
  }
  template <class data_t> void stce_10288(const data_t* data, const double& tangent) {
    if (stce_10267 == 0) {
      stce_10270.push_back(data);
      stce_10268.push_back(data->_tape_index());
      stce_10269.push_back(tangent);
    }
  }
  template <typename stce_10289> void stce_10290() {
    double stce_10291 = 0;
    for (size_t stce_9847 = 0; stce_9847 < stce_10270.size(); ++stce_9847) {
      const stce_10289& stce_9828 = *static_cast<const stce_10289*>(stce_10270[stce_9847]);
      stce_10291 = std::max(stce_10291, std::fabs(stce_9828.stce_10292[0]));
    }
    const double stce_10293 = 1e-14;
    stce_10267 = std::sqrt(stce_10293) * stce_10291;
    for (size_t stce_9847 = 0; stce_9847 < stce_10270.size(); ++stce_9847) {
      const stce_10289& stce_9828 = *static_cast<const stce_10289*>(stce_10270[stce_9847]);
      stce_9828.stce_10292[0] -= stce_10267 * stce_9828.stce_9975;
      stce_9828.stce_10292[1] += stce_10267 * stce_9828.stce_9975;
    }
  }
};
} // namespace internal
} // namespace dco

namespace dco {
namespace internal {
template <class stce_9981, memory_model::TYPE stce_9982>
class stce_9983<memory_model::stce_9768, stce_9981, stce_9982>
    : public stce_9983<stce_9982, stce_9981, memory_model::stce_9768> {
public:
  typedef typename stce_9792<stce_9981>::type stce_10176;
  typedef stce_9983<stce_9982, stce_9981, memory_model::stce_9768> stce_10260;
  explicit stce_9983(tape_options stce_9944, stce_9981& tape) : stce_10260(stce_10190, tape), stce_10190() {
    stce_10260::init(stce_9944);
  }
  struct iterator : public stce_10260::iterator {
    iterator() : stce_10294(1), stce_10295(0) {}
    iterator(const typename stce_10260::iterator& stce_10296)
        : stce_10260::iterator(stce_10296), stce_10294(-1), stce_10295(-1) {}
    index_t stce_10294;
    index_t stce_10295;
    const index_t& max_dist() const { return stce_10294; }
    void stce_10297(const index_t& stce_10298) {
      stce_10294 = stce_10298 + 1;
      DCO_LOG(logDEBUG3) << " updating max dist: " << stce_10294;
    }
    const index_t& stce_10299() const { return stce_10295; }
    index_t stce_10189() {
      stce_10295++;
      return stce_10260::iterator::stce_10189();
    }
  };
  class edge_inserter : public stce_10260::edge_inserter {
    iterator& stce_10190;

  public:
    edge_inserter(iterator& current) : stce_10260::edge_inserter(current), stce_10190(current) {}
    iterator& current() { return stce_10190; }
    DCO_ALWAYS_INLINE void insert(const index_t& stce_10079, const stce_10176& pval) {
      DCO_LOG(logDEBUG4) << "target = " << stce_10079 << ", parametercounter = " << current().stce_10299()
                         << ", max dist = " << current().max_dist();
      index_t stce_10300 = current().index();
      stce_10260::edge_inserter::insert(stce_10079, pval);
      if (stce_10079 > current().stce_10299()) {
        index_t stce_10301 = stce_10300 - stce_10079 + 1;
        DCO_LOG(logDEBUG4) << "curdist = " << stce_10301;
        if (stce_10301 - current().max_dist() > 0) {
          current().stce_10297(stce_10301);
        }
      }
    }

  private:
    edge_inserter(const edge_inserter& stce_9936);
  };
  iterator current() const { return stce_10190; }
  iterator current() { return stce_10190; }
  iterator& current_ref() { return stce_10190; }
  iterator rbegin() const { return stce_10190; }
  index_t stce_10207() {
    using ::log;
    using ::pow;
    index_t max_dist = stce_10190.max_dist();
    bool stce_10302 = (max_dist & (max_dist - 1)) == 0;
    if (HAS_BITWISE_MODULO && !stce_10302) {
      index_t stce_10024 = static_cast<index_t>(floor(log(static_cast<double>(max_dist)) / log(2.0))) + 1;
      stce_10190.stce_10297((1 << stce_9752(stce_10024)) - 1);
      DCO_LOG(logDEBUG2) << "rounding adjoint vector size to " << stce_10190.max_dist();
    }
    return stce_10190.stce_10299() + stce_10190.max_dist() + 1;
  }

private:
  iterator stce_10190;
};
} // namespace internal
namespace helper {
template <typename stce_9788, memory_model::TYPE stce_9789, typename external_adjoint_object_t>
struct stce_10011<internal::tape<memory_model::stce_9768, stce_9788, stce_9789>, external_adjoint_object_t> {
  typedef internal::tape<memory_model::stce_9768, stce_9788, stce_9789> tape_t;
  index_t stce_10303;
  index_t stce_10304;
  external_adjoint_object_t* stce_10305;
  stce_10011(external_adjoint_object_t* stce_10306)
      : stce_10303(std::numeric_limits<index_t>::max()), stce_10304(0), stce_10305(stce_10306) {}
  template <typename stce_9780> void register_input(const stce_9780& stce_9810) {
    index_t stce_9813 = stce_9810._tape_index();
    if (stce_9813 > stce_10305->tape()->current().stce_10299()) {
      stce_10303 = std::min(stce_10303, stce_9813);
    }
  }
  template <typename stce_9780> void register_output(const stce_9780& stce_10051) {
    stce_10304 = std::max(stce_10304, stce_10051._tape_index());
    if (stce_10303 != std::numeric_limits<index_t>::max()) {
      index_t max_dist = stce_10304 - stce_10303;
      if (max_dist > stce_10305->tape()->current_ref().max_dist()) {
        stce_10305->tape()->current_ref().stce_10297(max_dist);
      }
    }
  }
};
} // namespace helper
namespace internal {
template <typename stce_9793, typename stce_9981, memory_model::TYPE stce_9982>
class adjoint_vector_lazy<stce_9793, internal::stce_9983<memory_model::stce_9768, stce_9981, stce_9982>>
    : public adjoint_vector_lazy<stce_9793, internal::stce_9983<stce_9982, stce_9981, memory_model::stce_9768>> {
  typedef internal::stce_9983<memory_model::stce_9768, stce_9981, stce_9982> stce_9901;
  typedef typename stce_9901::stce_10260 stce_10260;
  typedef adjoint_vector_lazy<stce_9793, stce_10260> stce_10307;
  typedef typename stce_10307::stce_9762 stce_9762;

public:
  stce_9901& stce_9988;
  adjoint_vector_lazy(index_t size, stce_9901& tape, tape_options stce_9944)
      : stce_10307(size, static_cast<stce_10260&>(tape), stce_9944), stce_9988(tape), stce_10308(true), stce_10309(0) {}
  void init() {
    stce_10310 = stce_9988.current().stce_10299();
    if (HAS_BITWISE_MODULO) {
      stce_10311 = stce_9988.current().max_dist() - 1;
    } else {
      stce_10311 = stce_9988.current().max_dist();
    }
    stce_10312 = this->stce_9899.data() + stce_9752(stce_10310) + 1;
  }
  bool stce_9945(index_t stce_9946) const {
    if (stce_9946 > stce_9988.current().stce_10299()) {
      stce_9946 -= stce_9988.current().stce_10299();
      stce_9946 %= stce_9988.current().max_dist();
      stce_9946 += stce_9988.current().stce_10299() + 1;
    }
    return static_cast<index_t>(this->stce_9939) > stce_9946;
  }
  index_t stce_10313(index_t stce_9813) const {
    if (stce_9813 > stce_9988.current().stce_10299()) {
      stce_9813 -= stce_9988.current().stce_10299();
      stce_9813 %= stce_9988.current().max_dist();
      stce_9813 += stce_9988.current().stce_10299() + 1;
    }
    return stce_9813;
  }
  typename stce_10307::stce_9762& operator[](index_t stce_9813) {
    DCO_LOG(logDEBUG4) << "getting " << stce_9813;
    stce_9813 = stce_10313(stce_9813);
    DCO_LOG(logDEBUG4) << "matched to " << stce_9813;
    return stce_10307::operator[](stce_9813);
  }
  typename stce_10307::stce_9762 operator[](index_t stce_9813) const {
    DCO_LOG(logDEBUG4) << "getting " << stce_9813;
    stce_9813 = stce_10313(stce_9813);
    DCO_LOG(logDEBUG4) << "matched to " << stce_9813;
    return stce_10307::operator[](stce_9813);
  }
  stce_9762 at(index_t stce_9813) const { return stce_9945(stce_9813) ? (*this)[stce_9813] : 0; }
  stce_9762& at(const index_t stce_9813) {
    if (!stce_9945(stce_9813))
      this->resize(stce_9988.stce_10207());
    return (*this)[stce_9813];
  }
  void stce_9952(index_t stce_9813) {
    if (!stce_9945(stce_9813)) {
      DCO_LOG(logDEBUG2) << "Resizing internal adjoint vector to " << stce_9813;
      this->resize(stce_9988.stce_10207());
    }
  }
  template <typename iterator_t> void stce_9948(iterator_t& stce_9828) {
    index_t stce_9875 = stce_9828->arg();
    stce_9762 pval = stce_9828->pval();
    index_t stce_9874 = stce_9828.index();
    if (stce_10308) {
      DCO_LOG(logDEBUG3) << "setting " << stce_9874 << " to 0 ";
      stce_9762& stce_10314 = HAS_BITWISE_MODULO ? stce_10312[(stce_9874 - stce_10310) & stce_10311]
                                                 : stce_10312[(stce_9874 - stce_10310) % stce_10311];
      this->stce_10309 = stce_10314;
      stce_10314 = 0;
    }
    if (stce_9875 > stce_10310) {
      stce_9762& stce_10314 = HAS_BITWISE_MODULO ? stce_10312[(stce_9875 - stce_10310) & stce_10311]
                                                 : stce_10312[(stce_9875 - stce_10310) % stce_10311];
      stce_10314 += pval * this->stce_10309;
    } else {
      (*this)[stce_9875] += pval * this->stce_10309;
    }
    stce_10308 = stce_9828.stce_10009();
  }

private:
  stce_9762* stce_10312;
  index_t stce_10310;
  index_t stce_10311;
  bool stce_10308;
  stce_9762 stce_10309;
};
} // namespace internal
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_9790> struct stce_10315 {
public:
  typedef stce_9790 mode_t;
  typedef stce_10087 stce_10141;

private:
  static const size_t size = mode_t::p1f_size;
  typedef std::bitset<size> stce_10316;

public:
  typedef stce_10316 derivative_t;

private:
  mutable stce_10316 stce_10317;

public:
  stce_10315() {}
  DCO_STRONG_INLINE stce_10315(stce_10315 const& stce_10036) : stce_10317(stce_10036.stce_10317) {}
  DCO_STRONG_INLINE stce_10315& operator=(const stce_10315& stce_10084) {
    stce_10317 = stce_10084.stce_10317;
    return *this;
  }
  stce_10316& stce_9969() const { return stce_10317; }
  void clear() { stce_10317.reset(); }
  template <class stce_9910> DCO_ALWAYS_INLINE void stce_9911(const stce_9910& stce_10142) {
    stce_10315 stce_10029;
    stce_10318(stce_10142, stce_10029.stce_10317);
    stce_10317 = stce_10029.stce_10317;
  }
  typedef typename mode_t::value_t stce_9769;

private:
  template <class stce_10126>
  static void stce_10318(const dco::internal::active_type<stce_9769, stce_10126>& stce_9810, stce_10316& stce_10079) {
    stce_10079 |= stce_9810.stce_10317;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static void stce_10318(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810,
                         stce_10316& stce_10079) {
    stce_10318(stce_9810.stce_10132, stce_10079);
    stce_10318(stce_9810.stce_10134, stce_10079);
  }
  template <class stce_10136, class stce_10130>
  static void stce_10318(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9810,
                         stce_10316& stce_10079) {
    stce_10318(stce_9810.stce_10137, stce_10079);
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static void stce_10318(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810,
                         stce_10316& stce_10079) {
    stce_10318(stce_9810.stce_10132, stce_10079);
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static void stce_10318(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810,
                         stce_10316& stce_10079) {
    stce_10318(stce_9810.stce_10134, stce_10079);
  }
};
} // namespace internal
} // namespace dco
namespace dco {
namespace internal {
namespace stce_10319 {
template <typename stce_10320, typename adjoint_vector>
void stce_10321(stce_10320 stce_9828, stce_10320 stce_9875, const adjoint_vector& stce_10322,
                const std::string& filename = "tape.dot") {
  stce_10321(stce_9828, stce_9875, stce_10322, stce_9861(filename));
}
template <typename stce_10320, typename adjoint_vector>
void stce_10321(stce_10320 stce_9828, stce_10320 stce_9875, const adjoint_vector& stce_10322, stce_9861& stce_9862) {
  if (stce_9828.index() == stce_9875.index()) {
    return;
  } else if (stce_9828.index() < stce_9875.index()) {
    std::swap(stce_9828, stce_9875);
  }
  for (; stce_9828 != stce_9875; stce_9828--) {
    if (stce_9828->stce_10009()) {
      stce_9862.stce_9871(stce_9828.index(), stce_10322.at(stce_9828.index()));
    }
    stce_9862.stce_9873(stce_9828->arg(), stce_9828.index(), stce_9828->pval());
  }
  for (int stce_9847 = 0; stce_9847 <= stce_9828.index(); ++stce_9847) {
    stce_9862.stce_9871(stce_9847, stce_10322.at(stce_9847));
  }
}
template <typename stce_10320, typename adjoint_vector, typename stce_10323>
void stce_10321(stce_10320 stce_9828, stce_10320 stce_9875, const adjoint_vector& stce_10322,
                const stce_10323& stce_10324, stce_9861& stce_9862) {
  if (stce_9828.index() < stce_9875.index()) {
    std::swap(stce_9828, stce_9875);
  }
  stce_10321(stce_9828, stce_9875, stce_10322, stce_9862);
  typedef typename stce_10323::const_reverse_iterator stce_10325;
  for (stce_10325 stce_10005 = stce_10324.rbegin();
       stce_10005 != stce_10324.rend() && stce_9875 <= stce_10005->stce_10326(); ++stce_10005) {
    if (stce_9828 < stce_10005->stce_10326())
      continue;
    stce_10005->stce_10327()->stce_10017(stce_9862, stce_10005->stce_10326().index() + 1);
  }
}
template <typename stce_10320>
void stce_10328(stce_10320 stce_9828, stce_10320 stce_9875, std::string const& filename) {
  if (stce_9828.index() < stce_9875.index()) {
    std::swap(stce_9828, stce_9875);
  }
  std::ofstream stce_9818(filename.c_str());
  stce_9818 << stce_9828.index() << "\n";
  for (; stce_9828 != stce_9875; --stce_9828) {
    stce_9818 << stce_9828->arg() << ", " << stce_9828->pval() << "; ";
    if (stce_9828->stce_10009())
      stce_9818 << "\n";
  }
}
template <bool USE_SPARSE_INTERPRET, typename stce_10320, typename adjoint_vector, typename stce_10329>
DCO_STRONG_INLINE void interpret(stce_10320 stce_9828, const stce_10320& stce_9875, adjoint_vector& stce_10322,
                                 stce_10329 const& stce_10330) {
  using stce_10331 = typename dco::mode<typename adjoint_vector::stce_9938>::data_t;
  using stce_10332 = typename stce_10331::mode_t;
  static constexpr bool sparse_interpret =
      USE_SPARSE_INTERPRET || std::is_base_of<stce_10331, internal::stce_10315<stce_10332>>::value;
  stce_9828.index()--;
  stce_1000002();
  ;
  stce_10322.stce_9952(stce_9815(stce_9752(stce_9828.index())));
  stce_10322.init();
  for (; stce_9828 != stce_9875; --stce_9828) {
    if (sparse_interpret && folding::is_zero(stce_10322[stce_9828.index()])) {
      continue;
    }
    DCO_LOG(logDEBUG3) << stce_10322[stce_9828->arg()] << " <=> adj[" << stce_9828->arg()
                       << "] += " << stce_9828->pval() * stce_10322[stce_9828.index()] << " from idx "
                       << stce_9828.index();
    stce_10322.stce_9948(stce_9828);
    helper::stce_9836(int(), stce_10330, stce_9828->arg(), stce_9828->pval() * stce_10322[stce_9828.index()]);
  }
}
template <bool USE_SPARSE_INTERPRET, typename stce_10320, typename adjoint_vector, typename stce_10329>
DCO_STRONG_INLINE void stce_10333(stce_10320 stce_9828, const stce_10320& stce_9875, adjoint_vector& stce_10322,
                                  stce_10329 const& stce_10330) {
  using stce_10331 = typename dco::mode<typename adjoint_vector::stce_9938>::data_t;
  using stce_10332 = typename stce_10331::mode_t;
  static constexpr bool sparse_interpret =
      USE_SPARSE_INTERPRET || std::is_base_of<stce_10331, internal::stce_10315<stce_10332>>::value;
  stce_9828.index()--;
  stce_1000002();
  ;
  stce_10322.stce_9952(stce_9815(stce_9752(stce_9828.index())));
  stce_10322.init();
  for (; stce_9828 != stce_9875; --stce_9828) {
    if (sparse_interpret && folding::is_zero(stce_10322[stce_9828.index()])) {
      continue;
    }
    DCO_LOG(logDEBUG3) << stce_10322[stce_9828->arg()] << " <=> adj[" << stce_9828->arg()
                       << "] += " << stce_9828->pval() * stce_10322[stce_9828.index()] << " from idx "
                       << stce_9828.index();
    stce_10322.stce_9948(stce_9828);
    helper::stce_9836(int(), stce_10330, stce_9828->arg(), stce_9828->pval() * stce_10322[stce_9828.index()]);
    if (stce_9828->stce_10009()) {
      stce_10322[stce_9828.index()] = 0;
    }
  }
}
template <typename stce_10320, typename adjoint_vector>
DCO_STRONG_INLINE void stce_10334(stce_10320 stce_9828, const stce_10320& stce_9875, adjoint_vector& stce_10322) {
  stce_10322.stce_9952(stce_9828.index());
  for (; stce_9828 != stce_9875; --stce_9828) {
    std::cout << stce_9828.index() << ": " << stce_9828->arg() << ", " << stce_9828->pval() << ", "
              << stce_10322[stce_9828.index()] << std::endl;
  }
}
template <typename tape_t> DCO_STRONG_INLINE void stce_10334(const tape_t* tape) {
  typename tape_t::iterator stce_9828 = tape->get_position();
  for (; stce_9828 != tape->begin(); --stce_9828) {
    std::cout << stce_9828.index() << ": " << stce_9828->arg() << ", " << stce_9828->pval() << std::endl;
  }
}
} // namespace stce_10319
} // namespace internal
} // namespace dco

namespace dco {
template <typename tape_t> struct stce_10335 {
  typedef std::map<std::string, mem_long_t> stce_10336;
  stce_10336 stce_10337;
  tape_t* stce_9988;
  stce_10335(tape_t* tape) : stce_9988(tape) {
    stce_10337["max_tape_memory"] = 0;
    stce_10337["max_adjoint_memory"] = 0;
    stce_10337["max_checkpoint_memory"] = 0;
    stce_10337["max_total_memory"] = 0;
  }
  mem_long_t operator[](std::string stce_10338) { return stce_10337[stce_10338]; }
  void stce_10339() {
    mem_long_t stce_10340 = dco::size_of(stce_9988, tape_t::size_of_stack);
    if (stce_10340 > stce_10337["max_tape_memory"]) {
      stce_10337["max_tape_memory"] = stce_10340;
    }
    stce_10340 = dco::size_of(stce_9988, tape_t::size_of_internal_adjoint_vector);
    if (stce_10340 > stce_10337["max_adjoint_memory"]) {
      stce_10337["max_adjoint_memory"] = stce_10340;
    }
    stce_10340 = dco::size_of(stce_9988, tape_t::size_of_checkpoints);
    if (stce_10340 > stce_10337["max_checkpoint_memory"]) {
      stce_10337["max_checkpoint_memory"] = stce_10340;
    }
    stce_10337["max_total_memory"] = 0;
    for (stce_10336::iterator stce_9847 = stce_10337.begin(); stce_9847 != stce_10337.end(); ++stce_9847) {
      stce_10337["max_total_memory"] += stce_9847->second;
    }
  }
  mem_long_t stce_10341() { return stce_10337["max_tape_memory"]; }
};
} // namespace dco

struct stce_10342 {
  int stce_10343;

public:
  DCO_ALWAYS_INLINE stce_10342() : stce_10343(DCO_COMPATIBILITY_VERSION) {}
  DCO_ALWAYS_INLINE bool is_compatible(int stce_10344, bool stce_10334 = false) {
    if (stce_10334)
      dco::cout_diffs_in_version(stce_10344, stce_10343);
    return stce_10344 == stce_10343;
  }
};
namespace dco {
namespace internal {
template <memory_model::TYPE MEMORY_MODEL, typename stce_10345, memory_model::TYPE stce_9789>
class tape
    : public stce_10342,
      public dco::adjoint_vector_abstract<typename helper::vecsize_info<typename stce_10345::stce_9762>::stce_9853>,
      public stce_9983<MEMORY_MODEL, tape<MEMORY_MODEL, stce_10345, stce_9789>, stce_9789> {
public:
  typedef stce_10345 types_config_t;
  typedef stce_9983<MEMORY_MODEL, tape, stce_9789> stce_9901;
  typedef typename stce_9901::iterator iterator_t;
  typedef iterator_t position_t;
  typedef typename types_config_t::stce_9762 stce_9762;
  typedef typename types_config_t::stce_9761 stce_9761;
  typedef typename helper::vecsize_info<typename stce_10345::stce_9762>::stce_9853 stce_9938;
  typedef tape<MEMORY_MODEL, types_config_t, stce_9789> tape_t;
  typedef adjoint_vector_lazy<typename types_config_t::stce_9762, stce_9901> vector_t;
  vector_t stce_9899;
  stce_10335<tape> stce_10346;
  stce_10335<tape>& stce_10347() { return stce_10346; }
  const stce_10335<tape>& stce_10347() const { return stce_10346; }
  tape& get_tape() { return *this; }

private:
  bool stce_10348;
  bool stce_10349;
  struct stce_10350 {
    stce_10350() {}
    template <typename stce_9760> void operator()(index_t, stce_9760&&) const {}
  };
  static const stce_10350 stce_10351;
  index_t stce_9956;
  tape_options stce_9943;
  bool stce_10352;
  bool stce_10353;
  void stce_9961(const iterator_t& stce_9874, const iterator_t& stce_9875 = stce_9901::start()) {
    stce_9899.stce_9950(stce_9874.index(), stce_9875.index());
  }
  void stce_10354() {
    stce_9899.resize(this->stce_10207());
    stce_9899.stce_9953();
  }
  template <typename stce_10320, typename adjoint_vector, typename stce_10329>
  DCO_STRONG_INLINE void stce_10355(stce_10320 stce_9828, const stce_10320& stce_9875, adjoint_vector& stce_10322,
                                    stce_10329 const& stce_10330) {
    if (stce_10352) {
      dco::internal::stce_10319::interpret<true>(stce_9828, stce_9875, stce_10322, stce_10330);
    } else {
      dco::internal::stce_10319::interpret<false>(stce_9828, stce_9875, stce_10322, stce_10330);
    }
  }
  template <typename stce_10320, typename adjoint_vector, typename stce_10329>
  DCO_STRONG_INLINE void stce_10356(stce_10320 stce_9828, const stce_10320& stce_9875, adjoint_vector& stce_10322,
                                    stce_10329 const& stce_10330) {
    if (stce_10352) {
      dco::internal::stce_10319::stce_10333<true>(stce_9828, stce_9875, stce_10322, stce_10330);
    } else {
      dco::internal::stce_10319::stce_10333<false>(stce_9828, stce_9875, stce_10322, stce_10330);
    }
  }

public:
  const tape_options& stce_9944() const { return stce_9943; }
  bool stce_10357() { return this->start() == this->current(); }
  DCO_ALWAYS_INLINE tape(tape_options stce_9944 = tape_options())
      : stce_10342(), stce_9901(stce_9944, *this), stce_9899(1, *this, stce_9944), stce_10346(this), stce_10348(false),
        stce_10349(true), stce_9956(0), stce_9943(stce_9944), stce_10352(false), stce_10353(true) {}
  DCO_ALWAYS_INLINE ~tape() {
    for (typename std::vector<stce_10358>::iterator stce_10005 = stce_10359.begin(); stce_10005 != stce_10359.end();
         ++stce_10005) {
      stce_10005->stce_10360();
    }
  }
  bool is_active() { return stce_9757 ? stce_10349 : true; }
  bool& sparse_interpret() { return stce_10352; }
  bool& scalar_callback_mode() { return stce_10353; }
  DCO_TAPE_INT current_vector_mode_index() { return stce_9956; }
  iterator_t current() const { return get_position(); }
  iterator_t begin() const { return stce_9901::start(); }
  vector_t& adjoints() { return stce_9899; }
  template <typename stce_9780>
  typename std::enable_if<dco::mode<stce_9780>::is_adjoint_type, stce_9762>::type& adjoint(stce_9780 const& stce_9810) {
    return stce_9899[stce_9810._tape_index()];
  }
  typedef helper::stce_10013<tape> stce_10361;
  static void stce_10362(stce_10361* stce_10363) { stce_10363->get_tape()->stce_10352 = true; }
  static void stce_10364(stce_10361* stce_10363) { stce_10363->get_tape()->stce_10352 = false; }
  void set_sparse_interpret() {
    if (stce_10352 == false) {
      stce_10361* stce_10363 = this->create_callback_object<stce_10361>();
      this->insert_callback(stce_10364, stce_10363);
    }
    stce_10352 = true;
  }
  void unset_sparse_interpret() {
    if (stce_10352 == true) {
      stce_10361* stce_10363 = this->create_callback_object<stce_10361>();
      this->insert_callback(stce_10362, stce_10363);
    }
    stce_10352 = false;
  }
  bool switch_to_active() {
    if (!stce_9757) {
      throw dco::exception::create<std::runtime_error>("activity check disabled but switched",
                                                       "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/"
                                                       "dco_cpp_make_release/dco_cpp_dev/src/dco_tape.hpp",
                                                       189);
    }
    if (!stce_10349) {
      stce_10349 = true;
      return false;
    }
    return true;
  }
  bool switch_to_passive() {
    if (!stce_9757) {
      throw dco::exception::create<std::runtime_error>("activity check disabled but switched",
                                                       "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/"
                                                       "dco_cpp_make_release/dco_cpp_dev/src/dco_tape.hpp",
                                                       200);
    }
    if (stce_10349) {
      stce_10349 = false;
      return true;
    }
    return false;
  }
  bool switch_to(bool stce_10365) {
    bool stce_10366 = stce_10349;
    stce_10349 = stce_10365;
    return stce_10366;
  }
  template <bool stce_10367> index_t stce_10368() {
    if (!stce_10367 && this->empty()) {
      return stce_9901::current_ref().stce_10189();
    } else {
      typename stce_9901::edge_inserter stce_10369(stce_9901::current_ref());
      stce_10369.insert(0, static_cast<typename stce_9901::stce_10176>(0.0));
      return stce_10369.index();
    }
  }
  template <typename stce_10086, typename stce_10363>
  void register_variable(internal::active_type<stce_10086, stce_10363> const& stce_9810) {
    internal::active_type<stce_10086, stce_10363>::register_variable(stce_9810, stce_10368<false>(), this);
  }
  template <typename stce_10086> void register_variable(std::vector<stce_10086> const& stce_9810) {
    this->register_variable(stce_9810.data(), stce_9810.size());
  }
  template <typename stce_10370> void register_variable(stce_10370 first, stce_10370 stce_10371) {
    while (first != stce_10371) {
      this->register_variable(*first++);
    }
  }
  template <typename stce_10370, typename stce_10372>
  void register_variable(stce_10370 stce_10373, stce_10370 stce_10374, stce_10372 stce_10375) {
    while (stce_10373 != stce_10374) {
      *stce_10375 = *stce_10373++;
      this->register_variable(*stce_10375++);
    }
  }
  template <typename stce_10086> void register_variable(stce_10086* stce_9810, size_t stce_10032) {
    for (size_t stce_9847 = 0; stce_9847 < stce_10032; ++stce_9847) {
      stce_10086::register_variable(stce_9810[stce_9847], stce_10368<false>(), this);
    }
  }
  template <typename stce_10086> void register_output_variable(stce_10086& stce_9810) {
    typename stce_9901::edge_inserter stce_10369(stce_9901::current_ref());
    stce_10369.insert(dco::tape_index(stce_9810), static_cast<typename stce_9901::stce_10176>(1.0));
    dco::tape_index(stce_9810) = stce_10369.index();
  }
  template <typename stce_10086> void register_output_variable(std::vector<stce_10086>& stce_9810) {
    this->register_output_variable(stce_9810.data(), stce_9810.size());
  }
  template <typename stce_10086> void register_output_variable(stce_10086* stce_9810, size_t stce_10032) {
    for (size_t stce_9847 = 0; stce_9847 < stce_10032; ++stce_9847) {
      this->register_output_variable(stce_9810[stce_9847]);
    }
  }
  template <typename stce_10370> void register_output_variable(stce_10370 first, stce_10370 stce_10371) {
    while (first != stce_10371) {
      this->register_output_variable(*first++);
    }
  }
  template <stce_9796 stce_10376, typename stce_9780, typename stce_9890>
  void register_output_variable(stce_9900<stce_10376, stce_9780, stce_9890> stce_9810) {
    for (size_t stce_9847 = 0; stce_9847 < stce_9810.size(); ++stce_9847) {
      this->register_output_variable(stce_9810[stce_9847]);
    }
  }
  void reset_to(const iterator_t& stce_9875) {
    stce_10286(stce_9875);
    stce_10377(stce_9875);
  }
  void reset() { reset_to(stce_9901::start()); }
  void interpret_adjoint(interpretation_settings stce_9959 = interpretation_settings()) {
    iterator_t stce_9875 = stce_9901::start();
    stce_9960(get_position(), stce_9875, stce_9959, stce_10351);
  }
  template <typename stce_10329 = decltype(stce_10351)>
  typename std::enable_if<!std::is_same<stce_10329, interpretation_settings>::value>::type
  interpret_adjoint(stce_10329 const& stce_10330 = stce_10351) {
    iterator_t stce_9875 = stce_9901::start();
    interpretation_settings stce_9959;
    stce_9960(get_position(), stce_9875, stce_9959, stce_10330);
  }
  template <typename stce_10329 = decltype(stce_10351)>
  void interpret_adjoint_to(const iterator_t& stce_9875, stce_10329 const& stce_10330 = stce_10351) {
    interpretation_settings stce_9959;
    stce_9960(get_position(), stce_9875, stce_9959, stce_10330);
  }
  template <typename stce_10329 = decltype(stce_10351)>
  void interpret_adjoint_from(const iterator_t& stce_9874, stce_10329 const& stce_10330 = stce_10351) {
    iterator_t stce_9875 = stce_9901::start();
    interpretation_settings stce_9959;
    stce_9960(stce_9874, stce_9875, stce_9959, stce_10330);
  }
  template <typename stce_10329 = decltype(stce_10351)>
  void interpret_adjoint_from_to(const iterator_t& stce_9874, const iterator_t& stce_9875,
                                 stce_10329 const& stce_10330 = stce_10351) {
    interpretation_settings stce_9959;
    stce_9960(stce_9874, stce_9875, stce_9959, stce_10330);
  }
  template <typename stce_10329 = decltype(stce_10351)>
  void interpret_adjoint_and_reset_to(const iterator_t& stce_9875, stce_10329 const& stce_10330 = stce_10351) {
    iterator_t stce_9874(get_position());
    interpretation_settings stce_9959;
    stce_9959.reset = true;
    stce_9959.stce_9919 = true;
    stce_9960(stce_9874, stce_9875, stce_9959, stce_10330);
    stce_10286(stce_9875);
    stce_10377(stce_9875);
  }
  template <typename stce_10329 = decltype(stce_10351)>
  void interpret_adjoint_and_zero_adjoints_to(const iterator_t& stce_9875, stce_10329 const& stce_10330 = stce_10351) {
    iterator_t stce_9874(get_position());
    interpretation_settings stce_9959;
    stce_9959.reset = false;
    stce_9959.stce_9919 = true;
    stce_9960(stce_9874, stce_9875, stce_9959, stce_10330);
  }
  template <typename stce_10329 = decltype(stce_10351)>
  void interpret_adjoint_and_zero_adjoints_from_to(const iterator_t& stce_9874, const iterator_t& stce_9875,
                                                   stce_10329 const& stce_10330 = stce_10351) {
    interpretation_settings stce_9959;
    stce_9959.reset = false;
    stce_9959.stce_9919 = true;
    stce_9960(stce_9874, stce_9875, stce_9959, stce_10330);
  }
  void zero_adjoints() {
    iterator_t stce_9875 = stce_9901::start();
    stce_9961(get_position(), stce_9875);
  }
  void zero_adjoints_to(const iterator_t& stce_9875) { stce_9961(get_position(), stce_9875); }
  void zero_adjoints_from(const iterator_t& stce_9874) {
    iterator_t stce_9875 = stce_9901::start();
    stce_9961(stce_9874, stce_9875);
  }
  void zero_adjoints_from_to(const iterator_t& stce_9874, const iterator_t& stce_9875) {
    stce_9961(stce_9874, stce_9875);
  }
  void stce_10286(const iterator_t& stce_9875) {
    bool alloc = stce_9899.stce_9945(stce_9875.index());
    stce_9899.resize(stce_9875.index() + 1);
    if (alloc) {
      stce_9899.stce_9953();
    }
    stce_9901::erase(stce_9875);
  }

public:
  iterator_t get_position() const { return stce_9901::current(); }
  stce_9938& stce_10378(const index_t tape_index) {
    stce_9762& stce_9925 = _adjoint(tape_index);
    stce_9938* stce_10379 = reinterpret_cast<stce_9938*>(&stce_9925);
    return stce_10379[stce_9956];
  }
  stce_9938 stce_10378(const index_t tape_index) const {
    stce_9762 stce_9925(_adjoint(tape_index));
    stce_9938* stce_10379 = reinterpret_cast<stce_9938*>(&stce_9925);
    return stce_10379[stce_9956];
  }
  stce_9762& _adjoint(index_t tape_index) {
    if (!stce_9899.stce_9945(get_position().index() + 1))
      stce_10354();
    return stce_9899[tape_index];
  }
  stce_9762 _adjoint(const index_t tape_index) const {
    return stce_9899.stce_9945(tape_index) ? stce_9899[tape_index] : 0;
  }
  enum stce_10380 {
    size_of_stack = 1,
    size_of_allocated_stack = 2,
    size_of_internal_adjoint_vector = 4,
    size_of_checkpoints = 8,
    stce_9888 = size_of_stack | size_of_internal_adjoint_vector
  };
  mem_long_t stce_10381() const {
    mem_long_t stce_10382 = 0;
    for (size_t stce_9847 = 0; stce_9847 < stce_10359.size(); stce_9847++) {
      stce_10382 += stce_10359[stce_9847].stce_10327()->size_in_byte();
    }
    return stce_10382;
  }
  mem_long_t stce_9889(const int stce_10383 = stce_9888) const {
    mem_long_t stce_10384 = 0;
    if (stce_10383 & size_of_allocated_stack) {
      stce_10384 += static_cast<size_t>(stce_9901::stce_10204());
    } else if (stce_10383 & size_of_stack) {
      stce_10384 += static_cast<size_t>(stce_9901::size_in_byte());
    }
    if (stce_10383 & size_of_internal_adjoint_vector) {
      stce_10384 += stce_9899.stce_9947();
    }
    if (stce_10383 & size_of_checkpoints) {
      stce_10384 += stce_10381();
    }
    return stce_10384;
  }
  static DCO_ALWAYS_INLINE tape_t* create(tape_options stce_9944 = tape_options()) {
    tape_t* tape = new tape_t(stce_9944);
    return tape;
  }
  static DCO_ALWAYS_INLINE void remove(tape_t*& tape) {
    if (tape == 0)
      return;
    delete tape;
    tape = 0;
  }
  virtual stce_9938 _read_adjoint(const index_t stce_9813) { return stce_10378(stce_9813); }
  virtual void _increment_adjoint(const index_t stce_9813, const stce_9938& stce_9925) {
    stce_10378(stce_9813) += stce_9925;
  }
  typedef dco::helper::stce_10013<tape_t> callback_object_t;
  template <typename stce_10385> class stce_10386 {
  public:
    typedef void (*stce_10387)(tape_t& stce_10388, const interpretation_settings& stce_10389, stce_10385* stce_10390);
    typedef void (*stce_10391)(tape_t& stce_10388, stce_10385* stce_10390);
    typedef void (*stce_10392)(stce_10385* stce_10390);
  };
  class stce_10393 {
  public:
    virtual void stce_10394(tape_t& stce_10388, const interpretation_settings& stce_10389,
                            callback_object_t* stce_10390) = 0;
    virtual ~stce_10393(){};
  };
  template <typename stce_10385> class stce_10395 : public stce_10393 {
  private:
    union {
      typename stce_10386<stce_10385>::stce_10392 stce_10396;
      typename stce_10386<stce_10385>::stce_10391 stce_10397;
      typename stce_10386<stce_10385>::stce_10387 stce_10398;
    } stce_10396;
    int stce_10399;

  public:
    stce_10395(typename stce_10386<stce_10385>::stce_10392 stce_10400) : stce_10399(0) {
      stce_10396.stce_10396 = stce_10400;
    }
    stce_10395(typename stce_10386<stce_10385>::stce_10391 stce_10400) : stce_10399(1) {
      stce_10396.stce_10397 = stce_10400;
    }
    stce_10395(typename stce_10386<stce_10385>::stce_10387 stce_10400) : stce_10399(2) {
      stce_10396.stce_10398 = stce_10400;
    }
    void stce_10394(tape_t& stce_10388, const interpretation_settings& stce_10389, callback_object_t* stce_10390) {
      stce_10385* stce_10401 = static_cast<stce_10385*>(stce_10390);
      switch (stce_10399) {
      case 0:
        stce_10396.stce_10396(stce_10401);
        break;
      case 1:
        stce_10396.stce_10397(stce_10388, stce_10401);
        break;
      case 2:
        stce_10396.stce_10398(stce_10388, stce_10389, stce_10401);
        break;
      default:
        if (helper::stce_9839) {
          throw dco::exception::create<std::runtime_error>(
              "Internal error: Unknown callback type. Please contact NAG.");
        }
        break;
      }
    }
    ~stce_10395() {}
  };
  class stce_10358 {
    callback_object_t* stce_10390;
    stce_10393* stce_10402;
    iterator_t stce_10403;

  public:
    stce_10358() = delete;
    stce_10358(const stce_10358& stce_10036) noexcept
        : stce_10390(stce_10036.stce_10390), stce_10402(stce_10036.stce_10402), stce_10403(stce_10036.stce_10403){};
    stce_10358& operator=(const stce_10358& stce_10036) noexcept {
      stce_10390 = stce_10036.stce_10390;
      stce_10402 = stce_10036.stce_10402;
      stce_10403 = stce_10036.stce_10403;
      return *this;
    }
    stce_10358(const iterator_t& stce_10184) : stce_10390(0), stce_10402(0), stce_10403(stce_10184) {}
    bool operator<(const stce_10358& stce_9936) const { return stce_10403 < stce_9936.stce_10403; }
    void stce_10360() {
      delete stce_10390;
      if (stce_10402)
        delete stce_10402;
    }
    template <typename stce_10385, typename stce_10404> void stce_10405(stce_10404 stce_10400) {
      if (stce_10402)
        throw dco::exception::create<std::runtime_error>(
            "Currently not supported to insert external_adjoint_object_bases twice.");
      stce_10402 = new stce_10395<stce_10385>(stce_10400);
    }
    callback_object_t*& stce_10327() { return stce_10390; }
    callback_object_t* stce_10327() const { return stce_10390; }
    iterator_t& stce_10326() { return stce_10403; }
    iterator_t stce_10326() const { return stce_10403; }
    void stce_10394(tape_t& stce_10388, const interpretation_settings& stce_10389) {
      if (stce_10402)
        stce_10402->stce_10394(stce_10388, stce_10389, stce_10390);
    }
  };
  std::vector<stce_10358> stce_10359;
  size_t number_of_callbacks() { return stce_10359.size(); }
  template <class stce_10406> void stce_10407(stce_10406* stce_10390) {
    stce_10359.emplace_back(stce_10358(stce_9901::current()));
    stce_10359.back().stce_10327() = stce_10390;
    stce_10390->set_tape(this);
    typedef typename stce_10406::active_t stce_9984;
    typedef dco::stce_10069::stce_10073<tape_t, stce_9984> stce_10408;
    stce_10408* stce_10068 = stce_10390;
    insert_callback(&dco::stce_10069::stce_10067<tape_t, stce_9984>, stce_10068);
  }
  template <class stce_10406, typename stce_10404> void insert_callback(stce_10404 stce_10402, stce_10406* stce_10363) {
    if (stce_10359.back().stce_10327() == stce_10363) {
      stce_10363->stce_10016();
      stce_10359.back().template stce_10405<stce_10406>(stce_10402);
      stce_10359.back().stce_10326() = stce_9901::current();
      stce_10368<true>();
    } else {
      throw dco::exception::create<std::runtime_error>(
          "please always insert most recently created external function object.");
    }
  }
  template <typename stce_10329> struct stce_10409 : helper::stce_10013<tape> {
    stce_10329 stce_10330;
    template <typename stce_10410>
    stce_10409(stce_10410&& stce_10330) : stce_10330(std::forward<stce_10410>(stce_10330)) {}
  };
  template <typename stce_10411> static auto stce_10412(stce_10411* stce_10363) -> decltype(stce_10363->stce_10330()) {
    stce_10363->stce_10330();
  }
  template <typename stce_10411>
  static auto stce_10412(stce_10411* stce_10363) -> decltype(stce_10363->stce_10330(*stce_10363->_adjoint_vector)) {
    stce_10363->stce_10330(*stce_10363->_adjoint_vector);
  }
  template <typename stce_10329> void insert_callback(stce_10329&& stce_9851) {
    using stce_10413 = stce_10409<typename std::decay<stce_10329>::type>;
    auto* stce_10363 = this->create_callback_object<stce_10413>(std::forward<stce_10329>(stce_9851));
    this->insert_callback(stce_10412<stce_10413>, stce_10363);
  }
  template <class stce_10406, typename... FCN_PARAMETERS>
  stce_10406* create_callback_object(FCN_PARAMETERS&&... parameters) {
    stce_10359.emplace_back(stce_10358(stce_9901::current()));
    stce_10406* stce_10390 = new stce_10406(std::forward<FCN_PARAMETERS>(parameters)...);
    stce_10359.back().stce_10327() = stce_10390;
    stce_10390->set_tape(this);
    return stce_10390;
  }
  template <class stce_10406> inline stce_10406* create_ACM_object() {
    stce_10406* stce_9849 = create_callback_object<stce_10406>();
    typedef typename stce_10406::active_t stce_9984;
    typedef dco::ACM::baseclass<tape_t, stce_9984> stce_10414;
    stce_10414* stce_10068 = stce_9849;
    insert_callback(&dco::ACM::stce_10067<tape_t, stce_9984>, stce_10068);
    return stce_9849;
  }
  template <class stce_10406, typename FCN_PARAMETERS>
  inline stce_10406* create_ACM_object(const FCN_PARAMETERS& parameters) {
    const stce_9858<FCN_PARAMETERS> stce_10415(parameters);
    stce_10358 stce_10416(stce_9901::current());
    stce_10359.push_back(stce_10416);
    stce_10406* stce_10390 = stce_10415.template create<stce_10406>();
    stce_10359.back().stce_10327() = stce_10390;
    stce_10390->set_tape(this);
    typedef typename stce_10406::active_t stce_9984;
    typedef dco::ACM::baseclass<tape_t, stce_9984> stce_10414;
    stce_10414* stce_10068 = stce_10390;
    insert_callback(&dco::ACM::stce_10067<tape_t, stce_9984>, stce_10068);
    return stce_10390;
  }
  template <class stce_10406> void insert_ACM_object(stce_10406* stce_10390) {
    stce_10358 stce_10416(stce_9901::current());
    stce_10359.push_back(stce_10416);
    stce_10359.back().stce_10327() = stce_10390;
    stce_10390->set_tape(this);
    typedef typename stce_10406::active_t stce_9984;
    typedef dco::ACM::baseclass<tape_t, stce_9984> stce_10414;
    stce_10414* stce_10068 = stce_10390;
    insert_callback(&dco::ACM::stce_10067<tape_t, stce_9984>, stce_10068);
  }
  void stce_10377(const iterator_t& stce_9875) {
    typedef typename std::vector<stce_10358>::iterator stce_10325;
    stce_10325 stce_10079 = stce_10359.begin();
    for (; stce_10079 != stce_10359.end() && stce_10079->stce_10326().index() < stce_9875.index(); ++stce_10079) {
    }
    for (stce_10325 stce_10005 = stce_10079; stce_10005 != stce_10359.end(); ++stce_10005)
      stce_10005->stce_10360();
    stce_10359.erase(stce_10079, stce_10359.end());
  }

public:
  void write_to_dot(const std::string& filename = "tape.dot") {
    write_to_dot(stce_9901::current(), stce_9901::start(), filename);
  }
  void write_to_dot(iterator_t stce_9874) { write_to_dot(stce_9874, stce_9901::start()); }
  void write_to_dot(iterator_t stce_9828, iterator_t stce_9875, const std::string& filename = "tape.dot") {
    stce_9861 stce_9862(filename);
    dco::internal::stce_10319::stce_10321(stce_9828, stce_9875, stce_9899, stce_10359, stce_9862);
  }
  void write_to_csv(const std::string& filename = "tape.csv") {
    write_to_csv(stce_9901::current(), stce_9901::start(), filename);
  }
  void write_to_csv(iterator_t stce_9874) { write_to_csv(stce_9874, stce_9901::start()); }
  void write_to_csv(iterator_t stce_9828, iterator_t stce_9875, const std::string& filename = "tape.csv") {
    if (stce_10359.size() != 0)
      throw dco::exception::create<std::runtime_error>("write_to_csv not implemented for callbacks.",
                                                       "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/"
                                                       "dco_cpp_make_release/dco_cpp_dev/src/dco_tape.hpp",
                                                       795);
    dco::internal::stce_10319::stce_10328(stce_9828, stce_9875, filename);
  }
  void synchronize_with(tape const* const stce_9936) { this->stce_10208(stce_9936); }
  void stce_10417(iterator_t const& stce_9828, stce_10358& stce_10418, interpretation_settings const& stce_9959) {
    this->stce_10417(*this, stce_9828, stce_10418, stce_9959);
  }
  template <class stce_10419>
  void stce_10417(stce_10419& stce_10379, const iterator_t& stce_9828, stce_10358& stce_10418,
                  const interpretation_settings& stce_9959) {
    if (stce_10418.stce_10326() != stce_9828)
      throw dco::exception::create<std::runtime_error>("invoking callback at wrong position",
                                                       "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/"
                                                       "dco_cpp_make_release/dco_cpp_dev/src/dco_tape.hpp",
                                                       814);
    if (stce_9959.reset) {
      stce_10286(stce_9828);
      stce_10368<true>();
    }
    index_t vecsize = static_cast<index_t>(dco::helper::vecsize_info<typename types_config_t::stce_9762>::vecsize);
    if (stce_10353) {
      for (index_t stce_10420 = 0; stce_10420 < vecsize; stce_10420++) {
        stce_9956 = stce_10420;
        stce_10418.stce_10327()->_adjoint_vector = &stce_10379;
        stce_10418.stce_10394(*this, stce_9959);
      }
    } else {
      stce_10418.stce_10327()->_adjoint_vector = &stce_10379;
      stce_10418.stce_10394(*this, stce_9959);
    }
  }
  struct stce_10421 {
    tape* stce_9988;
    bool stce_10352;
    stce_10421(tape* stce_10015) : stce_9988(stce_10015), stce_10352(stce_10015->sparse_interpret()) {}
    ~stce_10421() { stce_9988->sparse_interpret() = stce_10352; }
  };
  template <typename stce_10329 = decltype(stce_10351)>
  void stce_9960(iterator_t stce_9828, const iterator_t& stce_9875, const interpretation_settings& stce_9959,
                 stce_10329 const& stce_10330) {
    stce_10354();
    stce_9966(stce_9899, *this, stce_9828, stce_9875, stce_9959, stce_10330);
  }
  template <typename stce_10419, typename stce_10422, typename stce_10329>
  void stce_9966(stce_10419& stce_10379, stce_10422& stce_10423, iterator_t stce_9828, const iterator_t& stce_9875,
                 const interpretation_settings& stce_9959, stce_10329 const& stce_10330) {
    stce_10421 stce_10424(this);
    if (stce_9828 > stce_9901::current()) {
      throw dco::exception::create<std::runtime_error>("you try to use a tape position outside of the current tape.",
                                                       "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/"
                                                       "dco_cpp_make_release/dco_cpp_dev/src/dco_tape.hpp",
                                                       867);
    }
    if (stce_9875 > stce_9828) {
      throw dco::exception::create<std::runtime_error>("adjoint interpretation: from < to.",
                                                       "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/"
                                                       "dco_cpp_make_release/dco_cpp_dev/src/dco_tape.hpp",
                                                       872);
    }
    for (int stce_9847 = static_cast<int>(stce_10359.size() - 1);
         stce_9847 >= 0 && stce_9875 <= stce_10359[stce_9847].stce_10326(); --stce_9847) {
      const iterator_t& stce_10425 = stce_10359[stce_9847].stce_10326();
      if (stce_9828 < stce_10425) {
        continue;
      }
      stce_9901::stce_10205(stce_9828);
      if (stce_9959.stce_9919)
        stce_10356(stce_9828, stce_10425, stce_10379, stce_10330);
      else {
        stce_10355(stce_9828, stce_10425, stce_10379, stce_10330);
      }
      stce_9828 = stce_10425;
      stce_9901::stce_10206();
      stce_10417(stce_10423, stce_9828, stce_10359[stce_9847], stce_9959);
      if (stce_9959.reset) {
        stce_10286(stce_9828);
        stce_10359[stce_9847].stce_10360();
        stce_10359.erase(stce_10359.begin() + stce_9847);
      }
    }
    stce_9901::stce_10205(stce_9828);
    if (stce_9959.stce_9919) {
      stce_10356(stce_9828, stce_9875, stce_10379, stce_10330);
    } else {
      stce_10355(stce_9828, stce_9875, stce_10379, stce_10330);
    }
    if (stce_9959.reset) {
      stce_10286(stce_9828);
    }
    stce_9901::stce_10206();
  }
};
template <memory_model::TYPE MEMORY_MODEL, typename stce_10345, memory_model::TYPE stce_9789>
const typename tape<MEMORY_MODEL, stce_10345, stce_9789>::stce_10350
    tape<MEMORY_MODEL, stce_10345, stce_9789>::stce_10351;
} // namespace internal
} // namespace dco
namespace dco {
template <class stce_9780, class stce_9759 = stce_9780, class stce_9760 = stce_9759,
          memory_model::TYPE MEMORY_MODEL = DCO_TAPE_MEMORY_MODEL>
class ga1sm_mod {
  typedef types_config_t<stce_9780, stce_9759, stce_9760> stce_10144;

public:
  typedef ga1sm_mod mode_t;
  typedef dco::internal::stce_10146<ga1sm_mod> data_t;
  static const memory_model::TYPE TAPE_MODEL = memory_model::stce_9768;
  static const memory_model::TYPE stce_10426 = MEMORY_MODEL;
  typedef typename stce_10144::value_t value_t;
  typedef typename stce_10144::value_t active_value_t;
  typedef value_t scalar_value_t;
  typedef typename stce_10144::stce_9762 derivative_t;
  typedef derivative_t stce_9985;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::active_type<value_t, data_t> type;
  typedef type active_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = true;
  static const bool is_tangent_type = false;
  static const bool stce_10145 = false;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
  typedef dco::internal::tape<TAPE_MODEL, stce_10144, stce_10426> tape_t;
  typedef typename internal::stce_10076<type> local_gradient_t;
  typedef dco::helper::stce_10013<tape_t> callback_object_t;
  typedef dco::helper::stce_10019<type, tape_t> userdata_object_t;
  typedef dco::helper::stce_10037<type, tape_t> external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<type> jacobian_preaccumulator_t;
};
} // namespace dco

namespace dco {
template <class stce_9780, class stce_9759 = stce_9780, class stce_9760 = stce_9759,
          memory_model::TYPE MEMORY_MODEL = DCO_TAPE_MEMORY_MODEL>
class ga1s_mod {
  typedef types_config_t<stce_9780, stce_9759, stce_9760> stce_10144;

public:
  typedef ga1s_mod mode_t;
  static const memory_model::TYPE TAPE_MODEL = memory_model::stce_9768;
  static const memory_model::TYPE stce_10426 = MEMORY_MODEL;
  typedef dco::internal::stce_10139<ga1s_mod> data_t;
  typedef typename stce_10144::value_t value_t;
  typedef typename stce_10144::value_t active_value_t;
  typedef value_t scalar_value_t;
  typedef typename stce_10144::stce_9762 derivative_t;
  typedef derivative_t stce_9985;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::active_type<value_t, data_t> type;
  typedef type active_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = true;
  static const bool is_tangent_type = false;
  static const bool stce_10145 = false;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
  typedef dco::internal::tape<TAPE_MODEL, stce_10144, stce_10426> tape_t;
  static DCOi_THREAD_LOCAL tape_t* global_tape;
  typedef typename internal::stce_10076<type> local_gradient_t;
  typedef dco::helper::stce_10013<tape_t> callback_object_t;
  typedef dco::helper::stce_10019<type, tape_t> userdata_object_t;
  typedef dco::helper::stce_10037<type, tape_t> external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<type> jacobian_preaccumulator_t;
};
template <class stce_9780, class stce_9759, class stce_9760, memory_model::TYPE MEMORY_MODEL>
DCOi_THREAD_LOCAL typename ga1s_mod<stce_9780, stce_9759, stce_9760, MEMORY_MODEL>::tape_t*
    ga1s_mod<stce_9780, stce_9759, stce_9760, MEMORY_MODEL>::global_tape = 0;
} // namespace dco

namespace dco {
template <typename stce_9780, const size_t stce_10427 = 1, typename stce_9759 = stce_9780,
          typename stce_9760 = stce_9759, memory_model::TYPE MEMORY_MODEL = DCO_TAPE_MEMORY_MODEL>
class ga1v {
  typedef types_config_t<stce_9780, stce_9759, dco::helper::valvec<stce_9760, stce_10427>> stce_10144;

public:
  typedef ga1v mode_t;
  typedef dco::internal::stce_10139<ga1v> data_t;
  static const memory_model::TYPE TAPE_MODEL = MEMORY_MODEL;
  typedef typename stce_10144::value_t value_t;
  typedef typename stce_10144::value_t active_value_t;
  typedef value_t scalar_value_t;
  typedef typename stce_10144::stce_9762 derivative_t;
  typedef stce_9760 stce_9985;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::active_type<value_t, data_t> type;
  typedef type active_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = true;
  static const bool is_tangent_type = false;
  static const bool stce_10145 = true;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
  typedef internal::tape<TAPE_MODEL, stce_10144> tape_t;
  static DCOi_THREAD_LOCAL tape_t* global_tape;
  typedef typename internal::stce_10076<type> local_gradient_t;
  typedef dco::helper::stce_10013<tape_t> callback_object_t;
  typedef dco::helper::stce_10019<type, tape_t> userdata_object_t;
  typedef dco::helper::stce_10037<type, tape_t> external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<type> jacobian_preaccumulator_t;
};
template <typename stce_9780, const size_t stce_10427, typename stce_9759, typename stce_9760,
          memory_model::TYPE MEMORY_MODEL>
DCOi_THREAD_LOCAL typename ga1v<stce_9780, stce_10427, stce_9759, stce_9760, MEMORY_MODEL>::tape_t*
    ga1v<stce_9780, stce_10427, stce_9759, stce_9760, MEMORY_MODEL>::global_tape;
} // namespace dco

namespace dco {
template <typename stce_9780, const size_t stce_10427 = 1, typename stce_9759 = stce_9780,
          typename stce_9760 = stce_9759, memory_model::TYPE MEMORY_MODEL = DCO_TAPE_MEMORY_MODEL>
class ga1vm {
  typedef types_config_t<stce_9780, stce_9759, dco::helper::valvec<stce_9760, stce_10427>> stce_10144;

public:
  typedef ga1vm mode_t;
  typedef dco::internal::stce_10146<ga1vm> data_t;
  static const memory_model::TYPE TAPE_MODEL = MEMORY_MODEL;
  typedef typename stce_10144::value_t value_t;
  typedef typename stce_10144::value_t active_value_t;
  typedef value_t scalar_value_t;
  typedef typename stce_10144::stce_9762 derivative_t;
  typedef stce_9760 stce_9985;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::active_type<value_t, data_t> type;
  typedef type active_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = true;
  static const bool is_tangent_type = false;
  static const bool stce_10145 = true;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
  typedef internal::tape<TAPE_MODEL, stce_10144> tape_t;
  typedef typename internal::stce_10076<type> local_gradient_t;
  typedef dco::helper::stce_10013<tape_t> callback_object_t;
  typedef dco::helper::stce_10019<type, tape_t> userdata_object_t;
  typedef dco::helper::stce_10037<type, tape_t> external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<type> jacobian_preaccumulator_t;
};
} // namespace dco

namespace dco {
template <typename stce_9780, const size_t stce_10427 = 1, typename stce_9759 = stce_9780,
          typename stce_9760 = stce_9759, memory_model::TYPE MEMORY_MODEL = DCO_TAPE_MEMORY_MODEL>
class ga1vm_mod {
  typedef types_config_t<stce_9780, stce_9759, dco::helper::valvec<stce_9760, stce_10427>> stce_10144;

public:
  typedef ga1vm_mod mode_t;
  typedef dco::internal::stce_10146<ga1vm_mod> data_t;
  static const memory_model::TYPE TAPE_MODEL = memory_model::stce_9768;
  static const memory_model::TYPE stce_10426 = MEMORY_MODEL;
  typedef typename stce_10144::value_t value_t;
  typedef typename stce_10144::value_t active_value_t;
  typedef value_t scalar_value_t;
  typedef typename stce_10144::stce_9762 derivative_t;
  typedef typename derivative_t::value_t stce_9985;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::active_type<value_t, data_t> type;
  typedef type active_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = true;
  static const bool is_tangent_type = false;
  static const bool stce_10145 = true;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
  typedef dco::internal::tape<TAPE_MODEL, stce_10144, stce_10426> tape_t;
  typedef typename internal::stce_10076<type> local_gradient_t;
  typedef dco::helper::stce_10013<tape_t> callback_object_t;
  typedef dco::helper::stce_10019<type, tape_t> userdata_object_t;
  typedef dco::helper::stce_10037<type, tape_t> external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<type> jacobian_preaccumulator_t;
};
} // namespace dco

namespace dco {
template <typename stce_9780, const size_t stce_10427 = 1, typename stce_9759 = stce_9780,
          typename stce_9760 = stce_9759, memory_model::TYPE MEMORY_MODEL = DCO_TAPE_MEMORY_MODEL>
class ga1v_mod {
  typedef types_config_t<stce_9780, stce_9759, dco::helper::valvec<stce_9760, stce_10427>> stce_10144;

public:
  typedef ga1v_mod mode_t;
  typedef dco::internal::stce_10139<ga1v_mod> data_t;
  static const memory_model::TYPE TAPE_MODEL = memory_model::stce_9768;
  static const memory_model::TYPE stce_10426 = MEMORY_MODEL;
  typedef typename stce_10144::value_t value_t;
  typedef value_t scalar_value_t;
  typedef typename stce_10144::value_t active_value_t;
  typedef typename stce_10144::stce_9762 derivative_t;
  typedef typename derivative_t::value_t stce_9985;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::active_type<value_t, data_t> type;
  typedef type active_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = true;
  static const bool is_tangent_type = false;
  static const bool stce_10145 = true;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
  typedef dco::internal::tape<TAPE_MODEL, stce_10144, stce_10426> tape_t;
  static DCOi_THREAD_LOCAL tape_t* global_tape;
  typedef typename internal::stce_10076<type> local_gradient_t;
  typedef dco::helper::stce_10013<tape_t> callback_object_t;
  typedef dco::helper::stce_10019<type, tape_t> userdata_object_t;
  typedef dco::helper::stce_10037<type, tape_t> external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<type> jacobian_preaccumulator_t;
};
template <typename stce_9780, const size_t stce_10427, typename stce_9759, typename stce_9760,
          memory_model::TYPE MEMORY_MODEL>
DCOi_THREAD_LOCAL typename ga1v_mod<stce_9780, stce_10427, stce_9759, stce_9760, MEMORY_MODEL>::tape_t*
    ga1v_mod<stce_9780, stce_10427, stce_9759, stce_9760, MEMORY_MODEL>::global_tape;
} // namespace dco

namespace dco {
template <typename active_t, typename stce_10428 = void> struct gbcp;
template <typename stce_9984>
struct gbcp<stce_9984, typename dco::enable_if<(dco::mode<stce_9984>::is_dco_type &&
                                                !internal::is_gbcp_type<stce_9984>::value)>::type> {
  typedef stce_9984 binary_t;
  typedef typename dco::mode<binary_t>::value_t active_t;
  typedef active_t active_value_t;
  typedef typename dco::mode<active_value_t>::value_t value_t;
  typedef typename dco::mode<active_value_t>::scalar_value_t scalar_value_t;
  typedef typename mode<active_value_t>::passive_t passive_t;
  typedef typename mode<active_value_t>::scalar_passive_t scalar_passive_t;
  typedef internal::jacobian_preaccumulator_t<void> jacobian_preaccumulator_t;
  typedef dco::internal::stce_9909<gbcp> data_t;
  typedef dco::internal::active_type<active_value_t, data_t> type;
  typedef typename dco::mode<active_value_t>::tape_t tape_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = dco::mode<active_value_t>::is_adjoint_type;
  static const bool is_tangent_type = dco::mode<active_value_t>::is_tangent_type;
  static const bool stce_10145 = dco::mode<active_value_t>::stce_10145;
  static const int gbcp_order = 1;
  static const int order = dco::mode<binary_t>::order - 1;
  static const size_t p1f_size = 0;
};
template <typename stce_10429>
struct gbcp<stce_10429, typename dco::enable_if<(dco::mode<stce_10429>::is_dco_type &&
                                                 internal::is_gbcp_type<stce_10429>::value)>::type> {
  typedef stce_10429 binary_t;
  typedef typename dco::mode<binary_t>::active_t active_t;
  typedef typename dco::mode<binary_t>::active_value_t active_value_t;
  typedef typename dco::mode<binary_t>::value_t value_t;
  typedef typename dco::mode<binary_t>::scalar_value_t scalar_value_t;
  typedef typename dco::mode<binary_t>::passive_t passive_t;
  typedef typename dco::mode<binary_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::stce_9909<gbcp> data_t;
  typedef dco::internal::active_type<active_value_t, data_t> type;
  typedef internal::jacobian_preaccumulator_t<void> jacobian_preaccumulator_t;
  typedef typename dco::mode<active_value_t>::tape_t tape_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = dco::mode<binary_t>::is_adjoint_type;
  static const bool is_tangent_type = dco::mode<binary_t>::is_tangent_type;
  static const int gbcp_order = dco::mode<binary_t>::gbcp_order + 1;
  static const int order = dco::mode<binary_t>::order - 1;
};
template <typename stce_9977>
struct gbcp<stce_9977, typename dco::enable_if<(!dco::mode<stce_9977>::is_dco_type)>::type> {
  typedef internal::jacobian_preaccumulator_t<void> jacobian_preaccumulator_t;
  typedef stce_9977 binary_t;
  typedef binary_t active_t;
  typedef binary_t active_value_t;
  typedef binary_t value_t;
  typedef binary_t scalar_value_t;
  typedef binary_t passive_t;
  typedef typename dco::mode<binary_t>::scalar_passive_t scalar_passive_t;
  typedef binary_t type;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = false;
  static const bool is_tangent_type = false;
  static const int gbcp_order = 1;
  static const int order = 0;
  typedef typename dco::mode<active_value_t>::tape_t tape_t;
};
} // namespace dco

namespace dco {
template <typename stce_9780, size_t stce_10430 = 32> struct gp1f {
  typedef stce_9780 value_t;
  typedef stce_9780 active_value_t;
  typedef value_t scalar_value_t;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  static const size_t p1f_size = stce_10430;
  typedef internal::stce_10315<gp1f> data_t;
  typedef internal::active_type<stce_9780, data_t> type;
  typedef typename data_t::derivative_t derivative_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = false;
  static const bool is_tangent_type = false;
  static const bool is_intermediate_type = false;
  static const int order = dco::mode<stce_9780>::order + 1;
  typedef stce_9807 tape_t;
  typedef void local_gradient_t;
  typedef void external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<void> jacobian_preaccumulator_t;
};
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_9790> struct stce_10431 {
  typedef stce_9790 mode_t;
  index_t tape_index;
  stce_10431() : tape_index(0) {}
  void clear() { tape_index = 0; }
  typedef typename mode_t::value_t stce_9769;

private:
  template <class stce_10126>
  static void interpret(const dco::internal::active_type<stce_9769, stce_10126>& stce_9810, bool stce_10432) {
    (void)stce_10432;
    stce_9790::global_tape->stce_10433[stce_9790::global_tape->stce_10434] = stce_9810.tape_index;
    stce_9790::global_tape->stce_10434++;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static void interpret(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810,
                        bool stce_10432) {
    interpret(stce_9810.stce_10132, stce_10432);
    interpret(stce_9810.stce_10134, stce_10432);
  }
  template <class stce_10136, class stce_10130>
  static void interpret(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9810, bool stce_10432) {
    interpret(stce_9810.stce_10137, stce_10432);
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static void interpret(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810,
                        bool stce_10432) {
    interpret(stce_9810.stce_10132, stce_10432);
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static void interpret(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810,
                        bool stce_10432) {
    interpret(stce_9810.stce_10134, stce_10432);
  }

protected:
  template <class stce_9910, class stce_9795> static void stce_9911(const stce_9910& stce_9907, stce_9795& stce_10435) {
    const int stce_10436 = stce_9790::global_tape->stce_10434;
    interpret(stce_9907, false);
    stce_10431& data = const_cast<stce_10431&>(stce_10435);
    if (stce_10436 == stce_9790::global_tape->stce_10434) {
      data.clear();
    } else {
      stce_9790::global_tape->stce_10437++;
      data.tape_index = stce_9790::global_tape->stce_10437;
      stce_9790::global_tape->stce_10438[stce_9790::global_tape->stce_10437].stce_10439 =
          stce_9790::global_tape->stce_10434 - stce_10436;
      stce_9790::global_tape->stce_10438[stce_9790::global_tape->stce_10437].stce_10436 = stce_10436;
    }
  }
  template <class stce_9910> void stce_9911(const stce_9910& stce_9907) { stce_9911(stce_9907, *this); }
};
} // namespace internal
} // namespace dco
namespace dco {
namespace internal {
template <typename stce_9769> struct stce_10440 {
private:
  template <typename stce_9790> friend struct stce_10431;
  struct stce_10441 {
    index_t stce_10439;
    index_t stce_10436;
  };
  stce_10441* stce_10438;
  index_t stce_10437;
  int* stce_10433;
  index_t stce_10434;
  stce_10440(const stce_10440<stce_9769>&) {
    throw dco::exception::create<std::runtime_error>("dco_error: Not implemented yet! Please report, why needed!",
                                                     "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/"
                                                     "dco_cpp_make_release/dco_cpp_dev/src/dco_tape_blob_pattern.hpp",
                                                     32);
  }
  stce_10440(index_t stce_10439, index_t stce_10442) {
    stce_10438 = new stce_10441[stce_9752(stce_10442)];
    stce_10437 = 0;
    stce_10433 = new int[size_t(stce_10439)];
    stce_10434 = 0;
  }
  ~stce_10440() {
    if (stce_10438)
      delete[] stce_10438;
    if (stce_10433)
      delete[] stce_10433;
  }

public:
  struct stce_10443 {
    friend struct stce_10440<stce_9769>;

  private:
    index_t stce_10444;
    index_t stce_10445;
    stce_10443(index_t stce_10446, index_t stce_10447) : stce_10444(stce_10446), stce_10445(stce_10447) {}

  public:
    stce_10443() : stce_10444(0), stce_10445(0){};
    index_t stce_10448() { return stce_10444; }
    index_t stce_10449() {
      if (stce_10445 < 0)
        return -stce_10445;
      return stce_10445;
    }
    bool stce_10432() { return stce_10445 < 0; }
  };
  struct iterator_t {
  private:
    index_t _progvarcounter;

  public:
    index_t stce_10442() const { return _progvarcounter; }
    iterator_t(const index_t stce_10450) : _progvarcounter(stce_10450) {}
  };
  iterator_t get_position() { return iterator_t(stce_10437); }
  typedef std::vector<stce_10443> sparse_jacobi;
  template <class stce_9780>
  sparse_jacobi* build_pattern(stce_9780* stce_10448, index_t stce_10032, const iterator_t& stce_10451) {
    sparse_jacobi* stce_9849 = new sparse_jacobi();
    for (index_t stce_9847 = 0; stce_9847 < stce_10032; ++stce_9847) {
      stce_10452(stce_9847 + 1, stce_10448[stce_9847].tape_index, stce_10451, stce_9849);
    }
    return stce_9849;
  }
  void create_pattern_file(sparse_jacobi* stce_10453, std::string filename) {
    std::ofstream out(filename.c_str());
    for (size_t stce_9847 = 0; stce_9847 < stce_10453->size(); ++stce_9847) {
      stce_10443& stce_10454 = (*stce_10453)[stce_9847];
      out << stce_10454.stce_10448() << " " << stce_10454.stce_10449() << " 1" << std::endl;
    }
    out.close();
  }
  void stce_10455(std::string filename) {
    std::ofstream out(filename.c_str());
    out << "digraph {" << std::endl;
    for (index_t stce_9847 = 1; stce_9847 <= stce_10437; ++stce_9847) {
      out << stce_9847 << std::endl;
    }
    for (index_t stce_9847 = 1; stce_9847 <= stce_10437; ++stce_9847) {
      int stce_10439 = stce_10438[stce_9847].stce_10439;
      int stce_10456 = stce_10438[stce_9847].stce_10436;
      for (int stce_10457 = 0; stce_10457 < stce_10439; ++stce_10457) {
        int stce_10079 = stce_10433[stce_10457 + stce_10456];
        out << stce_9847 << " -> " << stce_10079 << std::endl;
      }
    }
    out << "}" << std::endl;
    out.close();
  }
  void stce_10452(index_t stce_10446, index_t stce_9870, const iterator_t& stce_10451, sparse_jacobi* stce_10458) {
    if (stce_9870 == 0)
      return;
    if (stce_9870 <= stce_10451.stce_10442()) {
      stce_10458->push_back(stce_10443(stce_10446, stce_9870));
    } else {
      index_t stce_10439 = stce_10438[stce_9870].stce_10439;
      index_t stce_10456 = stce_10438[stce_9870].stce_10436;
      for (int stce_9847 = 0; stce_9847 < stce_10439; ++stce_9847) {
        stce_10452(stce_10446, stce_10433[stce_9847 + stce_10456], stce_10451, stce_10458);
      }
    }
  }
  static stce_10440* create(index_t size, index_t stce_10459 = 0) {
    if (stce_10459 == 0)
      stce_10459 = size / 2;
    return new stce_10440(size, stce_10459);
  }
  static void remove(stce_10440*& tape) {
    delete tape;
    tape = 0;
  }
  template <class stce_10126> void register_variable(dco::internal::active_type<stce_9769, stce_10126>& stce_10460) {
    stce_10126& data = stce_10460.data();
    stce_10437++;
    data.tape_index = stce_10437;
  }
};
} // namespace internal
} // namespace dco
namespace dco {
template <typename stce_9780 = double> struct gp1t {
  typedef stce_9780 value_t;
  typedef value_t scalar_value_t;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef typename internal::stce_10440<stce_9780> tape_t;
  static DCOi_THREAD_LOCAL tape_t* global_tape;
  typedef internal::stce_10431<gp1t> data_t;
  typedef internal::active_type<stce_9780, data_t> type;
  static const bool is_dco_type = true;
  static const bool is_intermediate_type = false;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
};
template <class stce_9780> DCOi_THREAD_LOCAL typename gp1t<stce_9780>::tape_t* gp1t<stce_9780>::global_tape = 0;
} // namespace dco

namespace dco {
namespace internal {
inline bool all(bool stce_10461) { return stce_10461; }
template <std::size_t stce_10032> inline bool all(std::bitset<stce_10032> const& stce_10461) {
  return stce_10461.all();
}
template <typename, typename, typename enable_if = void> struct stce_10462 {
  template <typename stce_9879, typename stce_10376>
  static typename std::common_type<typename dco::mode<stce_9879>::derivative_t, stce_10376>::type
  get(stce_9879&& stce_9810, stce_10376 const& pval) {
    return (HAS_GT1S_ACTIVITY_CHECK && all(stce_9810.stce_10463 == 0.0)) ? stce_9810.stce_10463
                                                                         : stce_9810.stce_10463 * pval;
  }
};
template <typename stce_10464, typename stce_9790>
struct stce_10462<
    stce_10464, stce_9790,
    typename std::enable_if<std::is_base_of<typename stce_10464::data_t,
                                            internal::stce_10315<typename stce_10464::data_t::mode_t>>::value>::type> {
  template <typename stce_9879, typename stce_10376>
  static typename stce_9790::derivative_t get(stce_9879&& stce_9810, stce_10376&& pval) {
    return (stce_9810.stce_10463 == 0) ? static_cast<typename stce_9790::derivative_t>(0.0)
                                       : stce_9810.stce_10463 * (pval == 0 ? pval + 1 : pval);
  }
};
template <typename stce_9790> struct stce_10465 {
  typedef stce_9790 mode_t;
  typedef stce_10087 stce_10141;
  typedef typename mode_t::derivative_t derivative_t;
  mutable derivative_t stce_10463;
  stce_10465() : stce_10463(0.0) {}
  DCO_STRONG_INLINE stce_10465(const stce_10465& stce_10084) : stce_10463(stce_10084.stce_10463) {}
  stce_10465& operator=(const stce_10465& stce_10084) {
    stce_10463 = stce_10084.stce_10463;
    return *this;
  }
  void stce_10085(const derivative_t& stce_9753) { stce_10463 = stce_9753; }
  void stce_9962(derivative_t& stce_9753) const { stce_9753 = stce_10463; }
  void clear() { stce_10463 = 0.0; }
  derivative_t& stce_9969() const {
    stce_1000002();
    ;
    return stce_10463;
  }
  derivative_t& stce_9975() const { return stce_9969(); }
  template <class stce_9910> void stce_9911(const stce_9910& stce_10142) {
    stce_10463 = stce_10466(stce_10142, static_cast<derivative_t>(1.0));
  }
  template <class stce_9769, class stce_10126>
  static derivative_t stce_10466(const dco::internal::active_type<stce_9769, stce_10126>& stce_9810,
                                 const derivative_t& pval) {
    return stce_10462<dco::mode<typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::value_t>,
                      stce_9790>::get(stce_9810, pval);
  }
  template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
  static derivative_t
  stce_10466(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810,
             const derivative_t& pval) {
    return stce_10466(stce_9810.stce_10132, stce_9810.stce_10133() * pval) +
           stce_10466(stce_9810.stce_10134, stce_9810.stce_10135() * pval);
  }
  template <class stce_9769, class stce_10136, class stce_10130>
  static derivative_t stce_10466(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9810,
                                 const derivative_t& pval) {
    return stce_10466(stce_9810.stce_10137, stce_9810.pval() * pval);
  }
  template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
  static derivative_t
  stce_10466(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810,
             const derivative_t& pval) {
    return stce_10466(stce_9810.stce_10132, stce_9810.stce_10133() * pval);
  }
  template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
  static derivative_t
  stce_10466(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810,
             const derivative_t& pval) {
    return stce_10466(stce_9810.stce_10134, stce_9810.stce_10135() * pval);
  }
  static typename mode_t::tape_t* tape() { return nullptr; }
  index_t _tape_index() const { return 0; }
};
} // namespace internal
} // namespace dco
namespace dco {
template <class stce_9780, typename stce_10467 = stce_9780> class gt1s {
public:
  typedef gt1s mode_t;
  typedef dco::internal::stce_10465<gt1s> data_t;
  typedef stce_9780 value_t;
  typedef stce_9780 active_value_t;
  typedef stce_9780 scalar_value_t;
  typedef stce_10467 derivative_t;
  typedef stce_10467 stce_9985;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::active_type<stce_9780, data_t> type;
  typedef type active_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = false;
  static const bool is_tangent_type = true;
  static const bool stce_10145 = false;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
  typedef stce_9807 tape_t;
  typedef void local_gradient_t;
  typedef void external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<void> jacobian_preaccumulator_t;
};
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_9790> struct stce_10468 {
  typedef stce_9790 mode_t;
  typedef stce_10087 stce_10141;
  typedef typename mode_t::derivative_t derivative_t;
  typedef typename derivative_t::value_t stce_9985;

protected:
  typedef typename mode_t::value_t stce_9769;

public:
  static const int vecsize = derivative_t::stce_9843;
  mutable bool stce_10469;
  mutable derivative_t tlms;
  stce_10468() : stce_10469(false) {
    for (int stce_9847 = 0; stce_9847 < vecsize; ++stce_9847)
      tlms[stce_9847] = 0;
  }
  void stce_10085(const stce_9985& stce_9753, const int stce_10470) {
    if (!stce_10469) {
      stce_10469 = true;
    }
    tlms[stce_10470] = stce_9753;
  }
  derivative_t& stce_9969() const {
    stce_1000002();
    ;
    stce_10469 = true;
    return tlms;
  }
  derivative_t& stce_9975() const { return stce_9969(); }
  void stce_9962(stce_9985& stce_9753, const int stce_10470) const {
    stce_1000002();
    ;
    if (stce_10469) {
      stce_9753 = tlms[stce_10470];
    } else {
      stce_9753 = 0;
    }
  }
  void clear() {
    for (int stce_9847 = 0; stce_9847 < vecsize; ++stce_9847) {
      tlms[stce_9847] = 0.0;
    }
  }
  template <class stce_9910> DCO_ALWAYS_INLINE void stce_9911(const stce_9910& stce_10142) {
    bool stce_10471 = this->stce_10472(stce_10142);
    if (stce_10471) {
      derivative_t stce_10473{};
      stce_10466(stce_10473, stce_10142, 1.0);
      tlms = stce_10473;
      stce_10469 = true;
    } else {
      stce_10469 = false;
    }
  }
  template <class stce_10126>
  static DCO_ALWAYS_INLINE void stce_10466(derivative_t& tlms,
                                           const dco::internal::active_type<stce_9769, stce_10126>& stce_9810,
                                           const stce_9985& pval) {
    if (stce_9810.stce_10469) {
      tlms += stce_9810.tlms * pval;
    }
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static DCO_ALWAYS_INLINE void
  stce_10466(derivative_t& tlms,
             const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810,
             const stce_9985& pval) {
    stce_10466(tlms, stce_9810.stce_10132, stce_9810.stce_10133() * pval);
    stce_10466(tlms, stce_9810.stce_10134, stce_9810.stce_10135() * pval);
  }
  template <class stce_10136, class stce_10130>
  static DCO_ALWAYS_INLINE void stce_10466(derivative_t& tlms,
                                           const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9810,
                                           const stce_9985& pval) {
    stce_10466(tlms, stce_9810.stce_10137, stce_9810.pval() * pval);
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static DCO_ALWAYS_INLINE void
  stce_10466(derivative_t& tlms,
             const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810,
             const stce_9985& pval) {
    stce_10466(tlms, stce_9810.stce_10132, stce_9810.stce_10133() * pval);
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static DCO_ALWAYS_INLINE void
  stce_10466(derivative_t& tlms,
             const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810,
             const stce_9985& pval) {
    stce_10466(tlms, stce_9810.stce_10134, stce_9810.stce_10135() * pval);
  }
  template <class stce_10126>
  static bool stce_10472(const dco::internal::active_type<stce_9769, stce_10126>& stce_9810) {
    return stce_9810.stce_10469;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static bool stce_10472(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    return stce_10472(stce_9810.stce_10132) || stce_10472(stce_9810.stce_10134);
  }
  template <class stce_10136, class stce_10130>
  static bool stce_10472(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9810) {
    return stce_10472(stce_9810.stce_10137);
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static bool stce_10472(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    return stce_10472(stce_9810.stce_10132);
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static bool stce_10472(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    return stce_10472(stce_9810.stce_10134);
  }
  typename mode_t::tape_t* tape() const { return NULL; }
  index_t _tape_index() const { return 0; }
};
} // namespace internal
} // namespace dco
namespace dco {
template <class stce_9780, size_t stce_10474 = 1, typename stce_10467 = stce_9780> class gt1v {
public:
  typedef gt1v mode_t;
  typedef dco::internal::stce_10468<gt1v> data_t;
  typedef stce_9780 value_t;
  typedef stce_9780 active_value_t;
  typedef value_t scalar_value_t;
  typedef dco::helper::valvec<stce_10467, stce_10474> derivative_t;
  typedef stce_10467 stce_9985;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::active_type<stce_9780, data_t> type;
  typedef type active_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = false;
  static const bool is_tangent_type = true;
  static const bool stce_10145 = true;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
  typedef stce_9807 tape_t;
  typedef void local_gradient_t;
  typedef void external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<void> jacobian_preaccumulator_t;
};
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_9790> class stce_10475 : public stce_10465<stce_9790>, public stce_10139<stce_9790> {
  using stce_10476 = stce_10465<stce_9790>;
  using stce_10477 = stce_10139<stce_9790>;

public:
  typedef stce_9790 mode_t;
  typedef stce_10087 stce_10141;
  typedef typename stce_9790::tape_t tape_t;
  typedef typename tape_t::stce_9762 derivative_t;

public:
  stce_10475() : stce_10476(), stce_10477() {}
  DCO_STRONG_INLINE stce_10475(const stce_10475& stce_10084) : stce_10476(stce_10084), stce_10477(stce_10084) {}
  DCO_STRONG_INLINE stce_10475& operator=(const stce_10475& stce_9810) {
    stce_10476::operator=(static_cast<const stce_10476&>(stce_9810));
    stce_10477::operator=(static_cast<const stce_10477&>(stce_9810));
    return *this;
  }
  inline void clear() {
    stce_10476::clear();
    stce_10477::clear();
  }
  inline index_t& _tape_index() const { return stce_10477::_tape_index(); }
  static typename stce_9790::tape_t* tape() { return stce_10477::tape(); }
  template <typename stce_10086>
  static DCO_STRONG_INLINE void register_variable(stce_10086& stce_9810, index_t index, tape_t* tape) {
    stce_10477::register_variable(stce_9810, index, tape);
  }
  template <class stce_9910> DCO_ALWAYS_INLINE void stce_9911(const stce_9910& stce_10142) {
    stce_10476::stce_9911(stce_10142);
    stce_10477::stce_9911(stce_10142);
  }
};
} // namespace internal
} // namespace dco
namespace dco {
template <typename stce_9780, typename stce_9759 = stce_9780, typename stce_9760 = stce_9759,
          memory_model::TYPE MEMORY_MODEL = DCO_TAPE_MEMORY_MODEL>
class gtas {
  typedef types_config_t<stce_9780, stce_9759, stce_9760> stce_10144;

public:
  static const memory_model::TYPE TAPE_MODEL = MEMORY_MODEL;
  typedef gtas mode_t;
  typedef dco::internal::stce_10475<gtas> data_t;
  typedef typename stce_10144::value_t value_t;
  typedef value_t scalar_value_t;
  typedef typename stce_10144::value_t active_value_t;
  typedef typename stce_10144::stce_9762 derivative_t;
  typedef derivative_t stce_9985;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::active_type<value_t, data_t> type;
  typedef type active_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = true;
  static const bool is_tangent_type = true;
  static const bool stce_10145 = false;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
  typedef internal::tape<TAPE_MODEL, stce_10144> tape_t;
  static DCOi_THREAD_LOCAL tape_t* global_tape;
  typedef typename internal::stce_10076<type> local_gradient_t;
  typedef dco::helper::stce_10013<tape_t> callback_object_t;
  typedef dco::helper::stce_10019<type, tape_t> userdata_object_t;
  typedef dco::helper::stce_10037<type, tape_t> external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<type> jacobian_preaccumulator_t;
};
template <class stce_9780, class stce_9759, class stce_9760, memory_model::TYPE MEMORY_MODEL>
DCOi_THREAD_LOCAL typename gtas<stce_9780, stce_9759, stce_9760, MEMORY_MODEL>::tape_t*
    gtas<stce_9780, stce_9759, stce_9760, MEMORY_MODEL>::global_tape = 0;
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_9780, typename stce_9791> struct smart_tape_ptr_t {
  static_assert(sizeof(stce_9780) == 0, "'dco::smart_tape_ptr_t' got instantiated with a non-adjoint type/mode.");
};
template <typename mode_t>
struct smart_tape_ptr_t<
    mode_t,
    typename std::enable_if<mode_t::is_adjoint_type &&
                            (std::is_base_of<typename mode_t::data_t, internal::stce_10139<mode_t>>::value ||
                             std::is_base_of<typename mode_t::data_t, internal::stce_10475<mode_t>>::value)>::type> {
  typename mode_t::tape_t*& stce_9988;
  smart_tape_ptr_t(tape_options stce_9944 = tape_options()) : stce_9988(mode_t::global_tape) {
    if (stce_9988) {
      throw dco::exception::create<std::runtime_error>("global_tape already allocated.");
    }
    stce_9988 = mode_t::tape_t::create(stce_9944);
  }
  ~smart_tape_ptr_t() {
    mode_t::tape_t::remove(stce_9988);
    stce_9988 = nullptr;
  }
  typename mode_t::tape_t*& data() { return stce_9988; }
  typename mode_t::tape_t* const& data() const { return stce_9988; }
  typename mode_t::tape_t* operator->() { return stce_9988; }
  typename mode_t::tape_t const* operator->() const { return stce_9988; }
  typename mode_t::tape_t& operator*() { return *stce_9988; }
  typename mode_t::tape_t const& operator*() const { return *stce_9988; }
  operator typename mode_t::tape_t *() { return stce_9988; }
  operator typename mode_t::tape_t const*() const { return stce_9988; }
};
template <typename mode_t>
struct smart_tape_ptr_t<
    mode_t,
    typename std::enable_if<mode_t::is_adjoint_type &&
                            std::is_base_of<typename mode_t::data_t, internal::stce_10146<mode_t>>::value>::type> {
  typename mode_t::tape_t* stce_9988;
  smart_tape_ptr_t(tape_options stce_9944 = tape_options()) { stce_9988 = mode_t::tape_t::create(stce_9944); }
  ~smart_tape_ptr_t() {
    mode_t::tape_t::remove(stce_9988);
    stce_9988 = nullptr;
  }
  typename mode_t::tape_t*& data() { return stce_9988; }
  typename mode_t::tape_t* const& data() const { return stce_9988; }
  typename mode_t::tape_t* operator->() { return stce_9988; }
  typename mode_t::tape_t const* operator->() const { return stce_9988; }
  typename mode_t::tape_t& operator*() { return *stce_9988; }
  typename mode_t::tape_t const& operator*() const { return *stce_9988; }
};
template <typename stce_9780, typename stce_10363>
struct smart_tape_ptr_t<internal::active_type<stce_9780, stce_10363>>
    : public smart_tape_ptr_t<typename stce_10363::mode_t> {};
} // namespace internal
template <typename stce_9790> using smart_tape_ptr_t = internal::smart_tape_ptr_t<stce_9790>;
} // namespace dco

namespace dco {
template <size_t stce_10478> struct subrange_t {
  static const size_t stce_10479 = stce_10478;
  subrange_t(size_t stce_10032) : stce_10031(stce_10032) {}
  size_t stce_10031;
};
template <size_t stce_10478> struct range_t {
  subrange_t<stce_10478> const& stce_10480;
  size_t global_index, stce_10186;
  range_t(subrange_t<stce_10478> const& stce_10389) : stce_10480(stce_10389), global_index(0), stce_10186(0) {}
  range_t& operator++() {
    global_index += stce_10480.stce_10479;
    ++stce_10186;
    return *this;
  }
  bool operator!=(range_t const& stce_10004) const {
    if (stce_10004.stce_10186 != stce_10186)
      return true;
    return false;
  }
  range_t& operator*() { return *this; }
  range_t const& operator*() const { return *this; }
  void stce_10216() {
    global_index = stce_10480.stce_10031;
    stce_10186 = static_cast<size_t>(std::ceil(static_cast<double>(stce_10480.stce_10031) / stce_10478));
  }
  bool is_last() const { return global_index + stce_10478 >= stce_10480.stce_10031; }
};
template <size_t stce_10478> struct inner_range_t {
  range_t<stce_10478> const& stce_10481;
  size_t global_index, sub_index;
  inner_range_t(range_t<stce_10478> const& stce_9852)
      : stce_10481(stce_9852), global_index(stce_9852.global_index), sub_index(0) {}
  inner_range_t& operator++() {
    ++sub_index;
    ++global_index;
    return *this;
  }
  void stce_10216() {
    if ((stce_10481.stce_10186 + 1) * stce_10481.stce_10480.stce_10479 > stce_10481.stce_10480.stce_10031) {
      sub_index = stce_10481.stce_10480.stce_10031 % stce_10481.stce_10480.stce_10479;
    } else {
      sub_index = stce_10481.stce_10480.stce_10479;
    }
  }
  bool operator!=(inner_range_t const& stce_10004) const {
    if (stce_10004.sub_index != sub_index)
      return true;
    return false;
  }
  inner_range_t& operator*() { return *this; }
  inner_range_t const& operator*() const { return *this; }
};
template <size_t stce_10478> static inner_range_t<stce_10478> begin(range_t<stce_10478> const& stce_9852) {
  return inner_range_t<stce_10478>(stce_9852);
}
template <size_t stce_10478> static range_t<stce_10478> begin(subrange_t<stce_10478> const& stce_10389) {
  return range_t<stce_10478>(stce_10389);
}
template <size_t stce_10478> static inner_range_t<stce_10478> end(range_t<stce_10478> const& stce_9852) {
  inner_range_t<stce_10478> stce_10482(stce_9852);
  stce_10482.stce_10216();
  return stce_10482;
}
template <size_t stce_10478> static range_t<stce_10478> end(subrange_t<stce_10478> const& stce_10389) {
  range_t<stce_10478> stce_10482(stce_10389);
  stce_10482.stce_10216();
  return stce_10482;
}
template <size_t stce_10478> static subrange_t<stce_10478> subranges(size_t stce_10032) {
  return subrange_t<stce_10478>(stce_10032);
}
} // namespace dco
namespace dco {
namespace stce_10483 {
template <class stce_9769> struct stce_10484 {
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10485& stce_10162, const stce_10156& stce_10163) {
    return static_cast<stce_9769>(stce_10162 + stce_10163);
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10164(const stce_9769& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0));
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10165(const stce_9769& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0));
  }
};
template <class stce_9769> struct stce_10486 {
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10485& stce_10162, const stce_10156& stce_10163) {
    return static_cast<stce_9769>(stce_10162 - stce_10163);
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10164(const stce_9769& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0));
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10165(const stce_9769& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(static_cast<stce_9769>(-1.0));
  }
};
template <class stce_9769> struct stce_10487 {
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10485& stce_10162, const stce_10156& stce_10163) {
    return static_cast<stce_9769>(stce_10162 * stce_10163);
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10164(const stce_9769& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(stce_10163);
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10165(const stce_9769& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(stce_10162);
  }
};
template <class stce_9769> struct stce_10488 {
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10485& stce_10162, const stce_10156& stce_10163) {
    return static_cast<stce_9769>(stce_10162 / stce_10163);
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10164(const stce_9769& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0) / stce_10163);
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10165(const stce_9769& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(-_value / stce_10163);
  }
};
template <class stce_9769> struct stce_10489 {
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10485& stce_10162, const stce_10156& stce_10163) {
    return stce_10162 + stce_10163;
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10164(const stce_9769& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0));
  }
};
template <class stce_9769> struct stce_10490 {
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10485& stce_10162, const stce_10156& stce_10163) {
    return stce_10162 + stce_10163;
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10165(const stce_9769& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0));
  }
};
template <class stce_9769> struct stce_10491 {
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10485& stce_10162, const stce_10156& stce_10163) {
    return stce_10162 - stce_10163;
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10164(const stce_9769& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0));
  }
};
template <class stce_9769> struct stce_10492 {
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10485& stce_10162, const stce_10156& stce_10163) {
    return stce_10162 - stce_10163;
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10165(const stce_9769& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(static_cast<stce_9769>(-1.0));
  }
};
template <class stce_9769> struct stce_10493 {
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10485& stce_10162, const stce_10156& stce_10163) {
    return stce_10162 * stce_10163;
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10164(const stce_9769& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(stce_10163);
  }
};
template <class stce_9769> struct stce_10494 {
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10485& stce_10162, const stce_10156& stce_10163) {
    return stce_10162 * stce_10163;
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10165(const stce_9769& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(stce_10162);
  }
};
template <class stce_9769> struct stce_10495 {
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10485& stce_10162, const stce_10156& stce_10163) {
    return stce_10162 / stce_10163;
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10164(const stce_9769& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0) / stce_10163);
  }
};
template <class stce_9769> struct stce_10496 {
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10485& stce_10162, const stce_10156& stce_10163) {
    return stce_10162 / stce_10163;
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10165(const stce_9769& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(-(stce_10162 / stce_10163) / stce_10163);
  }
};
template <class stce_9769> struct stce_10497 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::sin;
    return sin(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9810) {
    using std::cos;
    (void)_value;
    return static_cast<stce_9769>(cos(stce_9810));
  }
};
template <class stce_9769> struct stce_10498 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::cos;
    return cos(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9810) {
    using std::sin;
    (void)_value;
    return static_cast<stce_9769>(-sin(stce_9810));
  }
};
template <class stce_9769> struct stce_10499 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::tan;
    return tan(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9810) {
    using std::tan;
    (void)_value;
    return static_cast<stce_9769>((static_cast<stce_9769>(1.0) + (tan(stce_9810) * tan(stce_9810))));
  }
};
template <class stce_9769> struct stce_10500 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::cosh;
    return cosh(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9810) {
    using std::sinh;
    (void)_value;
    return static_cast<stce_9769>(sinh(stce_9810));
  }
};
template <class stce_9769> struct stce_10501 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::sinh;
    return sinh(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9810) {
    using std::cosh;
    (void)_value;
    return static_cast<stce_9769>(cosh(stce_9810));
  }
};
template <class stce_9769> struct stce_10502 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::tanh;
    return tanh(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9810) {
    using std::tanh;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0) - tanh(stce_9810) * tanh(stce_9810));
  }
};
template <class stce_9769> struct stce_10503 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::asin;
    return asin(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9810) {
    using std::sqrt;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0) /
                                  sqrt(static_cast<stce_9769>(1.0) - stce_9810 * stce_9810));
  }
};
template <class stce_9769> struct stce_10504 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::acos;
    return acos(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9810) {
    using std::sqrt;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(-1.0) /
                                  sqrt(static_cast<stce_9769>(1.0) - stce_9810 * stce_9810));
  }
};
template <class stce_9769> struct stce_10505 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::atan;
    return atan(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9810) {
    using std::atan;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0) / (static_cast<stce_9769>(1.0) + stce_9810 * stce_9810));
  }
};
template <class stce_9769> struct stce_10506 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::exp;
    return exp(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9810) {
    using std::exp;
    (void)_value;
    return static_cast<stce_9769>(exp(stce_9810));
  }
};
template <class stce_9769> struct stce_10507 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::sqrt;
    return sqrt(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9810) {
    using std::sqrt;
    (void)_value;
    return static_cast<stce_9769>(
        static_cast<stce_9769>(1.0) /
        (static_cast<stce_9769>(2.0) *
         sqrt(stce_9810 + ((HAS_SQRT_AVOID_DIVZERO && stce_9810 == static_cast<stce_9769>(0.0))
                               ? static_cast<stce_9769>(DCO_SQRT_EPS)
                               : static_cast<stce_9769>(0.0)))));
  }
};
template <class stce_9769> struct stce_10508 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::log;
    return log(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9810) {
    using std::log;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0) / stce_9810);
  }
};
template <class stce_9769> struct stce_10509 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using ::erf;
    return erf(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9810) {
    using ::exp;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(2.0) /
                                  sqrt(static_cast<stce_9769>(3.14159265358979323846264338327950288)) *
                                  exp(-stce_9810 * stce_9810));
  }
};
template <class stce_9769> struct stce_10510 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using ::erfc;
    return erfc(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9810) {
    using ::exp;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(-2.0) /
                                  sqrt(static_cast<stce_9769>(3.14159265358979323846264338327950288)) *
                                  exp(-stce_9810 * stce_9810));
  }
};
template <class stce_9769> struct stce_10511 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using ::asinh;
    return asinh(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9810) {
    using ::sqrt;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.) /
                                  sqrt(static_cast<stce_9769>(1.) + (stce_9810 * stce_9810)));
  }
};
template <class stce_9769> struct stce_10512 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using ::acosh;
    return acosh(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9810) {
    using ::sqrt;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.) /
                                  sqrt((stce_9810 * stce_9810) - static_cast<stce_9769>(1.)));
  }
};
template <class stce_9769> struct stce_10513 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using ::atanh;
    return atanh(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9810) {
    using ::atanh;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.) / (static_cast<stce_9769>(1.) - (stce_9810 * stce_9810)));
  }
};
template <class stce_9769> struct stce_10514 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using ::expm1;
    return expm1(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9810) {
    using ::exp;
    (void)_value;
    return static_cast<stce_9769>(exp(stce_9810));
  }
};
template <class stce_9769> struct stce_10515 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using ::log1p;
    return log1p(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9810) {
    using ::log1p;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0) / (stce_9810 + static_cast<stce_9769>(1.0)));
  }
};
template <class stce_9769> struct stce_10516 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using ::log10;
    return log10(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9810) {
    using ::log10;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0) / (stce_9810 * static_cast<stce_9769>(log(10))));
  }
};
template <class stce_9769> struct stce_10517 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& stce_10162) {
    return -stce_10162;
  }
  template <class stce_9780> static inline const stce_9769 stce_10161(const stce_9769&, const stce_9780&) {
    return static_cast<stce_9769>(-1.0);
  }
};
template <class stce_9769> struct stce_10518 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& stce_10162) {
    return stce_10162;
  }
  template <class stce_9780> static inline const stce_9769 stce_10161(const stce_9769&, const stce_9780&) {
    return static_cast<stce_9769>(1.0);
  }
};
using ::fabs;
template <class stce_9769> struct stce_10519 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& stce_10162) {
    return fabs(stce_10162);
  }
  template <class stce_9780> static inline const stce_9769 stce_10161(const stce_9769&, const stce_9780& stce_10162) {
    if (stce_10162 < 0)
      return static_cast<stce_9769>(-1.0);
    else
      return static_cast<stce_9769>(1.0);
  }
};
using std::abs;
template <class stce_9769> struct stce_10520 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& stce_10162) {
    return abs(stce_10162);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_10162) {
    (void)_value;
    if (stce_10162 < 0)
      return static_cast<stce_9769>(-1.0);
    else
      return static_cast<stce_9769>(1.0);
  }
};
using std::atan2;
template <class stce_9769> struct stce_10521 {
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10485& stce_10162, const stce_10156& stce_10163) {
    (void)stce_10162;
    (void)stce_10163;
    return atan2(stce_10162, stce_10163);
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10164(stce_9769 const& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return stce_10163 / (stce_10163 * stce_10163 + stce_10162 * stce_10162);
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10165(stce_9769 const& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return -stce_10162 / (stce_10163 * stce_10163 + stce_10162 * stce_10162);
  }
};
template <class stce_9769> struct stce_10522 {
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10485& stce_10162, const stce_10156& stce_10163) {
    (void)stce_10162;
    (void)stce_10163;
    return atan2(stce_10162, stce_10163);
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10164(stce_9769 const& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return stce_10163 / (stce_10163 * stce_10163 + stce_10162 * stce_10162);
  }
};
template <class stce_9769> struct stce_10523 {
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10485& stce_10162, const stce_10156& stce_10163) {
    (void)stce_10162;
    (void)stce_10163;
    return atan2(stce_10162, stce_10163);
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10165(stce_9769 const& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return -stce_10162 / (stce_10163 * stce_10163 + stce_10162 * stce_10162);
  }
};
template <class stce_9769> struct stce_10524 {
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10485& stce_10162, const stce_10156& stce_10163) {
    using std::pow;
    return pow(stce_10162, stce_10163);
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10164(stce_9769 const& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    using std::pow;
    (void)_value;
    return stce_10163 * pow(stce_10162, stce_10163 - static_cast<stce_9769>(1.0));
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10165(stce_9769 const& _value, const stce_10485& stce_10162, const stce_10156&) {
    using std::log;
    using std::pow;
    return log(stce_10162) * _value;
  }
};
template <class stce_9769> struct stce_10525 {
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10485& stce_10162, const stce_10156& stce_10163) {
    using std::pow;
    return pow(stce_10162, stce_10163);
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10164(stce_9769 const& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    using std::pow;
    (void)_value;
    return stce_10163 * pow(stce_10162, stce_10163 - static_cast<stce_10156>(1.0));
  }
};
template <class stce_9769> struct stce_10526 {
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10485& stce_10162, const stce_10156& stce_10163) {
    using std::pow;
    return pow(stce_10162, stce_10163);
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10165(stce_9769 const& _value, const stce_10485& stce_10162, const stce_10156&) {
    using std::log;
    using std::pow;
    return log(stce_10162) * _value;
  }
};
template <typename stce_9808, size_t stce_9809, typename stce_10527> struct stce_10528 {
  template <class stce_9780>
  static inline const vector_ns::vector_t<stce_9808, stce_9809>
  stce_10161(const vector_ns::vector_t<stce_9808, stce_9809>& _value, const stce_9780& stce_9810) {
    vector_ns::vector_t<stce_9808, stce_9809> stce_9849;
    for (size_t stce_9847 = 0; stce_9847 < stce_9809; ++stce_9847) {
      stce_9849[stce_9847] = stce_10527::stce_10161(_value[stce_9847], stce_9810[stce_9847]);
    }
    return stce_9849;
  }
};
template <typename stce_9808, size_t stce_9809>
struct stce_10520<vector_ns::vector_t<stce_9808, stce_9809>>
    : public stce_10528<stce_9808, stce_9809, stce_10520<stce_9808>> {
  template <class stce_9780>
  static inline const vector_ns::vector_t<stce_9808, stce_9809> stce_10160(const stce_9780& stce_10162) {
    return abs(stce_10162);
  }
};
template <typename stce_9808, size_t stce_9809>
struct stce_10519<vector_ns::vector_t<stce_9808, stce_9809>>
    : public stce_10528<stce_9808, stce_9809, stce_10519<stce_9808>> {
  template <class stce_9780>
  static inline const vector_ns::vector_t<stce_9808, stce_9809> stce_10160(const stce_9780& stce_10162) {
    return fabs(stce_10162);
  }
};
template <typename stce_9808, size_t stce_9809>
struct stce_10507<vector_ns::vector_t<stce_9808, stce_9809>>
    : public stce_10528<stce_9808, stce_9809, stce_10507<stce_9808>> {
  template <class stce_9780>
  static inline const vector_ns::vector_t<stce_9808, stce_9809> stce_10160(const stce_9780& arg) {
    return sqrt(arg);
  }
};
using ::hypot;
template <class stce_9769> struct stce_10529 {
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10485& stce_10162, const stce_10156& stce_10163) {
    (void)stce_10162;
    (void)stce_10163;
    return hypot(stce_10162, stce_10163);
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10164(stce_9769 const& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return stce_10162 / _value;
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10165(stce_9769 const& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return stce_10163 / _value;
  }
};
template <class stce_9769> struct stce_10530 {
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10485& stce_10162, const stce_10156& stce_10163) {
    (void)stce_10162;
    (void)stce_10163;
    return hypot(stce_10162, stce_10163);
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10164(stce_9769 const& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return stce_10162 / _value;
  }
};
template <class stce_9769> struct stce_10531 {
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10485& stce_10162, const stce_10156& stce_10163) {
    (void)stce_10162;
    (void)stce_10163;
    return hypot(stce_10162, stce_10163);
  }
  template <class stce_10485, class stce_10156>
  static inline const stce_9769 stce_10165(stce_9769 const& _value, const stce_10485& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return stce_10163 / _value;
  }
};
} // namespace stce_10483
} // namespace dco
namespace dco {
namespace internal {
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10517<stce_9769>>
operator-(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10517<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10517<stce_9769>>
operator-(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10517<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10517<stce_9769>>
operator-(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10517<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10517<stce_9769>>
operator-(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10517<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10517<stce_9769>>
operator-(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10517<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10518<stce_9769>>
operator+(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10518<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10518<stce_9769>>
operator+(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10518<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10518<stce_9769>>
operator+(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10518<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10518<stce_9769>>
operator+(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10518<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10518<stce_9769>>
operator+(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10518<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10497<stce_9769>>
sin(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10497<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10497<stce_9769>>
sin(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10497<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10497<stce_9769>>
sin(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10497<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10497<stce_9769>>
sin(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10497<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10497<stce_9769>>
sin(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10497<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10498<stce_9769>>
cos(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10498<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10498<stce_9769>>
cos(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10498<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10498<stce_9769>>
cos(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10498<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10498<stce_9769>>
cos(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10498<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10498<stce_9769>>
cos(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10498<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10499<stce_9769>>
tan(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10499<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10499<stce_9769>>
tan(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10499<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10499<stce_9769>>
tan(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10499<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10499<stce_9769>>
tan(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10499<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10499<stce_9769>>
tan(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10499<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10500<stce_9769>>
cosh(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10500<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10500<stce_9769>>
cosh(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10500<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10500<stce_9769>>
cosh(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10500<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10500<stce_9769>>
cosh(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10500<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10500<stce_9769>>
cosh(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10500<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10501<stce_9769>>
sinh(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10501<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10501<stce_9769>>
sinh(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10501<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10501<stce_9769>>
sinh(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10501<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10501<stce_9769>>
sinh(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10501<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10501<stce_9769>>
sinh(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10501<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10503<stce_9769>>
asin(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10503<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10503<stce_9769>>
asin(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10503<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10503<stce_9769>>
asin(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10503<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10503<stce_9769>>
asin(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10503<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10503<stce_9769>>
asin(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10503<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10504<stce_9769>>
acos(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10504<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10504<stce_9769>>
acos(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10504<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10504<stce_9769>>
acos(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10504<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10504<stce_9769>>
acos(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10504<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10504<stce_9769>>
acos(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10504<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10506<stce_9769>>
exp(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10506<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10506<stce_9769>>
exp(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10506<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10506<stce_9769>>
exp(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10506<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10506<stce_9769>>
exp(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10506<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10506<stce_9769>>
exp(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10506<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10505<stce_9769>>
atan(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10505<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10505<stce_9769>>
atan(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10505<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10505<stce_9769>>
atan(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10505<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10505<stce_9769>>
atan(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10505<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10505<stce_9769>>
atan(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10505<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10502<stce_9769>>
tanh(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10502<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10502<stce_9769>>
tanh(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10502<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10502<stce_9769>>
tanh(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10502<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10502<stce_9769>>
tanh(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10502<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10502<stce_9769>>
tanh(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10502<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10507<stce_9769>>
sqrt(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10507<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10507<stce_9769>>
sqrt(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10507<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10507<stce_9769>>
sqrt(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10507<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10507<stce_9769>>
sqrt(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10507<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10507<stce_9769>>
sqrt(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10507<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10508<stce_9769>>
log(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10508<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10508<stce_9769>>
log(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10508<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10508<stce_9769>>
log(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10508<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10508<stce_9769>>
log(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10508<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10508<stce_9769>>
log(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10508<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10509<stce_9769>>
erf(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10509<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10509<stce_9769>>
erf(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10509<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10509<stce_9769>>
erf(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10509<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10509<stce_9769>>
erf(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10509<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10509<stce_9769>>
erf(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10509<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10510<stce_9769>>
erfc(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10510<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10510<stce_9769>>
erfc(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10510<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10510<stce_9769>>
erfc(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10510<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10510<stce_9769>>
erfc(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10510<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10510<stce_9769>>
erfc(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10510<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10514<stce_9769>>
expm1(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10514<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10514<stce_9769>>
expm1(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10514<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10514<stce_9769>>
expm1(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10514<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10514<stce_9769>>
expm1(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10514<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10514<stce_9769>>
expm1(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10514<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10511<stce_9769>>
asinh(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10511<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10511<stce_9769>>
asinh(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10511<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10511<stce_9769>>
asinh(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10511<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10511<stce_9769>>
asinh(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10511<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10511<stce_9769>>
asinh(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10511<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10512<stce_9769>>
acosh(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10512<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10512<stce_9769>>
acosh(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10512<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10512<stce_9769>>
acosh(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10512<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10512<stce_9769>>
acosh(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10512<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10512<stce_9769>>
acosh(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10512<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10513<stce_9769>>
atanh(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10513<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10513<stce_9769>>
atanh(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10513<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10513<stce_9769>>
atanh(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10513<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10513<stce_9769>>
atanh(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10513<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10513<stce_9769>>
atanh(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10513<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10515<stce_9769>>
log1p(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10515<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10515<stce_9769>>
log1p(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10515<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10515<stce_9769>>
log1p(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10515<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10515<stce_9769>>
log1p(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10515<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10515<stce_9769>>
log1p(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10515<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10516<stce_9769>>
log10(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10516<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10516<stce_9769>>
log10(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10516<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10516<stce_9769>>
log10(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10516<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10516<stce_9769>>
log10(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10516<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10516<stce_9769>>
log10(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10516<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10519<stce_9769>>
fabs(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10519<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10519<stce_9769>>
fabs(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10519<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10519<stce_9769>>
fabs(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10519<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10519<stce_9769>>
fabs(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10519<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10519<stce_9769>>
fabs(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10519<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::stce_10483::stce_10520<stce_9769>>
abs(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10520<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10520<stce_9769>>
abs(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10520<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10520<stce_9769>>
abs(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10520<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::stce_10483::stce_10520<stce_9769>>
abs(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10483::stce_10520<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10520<stce_9769>>
abs(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10483::stce_10520<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10484<stce_9769>>
operator+(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10484<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                         dco::stce_10483::stce_10489<stce_9769>>
operator+(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::stce_10483::stce_10489<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                             typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
                             dco::stce_10483::stce_10489<stce_9769>>>::type
operator+(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
                                  dco::stce_10483::stce_10489<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9779<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                         dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10490<stce_9769>>
operator+(const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10490<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769, typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
        dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10490<stce_9769>>>::type
operator+(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
      dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10490<stce_9769>>(stce_10091,
                                                                                                 stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10489<stce_9769>>
operator+(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                                  dco::stce_10483::stce_10489<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                             typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
                             dco::stce_10483::stce_10489<stce_9769>>>::type
operator+(
    const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
    const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
      typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::stce_10483::stce_10489<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9779<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                         dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10490<stce_9769>>
operator+(const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10483::stce_10490<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769, typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
        dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10483::stce_10490<stce_9769>>>::type
operator+(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10483::stce_10490<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10489<stce_9769>>
operator+(
    const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10483::stce_10489<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<
        stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::stce_10483::stce_10489<stce_9769>>>::type
operator+(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10483::stce_10489<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9779<
    stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
    dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10490<stce_9769>>
operator+(
    const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10490<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
        dco::stce_10483::stce_10490<stce_9769>>>::type
operator+(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10490<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10489<stce_9769>>
operator+(
    const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10483::stce_10489<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<
        stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::stce_10483::stce_10489<stce_9769>>>::type
operator+(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10483::stce_10489<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9779<
    stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
    dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10490<stce_9769>>
operator+(
    const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10490<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
        dco::stce_10483::stce_10490<stce_9769>>>::type
operator+(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10490<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10489<stce_9769>>
operator+(
    const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10483::stce_10489<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<
        stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::stce_10483::stce_10489<stce_9769>>>::type
operator+(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10483::stce_10489<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9779<
    stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
    dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10490<stce_9769>>
operator+(
    const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10490<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
        dco::stce_10483::stce_10490<stce_9769>>>::type
operator+(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10490<stce_9769>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
typename enable_if<
    (dco::mode<stce_9879>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9879>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9879>::active_value_t, typename dco::mode<stce_9879>::active_t,
                             stce_9879,
                             dco::stce_10483::stce_10484<typename dco::mode<stce_9879>::active_value_t>>>::type
operator+(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9879>::active_value_t,
                                  typename dco::mode<stce_9879>::active_t, stce_9879,
                                  dco::stce_10483::stce_10484<typename dco::mode<stce_9879>::active_value_t>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9879>::value ||
      (dco::mode<stce_9879>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9879::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9879>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                             typename dco::mode<stce_9780>::active_t,
                             dco::stce_10483::stce_10484<typename dco::mode<stce_9780>::active_value_t>>>::type
operator+(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                                  typename dco::mode<stce_9780>::active_t,
                                  dco::stce_10483::stce_10484<typename dco::mode<stce_9780>::active_value_t>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10486<stce_9769>>
operator-(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10486<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                         dco::stce_10483::stce_10491<stce_9769>>
operator-(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::stce_10483::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                             typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
                             dco::stce_10483::stce_10491<stce_9769>>>::type
operator-(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
                                  dco::stce_10483::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9779<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                         dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10492<stce_9769>>
operator-(const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10492<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769, typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
        dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10492<stce_9769>>>::type
operator-(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
      dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10492<stce_9769>>(stce_10091,
                                                                                                 stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10491<stce_9769>>
operator-(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                                  dco::stce_10483::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                             typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
                             dco::stce_10483::stce_10491<stce_9769>>>::type
operator-(
    const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
    const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
      typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::stce_10483::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9779<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                         dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10492<stce_9769>>
operator-(const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10483::stce_10492<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769, typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
        dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10483::stce_10492<stce_9769>>>::type
operator-(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10483::stce_10492<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10491<stce_9769>>
operator-(
    const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10483::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<
        stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::stce_10483::stce_10491<stce_9769>>>::type
operator-(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10483::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9779<
    stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
    dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10492<stce_9769>>
operator-(
    const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10492<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
        dco::stce_10483::stce_10492<stce_9769>>>::type
operator-(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10492<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10491<stce_9769>>
operator-(
    const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10483::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<
        stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::stce_10483::stce_10491<stce_9769>>>::type
operator-(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10483::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9779<
    stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
    dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10492<stce_9769>>
operator-(
    const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10492<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
        dco::stce_10483::stce_10492<stce_9769>>>::type
operator-(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10492<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10491<stce_9769>>
operator-(
    const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10483::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<
        stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::stce_10483::stce_10491<stce_9769>>>::type
operator-(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10483::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9779<
    stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
    dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10492<stce_9769>>
operator-(
    const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10492<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
        dco::stce_10483::stce_10492<stce_9769>>>::type
operator-(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10492<stce_9769>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
typename enable_if<
    (dco::mode<stce_9879>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9879>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9879>::active_value_t, typename dco::mode<stce_9879>::active_t,
                             stce_9879,
                             dco::stce_10483::stce_10486<typename dco::mode<stce_9879>::active_value_t>>>::type
operator-(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9879>::active_value_t,
                                  typename dco::mode<stce_9879>::active_t, stce_9879,
                                  dco::stce_10483::stce_10486<typename dco::mode<stce_9879>::active_value_t>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9879>::value ||
      (dco::mode<stce_9879>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9879::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9879>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                             typename dco::mode<stce_9780>::active_t,
                             dco::stce_10483::stce_10486<typename dco::mode<stce_9780>::active_value_t>>>::type
operator-(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                                  typename dco::mode<stce_9780>::active_t,
                                  dco::stce_10483::stce_10486<typename dco::mode<stce_9780>::active_value_t>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10487<stce_9769>>
operator*(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10487<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                         dco::stce_10483::stce_10493<stce_9769>>
operator*(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::stce_10483::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                             typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
                             dco::stce_10483::stce_10493<stce_9769>>>::type
operator*(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
                                  dco::stce_10483::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9779<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                         dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10494<stce_9769>>
operator*(const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769, typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
        dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10494<stce_9769>>>::type
operator*(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
      dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10494<stce_9769>>(stce_10091,
                                                                                                 stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10493<stce_9769>>
operator*(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                                  dco::stce_10483::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                             typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
                             dco::stce_10483::stce_10493<stce_9769>>>::type
operator*(
    const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
    const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
      typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::stce_10483::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9779<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                         dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10494<stce_9769>>
operator*(const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10483::stce_10494<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769, typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
        dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10483::stce_10494<stce_9769>>>::type
operator*(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10483::stce_10494<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10493<stce_9769>>
operator*(
    const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10483::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<
        stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::stce_10483::stce_10493<stce_9769>>>::type
operator*(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10483::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9779<
    stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
    dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10494<stce_9769>>
operator*(
    const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10494<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
        dco::stce_10483::stce_10494<stce_9769>>>::type
operator*(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10494<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10493<stce_9769>>
operator*(
    const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10483::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<
        stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::stce_10483::stce_10493<stce_9769>>>::type
operator*(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10483::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9779<
    stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
    dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10494<stce_9769>>
operator*(
    const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10494<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
        dco::stce_10483::stce_10494<stce_9769>>>::type
operator*(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10494<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10493<stce_9769>>
operator*(
    const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10483::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<
        stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::stce_10483::stce_10493<stce_9769>>>::type
operator*(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10483::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9779<
    stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
    dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10494<stce_9769>>
operator*(
    const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10494<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
        dco::stce_10483::stce_10494<stce_9769>>>::type
operator*(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10494<stce_9769>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
typename enable_if<
    (dco::mode<stce_9879>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9879>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9879>::active_value_t, typename dco::mode<stce_9879>::active_t,
                             stce_9879,
                             dco::stce_10483::stce_10487<typename dco::mode<stce_9879>::active_value_t>>>::type
operator*(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9879>::active_value_t,
                                  typename dco::mode<stce_9879>::active_t, stce_9879,
                                  dco::stce_10483::stce_10487<typename dco::mode<stce_9879>::active_value_t>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9879>::value ||
      (dco::mode<stce_9879>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9879::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9879>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                             typename dco::mode<stce_9780>::active_t,
                             dco::stce_10483::stce_10487<typename dco::mode<stce_9780>::active_value_t>>>::type
operator*(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                                  typename dco::mode<stce_9780>::active_t,
                                  dco::stce_10483::stce_10487<typename dco::mode<stce_9780>::active_value_t>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10488<stce_9769>>
operator/(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10488<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                         dco::stce_10483::stce_10495<stce_9769>>
operator/(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::stce_10483::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                             typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
                             dco::stce_10483::stce_10495<stce_9769>>>::type
operator/(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
                                  dco::stce_10483::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9779<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                         dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10496<stce_9769>>
operator/(const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10496<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769, typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
        dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10496<stce_9769>>>::type
operator/(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
      dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10496<stce_9769>>(stce_10091,
                                                                                                 stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10495<stce_9769>>
operator/(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                                  dco::stce_10483::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                             typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
                             dco::stce_10483::stce_10495<stce_9769>>>::type
operator/(
    const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
    const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
      typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::stce_10483::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9779<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                         dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10496<stce_9769>>
operator/(const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10483::stce_10496<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769, typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
        dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10483::stce_10496<stce_9769>>>::type
operator/(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10483::stce_10496<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10495<stce_9769>>
operator/(
    const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10483::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<
        stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::stce_10483::stce_10495<stce_9769>>>::type
operator/(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10483::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9779<
    stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
    dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10496<stce_9769>>
operator/(
    const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10496<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
        dco::stce_10483::stce_10496<stce_9769>>>::type
operator/(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10496<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10495<stce_9769>>
operator/(
    const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10483::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<
        stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::stce_10483::stce_10495<stce_9769>>>::type
operator/(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10483::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9779<
    stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
    dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10496<stce_9769>>
operator/(
    const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10496<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
        dco::stce_10483::stce_10496<stce_9769>>>::type
operator/(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10496<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10495<stce_9769>>
operator/(
    const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10483::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<
        stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::stce_10483::stce_10495<stce_9769>>>::type
operator/(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10483::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9779<
    stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
    dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10496<stce_9769>>
operator/(
    const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10496<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
        dco::stce_10483::stce_10496<stce_9769>>>::type
operator/(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10496<stce_9769>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
typename enable_if<
    (dco::mode<stce_9879>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9879>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9879>::active_value_t, typename dco::mode<stce_9879>::active_t,
                             stce_9879,
                             dco::stce_10483::stce_10488<typename dco::mode<stce_9879>::active_value_t>>>::type
operator/(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9879>::active_value_t,
                                  typename dco::mode<stce_9879>::active_t, stce_9879,
                                  dco::stce_10483::stce_10488<typename dco::mode<stce_9879>::active_value_t>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9879>::value ||
      (dco::mode<stce_9879>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9879::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9879>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                             typename dco::mode<stce_9780>::active_t,
                             dco::stce_10483::stce_10488<typename dco::mode<stce_9780>::active_value_t>>>::type
operator/(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                                  typename dco::mode<stce_9780>::active_t,
                                  dco::stce_10483::stce_10488<typename dco::mode<stce_9780>::active_value_t>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10521<stce_9769>>
atan2(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10521<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                         dco::stce_10483::stce_10522<stce_9769>>
atan2(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::stce_10483::stce_10522<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                             typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
                             dco::stce_10483::stce_10522<stce_9769>>>::type
atan2(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
                                  dco::stce_10483::stce_10522<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9779<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                         dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10523<stce_9769>>
atan2(const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10523<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769, typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
        dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10523<stce_9769>>>::type
atan2(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
      dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10523<stce_9769>>(stce_10091,
                                                                                                 stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10522<stce_9769>>
atan2(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                                  dco::stce_10483::stce_10522<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                             typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
                             dco::stce_10483::stce_10522<stce_9769>>>::type
atan2(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
      typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::stce_10483::stce_10522<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9779<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                         dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10523<stce_9769>>
atan2(const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10483::stce_10523<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769, typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
        dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10483::stce_10523<stce_9769>>>::type
atan2(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10483::stce_10523<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10522<stce_9769>>
atan2(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10483::stce_10522<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<
        stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::stce_10483::stce_10522<stce_9769>>>::type
atan2(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10483::stce_10522<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9779<
    stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
    dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10523<stce_9769>>
atan2(const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10523<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
        dco::stce_10483::stce_10523<stce_9769>>>::type
atan2(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10523<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10522<stce_9769>>
atan2(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10483::stce_10522<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<
        stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::stce_10483::stce_10522<stce_9769>>>::type
atan2(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10483::stce_10522<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9779<
    stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
    dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10523<stce_9769>>
atan2(const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10523<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
        dco::stce_10483::stce_10523<stce_9769>>>::type
atan2(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10523<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10522<stce_9769>>
atan2(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10483::stce_10522<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<
        stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::stce_10483::stce_10522<stce_9769>>>::type
atan2(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10483::stce_10522<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9779<
    stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
    dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10523<stce_9769>>
atan2(const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10523<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
        dco::stce_10483::stce_10523<stce_9769>>>::type
atan2(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10523<stce_9769>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
typename enable_if<
    (dco::mode<stce_9879>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9879>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9879>::active_value_t, typename dco::mode<stce_9879>::active_t,
                             stce_9879,
                             dco::stce_10483::stce_10521<typename dco::mode<stce_9879>::active_value_t>>>::type
atan2(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9879>::active_value_t,
                                  typename dco::mode<stce_9879>::active_t, stce_9879,
                                  dco::stce_10483::stce_10521<typename dco::mode<stce_9879>::active_value_t>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9879>::value ||
      (dco::mode<stce_9879>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9879::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9879>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                             typename dco::mode<stce_9780>::active_t,
                             dco::stce_10483::stce_10521<typename dco::mode<stce_9780>::active_value_t>>>::type
atan2(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                                  typename dco::mode<stce_9780>::active_t,
                                  dco::stce_10483::stce_10521<typename dco::mode<stce_9780>::active_value_t>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
    const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
    const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
    const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
    const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
    const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
    const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
    const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
    const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
    const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
    const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10524<stce_9769>>
pow(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10524<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                         dco::stce_10483::stce_10525<stce_9769>>
pow(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
    const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::stce_10483::stce_10525<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                             typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
                             dco::stce_10483::stce_10525<stce_9769>>>::type
pow(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
    const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
                                  dco::stce_10483::stce_10525<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9779<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                         dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10526<stce_9769>>
pow(const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10091,
    const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10526<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769, typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
        dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10526<stce_9769>>>::type
pow(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
    const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
      dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10526<stce_9769>>(stce_10091,
                                                                                                 stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10525<stce_9769>>
pow(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
    const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                                  dco::stce_10483::stce_10525<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                             typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
                             dco::stce_10483::stce_10525<stce_9769>>>::type
pow(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
    const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
      typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::stce_10483::stce_10525<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9779<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                         dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10526<stce_9769>>
pow(const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10483::stce_10526<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769, typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
        dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10483::stce_10526<stce_9769>>>::type
pow(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
    const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10483::stce_10526<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10525<stce_9769>>
pow(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10483::stce_10525<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<
        stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::stce_10483::stce_10525<stce_9769>>>::type
pow(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
        stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10483::stce_10525<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9779<
    stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
    dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10526<stce_9769>>
pow(const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10526<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
        dco::stce_10483::stce_10526<stce_9769>>>::type
pow(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
        stce_10091,
    const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10526<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10525<stce_9769>>
pow(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10483::stce_10525<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<
        stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::stce_10483::stce_10525<stce_9769>>>::type
pow(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
        stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10483::stce_10525<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9779<
    stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
    dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10526<stce_9769>>
pow(const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10526<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
        dco::stce_10483::stce_10526<stce_9769>>>::type
pow(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
        stce_10091,
    const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10526<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10525<stce_9769>>
pow(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10483::stce_10525<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<
        stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::stce_10483::stce_10525<stce_9769>>>::type
pow(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
        stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10483::stce_10525<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9779<
    stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
    dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10526<stce_9769>>
pow(const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10526<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
        dco::stce_10483::stce_10526<stce_9769>>>::type
pow(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
        stce_10091,
    const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10526<stce_9769>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
typename enable_if<
    (dco::mode<stce_9879>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9879>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9879>::active_value_t, typename dco::mode<stce_9879>::active_t,
                             stce_9879,
                             dco::stce_10483::stce_10524<typename dco::mode<stce_9879>::active_value_t>>>::type
pow(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9879>::active_value_t,
                                  typename dco::mode<stce_9879>::active_t, stce_9879,
                                  dco::stce_10483::stce_10524<typename dco::mode<stce_9879>::active_value_t>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9879>::value ||
      (dco::mode<stce_9879>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9879::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9879>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                             typename dco::mode<stce_9780>::active_t,
                             dco::stce_10483::stce_10524<typename dco::mode<stce_9780>::active_value_t>>>::type
pow(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                                  typename dco::mode<stce_9780>::active_t,
                                  dco::stce_10483::stce_10524<typename dco::mode<stce_9780>::active_value_t>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::active_type<stce_9769, stce_10536>, dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10536>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10536>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                         dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                         dco::stce_10483::stce_10529<stce_9769>>
hypot(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>,
                                  dco::stce_10483::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                         typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                         dco::stce_10483::stce_10530<stce_9769>>
hypot(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::stce_10483::stce_10530<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                             typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
                             dco::stce_10483::stce_10530<stce_9769>>>::type
hypot(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
                                  dco::stce_10483::stce_10530<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::stce_9779<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                         dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10531<stce_9769>>
hypot(const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10483::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769, typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
        dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10531<stce_9769>>>::type
hypot(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
      dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10483::stce_10531<stce_9769>>(stce_10091,
                                                                                                 stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10530<stce_9769>>
hypot(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                                  dco::stce_10483::stce_10530<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                             typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
                             dco::stce_10483::stce_10530<stce_9769>>>::type
hypot(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
      typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::stce_10483::stce_10530<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::stce_9779<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                         dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                         dco::stce_10483::stce_10531<stce_9769>>
hypot(const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10483::stce_10531<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769, typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
        dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10483::stce_10531<stce_9769>>>::type
hypot(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10483::stce_10531<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                         typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10530<stce_9769>>
hypot(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10483::stce_10530<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<
        stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::stce_10483::stce_10530<stce_9769>>>::type
hypot(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10483::stce_10530<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9779<
    stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
    dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10531<stce_9769>>
hypot(const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10531<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
        dco::stce_10483::stce_10531<stce_9769>>>::type
hypot(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10531<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                         typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10530<stce_9769>>
hypot(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10483::stce_10530<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<
        stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::stce_10483::stce_10530<stce_9769>>>::type
hypot(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10483::stce_10530<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9779<
    stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
    dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10531<stce_9769>>
hypot(const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10531<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
        dco::stce_10483::stce_10531<stce_9769>>>::type
hypot(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10531<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9778<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                         typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
                         dco::stce_10483::stce_10530<stce_9769>>
hypot(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10483::stce_10530<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9778<
        stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::stce_10483::stce_10530<stce_9769>>>::type
hypot(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10483::stce_10530<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::stce_9779<
    stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
    dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10531<stce_9769>>
hypot(const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10531<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::stce_9779<
        stce_9769,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
        dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
        dco::stce_10483::stce_10531<stce_9769>>>::type
hypot(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10483::stce_10531<stce_9769>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
typename enable_if<
    (dco::mode<stce_9879>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9879>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9879>::active_value_t, typename dco::mode<stce_9879>::active_t,
                             stce_9879,
                             dco::stce_10483::stce_10529<typename dco::mode<stce_9879>::active_value_t>>>::type
hypot(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9879>::active_value_t,
                                  typename dco::mode<stce_9879>::active_t, stce_9879,
                                  dco::stce_10483::stce_10529<typename dco::mode<stce_9879>::active_value_t>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9879>::value ||
      (dco::mode<stce_9879>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9879::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9879>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                             typename dco::mode<stce_9780>::active_t,
                             dco::stce_10483::stce_10529<typename dco::mode<stce_9780>::active_value_t>>>::type
hypot(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                                  typename dco::mode<stce_9780>::active_t,
                                  dco::stce_10483::stce_10529<typename dco::mode<stce_9780>::active_value_t>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto operator==(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10090(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10090(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10532, class stce_10533>
static inline auto operator==(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10090(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10090(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator==(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10090(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10090(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator==(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10090(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10090(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator==(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10090(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10090(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10536>
static inline auto operator==(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10090(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator==(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10090(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator==(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10090(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator==(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10090(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator==(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10090(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
static inline auto operator==(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator==(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator==(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator==(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator==(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
static inline auto operator==(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator==(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator==(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator==(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator==(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
static inline auto operator==(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator==(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator==(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator==(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator==(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator==(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
           const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10093(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10093(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator==(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
           const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10094(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10094(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator==(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10093(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10093(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator==(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
           const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10094(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10094(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator==(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10093(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10093(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator==(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10094(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10094(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator==(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10093(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10093(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator==(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10094(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10094(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator==(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10093(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10093(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator==(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10094(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10094(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator==(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10093(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator==(const stce_9780& stce_10091, const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10094(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator==(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10093(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator==(const stce_9780& stce_10091, const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10094(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator==(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10093(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator==(const stce_9780& stce_10091,
           const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10094(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator==(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10093(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator==(const stce_9780& stce_10091,
           const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10094(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator==(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10093(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator==(const stce_9780& stce_10091,
           const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10094(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
static inline typename enable_if<
    (dco::mode<stce_9879>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9879>::active_t>::value),
    bool>::type
operator==(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::mode<stce_9879>::active_t::data_t::stce_10141::stce_10090(stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
static inline typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9879>::value ||
      (dco::mode<stce_9879>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9879::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9879>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    bool>::type
operator==(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::mode<stce_9780>::active_t::data_t::stce_10141::stce_10090(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto operator!=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10095(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10095(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10532, class stce_10533>
static inline auto operator!=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10095(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10095(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator!=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10095(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10095(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator!=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10095(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10095(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator!=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10095(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10095(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10536>
static inline auto operator!=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10095(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator!=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10095(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator!=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10095(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator!=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10095(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator!=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10095(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
static inline auto operator!=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator!=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator!=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator!=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator!=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
static inline auto operator!=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator!=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator!=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator!=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator!=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
static inline auto operator!=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator!=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator!=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator!=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator!=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator!=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
           const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10096(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10096(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator!=(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
           const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10097(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10097(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator!=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10096(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10096(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator!=(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
           const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10097(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10097(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator!=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10096(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10096(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator!=(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10097(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10097(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator!=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10096(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10096(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator!=(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10097(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10097(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator!=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10096(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10096(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator!=(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10097(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10097(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator!=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10096(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator!=(const stce_9780& stce_10091, const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10097(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator!=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10096(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator!=(const stce_9780& stce_10091, const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10097(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator!=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10096(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator!=(const stce_9780& stce_10091,
           const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10097(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator!=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10096(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator!=(const stce_9780& stce_10091,
           const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10097(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator!=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10096(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator!=(const stce_9780& stce_10091,
           const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10097(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
static inline typename enable_if<
    (dco::mode<stce_9879>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9879>::active_t>::value),
    bool>::type
operator!=(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::mode<stce_9879>::active_t::data_t::stce_10141::stce_10095(stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
static inline typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9879>::value ||
      (dco::mode<stce_9879>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9879::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9879>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    bool>::type
operator!=(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::mode<stce_9780>::active_t::data_t::stce_10141::stce_10095(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto operator<(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                             const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10098(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10098(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10532, class stce_10533>
static inline auto operator<(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                             const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10098(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10098(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator<(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                             const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10098(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10098(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator<(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                             const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10098(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10098(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator<(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                             const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10098(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10098(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10536>
static inline auto operator<(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                             const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10098(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator<(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                             const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10098(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator<(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                             const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10098(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator<(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                             const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10098(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator<(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                             const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10098(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
static inline auto operator<(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator<(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator<(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator<(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator<(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
static inline auto operator<(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator<(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator<(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator<(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator<(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
static inline auto operator<(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator<(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator<(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator<(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator<(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator<(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10099(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10099(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator<(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10100(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10100(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator<(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10099(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10099(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator<(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10100(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10100(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10099(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10099(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10100(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10100(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10099(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10099(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10100(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10100(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10099(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10099(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10100(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10100(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10099(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<(const stce_9780& stce_10091, const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10100(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10099(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<(const stce_9780& stce_10091, const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10100(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const stce_9780& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10099(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<(const stce_9780& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10100(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const stce_9780& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10099(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<(const stce_9780& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10100(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const stce_9780& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10099(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<(const stce_9780& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10100(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
static inline typename enable_if<
    (dco::mode<stce_9879>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9879>::active_t>::value),
    bool>::type
operator<(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::mode<stce_9879>::active_t::data_t::stce_10141::stce_10098(stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
static inline typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9879>::value ||
      (dco::mode<stce_9879>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9879::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9879>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    bool>::type
operator<(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::mode<stce_9780>::active_t::data_t::stce_10141::stce_10098(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto operator<=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10101(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10101(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10532, class stce_10533>
static inline auto operator<=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10101(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10101(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator<=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10101(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10101(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator<=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10101(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10101(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator<=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10101(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10101(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10536>
static inline auto operator<=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10101(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator<=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10101(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator<=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10101(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator<=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10101(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator<=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10101(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
static inline auto operator<=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator<=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator<=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator<=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator<=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
static inline auto operator<=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator<=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator<=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator<=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator<=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
static inline auto operator<=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator<=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator<=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator<=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator<=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator<=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
           const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10102(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10102(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator<=(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
           const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10103(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10103(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator<=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10102(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10102(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator<=(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
           const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10103(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10103(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10102(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10102(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<=(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10103(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10103(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10102(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10102(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<=(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10103(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10103(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10102(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10102(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<=(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10103(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10103(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10102(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<=(const stce_9780& stce_10091, const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10103(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10102(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<=(const stce_9780& stce_10091, const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10103(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10102(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<=(const stce_9780& stce_10091,
           const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10103(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10102(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<=(const stce_9780& stce_10091,
           const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10103(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10102(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<=(const stce_9780& stce_10091,
           const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10103(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
static inline typename enable_if<
    (dco::mode<stce_9879>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9879>::active_t>::value),
    bool>::type
operator<=(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::mode<stce_9879>::active_t::data_t::stce_10141::stce_10101(stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
static inline typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9879>::value ||
      (dco::mode<stce_9879>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9879::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9879>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    bool>::type
operator<=(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::mode<stce_9780>::active_t::data_t::stce_10141::stce_10101(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto operator>(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                             const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10104(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10104(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10532, class stce_10533>
static inline auto operator>(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                             const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10104(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10104(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator>(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                             const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10104(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10104(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator>(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                             const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10104(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10104(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator>(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                             const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10104(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10104(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10536>
static inline auto operator>(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                             const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10104(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator>(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                             const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10104(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator>(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                             const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10104(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator>(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                             const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10104(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator>(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                             const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10104(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
static inline auto operator>(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator>(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator>(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator>(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator>(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
static inline auto operator>(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator>(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator>(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator>(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator>(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
static inline auto operator>(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator>(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator>(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator>(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator>(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator>(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10105(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10105(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator>(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10106(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10106(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator>(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10105(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10105(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator>(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10106(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10106(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10105(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10105(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10106(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10106(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10105(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10105(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10106(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10106(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10105(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10105(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10106(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10106(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10105(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>(const stce_9780& stce_10091, const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10106(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10105(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>(const stce_9780& stce_10091, const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10106(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const stce_9780& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10105(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>(const stce_9780& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10106(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const stce_9780& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10105(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>(const stce_9780& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10106(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const stce_9780& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10105(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>(const stce_9780& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10106(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
static inline typename enable_if<
    (dco::mode<stce_9879>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9879>::active_t>::value),
    bool>::type
operator>(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::mode<stce_9879>::active_t::data_t::stce_10141::stce_10104(stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
static inline typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9879>::value ||
      (dco::mode<stce_9879>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9879::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9879>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    bool>::type
operator>(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::mode<stce_9780>::active_t::data_t::stce_10141::stce_10104(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto operator>=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10107(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10107(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10532, class stce_10533>
static inline auto operator>=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10107(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10107(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator>=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10107(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10107(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator>=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10107(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10107(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator>=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10107(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10107(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10536>
static inline auto operator>=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10107(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator>=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10107(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator>=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10107(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator>=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10107(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10534, class stce_10535, class stce_10533>
static inline auto operator>=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10107(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
static inline auto operator>=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator>=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator>=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator>=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator>=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
static inline auto operator>=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator>=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator>=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator>=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator>=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10536>
static inline auto operator>=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10536>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10532, class stce_10533>
static inline auto operator>=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10532, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator>=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator>=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10534, class stce_10535,
          class stce_10533>
static inline auto operator>=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10534, stce_10535, stce_10533>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator>=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
           const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10108(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10108(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator>=(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
           const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10109(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10109(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator>=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10108(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10108(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator>=(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
           const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10109(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10109(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10108(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10108(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>=(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10109(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10109(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10108(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10108(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>=(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10109(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10109(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10108(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10108(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>=(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10109(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10109(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10108(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>=(const stce_9780& stce_10091, const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10109(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10108(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>=(const stce_9780& stce_10091, const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10109(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10108(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>=(const stce_9780& stce_10091,
           const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10109(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10108(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>=(const stce_9780& stce_10091,
           const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10109(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10108(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>=(const stce_9780& stce_10091,
           const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10109(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
static inline typename enable_if<
    (dco::mode<stce_9879>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9879>::active_t>::value),
    bool>::type
operator>=(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::mode<stce_9879>::active_t::data_t::stce_10141::stce_10107(stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9879>
static inline typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9879>::value ||
      (dco::mode<stce_9879>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9879::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9879>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    bool>::type
operator>=(const stce_9780& stce_10091, const stce_9879& stce_10092) {
  return dco::mode<stce_9780>::active_t::data_t::stce_10141::stce_10107(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline void stce_10537(dco::internal::active_type<stce_9769, stce_10126>& stce_9810) {
  double stce_10029 = 0;
  get(stce_9810, stce_10029);
  stce_9810 = stce_10029;
}
template <class stce_9769, class stce_10126>
static inline std::istream& operator>>(std::istream& in, dco::internal::active_type<stce_9769, stce_10126>& stce_9810) {
  stce_9769& stce_10029 = stce_9810._value();
  in >> stce_10029;
  return in;
}
using std::ceil;
using std::floor;
using std::isfinite;
using std::isinf;
using std::isnan;
using std::isnormal;
using std::lround;
using std::round;
template <class stce_9769, class stce_10126>
static inline bool isnan(const dco::internal::active_type<stce_9769, stce_10126>& stce_9810) {
  return isnan(stce_9810._value());
}
template <class stce_9769, class stce_10126>
static inline bool isnormal(const dco::internal::active_type<stce_9769, stce_10126>& stce_9810) {
  return isnormal(stce_9810._value());
}
template <class stce_9769, class stce_10126>
static inline bool isinf(const dco::internal::active_type<stce_9769, stce_10126>& stce_9810) {
  return isinf(stce_9810._value());
}
template <class stce_9769, class stce_10126>
static inline double ceil(const dco::internal::active_type<stce_9769, stce_10126>& stce_9810) {
  return ceil(stce_9810._value());
}
template <class stce_9769, class stce_10126>
static inline double floor(const dco::internal::active_type<stce_9769, stce_10126>& stce_9810) {
  return floor(stce_9810._value());
}
template <class stce_9769, class stce_10126>
static inline bool isfinite(const dco::internal::active_type<stce_9769, stce_10126>& stce_9810) {
  return isfinite(stce_9810._value());
}
template <class stce_9769, class stce_10126>
static inline typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t
round(const dco::internal::active_type<stce_9769, stce_10126>& stce_9810) {
  return round(dco::passive_value(stce_9810));
}
template <class stce_9769, class stce_10126>
static inline long int lround(const dco::internal::active_type<stce_9769, stce_10126>& stce_9810) {
  return lround(dco::passive_value(stce_9810));
}
using std::ceil;
using std::floor;
using std::isfinite;
using std::isinf;
using std::isnan;
using std::isnormal;
using std::lround;
using std::round;
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isnan(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return isnan(stce_9810._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isnormal(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return isnormal(stce_9810._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isinf(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return isinf(stce_9810._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline double ceil(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return ceil(stce_9810._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline double floor(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return floor(stce_9810._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isfinite(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return isfinite(stce_9810._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t
round(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return round(dco::passive_value(stce_9810));
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline long int
lround(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return lround(dco::passive_value(stce_9810));
}
using std::ceil;
using std::floor;
using std::isfinite;
using std::isinf;
using std::isnan;
using std::isnormal;
using std::lround;
using std::round;
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isnan(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return isnan(stce_9810._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isnormal(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return isnormal(stce_9810._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isinf(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return isinf(stce_9810._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline double ceil(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return ceil(stce_9810._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline double floor(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return floor(stce_9810._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isfinite(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return isfinite(stce_9810._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t
round(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return round(dco::passive_value(stce_9810));
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline long int
lround(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return lround(dco::passive_value(stce_9810));
}
using std::ceil;
using std::floor;
using std::isfinite;
using std::isinf;
using std::isnan;
using std::isnormal;
using std::lround;
using std::round;
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isnan(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return isnan(stce_9810._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isnormal(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return isnormal(stce_9810._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isinf(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return isinf(stce_9810._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline double ceil(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return ceil(stce_9810._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline double floor(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return floor(stce_9810._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isfinite(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return isfinite(stce_9810._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t
round(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return round(dco::passive_value(stce_9810));
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline long int
lround(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  return lround(dco::passive_value(stce_9810));
}
using std::ceil;
using std::floor;
using std::isfinite;
using std::isinf;
using std::isnan;
using std::isnormal;
using std::lround;
using std::round;
template <class stce_9769, class stce_10136, class stce_10130>
static inline bool isnan(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9810) {
  return isnan(stce_9810._value());
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline bool isnormal(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9810) {
  return isnormal(stce_9810._value());
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline bool isinf(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9810) {
  return isinf(stce_9810._value());
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline double ceil(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9810) {
  return ceil(stce_9810._value());
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline double floor(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9810) {
  return floor(stce_9810._value());
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline bool isfinite(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9810) {
  return isfinite(stce_9810._value());
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t
round(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9810) {
  return round(dco::passive_value(stce_9810));
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline long int lround(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9810) {
  return lround(dco::passive_value(stce_9810));
}
template <class stce_9769, class stce_10126>
static inline std::ostream& operator<<(std::ostream& out,
                                       const dco::internal::active_type<stce_9769, stce_10126>& stce_9810) {
  out << stce_9810._value();
  return out;
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline std::ostream&
operator<<(std::ostream& out,
           const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  out << stce_9810._value();
  return out;
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline std::ostream&
operator<<(std::ostream& out,
           const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  out << stce_9810._value();
  return out;
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline std::ostream&
operator<<(std::ostream& out,
           const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
  out << stce_9810._value();
  return out;
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline std::ostream& operator<<(std::ostream& out,
                                       const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9810) {
  out << stce_9810._value();
  return out;
}
template <typename stce_9780, typename stce_9879,
          typename stce_10538 = decltype(passive_value(std::declval<stce_9780>()) <
                                         passive_value(std::declval<stce_9879>()))>
typename enable_if<mode<stce_9780>::is_dco_type || mode<stce_9879>::is_dco_type,
                   typename stce_9878<(mode<stce_9780>::order > mode<stce_9879>::order), typename mode<stce_9780>::type,
                                      typename mode<stce_9879>::type>::type>::type
min(stce_9780 const& stce_10015, stce_9879 const& stce_10539) {
  if (passive_value(stce_10015) < passive_value(stce_10539))
    return stce_10015;
  else
    return stce_10539;
}
template <typename stce_9780, typename stce_9879,
          typename stce_10538 = decltype(passive_value(std::declval<stce_9780>()) >
                                         passive_value(std::declval<stce_9879>()))>
typename enable_if<mode<stce_9780>::is_dco_type || mode<stce_9879>::is_dco_type,
                   typename stce_9878<(mode<stce_9780>::order > mode<stce_9879>::order), typename mode<stce_9780>::type,
                                      typename mode<stce_9879>::type>::type>::type
max(stce_9780 const& stce_10015, stce_9879 const& stce_10539) {
  if (passive_value(stce_10015) > passive_value(stce_10539))
    return stce_10015;
  else
    return stce_10539;
}
} // namespace internal
} // namespace dco

namespace dco {
namespace helper {
template <typename stce_9780> class complex_t {
private:
  stce_9780 stce_10540;
  stce_9780 stce_10541;

public:
  DCO_STRONG_INLINE complex_t(stce_9780 const& real = 0.0, stce_9780 const& imag = 0.0)
      : stce_10540(real), stce_10541(imag) {}
  template <typename stce_9879> complex_t(std::complex<stce_9879> const& stce_10542) {
    stce_10540 = stce_10542.real();
    stce_10541 = stce_10542.imag();
  }
  template <typename stce_9879> complex_t& operator=(stce_9879 const& stce_9907) {
    stce_10540 = stce_9907;
    stce_10541 = stce_9780();
    return *this;
  }
  template <typename stce_9879> complex_t& operator=(std::complex<stce_9879> const& stce_9907) {
    stce_10540 = stce_9907.real();
    stce_10541 = stce_9907.imag();
    return *this;
  }
  DCO_STRONG_INLINE stce_9780 real() const { return stce_10540; }
  DCO_STRONG_INLINE stce_9780 imag() const { return stce_10541; }
  DCO_STRONG_INLINE stce_9780& real() { return stce_10540; }
  DCO_STRONG_INLINE stce_9780& imag() { return stce_10541; }
  DCO_STRONG_INLINE void real(stce_9780 const& real) { stce_10540 = real; }
  DCO_STRONG_INLINE void imag(stce_9780 const& imag) { stce_10541 = imag; }
};
} // namespace helper
} // namespace dco
namespace std {
template <class stce_9769, typename stce_10543>
class complex<dco::internal::active_type<stce_9769, stce_10543>>
    : public dco::helper::complex_t<dco::internal::active_type<stce_9769, stce_10543>> {
public:
  typedef dco::internal::active_type<stce_9769, stce_10543> active_t;
  typedef dco::helper::complex_t<active_t> stce_10544;
  complex(active_t const& real = active_t(), active_t const& imag = active_t()) : stce_10544(real, imag) {}
  template <typename TYPE>
  complex(TYPE const& real, typename dco::dco_type_constructable_from<TYPE>::type* = 0) : stce_10544(real, TYPE()) {}
  template <typename TYPE>
  complex(TYPE const& real,
          typename dco::enable_if<(dco::mode<TYPE>::is_dco_type &&
                                   dco::stce_9884<dco::mode<TYPE>, dco::mode<active_t>>::value) ||
                                      dco::is_same<TYPE, typename dco::mode<active_t>::passive_t>::value,
                                  void*>::type = NULL)
      : stce_10544(real, TYPE()) {}
  template <typename stce_9879> complex(complex<stce_9879> const& stce_10542) : stce_10544(stce_10542) {}
  complex& operator=(active_t const& stce_9907) {
    static_cast<stce_10544&>(*this) = stce_9907;
    return *this;
  }
  template <typename stce_9879> complex& operator=(complex<stce_9879> const& stce_9907) {
    static_cast<stce_10544&>(*this) = stce_9907;
    return *this;
  }
  template <typename TYPE>
  typename dco::dco_type_constructable_from<TYPE, complex>::type& operator=(const TYPE& stce_9907) {
    static_cast<stce_10544&>(*this) = stce_9907;
    return *this;
  }
  complex& operator=(typename dco::mode<active_t>::passive_t const& stce_9907) {
    static_cast<stce_10544&>(*this) = stce_9907;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE complex(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810)
      : stce_10544(
            stce_9810,
            typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::active_t()) {}
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE complex&
  operator=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    static_cast<stce_10544&>(*this) = stce_9810;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE complex(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810)
      : stce_10544(
            stce_9810,
            typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::active_t()) {}
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE complex&
  operator=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    static_cast<stce_10544&>(*this) = stce_9810;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE complex(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810)
      : stce_10544(
            stce_9810,
            typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::active_t()) {}
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE complex&
  operator=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9810) {
    static_cast<stce_10544&>(*this) = stce_9810;
    return *this;
  }
  template <class stce_10136, class stce_10130>
  DCO_ALWAYS_INLINE complex(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9810)
      : stce_10544(stce_9810,
                   typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::active_t()) {}
  template <class stce_10136, class stce_10130>
  DCO_ALWAYS_INLINE complex& operator=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9810) {
    static_cast<stce_10544&>(*this) = stce_9810;
    return *this;
  }
  DCO_STRONG_INLINE complex operator-() const { return complex(-this->real(), -this->imag()); }
};
template <typename stce_10485, typename stce_10156, bool stce_10545 = true> struct stce_10546 {
  typedef typename dco::stce_9878<
      dco::mode<stce_10485>::is_dco_type && !dco::mode<stce_10485>::is_intermediate_type, stce_10485,
      typename dco::stce_9878<dco::mode<stce_10156>::is_dco_type && !dco::mode<stce_10156>::is_intermediate_type,
                              stce_10156, void>::type>::type stce_10547;
  typedef typename dco::stce_9878<dco::is_same<stce_10547, stce_10485>::value, stce_10156, stce_10485>::type stce_10548;
  static const bool stce_10549 =
      (stce_10545 || dco::is_same<stce_10547, stce_10485>::value) && !dco::is_same<stce_10547, void>::value &&
      (dco::is_same<stce_10547, typename dco::mode<stce_10548>::active_t>::value ||
       (dco::mode<stce_10548>::is_dco_type && dco::stce_9884<dco::mode<stce_10548>, dco::mode<stce_10547>>::value) ||
       dco::is_same<stce_10548, typename dco::mode<stce_10547>::passive_t>::value);
};
template <typename stce_10485, typename stce_10156, bool stce_10428 = false> struct stce_10550 {};
template <typename stce_10485, typename stce_10156> struct stce_10550<stce_10485, stce_10156, true> {
  typedef typename stce_10546<stce_10485, stce_10156>::stce_10547 type;
  typedef complex<type> stce_10551;
};
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
cos(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810);
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
cosh(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810);
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
exp(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810);
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
log(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810);
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
log10(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810);
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
sin(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810);
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
sinh(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810);
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
sqrt(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810);
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
tan(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810);
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
tanh(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810);
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
asin(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810);
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
asinh(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810);
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
acos(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810);
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
acosh(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810);
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
atan(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810);
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
atanh(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810);
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
proj(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810);
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE dco::internal::active_type<stce_9769, stce_10543>
abs(complex<dco::internal::active_type<stce_9769, stce_10543>> const&);
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE dco::internal::active_type<stce_9769, stce_10543>
arg(complex<dco::internal::active_type<stce_9769, stce_10543>> const&);
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>
polar(dco::internal::active_type<stce_9769, stce_10543> const&,
      const dco::internal::active_type<stce_9769, stce_10543>& = 0);
template <typename stce_9780>
complex<stce_9780> stce_10552(complex<stce_9780> const& stce_10091, complex<stce_9780> const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    complex<passive_t> stce_10556(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10554 = stce_10555 + stce_10556;
    stce_10553.real(stce_10091.real() + stce_10092.real());
    stce_10553.imag(stce_10091.imag() + stce_10092.imag());
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10091.real() + stce_10092.real());
    stce_10553.imag(stce_10091.imag() + stce_10092.imag());
    return stce_10553;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10552(complex<stce_9780> const& stce_10091, stce_9780 const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    passive_t stce_10556(dco::passive_value(stce_10092));
    stce_10554 = stce_10555 + stce_10556;
    stce_10553.real(stce_10091.real() + stce_10092);
    stce_10553.imag(stce_10091.imag());
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10091.real() + stce_10092);
    stce_10553.imag(stce_10091.imag());
    return stce_10553;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10552(stce_9780 const& stce_10091, complex<stce_9780> const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    passive_t stce_10555(dco::passive_value(stce_10091));
    complex<passive_t> stce_10556(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10554 = stce_10555 + stce_10556;
    stce_10553.real(stce_10091 + stce_10092.real());
    stce_10553.imag(stce_10092.imag());
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10091 + stce_10092.real());
    stce_10553.imag(stce_10092.imag());
    return stce_10553;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10557(complex<stce_9780> const& stce_10091, complex<stce_9780> const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    complex<passive_t> stce_10556(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10554 = stce_10555 - stce_10556;
    stce_10553.real(stce_10091.real() - stce_10092.real());
    stce_10553.imag(stce_10091.imag() - stce_10092.imag());
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10091.real() - stce_10092.real());
    stce_10553.imag(stce_10091.imag() - stce_10092.imag());
    return stce_10553;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10557(complex<stce_9780> const& stce_10091, stce_9780 const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    passive_t stce_10556(dco::passive_value(stce_10092));
    stce_10554 = stce_10555 - stce_10556;
    stce_10553.real(stce_10091.real() - stce_10092);
    stce_10553.imag(stce_10091.imag());
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10091.real() - stce_10092);
    stce_10553.imag(stce_10091.imag());
    return stce_10553;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10557(stce_9780 const& stce_10091, complex<stce_9780> const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    passive_t stce_10555(dco::passive_value(stce_10091));
    complex<passive_t> stce_10556(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10554 = stce_10555 - stce_10556;
    stce_10553.real(stce_10091 - stce_10092.real());
    stce_10553.imag(-stce_10092.imag());
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10091 - stce_10092.real());
    stce_10553.imag(-stce_10092.imag());
    return stce_10553;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10558(complex<stce_9780> const& stce_10091, complex<stce_9780> const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    complex<passive_t> stce_10556(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10554 = stce_10555 * stce_10556;
    stce_10553.real(stce_10091.real() * stce_10092.real() - stce_10091.imag() * stce_10092.imag());
    stce_10553.imag(stce_10091.real() * stce_10092.imag() + stce_10091.imag() * stce_10092.real());
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10091.real() * stce_10092.real() - stce_10091.imag() * stce_10092.imag());
    stce_10553.imag(stce_10091.real() * stce_10092.imag() + stce_10091.imag() * stce_10092.real());
    return stce_10553;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10558(complex<stce_9780> const& stce_10091, stce_9780 const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    passive_t stce_10556(dco::passive_value(stce_10092));
    stce_10554 = stce_10555 * stce_10556;
    stce_10553.real(stce_10091.real() * stce_10092);
    stce_10553.imag(stce_10091.imag() * stce_10092);
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10091.real() * stce_10092);
    stce_10553.imag(stce_10091.imag() * stce_10092);
    return stce_10553;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10558(stce_9780 const& stce_10091, complex<stce_9780> const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    passive_t stce_10555(dco::passive_value(stce_10091));
    complex<passive_t> stce_10556(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10554 = stce_10555 * stce_10556;
    stce_10553.real(stce_10091 * stce_10092.real());
    stce_10553.imag(stce_10091 * stce_10092.imag());
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10091 * stce_10092.real());
    stce_10553.imag(stce_10091 * stce_10092.imag());
    return stce_10553;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10559(complex<stce_9780> const& stce_10091, complex<stce_9780> const& stce_10092) {
  complex<stce_9780> stce_10046 = stce_10091 * complex<stce_9780>(stce_10092.real(), -stce_10092.imag());
  stce_9780 stce_10084 = stce_10092.real() * stce_10092.real() + stce_10092.imag() * stce_10092.imag();
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    complex<passive_t> stce_10556(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10554 = stce_10555 / stce_10556;
    stce_10553.real(stce_10046.real() / stce_10084);
    stce_10553.imag(stce_10046.imag() / stce_10084);
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10046.real() / stce_10084);
    stce_10553.imag(stce_10046.imag() / stce_10084);
    return stce_10553;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10559(complex<stce_9780> const& stce_10091, stce_9780 const& stce_10092) {
  complex<stce_9780> stce_10046 = stce_10091 * stce_10092;
  stce_9780 stce_10084 = stce_10092 * stce_10092;
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    passive_t stce_10556(dco::passive_value(stce_10092));
    stce_10554 = stce_10555 / stce_10556;
    stce_10553.real(stce_10046.real() / stce_10084);
    stce_10553.imag(stce_10046.imag() / stce_10084);
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10046.real() / stce_10084);
    stce_10553.imag(stce_10046.imag() / stce_10084);
    return stce_10553;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10559(stce_9780 const& stce_10091, complex<stce_9780> const& stce_10092) {
  complex<stce_9780> stce_10046 = stce_10091 * complex<stce_9780>(stce_10092.real(), -stce_10092.imag());
  stce_9780 stce_10084 = stce_10092.real() * stce_10092.real() + stce_10092.imag() * stce_10092.imag();
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    passive_t stce_10555(dco::passive_value(stce_10091));
    complex<passive_t> stce_10556(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10554 = stce_10555 / stce_10556;
    stce_10553.real(stce_10046.real() / stce_10084);
    stce_10553.imag(stce_10046.imag() / stce_10084);
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10046.real() / stce_10084);
    stce_10553.imag(stce_10046.imag() / stce_10084);
    return stce_10553;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10560(complex<stce_9780> const& stce_10091, complex<stce_9780> const& stce_10092) {
  complex<stce_9780> stce_10029;
  if (stce_10091 == stce_9780()) {
    stce_10029 = complex<stce_9780>();
  } else {
    stce_10029 = exp(stce_10092 * log(stce_10091));
  }
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    complex<passive_t> stce_10556(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10554 = pow(stce_10555, stce_10556);
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    return stce_10553;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10560(complex<stce_9780> const& stce_10091, stce_9780 const& stce_10092) {
  complex<stce_9780> stce_10029;
  if (stce_10091.imag() == typename dco::mode<stce_9780>::active_t() &&
      stce_10091.real() > typename dco::mode<stce_9780>::active_t()) {
    stce_10029 = pow(stce_10091.real(), stce_10092);
  } else {
    complex<stce_9780> stce_10015 = log(stce_10091);
    stce_10029 = polar(static_cast<stce_9780>(exp(stce_10092 * stce_10015.real())),
                       static_cast<stce_9780>(stce_10092 * stce_10015.imag()));
  }
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    passive_t stce_10556(dco::passive_value(stce_10092));
    stce_10554 = pow(stce_10555, stce_10556);
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    return stce_10553;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10560(stce_9780 const& stce_10091, complex<stce_9780> const& stce_10092) {
  complex<stce_9780> stce_10029;
  if (stce_10091 > stce_9780()) {
    stce_10029 = polar(static_cast<stce_9780>(pow(stce_10091, stce_10092.real())),
                       static_cast<stce_9780>(stce_10092.imag() * log(stce_10091)));
  } else {
    stce_10029 = pow(complex<stce_9780>(stce_10091), stce_10092);
  }
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    passive_t stce_10555(dco::passive_value(stce_10091));
    complex<passive_t> stce_10556(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10554 = pow(stce_10555, stce_10556);
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    return stce_10553;
  }
}
template <typename stce_9780>
complex<stce_9780>& stce_10561(complex<stce_9780>& stce_10091, complex<stce_9780> const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    complex<passive_t> stce_10556(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10555 += stce_10556;
    complex<stce_9780> stce_10029;
    stce_10029.real(stce_10091.real() + stce_10092.real());
    stce_10029.imag(stce_10091.imag() + stce_10092.imag());
    stce_10091 = stce_10029;
    dco::passive_value(stce_10091.real()) = stce_10555.real();
    dco::passive_value(stce_10091.imag()) = stce_10555.imag();
    return stce_10091;
  } else {
    complex<stce_9780> stce_10029;
    stce_10029.real(stce_10091.real() + stce_10092.real());
    stce_10029.imag(stce_10091.imag() + stce_10092.imag());
    stce_10091 = stce_10029;
    return stce_10091;
  }
}
template <typename stce_9780>
complex<stce_9780>& stce_10561(complex<stce_9780>& stce_10091, stce_9780 const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    passive_t stce_10556(dco::passive_value(stce_10092));
    stce_10555 += stce_10556;
    complex<stce_9780> stce_10029;
    stce_10029.real(stce_10091.real() + stce_10092);
    stce_10029.imag(stce_10091.imag());
    stce_10091 = stce_10029;
    dco::passive_value(stce_10091.real()) = stce_10555.real();
    dco::passive_value(stce_10091.imag()) = stce_10555.imag();
    return stce_10091;
  } else {
    complex<stce_9780> stce_10029;
    stce_10029.real(stce_10091.real() + stce_10092);
    stce_10029.imag(stce_10091.imag());
    stce_10091 = stce_10029;
    return stce_10091;
  }
}
template <typename stce_9780>
complex<stce_9780>& stce_10562(complex<stce_9780>& stce_10091, complex<stce_9780> const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    complex<passive_t> stce_10556(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10555 -= stce_10556;
    complex<stce_9780> stce_10029;
    stce_10029.real(stce_10091.real() - stce_10092.real());
    stce_10029.imag(stce_10091.imag() - stce_10092.imag());
    stce_10091 = stce_10029;
    dco::passive_value(stce_10091.real()) = stce_10555.real();
    dco::passive_value(stce_10091.imag()) = stce_10555.imag();
    return stce_10091;
  } else {
    complex<stce_9780> stce_10029;
    stce_10029.real(stce_10091.real() - stce_10092.real());
    stce_10029.imag(stce_10091.imag() - stce_10092.imag());
    stce_10091 = stce_10029;
    return stce_10091;
  }
}
template <typename stce_9780>
complex<stce_9780>& stce_10562(complex<stce_9780>& stce_10091, stce_9780 const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    passive_t stce_10556(dco::passive_value(stce_10092));
    stce_10555 -= stce_10556;
    complex<stce_9780> stce_10029;
    stce_10029.real(stce_10091.real() - stce_10092);
    stce_10029.imag(stce_10091.imag());
    stce_10091 = stce_10029;
    dco::passive_value(stce_10091.real()) = stce_10555.real();
    dco::passive_value(stce_10091.imag()) = stce_10555.imag();
    return stce_10091;
  } else {
    complex<stce_9780> stce_10029;
    stce_10029.real(stce_10091.real() - stce_10092);
    stce_10029.imag(stce_10091.imag());
    stce_10091 = stce_10029;
    return stce_10091;
  }
}
template <typename stce_9780>
complex<stce_9780>& stce_10563(complex<stce_9780>& stce_10091, complex<stce_9780> const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    complex<passive_t> stce_10556(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10555 *= stce_10556;
    complex<stce_9780> stce_10029;
    stce_10029.real(stce_10091.real() * stce_10092.real() - stce_10091.imag() * stce_10092.imag());
    stce_10029.imag(stce_10091.real() * stce_10092.imag() + stce_10091.imag() * stce_10092.real());
    stce_10091 = stce_10029;
    dco::passive_value(stce_10091.real()) = stce_10555.real();
    dco::passive_value(stce_10091.imag()) = stce_10555.imag();
    return stce_10091;
  } else {
    complex<stce_9780> stce_10029;
    stce_10029.real(stce_10091.real() * stce_10092.real() - stce_10091.imag() * stce_10092.imag());
    stce_10029.imag(stce_10091.real() * stce_10092.imag() + stce_10091.imag() * stce_10092.real());
    stce_10091 = stce_10029;
    return stce_10091;
  }
}
template <typename stce_9780>
complex<stce_9780>& stce_10563(complex<stce_9780>& stce_10091, stce_9780 const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    passive_t stce_10556(dco::passive_value(stce_10092));
    stce_10555 *= stce_10556;
    complex<stce_9780> stce_10029;
    stce_10029.real(stce_10091.real() * stce_10092);
    stce_10029.imag(stce_10091.imag() * stce_10092);
    stce_10091 = stce_10029;
    dco::passive_value(stce_10091.real()) = stce_10555.real();
    dco::passive_value(stce_10091.imag()) = stce_10555.imag();
    return stce_10091;
  } else {
    complex<stce_9780> stce_10029;
    stce_10029.real(stce_10091.real() * stce_10092);
    stce_10029.imag(stce_10091.imag() * stce_10092);
    stce_10091 = stce_10029;
    return stce_10091;
  }
}
template <typename stce_9780>
complex<stce_9780>& stce_10564(complex<stce_9780>& stce_10091, complex<stce_9780> const& stce_10092) {
  complex<stce_9780> stce_10046 = stce_10091 * complex<stce_9780>(stce_10092.real(), -stce_10092.imag());
  stce_9780 stce_10084 = stce_10092.real() * stce_10092.real() + stce_10092.imag() * stce_10092.imag();
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    complex<passive_t> stce_10556(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10555 /= stce_10556;
    complex<stce_9780> stce_10029;
    stce_10029.real(stce_10046.real() / stce_10084);
    stce_10029.imag(stce_10046.imag() / stce_10084);
    stce_10091 = stce_10029;
    dco::passive_value(stce_10091.real()) = stce_10555.real();
    dco::passive_value(stce_10091.imag()) = stce_10555.imag();
    return stce_10091;
  } else {
    complex<stce_9780> stce_10029;
    stce_10029.real(stce_10046.real() / stce_10084);
    stce_10029.imag(stce_10046.imag() / stce_10084);
    stce_10091 = stce_10029;
    return stce_10091;
  }
}
template <typename stce_9780>
complex<stce_9780>& stce_10564(complex<stce_9780>& stce_10091, stce_9780 const& stce_10092) {
  complex<stce_9780> stce_10046 = stce_10091 * stce_10092;
  stce_9780 stce_10084 = stce_10092 * stce_10092;
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    passive_t stce_10556(dco::passive_value(stce_10092));
    stce_10555 /= stce_10556;
    complex<stce_9780> stce_10029;
    stce_10029.real(stce_10046.real() / stce_10084);
    stce_10029.imag(stce_10046.imag() / stce_10084);
    stce_10091 = stce_10029;
    dco::passive_value(stce_10091.real()) = stce_10555.real();
    dco::passive_value(stce_10091.imag()) = stce_10555.imag();
    return stce_10091;
  } else {
    complex<stce_9780> stce_10029;
    stce_10029.real(stce_10046.real() / stce_10084);
    stce_10029.imag(stce_10046.imag() / stce_10084);
    stce_10091 = stce_10029;
    return stce_10091;
  }
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>
operator+(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10091,
          complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10092) {
  return stce_10552(stce_10091, stce_10092);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>
operator+(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10091,
          dco::internal::active_type<stce_9769, stce_10543> const& stce_10092) {
  return stce_10552(static_cast<complex<dco::internal::active_type<stce_9769, stce_10543>>>(stce_10091),
                    static_cast<dco::internal::active_type<stce_9769, stce_10543>>(stce_10092));
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>
operator+(dco::internal::active_type<stce_9769, stce_10543> const& stce_10091,
          complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10092) {
  return stce_10552(static_cast<dco::internal::active_type<stce_9769, stce_10543>>(stce_10091),
                    static_cast<complex<dco::internal::active_type<stce_9769, stce_10543>>>(stce_10092));
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::stce_10551
    operator+(complex<stce_10485> const& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10552(stce_10091, stce_10092);
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::stce_10551
    operator+(complex<stce_10485> const& stce_10091, stce_10156 const& stce_10092) {
  return stce_10552(
      static_cast<
          complex<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>>(
          stce_10091),
      static_cast<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>(
          stce_10092));
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::stce_10551
    operator+(stce_10485 const& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10552(
      static_cast<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>(
          stce_10091),
      static_cast<
          complex<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>>(
          stce_10092));
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>
operator-(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10091,
          complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10092) {
  return stce_10557(stce_10091, stce_10092);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>
operator-(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10091,
          dco::internal::active_type<stce_9769, stce_10543> const& stce_10092) {
  return stce_10557(static_cast<complex<dco::internal::active_type<stce_9769, stce_10543>>>(stce_10091),
                    static_cast<dco::internal::active_type<stce_9769, stce_10543>>(stce_10092));
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>
operator-(dco::internal::active_type<stce_9769, stce_10543> const& stce_10091,
          complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10092) {
  return stce_10557(static_cast<dco::internal::active_type<stce_9769, stce_10543>>(stce_10091),
                    static_cast<complex<dco::internal::active_type<stce_9769, stce_10543>>>(stce_10092));
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::stce_10551
    operator-(complex<stce_10485> const& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10557(stce_10091, stce_10092);
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::stce_10551
    operator-(complex<stce_10485> const& stce_10091, stce_10156 const& stce_10092) {
  return stce_10557(
      static_cast<
          complex<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>>(
          stce_10091),
      static_cast<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>(
          stce_10092));
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::stce_10551
    operator-(stce_10485 const& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10557(
      static_cast<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>(
          stce_10091),
      static_cast<
          complex<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>>(
          stce_10092));
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>
operator*(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10091,
          complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10092) {
  return stce_10558(stce_10091, stce_10092);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>
operator*(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10091,
          dco::internal::active_type<stce_9769, stce_10543> const& stce_10092) {
  return stce_10558(static_cast<complex<dco::internal::active_type<stce_9769, stce_10543>>>(stce_10091),
                    static_cast<dco::internal::active_type<stce_9769, stce_10543>>(stce_10092));
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>
operator*(dco::internal::active_type<stce_9769, stce_10543> const& stce_10091,
          complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10092) {
  return stce_10558(static_cast<dco::internal::active_type<stce_9769, stce_10543>>(stce_10091),
                    static_cast<complex<dco::internal::active_type<stce_9769, stce_10543>>>(stce_10092));
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::stce_10551
    operator*(complex<stce_10485> const& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10558(stce_10091, stce_10092);
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::stce_10551
    operator*(complex<stce_10485> const& stce_10091, stce_10156 const& stce_10092) {
  return stce_10558(
      static_cast<
          complex<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>>(
          stce_10091),
      static_cast<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>(
          stce_10092));
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::stce_10551
    operator*(stce_10485 const& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10558(
      static_cast<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>(
          stce_10091),
      static_cast<
          complex<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>>(
          stce_10092));
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>
operator/(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10091,
          complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10092) {
  return stce_10559(stce_10091, stce_10092);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>
operator/(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10091,
          dco::internal::active_type<stce_9769, stce_10543> const& stce_10092) {
  return stce_10559(static_cast<complex<dco::internal::active_type<stce_9769, stce_10543>>>(stce_10091),
                    static_cast<dco::internal::active_type<stce_9769, stce_10543>>(stce_10092));
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>
operator/(dco::internal::active_type<stce_9769, stce_10543> const& stce_10091,
          complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10092) {
  return stce_10559(static_cast<dco::internal::active_type<stce_9769, stce_10543>>(stce_10091),
                    static_cast<complex<dco::internal::active_type<stce_9769, stce_10543>>>(stce_10092));
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::stce_10551
    operator/(complex<stce_10485> const& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10559(stce_10091, stce_10092);
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::stce_10551
    operator/(complex<stce_10485> const& stce_10091, stce_10156 const& stce_10092) {
  return stce_10559(
      static_cast<
          complex<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>>(
          stce_10091),
      static_cast<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>(
          stce_10092));
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::stce_10551
    operator/(stce_10485 const& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10559(
      static_cast<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>(
          stce_10091),
      static_cast<
          complex<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>>(
          stce_10092));
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>
pow(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10091,
    complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10092) {
  return stce_10560(stce_10091, stce_10092);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>
pow(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10091,
    dco::internal::active_type<stce_9769, stce_10543> const& stce_10092) {
  return stce_10560(static_cast<complex<dco::internal::active_type<stce_9769, stce_10543>>>(stce_10091),
                    static_cast<dco::internal::active_type<stce_9769, stce_10543>>(stce_10092));
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>
pow(dco::internal::active_type<stce_9769, stce_10543> const& stce_10091,
    complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10092) {
  return stce_10560(static_cast<dco::internal::active_type<stce_9769, stce_10543>>(stce_10091),
                    static_cast<complex<dco::internal::active_type<stce_9769, stce_10543>>>(stce_10092));
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::stce_10551
    pow(complex<stce_10485> const& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10560(stce_10091, stce_10092);
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::stce_10551
    pow(complex<stce_10485> const& stce_10091, stce_10156 const& stce_10092) {
  return stce_10560(
      static_cast<
          complex<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>>(
          stce_10091),
      static_cast<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>(
          stce_10092));
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::stce_10551
    pow(stce_10485 const& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10560(
      static_cast<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>(
          stce_10091),
      static_cast<
          complex<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>>(
          stce_10092));
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>&
operator+=(complex<dco::internal::active_type<stce_9769, stce_10543>>& stce_10091,
           complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10092) {
  return stce_10561(stce_10091, stce_10092);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>&
operator+=(complex<dco::internal::active_type<stce_9769, stce_10543>>& stce_10091,
           dco::internal::active_type<stce_9769, stce_10543> const& stce_10092) {
  return stce_10561(static_cast<complex<dco::internal::active_type<stce_9769, stce_10543>>&>(stce_10091),
                    static_cast<dco::internal::active_type<stce_9769, stce_10543>>(stce_10092));
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156, false>::stce_10549>::stce_10551&
    operator+=(complex<stce_10485>& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10561(stce_10091, stce_10092);
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156, false>::stce_10549>::stce_10551&
    operator+=(complex<stce_10485>& stce_10091, stce_10156 const& stce_10092) {
  return stce_10561(
      static_cast<
          complex<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>&>(
          stce_10091),
      static_cast<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>(
          stce_10092));
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>&
operator-=(complex<dco::internal::active_type<stce_9769, stce_10543>>& stce_10091,
           complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10092) {
  return stce_10562(stce_10091, stce_10092);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>&
operator-=(complex<dco::internal::active_type<stce_9769, stce_10543>>& stce_10091,
           dco::internal::active_type<stce_9769, stce_10543> const& stce_10092) {
  return stce_10562(static_cast<complex<dco::internal::active_type<stce_9769, stce_10543>>&>(stce_10091),
                    static_cast<dco::internal::active_type<stce_9769, stce_10543>>(stce_10092));
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156, false>::stce_10549>::stce_10551&
    operator-=(complex<stce_10485>& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10562(stce_10091, stce_10092);
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156, false>::stce_10549>::stce_10551&
    operator-=(complex<stce_10485>& stce_10091, stce_10156 const& stce_10092) {
  return stce_10562(
      static_cast<
          complex<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>&>(
          stce_10091),
      static_cast<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>(
          stce_10092));
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>&
operator*=(complex<dco::internal::active_type<stce_9769, stce_10543>>& stce_10091,
           complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10092) {
  return stce_10563(stce_10091, stce_10092);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>&
operator*=(complex<dco::internal::active_type<stce_9769, stce_10543>>& stce_10091,
           dco::internal::active_type<stce_9769, stce_10543> const& stce_10092) {
  return stce_10563(static_cast<complex<dco::internal::active_type<stce_9769, stce_10543>>&>(stce_10091),
                    static_cast<dco::internal::active_type<stce_9769, stce_10543>>(stce_10092));
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156, false>::stce_10549>::stce_10551&
    operator*=(complex<stce_10485>& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10563(stce_10091, stce_10092);
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156, false>::stce_10549>::stce_10551&
    operator*=(complex<stce_10485>& stce_10091, stce_10156 const& stce_10092) {
  return stce_10563(
      static_cast<
          complex<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>&>(
          stce_10091),
      static_cast<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>(
          stce_10092));
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>&
operator/=(complex<dco::internal::active_type<stce_9769, stce_10543>>& stce_10091,
           complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_10092) {
  return stce_10564(stce_10091, stce_10092);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>&
operator/=(complex<dco::internal::active_type<stce_9769, stce_10543>>& stce_10091,
           dco::internal::active_type<stce_9769, stce_10543> const& stce_10092) {
  return stce_10564(static_cast<complex<dco::internal::active_type<stce_9769, stce_10543>>&>(stce_10091),
                    static_cast<dco::internal::active_type<stce_9769, stce_10543>>(stce_10092));
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156, false>::stce_10549>::stce_10551&
    operator/=(complex<stce_10485>& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10564(stce_10091, stce_10092);
}
template <typename stce_10485, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156, false>::stce_10549>::stce_10551&
    operator/=(complex<stce_10485>& stce_10091, stce_10156 const& stce_10092) {
  return stce_10564(
      static_cast<
          complex<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>&>(
          stce_10091),
      static_cast<typename stce_10550<stce_10485, stce_10156, stce_10546<stce_10485, stce_10156>::stce_10549>::type>(
          stce_10092));
}
template <typename stce_9780> complex<stce_9780> stce_10565(complex<stce_9780> const& stce_10091) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10554 = sin(stce_10555);
    stce_10553.real(sin(stce_10091.real()) * cosh(stce_10091.imag()));
    stce_10553.imag(cos(stce_10091.real()) * sinh(stce_10091.imag()));
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(sin(stce_10091.real()) * cosh(stce_10091.imag()));
    stce_10553.imag(cos(stce_10091.real()) * sinh(stce_10091.imag()));
    return stce_10553;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10566(complex<stce_9780> const& stce_10091) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10554 = sinh(stce_10555);
    stce_10553.real(sinh(stce_10091.real()) * cos(stce_10091.imag()));
    stce_10553.imag(cosh(stce_10091.real()) * sin(stce_10091.imag()));
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(sinh(stce_10091.real()) * cos(stce_10091.imag()));
    stce_10553.imag(cosh(stce_10091.real()) * sin(stce_10091.imag()));
    return stce_10553;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10567(complex<stce_9780> const& stce_10091) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10554 = cos(stce_10555);
    stce_10553.real(cos(stce_10091.real()) * cosh(stce_10091.imag()));
    stce_10553.imag(-sin(stce_10091.real()) * sinh(stce_10091.imag()));
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(cos(stce_10091.real()) * cosh(stce_10091.imag()));
    stce_10553.imag(-sin(stce_10091.real()) * sinh(stce_10091.imag()));
    return stce_10553;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10568(complex<stce_9780> const& stce_10091) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10554 = cosh(stce_10555);
    stce_10553.real(cosh(stce_10091.real()) * cos(stce_10091.imag()));
    stce_10553.imag(sinh(stce_10091.real()) * sin(stce_10091.imag()));
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(cosh(stce_10091.real()) * cos(stce_10091.imag()));
    stce_10553.imag(sinh(stce_10091.real()) * sin(stce_10091.imag()));
    return stce_10553;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10569(complex<stce_9780> const& stce_10091) {
  complex<stce_9780> stce_10029 = sin(stce_10091) / cos(stce_10091);
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10554 = tan(stce_10555);
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    return stce_10553;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10570(complex<stce_9780> const& stce_10091) {
  complex<stce_9780> stce_10029 = sinh(stce_10091) / cosh(stce_10091);
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10554 = tanh(stce_10555);
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    return stce_10553;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10571(complex<stce_9780> const& stce_10091) {
  complex<stce_9780> stce_10029 = polar(static_cast<stce_9780>(exp(stce_10091.real())), stce_10091.imag());
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10554 = exp(stce_10555);
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    return stce_10553;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10572(complex<stce_9780> const& stce_10091) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10554 = log(stce_10555);
    stce_10553.real(log(abs(stce_10091)));
    stce_10553.imag(arg(stce_10091));
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(log(abs(stce_10091)));
    stce_10553.imag(arg(stce_10091));
    return stce_10553;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10573(complex<stce_9780> const& stce_10091) {
  complex<stce_9780> stce_10029 = log(stce_10091) / log(typename dco::mode<stce_9780>::active_t(10.0));
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10554 = log10(stce_10555);
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    return stce_10553;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10574(complex<stce_9780> const& stce_10091) {
  complex<stce_9780> stce_10029;
  if (stce_10091.real() == typename dco::mode<stce_9780>::active_t()) {
    stce_9780 stce_10575 = sqrt(abs(stce_10091.imag()) / 2);
    stce_10029 = complex<stce_9780>(stce_10575, stce_10091.imag() < 0.0 ? stce_9780(-stce_10575) : stce_10575);
  } else {
    stce_9780 stce_10575 = sqrt(2 * (abs(stce_10091) + abs(stce_10091.real())));
    stce_9780 stce_10576 = stce_10575 / 2;
    stce_10029 = stce_10091.real() > typename dco::mode<stce_9780>::active_t()
                     ? complex<stce_9780>(stce_10576, stce_9780(stce_10091.imag() / stce_10575))
                     : complex<stce_9780>(abs(stce_10091.imag()) / stce_10575,
                                          stce_10091.imag() < stce_9780() ? stce_9780(-stce_10576) : stce_10576);
  }
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10554 = sqrt(stce_10555);
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    return stce_10553;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10577(complex<stce_9780> const& stce_10091) {
  complex<stce_9780> stce_10029(-stce_10091.imag(), stce_10091.real());
  stce_10029 = asinh(stce_10029);
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10554 = asin(stce_10555);
    stce_10553.real(stce_10029.imag());
    stce_10553.imag(-stce_10029.real());
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10029.imag());
    stce_10553.imag(-stce_10029.real());
    return stce_10553;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10578(complex<stce_9780> const& stce_10091) {
  complex<stce_9780> stce_10029((stce_10091.real() - stce_10091.imag()) * (stce_10091.real() + stce_10091.imag()) +
                                    stce_9780(1.0),
                                stce_9780(2.0) * stce_10091.real() * stce_10091.imag());
  stce_10029 = sqrt(stce_10029);
  stce_10029 = log(stce_10029 + stce_10091);
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10554 = asinh(stce_10555);
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    return stce_10553;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10579(complex<stce_9780> const& stce_10091) {
  complex<stce_9780> stce_10029 = asin(stce_10091);
  const stce_9780 stce_10580 = 1.5707963267948966192313216916397514L;
  stce_10029 = complex<stce_9780>(stce_10580 - stce_10029.real(), -stce_10029.imag());
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10554 = acos(stce_10555);
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    return stce_10553;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10581(complex<stce_9780> const& stce_10091) {
  complex<stce_9780> stce_10029 = stce_9780(2.0) * log(sqrt(stce_9780(0.5) * (stce_10091 + stce_9780(1.0))) +
                                                       sqrt(stce_9780(0.5) * (stce_10091 - stce_9780(1.0))));
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10554 = acosh(stce_10555);
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    return stce_10553;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10582(complex<stce_9780> const& stce_10091) {
  const stce_9780 stce_10583 = stce_10091.real() * stce_10091.real();
  const stce_9780 stce_10542 = stce_9780(1.0) - stce_10583 - stce_10091.imag() * stce_10091.imag();
  stce_9780 stce_10584 = stce_10091.imag() + stce_9780(1.0);
  stce_9780 stce_10585 = stce_10091.imag() - stce_9780(1.0);
  stce_10584 = stce_10583 + stce_10584 * stce_10584;
  stce_10585 = stce_10583 + stce_10585 * stce_10585;
  complex<stce_9780> stce_10029 =
      complex<stce_9780>(stce_9780(0.5) * atan2(stce_9780(2.0) * stce_10091.real(), stce_10542),
                         stce_9780(0.25) * log(stce_10584 / stce_10585));
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10554 = atan(stce_10555);
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    return stce_10553;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10586(complex<stce_9780> const& stce_10091) {
  const stce_9780 stce_10587 = stce_10091.imag() * stce_10091.imag();
  const stce_9780 stce_10542 = stce_9780(1.0) - stce_10587 - stce_10091.real() * stce_10091.real();
  stce_9780 stce_10584 = stce_9780(1.0) + stce_10091.real();
  stce_9780 stce_10585 = stce_9780(1.0) - stce_10091.real();
  stce_10584 = stce_10587 + stce_10584 * stce_10584;
  stce_10585 = stce_10587 + stce_10585 * stce_10585;
  complex<stce_9780> stce_10029 =
      complex<stce_9780>(stce_9780(0.25) * (log(stce_10584) - log(stce_10585)),
                         stce_9780(0.5) * atan2(stce_9780(2.0) * stce_10091.imag(), stce_10542));
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10553;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10554;
    complex<passive_t> stce_10555(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10554 = atanh(stce_10555);
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
    return stce_10553;
  } else {
    complex<stce_9780> stce_10553;
    stce_10553.real(stce_10029.real());
    stce_10553.imag(stce_10029.imag());
    return stce_10553;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10588(complex<stce_9780> const& stce_10091) {
  if (dco::IS_DEBUG && (isinf(stce_10091.real()) || isinf(stce_10091.imag()))) {
    throw dco::exception::create<std::runtime_error>(
        "std::proj(std::complex<T>): One value is inf; derivatives undefined. Please contact NAG (support@nag.co.uk).");
  }
  return stce_10091;
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
cos(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810) {
  return stce_10567(stce_9810);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
cosh(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810) {
  return stce_10568(stce_9810);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
exp(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810) {
  return stce_10571(stce_9810);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
log(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810) {
  return stce_10572(stce_9810);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
log10(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810) {
  return stce_10573(stce_9810);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
sin(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810) {
  return stce_10565(stce_9810);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
sinh(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810) {
  return stce_10566(stce_9810);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
sqrt(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810) {
  return stce_10574(stce_9810);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
tan(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810) {
  return stce_10569(stce_9810);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
tanh(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810) {
  return stce_10570(stce_9810);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
asin(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810) {
  return stce_10577(stce_9810);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
asinh(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810) {
  return stce_10578(stce_9810);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
acos(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810) {
  return stce_10579(stce_9810);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
acosh(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810) {
  return stce_10581(stce_9810);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
atan(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810) {
  return stce_10582(stce_9810);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
atanh(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810) {
  return stce_10586(stce_9810);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10543>>
proj(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810) {
  return stce_10588(stce_9810);
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE dco::internal::active_type<stce_9769, stce_10543>
abs(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810) {
  dco::internal::active_type<stce_9769, stce_10543> stce_10553 = hypot(stce_9810.real(), stce_9810.imag());
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    typedef typename dco::mode<dco::internal::active_type<stce_9769, stce_10543>>::passive_t passive_t;
    complex<passive_t> stce_10555(dco::passive_value(stce_9810.real()), dco::passive_value(stce_9810.imag()));
    passive_t stce_10554 = abs(stce_10555);
    dco::passive_value(stce_10553) = stce_10554;
  }
  return stce_10553;
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE dco::internal::active_type<stce_9769, stce_10543>
arg(complex<dco::internal::active_type<stce_9769, stce_10543>> const& stce_9810) {
  dco::internal::active_type<stce_9769, stce_10543> stce_10553 = atan2(stce_9810.imag(), stce_9810.real());
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    typedef typename dco::mode<dco::internal::active_type<stce_9769, stce_10543>>::passive_t passive_t;
    complex<passive_t> stce_10555(dco::passive_value(stce_9810.real()), dco::passive_value(stce_9810.imag()));
    passive_t stce_10554 = arg(stce_10555);
    dco::passive_value(stce_10553) = stce_10554;
  }
  return stce_10553;
}
template <class stce_9769, typename stce_10543>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10543>>
polar(dco::internal::active_type<stce_9769, stce_10543> const& stce_10589,
      dco::internal::active_type<stce_9769, stce_10543> const& stce_10590) {
  complex<dco::internal::active_type<stce_9769, stce_10543>> stce_10553 =
      complex<dco::internal::active_type<stce_9769, stce_10543>>(stce_10589 * cos(stce_10590),
                                                                 stce_10589 * sin(stce_10590));
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    typedef typename dco::mode<dco::internal::active_type<stce_9769, stce_10543>>::passive_t passive_t;
    passive_t stce_10555 = dco::passive_value(stce_10589);
    passive_t stce_10556 = dco::passive_value(stce_10590);
    std::complex<passive_t> stce_10554 = polar(stce_10555, stce_10556);
    dco::passive_value(stce_10553.real()) = stce_10554.real();
    dco::passive_value(stce_10553.imag()) = stce_10554.imag();
  }
  return stce_10553;
}
} // namespace std

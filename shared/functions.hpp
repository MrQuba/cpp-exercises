#pragma once
#include "../shared/random.hpp"
#include <type_traits>
namespace math {
template <typename T, typename R>
  requires std::is_arithmetic_v<T> && std::is_floating_point_v<R>
class functions {
public:
  static constexpr R linear(const T a, const T x, const T b) {
    return static_cast<R>((a * x) + b);
  }
};
template <typename T>
  requires std::is_arithmetic_v<T>
struct point {
  T x;
  T y;
  point() : x{}, y{} {}
  point(T n) : x(n), y(n) {}
  point(T x, T y) : x(x), y(y) {}
  point(point<T> &p) : x(p.x), y(p.y) {}
};
template <typename T>
  requires std::is_arithmetic_v<T>
struct point_3d {
  T x;
  T y;
  T z;
  point_3d() : x{}, y{}, z{} {}
  point_3d(T n) : x(n), y(n), z(n) {}
  point_3d(T x, T y, T z) : x(x), y(y), z(z) {}
  point_3d(point_3d<T> &p) : x(p.x), y(p.y), z{p.z} {}
  point_3d(point<T> &p) : x(p.x), y(p.y), z{} {}
};

namespace lambdas {
const auto random_point_generator = [](const int b = -109, const int e = 109) {
  Random r(b, e);
  return math::point<double>(r.get_number() / 10.0, r.get_number() / 10.0);
};
} // namespace lambdas

template <typename T>
  requires std::is_floating_point_v<T>
struct check_point_position_linear {
  unsigned int above{}, below{}, on{};
  check_point_position_linear() : a{}, b{} {}
  check_point_position_linear(T a, T b) : a(a), b(b) {}
  void operator()(math::point<T> p) {
    const T y = math::functions<T, T>::linear(a, p.x, b);
    if (y == p.y)
      this->on++;
    else if (y < p.y)
      this->below++;
    else
      this->above++;
  }

private:
  T a, b;
};
} // namespace math
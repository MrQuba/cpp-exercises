#pragma once
#include "random.hpp"
#include <ostream>
#include <string>
#include <type_traits>
namespace math {
template <typename T>
  requires std::is_arithmetic_v<T>
struct point {
  T x;
  T y;
  point() : x{}, y{} {}
  point(T n) : x(n), y(n) {}
  point(T x, T y) : x(x), y(y) {}
  point(const point<T> &p) : x(p.x), y(p.y) {}
   friend std::ostream& operator<<(std::ostream& s, point<T> p){
     s << "( " << p.x << ", " << p.y << ")";
     return s;
  }
};
template <typename T, typename R>
  requires std::is_arithmetic_v<T> && std::is_floating_point_v<R> || std::is_arithmetic_v<R>
class functions {
public:
  static constexpr R linear(const T a, const T x, const T b) {
    return static_cast<R>((a * x) + b);
  }
  static constexpr R two_point_linear(const point<T> pa, const point<T> pb,
                                      const point<T> px) {
    return static_cast<R>(((px.y - pa.y) * (pb.x - pa.x)) -
                          ((pb.y - pa.y) * (px.x - pa.x)));
  }
  static constexpr std::string linear_formula(const point<T> pa, const point<T> pb ){
    const T m = (pa.y - pb.y)/ (pa.x-pb.x);
    const T b = pa.y - (m*pa.x);
     std::string ms = std::to_string(m);
    ms.erase ( ms.find_last_not_of('0') + 1, std::string::npos );
    ms.erase ( ms.find_last_not_of('.') + 1, std::string::npos );
    std::string bs = std::to_string(b);
    bs.erase ( bs.find_last_not_of('0') + 1, std::string::npos );
    bs.erase ( bs.find_last_not_of('.') + 1, std::string::npos );

    return   ms + "x + " + bs; 
  }
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

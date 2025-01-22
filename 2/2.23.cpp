#include <cstdlib>
#include <iostream>
#include <sys/types.h>
double pow_common(const double b, const uint e) {
  double p = 1;
  for (uint i{}; i < e; i++) {
    p *= b;
  }
  return p;
}
double pow_common_recursive(const double b, const uint e, double t = 1,
                            uint i = 0) {
  if (i < e)
    return pow_common_recursive(b, e, t * b, i+1);
  else
    return t;
}
double pow(const double b, const int e, const bool recursive = false) {
  if (recursive)
    return (e < 0) ? 1 / pow_common_recursive(b, std::abs(e)) : pow_common_recursive(b, e);
  else
    return (e < 0) ? 1 / pow_common(b, std::abs(e)) : pow_common(b, e);
}
int main() {
  double base;
  uint exponent;
  std::cin >> base >> exponent;
  std::cout << pow(base, exponent, true) << "\n";
  return 0;
}
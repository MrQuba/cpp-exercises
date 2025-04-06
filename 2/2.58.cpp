#include "../shared/functions.hpp"
#include <array>
#include <iostream>
int main() {
  std::array<math::point<double>, 2> points = {
      math::point<double>(), math::point<double>()};
  int a, b;
  for (int i = 0; i < 2; i++) {
    std::cin >> a >> b;
    points[i].x = a;
    points[i].y = b;
  }
  std::cout << math::functions<double, double>::linear_formula(points[0], points[1]) << "\n";
};
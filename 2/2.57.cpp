#include "../shared/functions.hpp"
#include <array>
#include <iostream>
int main() {
  std::array<math::point<int>, 3> points = {
      math::point<int>(), math::point<int>(), math::point<int>()};
  int a, b;
  for (int i = 0; i < 3; i++) {
    std::cin >> a >> b;
    points[i].x = a;
    points[i].y = b;
  }
  std::cout << "\nThose points"
            << ((math::functions<int, float>::two_point_linear(
                     points[0], points[1], points[2]) == 0)
                    ? " "
                    : " don't ")
            << "lie on same line \n";
};
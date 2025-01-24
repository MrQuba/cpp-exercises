#include "../shared/functions.hpp"
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>

int main() {
  // test points: = { math::point<double>(0.0,1.0),
  // math::point<double>(1.0,10.0),math::point<double>(2.0,7.0)};
  std::array<math::point<double>, 100> points;

  std::generate(points.begin(), points.end(),
                math::lambdas::random_point_generator);

  auto check = math::check_point_position_linear<double>(2, 3);
  std::for_each(points.begin(), points.end(), std::ref(check));
  
  std::cout << "points: \n 1. Above function: " << check.above
            << "\n 2. On function: " << check.on
            << "\n 3. Below function: " << check.below << "\n";
}
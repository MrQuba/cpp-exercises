#include <iostream>
#include "../shared/convert.hpp"
int main() {
  std::cout << convert::bin_dec("11110") << "\n\n";
  std::cout << convert::dec_bin(30) << "\n\n";
  for (int b = 3; b <= 16; b++)
    std::cout << convert::dec_x(30, b) << "\n\n";
  std::cout << convert::x_dec("1E", 16) << "\n\n";

  return 0;
}
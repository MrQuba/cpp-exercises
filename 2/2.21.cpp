#include "../shared/squareutils.hpp"
#include "../shared/random.hpp"
#include <string>
#include <iostream>

int main() {
  Random r(5, 12);
  const unsigned int a = r.get_number();
  std::string square;

  SquareUtils::generate_square_with_char_at_random_pos(a, square, '@', '#', '#');
  std::cout << square << "\n";

  square = "";

  SquareUtils::generate_square_with_char_at_random_pos(a, square, '@', '#', ' ');
  std::cout << square;
  return 0;
}

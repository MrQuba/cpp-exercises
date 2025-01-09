#include "../shared/random.hpp"
#include "../shared/display.hpp"
#include <iostream>

int main() {
  char c;
  Random r(5, 10);
  std::cin >> c;
  Display::sq_chars<char>(c, r.get_number(), r.get_number());
}

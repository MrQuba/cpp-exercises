#include "../shared/random.hpp"
#include <string>

class SquareUtils {
public:
  static bool is_inside_square(const int a, const int i) {
    const unsigned j = (a + 1) * (i / (a + 1));
    const unsigned k = j + a;
    return (i > a) && (i < (std::pow(a, 2) - 1)) && i != j && i != k &&
           i != k - 1;
  }
  static void generate_square(std::string &s, const unsigned a,
                              const char f = '#', const char m = 'O') {
    s.reserve(a * (a + 1));
    std::string border_row(a+1, f);
    border_row[a] = '\n';
    s += border_row;

    std::string inside_row = f + std::string(a - 2, m) + f + '\n';
    for (unsigned i{}; i < a - 2; i++)
      s += inside_row;
    s += border_row;
  }
  static void generate_square_with_char_at_random_pos(const unsigned a,
                                                      std::string &square,
                                                      const char c = '@',
                                                      const char square_border = '#',
                                                      const char square_inside = 'O') {
    Random r(a, std::pow(a, 2));
    generate_square(square, a, square_border, square_inside);

    unsigned index =
        r.draw_until([&](int i) { return is_inside_square(a, i); });

    square[index] = c;
  }
};
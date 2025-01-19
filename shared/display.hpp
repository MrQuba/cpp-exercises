#include "concepts.hpp"
#include <iostream>
class Display {
public:
  template <displayable D>
  constexpr static void display_n_times(const unsigned int n, D content,
                                        const bool nline) {
    for (unsigned int i = 0; i < n; i++) {
      std::cout << content << ((nline) ? "\n" : " ");
    }
  }
  template <displayable D>
  constexpr static void line(const D c, const unsigned int n,
                             bool nline = true) {
    for (int j{}; j < n; j++)
      std::cout << c;
    if (nline)
      std::cout << "\n";
  }
  template <displayable D>
  constexpr static void alternating_line(const D w, const D b,
                                         const unsigned int n) {
    bool is_w = true;
    for (int j{}; j < n; j++) {
      std::cout << ((is_w) ? w : b);
      is_w = !is_w;
    }
    std::cout << "\n";
  }
  template <displayable D>
  constexpr static void rectangle(const D c, const unsigned int a,
                                  const unsigned int b) {
    for (int i{}; i < a; i++)
      line(c, b);
  }
  template <displayable D>
  constexpr static void chessboard(const D w, const D b, const unsigned int n) {
    bool swap = false;
    for (int i{}; i < n; i++) {
      if (!swap)
        alternating_line(w, b, n);
      else
        alternating_line(b, w, n);
      swap = !swap;
    }
  }
  template <displayable D>
  constexpr static void hollow_line(const D f, const D m = ' ',
                                    const unsigned int a = 5) {
    std::cout << f;
    line(m, a - 2, false);
    std::cout << f << "\n";
  }
  template <displayable D>
  constexpr static void hollow_square(const D f, const D m = ' ',
                                      const unsigned int a = 5) {
    line(f, a);
    for (int i{}; i < a - 2; i++)
      hollow_line(f, m, a);
    line(f, a);
  }
  template <displayable D>
  constexpr static void rect_triangle(const D c, const unsigned int a,
                                      bool flipped = false) {
    if (!flipped)
      for (int i = 1; i <= a; i++)
        line(c, i);
    else {
      for (int i = 1; i <= a; i++) {
        line(' ', a - i, false);
        line(c, i);
      }
    }
  }
  template <displayable D>
  constexpr static void pyramid(const D c, const unsigned int a,
                                bool flipped = false, bool margin = false, const unsigned int margin_size = 1) {
    if (!flipped)
      for (int i = 1; i <= a; i += 2) {
        line(' ', (a - i) / 2 + ((margin) ? margin_size : 0), false);
        line(c, i);
      }
    else
      for (int i = a; i > 0; i -= 2) {
        line(' ', (a - i) / 2 + ((margin) ? margin_size : 0), false);
        line(c, i);
      }
  }
  template <displayable D>
  constexpr static void diamond(const D c, const unsigned int a) {
    pyramid(c, a);
    pyramid(c, a-2, true, true);
  }
};
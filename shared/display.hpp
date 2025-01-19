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
  constexpr static void n_chars(const D c, const unsigned int n) {
    for (int j{}; j < n; j++)
      std::cout << c;
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
  constexpr static void sq_chars(const D c, const unsigned int a,
                                 const unsigned int b) {
    for (int i{}; i < a; i++)
      n_chars(c, b);
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
};
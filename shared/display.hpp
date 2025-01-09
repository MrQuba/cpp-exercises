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
  constexpr static void sq_chars(const D c, const unsigned int a, const unsigned int b) {
    for (int i{}; i < a; i++)
      n_chars(c, b);
  }
};
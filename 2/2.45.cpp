#include <algorithm>
#include <array>
#include <cstddef>
#include <iostream>
#include <ranges>

template <typename T, std::size_t x, std::size_t y>
using array_2d = std::array<std::array<T, x>, y>;

using dane = array_2d<char, 20, 7>;
using rdane = array_2d<char, 7, 20>;

template <std::ranges::bidirectional_range R>
  requires std::permutable<std::ranges::iterator_t<R>>
constexpr bool is_palindrome(const R &rr) {
  R reversed_rr = rr;
  std::ranges::reverse(reversed_rr);
  return rr == reversed_rr;
}
constexpr rdane rotate_dane(const dane &d) {
  rdane rd;
  int j{};
  for (auto a : d) {
    int i{};
    for (auto c : a) {
      rd[i][j] = c;
      i++;
    }
    j++;
  }
  return rd;
}
template <typename T, std::size_t x, std::size_t y>
constexpr void is_2darray_palindrome(const array_2d<T, x, y> &a) {
  for (auto b : a)
    std::cout << is_palindrome(b) << " ";
  std::cout << "\n";
}
int main() {
    constexpr dane d = {{
    {'-', '.', '.', '.', '.', '.', '.', '.', '.', '.', '-', '-', '.', '.', '.', '.', '.', '-',},
    {'.', '-', '-', '-', '.', '-', '-', '-', '.', '-', '-', '-', '.', '-', '-', '-', '.', '-',},
    {'.', '-', '-', '-', '-', '.', '.', '.', '.', '.', '.', '.', '-', '-', '-', '-', '.',},
    {'.', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',},
    {'.', '.', '.', '.', '.', '.', '-', '-', '-', '-', '-', '-', '-', '-', '.', '.', '-', '.', '.',},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
    {'-', '.', '.', '.', '.', '.', '-', '-', '-', '-', '-', '-', '-', '.', '.', '.', '.', '-',}
    }};
  is_2darray_palindrome(d);
  is_2darray_palindrome(rotate_dane(d));
  return 0;
}

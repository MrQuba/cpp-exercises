#include <cmath>
#include <iostream>
#include <ranges>

bool is_even(int n) {
  int bdig = std::log2(n);
  return ((((n << bdig) & (1 << bdig)) == (1 << bdig))) ? false : true;
}
int main() {
  for (auto i : std::views::iota(1, 16))
    std::cout << "Number " << i << " is " << (is_even(i) ? "" : "not ")
              << "even \n";
  return 0;
}
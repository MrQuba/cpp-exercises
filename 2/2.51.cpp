#include <iostream>
#include <ranges>

constexpr bool is_prime(const int n, const int div = 5) {
  if (n <= 1)
    return false;
  if (n == 2 || n == 3)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;
  if (div * div > n)
    return true;
  return (n % div == 0) ? false : is_prime(n, div + 2);
}
int main() {
  for (auto i : std::views::iota(0, 100)) {
    bool p = is_prime(i);
    if (p)
      std::cout << i << "\n";
  }
  return 0;
}
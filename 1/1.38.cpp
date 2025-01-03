#include <algorithm>
#include <array>
#include <iostream>
#include <ranges>
#include <utility>

constexpr auto print_subrange = [](std::ranges::viewable_range auto &&r) {
  for (auto e : r) {
    std::cout << e.first << ". ";
    break;
  }
  std::cout << '[';
  for (auto elem : r)
    std::cout << elem.second << " ";
  std::cout << "]\n";
};
constexpr auto sum_elements = [](std::ranges::viewable_range auto &&w) {
  int s{};
  for (auto e : w)
    s += e.second;
  return s == 10;
};
int main() {
  constexpr std::array<int, 83> v = {
      1, 2, 3, 2, 5, 6, 9, 1, 3, 7, 5, 8, 0, 9, 3, 1, 2, 5, 7, 6, 3,
      4, 2, 1, 0, 8, 9, 7, 8, 4, 6, 3, 2, 5, 4, 7, 8, 9, 1, 3, 2, 5,
      4, 7, 5, 6, 8, 0, 1, 2, 3, 6, 5, 8, 7, 1, 1, 2, 3, 4, 4, 5, 5,
      6, 8, 9, 0, 9, 8, 1, 9, 7, 5, 4, 1, 2, 7, 6, 9, 3, 4, 2, 6};
  auto vi = std::views::iota(1, static_cast<int>(v.size())) |
            std::views::transform(
                [&v](int i) { return std::make_pair(i - 1, v[i - 1]); });
  constexpr int sum = 10;
  for (const unsigned width : std::views::iota(1, sum)) {
    auto windows_filtered =
        vi | std::views::slide(width) | std::views::filter(sum_elements);
    std::ranges::for_each(windows_filtered, print_subrange);
  }

  return 0;
}
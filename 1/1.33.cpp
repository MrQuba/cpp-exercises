#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

struct result {
  int sum{};
  int sim{};
};
int main() {

  const std::vector<int> x = {2, 7, 1, 1, 4, 9, 3, 2, 1, 4, 1, 9, 6, 1, 3, 0, 1,
                              2, 3, 6, 8, 5, 6, 9, 3, 0, 8, 1, 8, 8, 7, 0, 7, 8,
                              5, 0, 2, 2, 3, 7, 1, 7, 2, 4, 7, 7, 5, 9, 0, 7, 7,
                              9, 2, 2, 2, 7, 0, 0, 5, 4, 6, 3, 9, 3, 5, 1, 0, 0,
                              9, 2, 9, 2, 8, 5, 0, 8, 5, 7, 0, 9, 6, 4, 9, 7, 8,
                              8, 6, 5, 4, 3, 2, 5, 8, 9, 4, 6, 8, 7, 9, 9};

  auto const windows = x | std::views::slide(2);
  result res;
  auto analyze = [&res](std::ranges::viewable_range auto &&r) {
    int sum{}, prev = -1;
    for (auto v : r) {
      sum += v;
      if (sum == 10)
        res.sum++;
      if (prev != -1 && prev == v)
        res.sim++;
      prev = v;
    }
  };
  std::ranges::for_each(windows, analyze);
  std::cout << res.sim << " " << res.sum << '\n';
}
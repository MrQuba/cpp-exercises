#include <algorithm>
#include <cctype>
#include <iostream>
#include <ranges>
int main() {
  const std::string T = "dfgnqeiut98tna1223v0w3r123334asdsh";
  int length = -1;
  std::string longest;
  auto longest_and_not_descending =
      [&length, &longest](std::ranges::viewable_range auto &&s) {
        if ((int)s.size() < length && !std::ranges::is_sorted(s))
          return;
        length = s.size();
        longest = std::string(s.begin(), s.end());
      };
  for (auto width : std::views::iota(1, (int)T.size()))
    std::ranges::for_each(T | std::views::slide(width) |
                              std::views::filter([](auto const &window) {
                                return std::ranges::all_of(window, [](char c) {
                                  return std::isdigit(c);
                                });
                              }),
                          longest_and_not_descending);
  std::cout << length << ": " << longest << "\n";
  return 0;
}
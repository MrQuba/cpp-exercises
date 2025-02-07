#include <algorithm>
#include <iostream>
#include <ranges>
#include <utility>
#include <vector>
#include "../shared/vector_utils.hpp"
int main() {
  std::vector<int> v = {3, 2, 1, 1, 4, 2, 4, 4, 4};
  std::vector<std::pair<int, std::vector<int>>> r;
  for (auto j : std::views::iota(2, (int)v.size() + 1)) {
    for (auto [i, w] : std::views::enumerate(v | std::views::slide(j))) {
      if (std::ranges::adjacent_find(w, std::ranges::not_equal_to()) != w.end())
        continue;
      r.push_back(std::make_pair(i,std::vector<int>(w.begin(), w.end())));
    }
  }
  std::ranges::sort(r,[](const auto& a, const auto& b) {
        return ((a.second.size() == b.second.size()) ? a.first > b.first: a.second.size() > b.second.size());});
  for(auto [i, w] : r)
  std::cout << i << " - " << i+w.size()-1 << ") " << w << "\n";
  return 0;
}
#include <iostream>
#include <ranges>
#include <vector>

int remove_until_last(const std::size_t size, const std::size_t jump) {
  auto range = std::views::iota(1, (int)size + 1);
  std::vector<int> v{range.begin(), range.end()};
  auto i = v.begin();
  while (v.size() != 1) {
    i = v.erase(v.begin() + std::distance(v.begin(), i + jump) % v.size());
  }
  return v.front();
}
/* same as above, but using for loop

int remove_until_last(const std::size_t size, const std::size_t jump) {
  auto range = std::views::iota(1, (int)size + 1);
  std::vector<int> v{range.begin(), range.end()};

  for (auto i = v.begin(); v.size() != 1;
       i = v.erase(v.begin() + std::distance(v.begin(), i + jump) % v.size()))
    ;
  return v.front();
}
*/
int main() {
  std::cout << remove_until_last(6, 3) << "\n"
            << remove_until_last(8, 3) << "\n";
  return 0;
}
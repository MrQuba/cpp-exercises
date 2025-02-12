#include "../shared/vector_utils.hpp"
#include <algorithm>
#include <vector>

int main() {
  std::vector<int> v1 = {1, 2, 3};
  std::vector<int> v2 = v1 + std::vector<int>{5, 6};
  auto v3 = VectorUtils<int>::common_part_of_vectors(&v1, &v2);
  std::ranges::sort(v3);
  std::cout << v3 << "\n";
  return 0;
}
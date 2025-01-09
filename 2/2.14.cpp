#include "../shared/display.hpp"
#include "../shared/random.hpp"
#include <iostream>
#include <vector>
void gen_nums_until(std::vector<int> &v, const int s) {
  int n{};
  Random r(1, s);
  while (n != s) {
    n = r.get_number();
    v.push_back(n);
    if (n == s)
      break;
    r.change_range(n, s);
  }
}
int main() {
  std::vector<int> res;
  const int s = 1000;
  gen_nums_until(res, s);
  for (auto i : res)
    std::cout << i << "\n";

  return 0;
}
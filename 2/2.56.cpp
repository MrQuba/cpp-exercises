#include "../shared/random.hpp"
#include <iostream>
#include <numeric>
std::string gen_num() {
  Random r(0, 9);
  int previous = -1;
  std::string result = "";
  result.push_back(r.draw_until([](auto n) { return n != 0; }) + '0');
  for (int i = 1; i < 10; i++) {
    int current;
    if (i != 2)
      current = (i < 8)
                    ? r.draw_until([previous](auto n) { return n != previous; })
                    : r.get_number();
    else
      current = r.draw_until([](auto n) { return n % 2 != 0; });

    result.push_back(current + '0');
    previous = current;
  }
  return (std::accumulate(result.begin(), result.end(), 0) - (10 * '0') < 30)
             ? gen_num()
             : result;
}
int main() {
  std::cout << gen_num() << "\n";
  return 0;
}
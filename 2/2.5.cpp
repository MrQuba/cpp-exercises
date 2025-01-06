#include "../shared/random.hpp"
#include <iostream>

int main() {
  Random r(0, 100);
  int draws{};
  while (true) {
    int n = r.get_number();
    draws++;
    std::cout << n << "\n";
    if(n == 100) break;
  }
  std::cout << "Got 100, after: " << draws << " draws\n";
  return 0;
}
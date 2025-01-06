#include "../shared/random.hpp"
#include "../shared/vector_utils.hpp"
#include <iostream>
#include <vector>

int main() {
  const int size = 20;
  Random r(0, size);
  std::vector<int> v(size, -1);
  int inserted_elements{};
  int number{};
  bool carry = false;
  while (inserted_elements < size) {
    if (!carry)
      number = r.get_number();

    int p = r.get_number();
    if (v[p] != -1) {
      carry = true;
      continue;
    }
    carry = false;
    v[p] = number;
    inserted_elements++;
  }
  std::cout << v;
  return 0;
}
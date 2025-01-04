#include "../shared/vector_utils.hpp"
#include <iostream>
#include <random>
#include <vector>
int main() {
  std::random_device rand_dev;
  std::default_random_engine def_rand_eng(rand_dev());
  std::uniform_int_distribution<int> uni_dist(1, 100000);
  std::vector<int> v{};
  for (int i{}; i < 3; i++)
    v.push_back(uni_dist(def_rand_eng));

  auto biggest = VectorUtils<int>::find_biggest_number_in_vector(&v);
  const int biggest_num = *biggest;
  v.erase(biggest);
  const int sum = v.front() + v.back();
  for (int i{}; i < biggest_num; i++) std::cout << sum << "\n";
    return 0;
}
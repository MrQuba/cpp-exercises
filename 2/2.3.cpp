#include "../shared/characters.hpp"
#include <array>
#include <iostream>
#include <random>
#include <utility>
int get_random_number(){
  std::random_device r;
  std::default_random_engine eng(r());
  std::uniform_int_distribution<int> uniform_dist(0, 51);
  return uniform_dist(eng);
}
std::pair<int, std::string> generate_character_until_got(const char c1 = 'z', const char c2 = 'A') {
  int count{};
  std::string str;
  char c{};

  while (c != c1 && c != c2) {
    c = Characters::letters[get_random_number()];
    count++;
    str.push_back(c);
  }
return std::make_pair(count, str);
}
int main() {
  auto r = generate_character_until_got();
  std::cout << r.first << ": " << r.second << "\n";
  return 0;
}
#include "../shared/random.hpp"
#include <array>
#include <iostream>
#include <string>

constexpr std::array<char, 5> begin{{'s', 'r', 'j', 'c', 'g'}};
constexpr std::array<char, 2> middle{{'e', 'o'}};
constexpr std::array<char, 3> end{{'q', 'v', 'x'}};
std::string gen_syllable(const char mid) {
  Random r(0, begin.size() - 1);
  const int b = r.get_number();
  r.change_range(0, end.size() - 1);
  const int e = r.get_number();
  return std::string{begin.at(b)} + std::string{mid} + std::string{end.at(e)};
}
std::string gen_name(const int n,const int mid, int it = 1,
    std::string name = ""){
  if (n % 2 == 0) {
    const char md = middle.at(mid);
    name += gen_syllable(md);
    return (it >= n) ? name : gen_name(n, mid, it+1, name);
  } else {
    const char md = middle.at((mid + 1) % middle.size());
    name += gen_syllable(md);
    return (it >= n) ? name : gen_name(n, (mid + 1) % middle.size(), it+1, name);
  }
}
std::string gen_name() {
  int m;
  int n;
    Random r(1, 4);
    n = r.get_number();
    r.change_range(1, middle.size() - 1);
    m = r.get_number();
    return gen_name(n, m);

}
int main() {
  for (int i = 0; i < 15; i++)
    std::cout << gen_name() << "\n";
}
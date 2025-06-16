#include <algorithm>
#include <cassert>
#include <fstream>
#include <ios>
#include <iostream>
#include <numeric>
#include <span>
#include <string>
#include <utility>
#include <vector>

template <typename T> float avg(std::span<T> s) {
  float sum = std::accumulate(s.begin(), s.end(), 0);
  return sum / s.size();
}

template <typename T>
std::vector<T> column(std::span<std::vector<T>> s, std::size_t n) {
  std::vector<T> v;
  n -= 1;
  std::ranges::for_each(s, [n, &v](auto &&l) {
    if (n >= l.size())
      return;
    v.push_back(l[n]);
  });
  return v;
}
template <typename T>
std::vector<std::pair<T, int>> max(std::span<std::vector<T>> s) {
  std::vector<std::pair<T, int>> r;
  int biggest = 0;
  for (int col = 1; col < s[0].size() + 1; col++) {
    auto c = column(s, col);
    auto m = std::ranges::max_element(c);
    if (*m >= biggest) {
      biggest = *m;
      r.push_back(std::make_pair(*m, col));
    }
  };
  r.erase(std::remove_if(r.begin(), r.end(),
                         [biggest](auto &a) { return biggest > a.first; }),
          r.end());
  return r;
}

std::vector<std::vector<short>> get_nums(std::fstream &f) {
  std::string line = "";
  std::vector<std::vector<short>> r;
  while (std::getline(f, line)) {
    std::vector<short> l;
    while (line != "") {
      auto it = std::find(line.begin(), line.end(), '\t');
      l.push_back(std::stoi(std::string(line.begin(), it)));
      line.erase(line.begin(), ((it + 1 < line.end()) ? it + 1 : line.end()));
    }
    r.push_back(l);
    l.clear();
  }
  return r;
}
template <typename T>
int rows_without_any_number_divisible_by(std::span<T> s, const int div = 10) {
  int rows = 0;
  for (auto v : s) {
    if (std::none_of(v.begin(), v.end(),
                     [div](auto n) { return n % div == 0; }))
      rows++;
  }
  return rows;
}
template <typename T> int rows_without_shrinking_elements(std::span<T> s) {
  int rows = 0;
  for (auto v : s)
    if (v[0] <= v[1] && v[1] <= v[2])
      rows++;
  return rows;
}
template <typename T>
int rows_with_exactly_three_elements_in_range(std::span<T> s, const int rb = 85,
                                              const int re = 100) {
  int rows = 0;
  for (auto v : s) {
    int elements = 0;
    for (auto i = rb; i <= re; i++)
      elements += std::count(v.begin(), v.end(), i);
    if (elements == 3)
      rows++;
  }
  return rows;
}
int main() {
  std::fstream f{"63_dane.txt", std::ios_base::in};
  auto v = get_nums(f);
  auto first_col = column(std::span{v}, 1);
  std::cout << avg(std::span{first_col}) << "\n";
  auto last_col = column(std::span{v}, v[0].size());
  std::cout << avg(std::span{last_col}) << "\n";
  for (auto p : max(std::span{v}))
    std::cout << p.second << ". " << p.first << " ";
  std::cout << "\n"
            << rows_without_any_number_divisible_by(std::span{v}) << "\n";
  std::cout << rows_without_shrinking_elements(std::span{v}) << "\n";
  std::cout << rows_with_exactly_three_elements_in_range(std::span{v}) << "\n";
  return 0;
}
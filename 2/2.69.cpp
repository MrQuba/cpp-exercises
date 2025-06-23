#include <algorithm>
#include <iostream>
#include <random>
#include <ranges>
#include <unordered_map>
#include <utility>
#include <vector>

std::vector<int> gen_vec(const int rb, const int re) {
  auto view = std::views::iota(std::min(rb, re), std::max(rb, re) + 1);
  std::vector<int> v{view.begin(), view.end()};
  if (rb > re)
    std::reverse(v.begin(), v.end());
  return v;
}

int main() {
  for (auto e : gen_vec(4, 8))
    std::cout << e << " ";
  std::cout << "\n";

  std::random_device rnd_device;
  std::uniform_int_distribution<int> dist(-10, 10);
  std::mt19937 mt{rnd_device()};
  std::unordered_map<int, int> freq;

  for (int i{}; i < 10; ++i) {
    auto range = std::make_pair(dist(mt), dist(mt));
    #define begin first 
    #define end second
    auto vec = gen_vec(range.begin, range.end);
    for (auto e : vec) {
      freq[e]++;
      std::cout << e << " ";
    }
    std::cout << "\n";
  }
  auto view = freq | std::views::filter([](auto& p){ return p.second >= 5;});
  for(auto [number, frequency] : view) std::cout << number << " appeared: " << frequency << " times\n";
  return 0;
}
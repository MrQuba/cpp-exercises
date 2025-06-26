#include <cstddef>
#include <iostream>
#include <random>
#include <ranges>
#include <unordered_map>
std::string sgen(std::size_t minL, std::size_t maxL, const std::string &dict) {
  std::random_device rd;
  std::mt19937 mt{rd()};
  std::uniform_int_distribution dist(minL, maxL);
  const std::size_t length = dist(mt);
  std::string result;
  dist = std::uniform_int_distribution<unsigned long>(0, dict.size() - 1);
  result.resize(length);

  for (std::size_t i = 0; i < length; ++i) {
    result.push_back(dict[dist(mt)]);
  }
  return result;
}

int main() {
  // std::cout   << sgen(2, 4, "abc") << "\n";
  const std::size_t amount_of_words = 25000;
  std::unordered_map<std::string, int> words;
  words.reserve(amount_of_words);
  for (std::size_t i = 0; i < amount_of_words; ++i) {
    words[sgen(5, 10, "qazwsxedcrfvtgby")]++;
  }
  auto filtered_words =
      words | std::views::filter([](auto &p) { return p.second > 1; });
  for (auto &[word, count] : filtered_words)
    std::cout << word << " ";
  std::cout << "\n";
  return 0;
}
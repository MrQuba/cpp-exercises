#include "../shared/random.hpp"
#include <algorithm>
#include <array>
#include <cstddef>
#include <cstring>
#include <iostream>

template <typename T, std::size_t x, std::size_t y>
using array_2d = std::array<std::array<T, x>, y>;

constexpr auto gen = [](auto &&W) {
  std::generate(W.begin(), W.end(), [s = std::string("abcdef")]() {
    Random r(97, 102);
    std::string str = "";
    for (int i = 0; i < 3; i++) {
      const char n = r.get_number();
      str.push_back(n);
    }
    return str;
  });
};
template <std::size_t strings_size, std::size_t wy, std::size_t wx>
constexpr int
find2x2_of_strings(const std::array<std::string, strings_size> strings,
                   const array_2d<std::string, wx, wy> W) {
  int c = 0;
  for (int y = 0; y < wy - 1; y++) {
    for (int x = 0; x < wx - 1; x++) {
      if (std::ranges::find(strings, W[y][x]) != strings.end() &&
          std::ranges::find(strings, W[y][x + 1]) != strings.end() &&
          std::ranges::find(strings, W[y + 1][x]) != strings.end() &&
          std::ranges::find(strings, W[y + 1][x + 1]) != strings.end())
        c++;
    }
  }
  return c;
}

constexpr std::array<std::string, 4> strings = {
    {{"abc"}, {"bcd"}, {"cde"}, {"def"}}};
int main() {
  array_2d<std::string, 15, 15> W;  
  std::ranges::for_each(W, gen);

  std::cout << find2x2_of_strings<strings.size(), W.size(), W[0].size()>(
                   strings, W)
            << "\n";
  return 0;
}
/* predefined W, with result of 2
W = {{
{"ebb","cbe","beb","bdd","fcf","eed","bdd","cfd","cec","fee","ebf","cba","bff","acf","aee"},
{"ddc","eee","cac","cca","daa","cce","cbd","cad","afa","ced","fcc","cdd","cca","cfc","afd"},
{"dad","afb","bae","ffd","dba","efd","bac","dda","cca","beb","add","fba","bbe","fbd","fab"},
{"dfd","bcd","ecc","bfb","efb","cbb","dcf","afb","aaf","fcd","dee","dba","dca","baa","cee"},
{"fab","fba","efc","dad","caf","bad","dba","afa","fbd","cbf","ccb","fda","cff","eac","bde"},
{"efa","eac","ada","edd","fcd","fae","dff","cab","eab","dcc","dbd","bac","bfe","efe","eec"},
{"ccc","bcc","fbf","afa","abc","cde","fec","faa","bfe","cac","acd","dad","eca","bbe","afd"},
{"eba","abb","cfd","ccb","abc","def","ffc","ead","cdd","baf","bef","fbd","afb","bae","bfe"},
{"fcf","acf","bdc","baa","cdf","adf","edb","cab","ebe","faf","dee","ddc","ebd","aad","eaa"},
{"eee","aec","cbc","edd","bcf","fbb","acc","abf","dbc","cab","bcd","bbc","ebc","fee","fcd"},
{"cdc","cef","bfe","def","ede","ade","ade","dea","cbc","bce","bce","cad","fbb","dbb","ccb"},
{"feb","dba","afe","efa","add","aeb","bfc","bee","aca","acc","ebe","ead","ffa","baa","eca"},
{"eea","fcd","bdf","baf","fdb","fdb","ddd","bce","eed","edf","efc","fca","dff","def","abc"},
{"ebc","fcd","fad","cde","daf","eee","dfd","aaf","cff","dcc","aff","cfb","afc","bcd","cde"},
{"cca","afe","daf","ecf","cfd","cdb","bfe","aea","ffe","dae","bae","fce","ade","bbc","fcd"}}};

*/
/*
for(auto a : W) {for(auto b : a) std::cout << b << " "; std::cout << "\n";}

Old code for generating array W
It generates  sliding windows of "abcdef" string starting at random index of s,
does not work in this scenario

constexpr auto gen = [](auto &&W) {
  std::generate(W.begin(), W.end(), [s = std::string("abcdef")]() {
    Random r(0, s.size() - 3);
    const int n = r.get_number();
    int i = 0;
    for (auto w : s | std::views::slide(3)) {
      if (i == n)
        return std::string(w.begin(), w.end());
      i++;
    }
    return std::string("");
  });
};
 */
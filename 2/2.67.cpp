#include <algorithm>
#include <array>
#include <iostream>
#include <ranges>
inline bool is_palindrome(std::string &str)  {
  return str == std::string(str.rbegin(), str.rend());
}
constexpr std::array<std::string_view, 48> randomStrings = {
    "abcdefghij",
    "klmnopqrst",
    "abcbaefghij", // Contains palindrome "abcba"
    "efghijklmnop",
    "qrstuvwxyzab",
    "cdefghijklmn",
    "opqrstuvwxyz",
    "abcdefghijklmno",
    "pqrstuvwxyzabc",
    "defghijklmnopqrs",
    "tuvwxyzabcdefg",
    "hijklmnopqrstuv",
    "wxyzabcdefghij",
    "klmnopqrstuvwxy",
    "zabcdefghijklmno",
    "pqrstuvwxyzabcd",
    "efghijklmnopqrst",
    "xyzyxuvwx", // Contains palindrome "xyzyx"
    "klmnopqrstuvwxyza",
    "bcdefghijklmnopqr",
    "stuvwxyzabcdefghij",
    "ijklmnopqrstuvwxy",
    "zabcdefghijklmno",
    "pqrstuvwxyzabcdef",
    "ghijkllkjihg", // Contains palindrome "llkjihg"
    "nopqrstuvwxyzabcde",
    "fghijklmnopqrstuv",
    "wxyzabcdefghijklm",
    "nopponabc", // Contains palindrome "noppon"
    "pqrstuvwxyzabcdefg",
    "hijklmnopqrstuvwxy",
    "zabcdefghijklmno",
    "pqrstuvwxyzabcdefg",
    "hijklmnopqrstuvwxy",
    "zabcdefghijklmno",
    "pqrstuvwxyzabcdefg",
    "hijklmnopqrstuvwxy",
    "zabcdefghijklmno",
    "pqrstuvwxyzabcdefg",
    "hijklmnopqrstuvwxy",
    "zabcdefghijklmno",
    "pqrstuvwxyzabcdefg",
    "hijklmnopqrstuvwxy",
    "zabcdefghijklmno",
    "pqrstuvwxyzabcdefg",
    "hijklmnopqrstuvwxy",
    "zabcdefghijklmno",
    "pqrstuvwxyzabcdefg"
};
int main() {
  std::ranges::for_each(randomStrings, [](auto &str) {
    std::cout << "checking string: " << str << ":\n";
    for (std::size_t w = 2; w <= str.size(); ++w) {
      auto windows = str | std::views::slide(w);
      std::ranges::for_each(windows, [](std::ranges::viewable_range auto &&w) {
        std::string w_str = std::string{w.begin(), w.end()};
        if (is_palindrome(w_str))
          std::cout << "found palindrome: " << w_str << "\n";
      });
    }
  });
  return 0;
}

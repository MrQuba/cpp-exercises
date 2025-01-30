#include <cmath>
#include <fstream>
#include <ranges>
#include <type_traits>
#include <vector>

template <typename T>
  requires std::is_arithmetic_v<T>
class Files {
public:
  static std::vector<T> ExtractNumbers(std::fstream &f) {
    std::vector<T> nums;
    std::string s;
    while (std::getline(f, s)) {
      auto r = s | std::views::filter([](auto &&c) {
                 return std::isdigit(c) || c == ';' || c == '.' || c == '-';
               });
      number_builder(r, nums);
    }
    return nums;
  }

private:
  static constexpr T ston(std::string s) {
    if constexpr (std::is_same_v<T, int>)
      return std::stoi(s);
    else if constexpr (std::is_same_v<T, double>)
      return std::stod(s);
  }
  constexpr static auto number_builder = [](auto &&view, std::vector<T> &v) {
    std::string num = "";
    for (auto c : view) {
      if (c == ';') {
        if (num != "")
          v.push_back(ston(num));
        num.clear();
        continue;
      }
      num.push_back(c);
    }
    if (num != "")
      v.push_back(ston(num));
  };
};
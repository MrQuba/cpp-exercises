//#pragma  once
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
class convert{
    static const std::unordered_map<int, char> hexMap;
    public:
constexpr static int bin_dec(std::string b) {
  if (b.empty())
    return 0;
  return ((b[0] - '0') * std::pow(2, b.size() - 1)) +
         bin_dec(b.substr(1, b.size() - 1));
}
constexpr static std::string dec_bin(int d, int i = 0) {
  if (d == 0)
    return (i == 0) ? "0" : "";
  return dec_bin(d / 2, i + 1) + std::to_string(d % 2);
}
constexpr static std::string dec_x(int d, int8_t base, int i = 0) {
  if (d == 0)
    return (i == 0) ? "0" : "";
  return dec_x(d / base, base, i + 1) + hexMap.at((d % base));
}
constexpr static int x_dec(std::string x, int8_t base) {
  if (x.empty())
    return 0;
  return ((std::find_if(hexMap.begin(), hexMap.end(),
                        [&x](auto &&i) { return x[0] == i.second; }))
              ->first *
          std::pow(base, x.size() - 1)) +
         x_dec(x.substr(1, x.size() - 1), base);
}
};
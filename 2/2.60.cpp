#include <iostream>
#include <string>
int substr(std::string &l, int p, int n) { return std::stoi(l.substr(p, n)); }
std::string subtract(std::string l, std::string r, int p, int n) {
  std::string h = std::to_string(substr(l, p, n) - substr(r, p, n));
  if (h.size() < 2)
    h.insert(h.begin(), '0');
  return h;
}
std::string operator-(std::string l, std::string r) {
  return subtract(l, r, 0, 2)+":" + subtract(l, r, 3, 2) + ":" + subtract(l, r, 6, 2);
}
int main() {
  const std::string a = "13:10:33";
  const std::string b = "09:05:08";
  std::cout << a << " - " << b << " = " << a - b << "\n";
}
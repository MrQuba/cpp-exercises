#include <cstdlib>
#include <iostream>

float multiply(float a, float b) {
  float r{};
  for (int i = 0; i < std::abs(b); i++)
    if (b - i < 1)
      r += a / (1 / (b - i));
    else
      r += a;
  if (b < 0)
    r = -r;
  return r;
}
int main() {
    float a, b;
    std::cin >> a >> b;
  std::cout << multiply(a, b) << "\n";
  return 0;
}
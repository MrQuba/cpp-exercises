#include <iostream>
double abs(const double a) { return (a < 0) ? a * -1 : a; }
int main() {
  double a;
  std::cin >> a;
  std::cout << abs(a) << "\n";

  return 0;
}
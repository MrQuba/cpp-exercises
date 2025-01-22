#include <iostream>

long long int round(const double a) {
  return (a > 0) ? (a - int(a) >= 0.5) ? (int)(a + 1) : (a - int(a) == 0) ? a : (int)(a - 1)
         : (std::abs(a) - std::abs(int(a)) >= 0.5) ? (int)(a - 1)
                                                   : (a - int(a) == 0) ? a : (int)(a + 1);
}

int main() { 
    double a;
    std::cin >> a;
    std::cout << round(a) << "\n";
    return 0; 
    }
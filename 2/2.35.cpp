#include "../shared/files.hpp"
#include <cctype>
#include <cmath>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>

int main() {
  std::fstream f("35_dane.txt", std::ios_base::in);
  if (!f.good())
    return -1;
  std::string s;
  for(auto d : Files<double>::ExtractNumbers(f)) std::cout << d << "\n";
  f.close();
  return 0;
}
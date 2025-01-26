#include "../shared/vector_utils.hpp"
#include <cctype>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::fstream f("liczby.txt", std::ios_base::in);
  std::vector<int> v;
  std::string s;
  while (std::getline(f, s)) {
        if(s.empty()) continue;
      v.push_back(std::stoi(s));
  }
  std::cout << v << "\n";
  return 0;
}
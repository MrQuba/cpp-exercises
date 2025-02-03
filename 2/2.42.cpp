#include <cctype>
#include <iostream>
#include <algorithm>
#include <vector>
int main() {
  const std::string T = "abd65asd7891das1d";
  std::string num = "";
  std::vector<std::string > v;
  for (auto c : T) {
    if(!std::isdigit(c)) {
      if(num != ""){
         v.push_back(num);
         num = "";
      }
      continue;
    }
    num .push_back(c);
  }
  std::ranges::for_each(v, [](std::string s){std::cout << s << "\n";});
  return 0;
}
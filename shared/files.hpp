#include <fstream>
#include <iostream>

class Files {
public:
  static void ExtractNumbers(std::fstream &f, const int n,
                             bool ends_with_semicolon = false) {
    std::string s;
    while (std::getline(f, s)) {
      for (int c{}; c < n; c++) {
        if (s.empty())
          continue;

        auto i = s.find_first_of(';');

        int a = std::stoi(std::string(
            s.begin(), (!ends_with_semicolon and c + 1 == n)
                           ? s.end()
                           : ((ends_with_semicolon) ? s.begin() + s.find_last_of(';') : s.begin() + i)));

        if (i != std::string::npos){
          s = s.erase(0, i + 1);
        }

        std::cout << a << " ";
      }
      std::cout << "\n";
    }
  }
};
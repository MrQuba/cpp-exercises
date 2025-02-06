#include <algorithm>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
void save_to_file(const std::string text, const std::string path,
                  const bool nline = false,
                  const std::ios_base::openmode mode = std::ios_base::out) {
  std::fstream f(path, mode);
  for (char c : text)
    f << (int)c << " ";
  f << ";" << ((nline) ? "\n" : "");
}
std::string read_from_file(const std::string path) {
  std::string s, l;
  std::fstream f(path, std::ios_base::in);
  while (std::getline(f, l)) {
    std::string::iterator it;
    do {
      it = std::find(l.begin(), l.end(), ' ');

      s += static_cast<char>(std::stoi(std::string(l.begin(), it)));

      l.erase(l.begin(), it + 1);
    } while (*it != std::string::npos && l != ";");
  }
  return s;
}
int main() {
  std::string s;
  std::cin >> s;
  save_to_file(s, "46.txt");
  std::cout << read_from_file("46.txt") << "\n";
  return 0;
}
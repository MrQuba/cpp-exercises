#include "../shared/random.hpp"
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
std::string get_line(const std::string &path, const int  n){
  std::fstream f(path, std::ios_base::in);
  std::string l;
  int i{};
  while (i < n) {
   std::getline(f,l);
   i++;
  }
  f.close();
  return l;
}
std::string random_line(const std::string &path, const int number_of_lines) {
  Random r(1, number_of_lines);
  int n = r.get_number();
  return get_line(path, n);
}
std::string gen_name() {
  std::string name = random_line("imiona.txt", 16);
  std::string surname = random_line("nazwiska.txt", 12);
  auto g = std::ranges::find(name, ';');
  if (*(g + 1) == 'm')
    surname.erase(std::ranges::find(surname, ';'), surname.end());
  else
    surname.erase(surname.begin(), std::ranges::find(surname, ';')+1);
  name.erase(g, name.end());
  return name + " " + surname;
}

int main() {
  std::cout << gen_name() << "\n";
  return 0;
}
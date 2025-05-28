#include <chrono>
#include <iostream>

int leap_years(int l, int r) {
  const auto ly = [](const int y) { return (y / 4) - (y / 100) + (y / 400); };
  return ly(r) - ly(l);
}
//attempt at not using loop, works fine until end of 2024 
/*int get_weekday(const int nth_day_of_year,
                                                 const int year = 2022) {
  constexpr int starting_day = 6;
  constexpr int starting_year = 2022;
  int amount_of_days = (year - starting_year) * 365 +
                       leap_years(year, starting_year) + nth_day_of_year - 1;
  return ((amount_of_days + starting_day) % 7);
} */
int get_weekday(const int nth_day_of_year, const int year = 2022) {
  constexpr int starting_day = 6;
  constexpr int starting_year = 2022;
  int amount_of_days = nth_day_of_year - 1;
  for (int y = starting_year; y < year; y++) {
    if (leap_years(y, y) > 0)
      amount_of_days += 1;
    amount_of_days += 365;
  }
  return ((amount_of_days + starting_day) % 7);
}
int main(int argc, char **argv) {
  if (argc < 3) {
    std::cout << "usage: program -d <days> -y <year>\n";
    return -1;
  }
  const int d = std::stoi(argv[2]);
  const int y = std::stoi(argv[4]);
  std::cout << std::chrono::weekday(get_weekday(d, y)) << "\n";
  return 0;
}
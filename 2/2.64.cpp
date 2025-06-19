#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <cstddef>
#include <fstream>
#include <ios>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

struct Person {
  Person(char id) : id(id) {}
  const char id;
  using day = int;
  using data = int;
  std::vector<std::pair<day, data>> all_measurements;
  template <std::size_t s = 5>
  static void init_people(std::fstream &f, std::array<Person, s> &people) {

    std::string line{};
    while (std::getline(f, line)) {
      std::replace(line.begin(), line.end(), ' ', '\0');
      int day = std::stoi(std::string(
          std::find(line.begin() + 2, line.end(), '\t') + 1, line.end()));
      int measurement = std::stoi(std::string(
          line.begin() + 1, std::find(line.begin() + 2, line.end(), '\t')));
      people[line[0] - 'A'].all_measurements.push_back(
          std::make_pair(day, measurement));
    }
  }
  static bool highest_amount_of_measurements(Person &p1, Person &p2) {
    return p1.all_measurements.size() < p2.all_measurements.size();
  }
  int sum() {
    return std::accumulate(all_measurements.begin(), all_measurements.end(), 0,
                           bin_op_for_sum);
  }

private:
  static int bin_op_for_sum(int acc, std::pair<day, data> e) {
    return acc += e.second;
  }
};
void sum_and_avg(Person &p) {
  int sum = p.sum();
  std::cout << p.id << "'s measurement sum: " << sum
            << ", average: " << (float)sum / p.all_measurements.size() << "\n";
}
int main() {
  std::array<Person, 5> people{Person('A'), Person('B'), Person('C'),
                               Person('D'), Person('E')};
  std::fstream f("64_dane.txt", std::ios_base::in);
  Person::init_people(f, people);
  std::cout << std::ranges::max_element(people,
                                        Person::highest_amount_of_measurements)
                   ->id
            << "\n";
  for (auto p : people)
    sum_and_avg(p);
  const int day = 1;
  auto days = [people]() {
    int max = 0;
    for (auto p : people)
      max = std::max(max, std::ranges::max_element(p.all_measurements)->first);
    return max;
  };
  int count{};
  for (int i = day; i <= days(); i += 7)
    count++;
  std::cout << count << "\n";
}

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <ostream>
#include <random>
#include <ranges>
#include <vector>
#include <numeric>
int get_increase(const int percentage) {
  return (percentage <= 50)                      ? -1
         : (percentage > 50 && percentage <= 80) ? 3
                                                 : 7;
}
std::vector<int> simulate(std::size_t starting_leaves,
                          std::size_t &leafless_tree_time) {
  std::random_device rd;
  std::mt19937 mt{rd()};
  std::uniform_int_distribution time_dist(1, 10);
  std::uniform_int_distribution percentage_dist(1, 100);
  std::uniform_int_distribution fall_amount_dist(1, 4);
  std::uniform_int_distribution small_fall_amount_dist(1, 3);
  std::vector<int> fall_amounts;
  int current_leaves = starting_leaves;
  while (current_leaves > 0) {
    leafless_tree_time += time_dist(mt);
    int increase_in_leaf_amount = get_increase(percentage_dist(mt));
    int fallen_leaves =
        increase_in_leaf_amount + ((increase_in_leaf_amount == 7)
                                       ? small_fall_amount_dist(mt)
                                       : fall_amount_dist(mt));
    fall_amounts.push_back(
        (current_leaves - fallen_leaves < 0) ? current_leaves : fallen_leaves);
    current_leaves -= fall_amounts.back();
  }
  return fall_amounts;
}
void display_time(std::ostream &os, const std::size_t time) {
  std::size_t h = time / 3600;
  std::size_t m = (time - (h * 3600)) / 60;
  std::size_t s = time - (m * 60) - (3600 * h);
  os << "Time it took for leaves to fall is: " << h << " hours " << m
     << " minutes " << s << " seconds\n";
}
int main() {
  constexpr std::size_t starting_leaves = 3000;
  std::size_t leafless_tree_time = 0;
  auto simulation_results = simulate(starting_leaves, leafless_tree_time);
  int element = 0;
  display_time(std::cout, leafless_tree_time);
  auto zero_to_three_leaves =
      simulation_results | std::views::filter([](auto &e) { return e < 3; });
  std::cout << "% of 0-3 leaves fallen: "
            << ((float)std::distance(zero_to_three_leaves.begin(),
                                    zero_to_three_leaves.end()) /
                   (float)simulation_results.size())*100
            << "\n";
    auto zero_leaves = zero_to_three_leaves | std::views::filter([](auto& l){return l == 0;});
    std::cout << "Times no leaves has fallen: " << std::distance(zero_leaves.begin(), zero_leaves.end()) << "\n";
    auto windows = simulation_results  | std::views::slide(10);
    int min = -1;
    int min_window;
    int step_number = 0;
    auto res_size = simulation_results.size();
    std::ranges::for_each(windows, [res_size, &min,&step_number, &min_window](std::ranges::viewable_range auto&& w){
        ++step_number;
       int count =  std::accumulate(w.begin(), w.end(), 0);
       if(min < 0 || min > count) {
        min = count;
        min_window = step_number;
       }
    });
    std::cout << "Smallest fallen leaf count is at steps: ";
    std::ranges::for_each(std::views::iota(min_window,min_window+10), [](int i){std::cout << i<< " ";});
    std::cout << "\n";
  return 0;
}
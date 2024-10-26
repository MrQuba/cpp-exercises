#include <iostream>
#include <vector>

int main() {
  const std::vector<bool> diet = {
      1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0,
      1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
      0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1,
      1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1,
      1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1,
      0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0,
      1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0,
      1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0,
      1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0,
      1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1,
      0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0,
      0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0,
      1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0,
      0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1,
      0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1};
    const unsigned int amount_of_days_of_the_diet = diet.size();
  unsigned int successes = 0;
  // five days in a row that were a 0
  unsigned int five_day_streaks_of_dietetic_failure = 0;
  unsigned int current_streak_of_dietetic_failure;
  std::vector<std::vector<bool>::const_iterator>
      days_starting_five_day_streaks_of_dietetic_failure;
  for (auto day = diet.begin(); day != diet.end(); day++) {
    if (*day == 0)
      current_streak_of_dietetic_failure++;
    else if (*day == 1) {
      successes++;
      current_streak_of_dietetic_failure = 0;
    }
    if (current_streak_of_dietetic_failure >= 5) {
      days_starting_five_day_streaks_of_dietetic_failure.push_back(day-current_streak_of_dietetic_failure+1);
    }
  }
  std::cout << "Days of dietetic success: " << successes << std::endl
            << "Streaks of at least five days that were dietetic failure: "
            << five_day_streaks_of_dietetic_failure << std::endl
            << "Days starting streaks of dietetic failure: " << std::endl;
  for (auto day : days_starting_five_day_streaks_of_dietetic_failure) {
    std::cout << amount_of_days_of_the_diet-(diet.end() - day) << " ";
  }
  std::cout << std::endl;
  return 0;
}
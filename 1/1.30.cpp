#include <iostream>

int main() {

  unsigned int weight_from_2_laps_ago = 1;
  unsigned int weight_from_previous_lap = 0;
  unsigned int current_weight = 0;
  const unsigned int amount_of_laps = 13;
  for (auto lap = 1; lap <= amount_of_laps; lap++) {
    current_weight = weight_from_2_laps_ago + weight_from_previous_lap;
    std::swap(weight_from_2_laps_ago, weight_from_previous_lap);
    weight_from_previous_lap = current_weight;
    std::cout << "Weight at lap " << lap << ": " << current_weight << std::endl;
  }

  return 0;
}
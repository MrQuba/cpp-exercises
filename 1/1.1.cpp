#include "../shared/input.hpp"
#include "../shared/vector_utils.hpp"
#include "../shared/display.hpp"
#include <iostream>
#include <vector>
/*
	Take from keyboard three non-negative numbers, find biggest of them.
	Display sum of the rest of numbers n times, where n is biggest number
*/
int main ()
{
	std::vector<unsigned int> numbers;
	Input input;

	const unsigned int iterations = 3;
	input.take_n_times_uint(iterations, numbers);

	std::cout << "[info] user's input:" << numbers;

	const auto iterator= VectorUtils<unsigned int>::find_biggest_number_in_vector(&numbers);

	std::cout << "[info] biggest number is: " << *iterator << "\n";

	numbers.erase(iterator);

	std::cout << "[info] user's input after erasing biggest number:" << numbers;

	const unsigned int sum = VectorUtils<unsigned int>::sum_vector_elements(numbers);

	Display::display_n_times(*iterator, sum, true);
	
	return 0;
}
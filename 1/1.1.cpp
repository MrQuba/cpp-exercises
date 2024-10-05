#include "../shared/input.hpp"
#include "../shared/vector_utils.hpp"
#include <iostream>
#include <vector>
#include <utility>
/*
	Take from keyboard three non-negative numbers, find biggest of them.
	Display sum of the rest of numbers n times, where n is biggest number
*/
int main ()
{
	std::vector<unsigned int> numbers;
	Input* input = new Input();

	const unsigned int iterations = 3;
	input->take_n_times_uint(iterations, numbers);
	delete input;

	std::cout << "[info] user's input:" << numbers;

	const auto pair = VectorUtils<unsigned int>::find_biggest_number_in_vector(&numbers);

	const unsigned int biggestNumber = pair.second;

	std::cout << "[info] biggest number is: " << biggestNumber << "\n";

	std::vector<unsigned int>::iterator it;

	numbers.erase(pair.first);

	std::cout << "[info] user's input after erasing biggest number:" << numbers;

	const unsigned int sum = VectorUtils<unsigned int>::sum_vector_elements(numbers);

	for(int i = biggestNumber; i > 0; i--) {
		std::cout << sum << "\n";
	}
	
	return 0;
}
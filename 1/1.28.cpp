#include "../shared/input.hpp"
#include "../shared/characters.hpp"
#include <cmath>
#include <algorithm>
#include <iostream>
int main(){
    Input* input = new Input();

    const auto condition = [](Input* in, unsigned int& current_amount_of_digits, const unsigned int max_amount_of_digits, std::vector<int>* v){
        if(!Characters::characters.contains(in->as_char())  || (Characters::characters.at(in->as_char()) != type::number && Characters::characters.contains(in->as_char()))) return false;
        v->push_back((in->as_char() - '0'));
        current_amount_of_digits++;
        if(current_amount_of_digits == max_amount_of_digits) return true;
        return false;
    };

    std::vector<int> numbers;
    unsigned int current_digits = 0;

    input->take_until(condition, current_digits, 5, &numbers);

    int iteration = 0;
    int result = 0;
  std::reverse(numbers.begin(), numbers.end());
    for(auto n : numbers){
        result += n * std::pow(10, iteration);
        iteration++;
    }
    std::cout << "Number: " << result << std::endl;
    return 0;
}
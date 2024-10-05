#include <iostream>
#include "../shared/utility.hpp"
#include "../shared/input.hpp"
int main(){

    const unsigned int amount_of_nums = 5;
    unsigned int amount_of_nums_divisible_by_2 = 0;
    Input* input = new Input();
    for(unsigned int i = amount_of_nums; i > 0; i--){
        if(Utility<unsigned int>::is_even(input->take()->as_decimal())){
            amount_of_nums_divisible_by_2++;
        }
    }
    delete  input;
    std::cout << "There is " << amount_of_nums_divisible_by_2 << " numbers divisible by 2 and " 
        << amount_of_nums - amount_of_nums_divisible_by_2 << " numbers that are not \n";
    return 0;
}
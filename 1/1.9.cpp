#include "../shared/input.hpp"
#include "../shared/utility.hpp"
#include <iostream>

int main(){

    Input* input = new Input();

    int number = input->take()->as_decimal();
    delete input;
    if(number < 0) number--;
    else if(number > 0) number++;
    std::cout <<"Number after changes: " << number << " is" << (Utility<int>::is_even(number) ? " " : " not ") << "even" << std::endl;

    return 0;
}
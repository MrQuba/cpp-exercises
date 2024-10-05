#include "../shared/input.hpp"
#include "../shared/utility.hpp"
#include <iostream>
int main()
{
    Input* input = new Input();
    const int number = input->take()->as_decimal();
    delete  input;

    std::cout << number << ((Utility<int>::is_even(number)) ? " is even \n" :  " is not even \n");    

    return 0;
}
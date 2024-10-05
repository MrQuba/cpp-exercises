#include <iostream>
#include "../shared/input.hpp"


int main(){
    Input* input = new Input();
    const char char_to_find = 'x';
    unsigned int amount_of_chars = 0;

    while(true){
        if(input->take("Input char: \n")->as_char() == char_to_find){
            break;
        }
        amount_of_chars++;
    }
    delete input;
    std::cout << "Amount of chars before 'x': " << amount_of_chars << std::endl;
    return 0;
}
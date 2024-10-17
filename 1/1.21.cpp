#include "../shared/input.hpp"
#include <iostream>
#include <limits>

int main(){
    Input* input = new Input();

    const unsigned int amount_of_numbers = 5;
    float previous_number;
    bool growing = true;
    
    previous_number = std::numeric_limits<float>::lowest(); // issue arises when user tries to input lowest float value then sequence will not be marked as growing
    for(int i = amount_of_numbers; i > 0; i--){

        float new_number = input->take()->as_float();

        if(new_number > previous_number){
            previous_number = new_number;
        } else {
            growing = false;
            // break; // <= it is possible to have a break here to terminate loop once we know that they do not create a growing sequence anymore
        }
    }
    
    std::cout << "Numbers" << ((growing) ? " " : " do not ") <<"create a growing sequence. " << std::endl;
    delete input;
    return 0;
}
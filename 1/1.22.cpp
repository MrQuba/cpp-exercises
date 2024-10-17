#include "../shared/input.hpp"
#include <iostream>

int main(){
    Input* input = new Input();

    auto condition = [](Input* in, float* pn){
        const float cn = in->as_float();
        if(cn == *pn) return true;
        else {
            *pn = cn;
            return false;
        }
    };
    float previous_number = 0;
    input->take_until(condition, &previous_number);
    std::cout << "Same number have been inputted twice. Aborting..." << std::endl;
    delete input;
    return 0;
}
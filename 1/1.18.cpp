#include "../shared/input.hpp"

int main(){

    Input* input = new Input();
    input->take_until(
        [](Input* input){
            if(input->as_decimal() == std::clamp(input->as_decimal(), 1, 10)) return true;
            return false;
        }
    );
    delete input;

    return 0;
}
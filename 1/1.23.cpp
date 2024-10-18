#include "../shared/input.hpp"
#include "../shared/log.hpp"
#include <vector>

int main(){
    Input* input = new Input();
    Log log;
    auto condition = [](Input* in, std::vector<int>* v){
        Log log;
        const float cn = in->as_float();
        bool exists = false;
        for(auto a : *v){
            if(a == cn) exists = true;
        }
        if(!exists) v->push_back(cn);
        else log.info("Number already exists in vector");
        if(v->size() == 10) return true;
        else return false;
        };
    std::vector<int> numbers;

    input->take_until(condition, &numbers);

    log.info("Vector has 10 elements \n");

    delete input;
    return 0;
}
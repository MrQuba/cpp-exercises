#include "../shared/input.hpp"
#include "../shared/log.hpp"
#include <vector>

int main(){
    Input* input = new Input();
    Log log;
    auto condition = [](Input* in, std::vector<int>* v){
        const float cn = in->as_decimal();
        v->push_back(cn);
        int pn = in->take()->as_float();
         v->push_back(pn);

        const int res = pn * cn; 
        if(res <= 1000) 
            v->push_back(res);
        else 
            return true;
        return false;
        };
    std::vector<int> numbers;

    input->take_until(condition, &numbers);
    log.info("Two last numbers multiplied are bigger than 1000. ");
    delete input;
    return 0;
}
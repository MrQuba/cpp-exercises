#include "../shared/sequences.hpp"
#include <iostream>
#include <vector>
int main(){
    auto sequence_pattern = [](const std::vector<int>& v, unsigned int* x, const unsigned int n) {
        // y = y - x
        std::vector<int>::const_iterator i = v.begin();
        int y = *i;
        while(*x < n){
            y = y - (*x);
            std::cout << y;
                std::cout << std::endl;
            (*x)++;
        } 
        std::cout << std::endl;
        };
    const std::vector<int> v = {100};
    Sequence* s = new Sequence();
    s->displayNElementsOfSequence(v, 100, sequence_pattern);
    delete s;
    return 0;
}
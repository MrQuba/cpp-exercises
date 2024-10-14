#include "../shared/sequences.hpp"
#include <iostream>
#include <vector>
int main(){
    auto sequence_pattern = [](const std::vector<int>& v, unsigned int* x, const unsigned int n) {
        // 3,1,2,1
        std::vector<int>::const_iterator i = v.begin();
        while(*x < n){
            std::cout << *i  << std::endl;
            if(i + 1 >= v.end()) i = v.begin();
            else  i++;
            (*x)++;
        } 
        std::cout << std::endl;
        };
    const std::vector<int> v = {3,1,2,1};
    Sequence* s = new Sequence();
    s->displayNElementsOfSequence(v, 100, sequence_pattern);
    delete s;
    return 0;
}
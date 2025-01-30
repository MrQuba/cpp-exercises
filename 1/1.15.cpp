#include "../shared/sequences.hpp"
#include <iostream>
#include <vector>
#include <ranges>
int main(){
    auto sequence_pattern = [](const std::vector<int>& v, unsigned int* x, const unsigned int n) {
        // n * cout << n
        std::vector<int>::const_iterator i = v.begin();
        while(*x < n){
            for(int j = (*i); j > 0; j--)
                std::cout << *i << std::endl;
            if(i + 1 >= v.end()) i = v.begin();
            else  i++;
            (*x)++;
        } 
        std::cout << std::endl;
        };
    auto i = std::views::iota(1, 101);
    std::vector<int> v(i.begin(), i .end());
    Sequence* s = new Sequence();
    s->displayNElementsOfSequence(v, 100, sequence_pattern);
    delete s;
    return 0;
}
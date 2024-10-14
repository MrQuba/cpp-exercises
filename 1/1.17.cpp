#include "../shared/sequences.hpp"
#include <iostream>
#include <vector>
#include "../shared/utility.hpp"
int main(){
    auto sequence_pattern = [](const std::vector<int>& v, unsigned int* x, const unsigned int n) {
        // y += 2, m += 1
        std::vector<int>::const_iterator i = v.begin();
        int y = *i;
        i++;
        int m = *i;
        while(*x < n){
            if(Utility<int>::is_even(*x)){
                y += 2;
                std::cout<< y;
            }
            else{
                m += 1;
                std::cout << m;
            }
            std::cout << std::endl;
            (*x)++;
        } 
        };
    const std::vector<int> v = {4, 1};
    Sequence* s = new Sequence();
    s->displayNElementsOfSequence(v, 100, sequence_pattern);
    delete s;
    return 0;
}
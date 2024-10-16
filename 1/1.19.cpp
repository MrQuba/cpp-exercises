#include "../shared/utility.hpp"
#include <iostream>
int main(){
    for(int i = 6; i <= 1000; i+= 6){
        if(Utility<int>::divisibleBy(i, 6)) std::cout << i <<" ";
    }
    std::cout<<std::endl;
    return 0;
}
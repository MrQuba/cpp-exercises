#include "../shared/functions.hpp"
#include <iostream>
int main(){
    int a,x,b;
    std::cin>> a >> x >> b;
    std::cout << Functions<int, double>::linear(a, x, b) << "\n";
    return 0;
}
#include "../shared/functions.hpp"
#include <iostream>
int main(){
    int a,x,b;
    std::cin>> a >> x >> b;
    std::cout << math::functions<int, double>::linear(a, x, b) << "\n";
    return 0;
}
#include <iostream>
#include "../shared/random.hpp"

int main(){
    Random r(20, 30);
    const unsigned int L = r.get_number();
    char c;
    std::cin >> c;
    for(int i{}; i < L; i++) std::cout << c << "\n";
    return 0;
}
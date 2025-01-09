#include <iostream>
#include <cmath>
double itd(const int a, const int b){
    return (double) a + ((double) std::abs(b) / std::pow(10, (int)std::log10(std::abs(b))+1.0));
}

int main(){
    int a, b;
    std::cin >> a >> b;
    std::cout << itd(a, b) << "\n";
    return 0;
}
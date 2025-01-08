#include <cstdlib>
#include <iostream>
#include<cmath>
#include <ctime>

double randd(const unsigned int precision){
    const int d = std::pow(10, precision);
    double r = rand() % d;
    return r / (double)d;
}

int main(){
    srand(time(NULL));
    std::cout << randd(3) << "\n";
    return 0;
}
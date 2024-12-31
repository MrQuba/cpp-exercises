#include <cmath>
#include <iostream>

int main(){
    float a,b,c;
    std::cin >> a >> b >> c;
    float smallest = std::min(std::min(a,b), c);
    float longest = std::max(std::max(a,b), c);
    float mid = (a+b+c) - longest - smallest;
    bool rect = (std::pow(mid,2) + std::pow(smallest,2) == std::pow(longest,2));
    std::cout << "Triangle is " << ((rect) ? "" : "not ") << "rectangular \n";
    return 0;
}
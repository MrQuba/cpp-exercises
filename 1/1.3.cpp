#include "../shared/input.hpp"
#include "../shared/utility.hpp"
#include <iostream>
#include <string>
std::string checkDivisibilityBy3or5(const int number){
    if(Utility<int>::divisibleBy(number, 5) and Utility<int>::divisibleBy(number, 3)) return "both 3 and 5";
    else if(Utility<int>::divisibleBy(number, 5) and not Utility<int>::divisibleBy(number, 3)) return "only 5";
    else if(not Utility<int>::divisibleBy(number, 5) and Utility<int>::divisibleBy(number, 3)) return "only 3";
    return "neither 5 or 3";
}
int main()
{
    Input* input = new Input();
    int number = input->take()->as_decimal();
    
    std::cout << number << " is divisble by " << checkDivisibilityBy3or5(number) << "\n";
    
    return 0;
}
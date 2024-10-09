#include "../shared/numbers.hpp"
#include "../shared/utility.hpp"
int main(){
    auto lambda = [](int x) { 
        if(!Utility<int>::divisibleBy(x, 7))
            return true;
        else
         return false;
        };
    Numbers::displayNumbersInRange(10, 100, lambda, true);
    return 0;
}
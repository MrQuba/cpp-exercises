#include "../shared/numbers.hpp"
#include "../shared/utility.hpp"
int main(){
    auto lambda = [](int x) { 
        if(Utility<int>::divisibleBy(x, 11) && Utility<int>::divisibleBy(x, 5) )
            return false;
        else
         return true;
        };
    Numbers::displayNumbersInRange(1, 120, lambda);
    Numbers::get();
    return 0;
}
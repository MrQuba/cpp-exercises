#include "../shared/numbers.hpp"
int main(){
    auto lambda = [](int x) { 
        if(x == 0)
            return false;
        else
         return true;
        };
    Numbers::displayNumbersInRange(-25, 25, lambda);
    return 0;
}
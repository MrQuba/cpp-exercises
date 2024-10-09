#include "../shared/numbers.hpp"
int main(){
    auto lambda = [](int x) { return true;};
    Numbers::displayNumbersInRange(1, 100, lambda);

    return 0;
}
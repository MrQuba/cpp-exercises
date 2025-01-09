#include <array>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>
#include <numeric>
#include <algorithm>
#include "../shared/random.hpp"

int main(){
    srand(time(NULL));
    constexpr  unsigned int size = 20;
    std::array<double, size> rnumbers; 

    std::generate(rnumbers.begin(), rnumbers.end(), [](){return rng::randd(-1, 1, 3);});

    const double sum = std::accumulate(rnumbers.begin(), rnumbers.end(), 0.0);

    std::cout << "Average of " << size << " numbers from range [-1;1] is: " << sum/(double)size << "\n";
    return 0;
}
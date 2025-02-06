#include "../shared/vector_utils.hpp"
#include <iostream>
#include <ranges>
#include <vector>

int main(){
    auto i = std::views::iota(0, 128);
    const std::vector<int> v(i.begin(), i.end());
    const auto freq = VectorUtils<int>::calculate_frequency(&v);
    const int x = 3;
    std::cout << freq.at(3) << "\n";


    return 0;
}
#include <iostream>
#include <algorithm>
#include <limits>
#include <ranges>
#include "../shared/random.hpp"

int main(){
    Random r(10,100);
    std::vector<int> v(r.get_number());
    r.change_range(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    const auto fill = [&](){
        return r.get_number();
    };
    std::generate(v.begin(), v.end(), fill);
    
    auto modv = v | std::views::transform([](int n) { int a = n; if(a % 2 == 0) a = 0; else a *= -1; return a;});
    v = std::vector(modv.begin(), modv.end());
    std::ranges::reverse(v);

    for(auto i : v) std::cout << i << "\n";
    return 0;
}
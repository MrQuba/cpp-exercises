#include <iostream>
#include <type_traits>
template <typename  A>
requires std::is_arithmetic_v<A>
bool in_range(const A n, const A lb, const A ub){
    return (n >= lb) && (n <= ub);
}

int main(){
    unsigned int sum{};
    char c;
    while(sum < 350){
        std::cin >> c;
        auto n = static_cast<int>(c);
        if(!in_range(n, 48, 57) && !in_range(n, 65, 90) && !in_range(n, 97, 122)) continue;
        sum += n;
        std::cout << sum << "\n";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
int main(){
    constexpr auto n =  std::views::iota(1, 11) | std::views::take(10); 
    std::vector<int> v(n.begin(), n.end());
    std::reverse(v.begin(), v.end());
    while(!v.empty()){
        std::cout << v.back() << " ";
        v.pop_back();
    }
    std::cout << "\n";
    return 0;
}
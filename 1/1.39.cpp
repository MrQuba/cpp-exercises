#include <vector>
#include <iostream>
#include <ranges>
#include <unordered_map>
int main(){
    const std::vector<char> znaki = { 'x','P','Q','4','\n','%','u','@','e',
    'T','B','$', '!',':','"','1','<','d','k','L','$',')','$','B','x',
    'w','q','P','c','X','B','>','?','[','r','x','$', '#','}','|','d','l','n','b','V','!'};
    
    std::unordered_map<char, int> z{};
    const char front = znaki.front();
    const char back = znaki.back();

    for(auto c : znaki){
        if(c != front and c != back)
        z[c]++;
    }
    for(auto [c, q] : z)if(q > 1) std::cout << c << "\n";

    int sum{};
    for(auto i : std::views::iota(1,10)){
        sum += i * z[static_cast<char>(i + '0')];
    }
    std::cout <<"\n"<< sum << "\n";
    return 0;
}
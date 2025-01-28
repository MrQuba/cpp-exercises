#include <iostream>
#include <algorithm>
#include <ranges>
unsigned int a_in_b(const std::string a, const std::string b){
    auto wins = b | std::views::slide(a.size());
    unsigned int c{};
    for(auto w : wins){
        if(std::equal(a.begin(), a.end(),
        w.begin(), w.end())) c++;
    }
    return c;
}

int main()
{
    std::cout << a_in_b("l", "hello") << "\n";
    return 0;
}
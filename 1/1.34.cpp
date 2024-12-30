#include <cctype>
#include <iostream>

int main(){
    unsigned int sum{};
    char c;
    while(sum < 350){
        std::cin >> c;
        if(!std::isalnum(c)) continue;
        sum += c;
        std::cout << sum << "\n";
    }
    return 0;
}
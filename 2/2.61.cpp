#include <iostream>
#include <set>
std::set<std::string > sort_alphebatically(std::string s1, std::string s2){
    return  std::set<std::string>{s1, s2};
}
int main(){
    static constexpr std::string s1 = "abcdef";
    static constexpr std::string s2 = "fedcba";
    for(auto s : sort_alphebatically(s1, s2)) std::cout << s << "\n";
    return 0;
}
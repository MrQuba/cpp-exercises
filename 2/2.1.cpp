#include <iostream>
constexpr bool isvowel(const char c){
    return c == 'a' || c == 'o' || c =='i' || c== 'u' || c =='y' || c =='e';
}
int main(){
    static constexpr std::string name = "name";
    unsigned int count{};
    for(auto c : name) if(isvowel(c)) count++;
    for(int i{}; i < count; i++) std::cout << name << "\n";
    return 0;
}
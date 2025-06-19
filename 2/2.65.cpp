#include <algorithm>
#include <iostream>
#include <iterator>
void convert(std::string n){
    const std::string p = "xo*";
    char ns = n[0];
    while(!n.empty()){
        auto f = std::find_first_of(n.begin()+1, n.end(), p.begin(), p.end());
        auto str = std::string(n.begin()+1, f);
        std::cout << str << " → ";
        std::cout << std::stoi(str, 0, (ns == 'x') ? 16 : (ns == 'o') ? 8 : (ns == '*')? 2 : 10)<< "\n";
        ns = *f;
        n.erase(0, std::distance(n.begin(), f));
    }
}
int main(){
    std::string nums = "xfac8*1101011*1110100xc8x32xff*1010o7311o1212xabcd*101*1*0x1o0xd*11111";
    convert(nums);
    return 0;
}
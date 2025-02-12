#include <algorithm>
#include <iostream>
#include <functional>
constexpr std::string remove_adjacent_pairs(const std::string_view& str, const bool inclusive = true){
    std::string s = std::string(str);
    std::string::iterator it;
     do{
     it = std::adjacent_find(s.begin(), s.end(), std::equal_to<char>());
     if(it != s.end()) s.erase(it, it+((inclusive) ? 2 : 1));
     } while(it != s.end());
     return s;
}

int main(){
    constexpr std::string_view s1{"skfuu12m2111flx"};
    constexpr std::string_view s2{"npq985yy5vnprr8ettemzp9yamppp98tywnmtvb9q8y4nqp948tydlfaaafld"};
    constexpr std::string_view s3{"1abbbbaaccdccdeeddccaeffabcdefa121122"};
    std::cout << "before: " << s1 << ", after: " << remove_adjacent_pairs(s1) << "\n";
    std::cout << "before: " << s2 << ", after: " << remove_adjacent_pairs(s2) << "\n";
    std::cout << "before: " << s3 << ", after: " << remove_adjacent_pairs(s3) << "\n";
    std::cout << "before: " << s1 << ", after: " << remove_adjacent_pairs(s1, false) << "\n";
    std::cout << "before: " << s2 << ", after: " << remove_adjacent_pairs(s2, false) << "\n";
    std::cout << "before: " << s3 << ", after: " << remove_adjacent_pairs(s3, false) << "\n";
    return 0;
}
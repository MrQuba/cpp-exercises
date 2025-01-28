#include <iostream>
#include <algorithm>

bool is_palindrome(std::string s){
    std::string c = s;
    std::reverse(s.begin(), s.end());
    return s == c;
}

int main()
{
    std::cout << is_palindrome("abc") << "\n";
    return 0;
}
#include <iostream>
using ull=unsigned long long;
ull reverse(ull n) {
    int u = 0;
    for (;n > 0; n/=10) {
        u = u * 10 + (n % 10);
    }
    return u;
}
int main(){
     ull n = 9811;
    std::cout <<reverse(n) << "\n";
    return 0;
}
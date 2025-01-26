#include "../shared/random.hpp"
#include <ios>
#include <iostream>
#include <fstream>

int main(){
    Random r(0, 1000);
    std::fstream f("liczby.txt", std::ios_base::out);
    if(!f.good()) return -1;
    r.draw_until([&f](int n){
        if(n % 10 == 0) f << n << "\n";
        return n == 1000;
    });
    f.close();
    return 0;
}
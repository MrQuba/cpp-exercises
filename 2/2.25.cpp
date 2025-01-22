#include <cmath>
#include <iostream>
void double_fractional_part(double& a){
    a = std::trunc(a) + 2*(a-(int)a);
}
int main(){
    double a;
    std::cin >> a;
    double_fractional_part(a); 
    std::cout << a << "\n";
}

#include <iostream>
struct is{
    int a;
    is(int a): a(a) {}
    bool divisible_by(int b) {
        return int(a/b) - ((float) a / (float) b) == 0;
    }
};
int main(){
   std::cout <<  std::boolalpha << is(16).divisible_by(3) << "\n";
   std::cout <<  std::boolalpha << is(16).divisible_by(4) << "\n";
}
#include <array>
#include <iostream>
#include "../shared/random.hpp"
template<size_t s>
void init_array(std::array<int, s>& a, const int rb = -10, const int re = 10){
    Random r(rb,re);
    for(size_t i{}; i < s;i++) a[i] = r.get_number(); 
}
int main(){
    const unsigned int size = 10;
    std::array<int, size> a;
    init_array<size>(a);
    int negative_count{}, even_count{}, positive_count{};
    for(auto i : a){
        if(i < 0) negative_count++;
        else if(i > 0) positive_count++;
        if(i % 2 == 0) even_count++;
    }
    std::cout << "There is: " << negative_count << " negative numbers, " << positive_count<< " positive numbers. \n"
    << even_count <<" even numbers and " << size-even_count << " uneven numbers.\n";  
    return 0;
}
#include <vector>
#include <iostream>
#include "../shared/sequences.hpp"
#include "../shared/vector_utils.hpp"

int main(){
     std::vector<int> v = {1, 2, 4, 3, 6, 8, 7, 7, 8, 3, 4, 5, 6, 7, 1, 3, 9, 1, 0, 4, 2, 3, 6, 9};

    auto not_decreasing =[](std::vector<int>::iterator begin, std::vector<int>::iterator end){
        if (begin == end) return false;
        std::vector<int>::iterator it = begin;
        int prev = *it;
        ++it;
        while(it != end){
            if(*it >= prev) {
                prev = *it;
                it++;
                continue;
            }
            return false;
        }
        return true;
    };
    auto vv = Sequence::find_all_n_element_subsequences(&v, 3, not_decreasing);
    std::cout << "All 3 elements not decreasing sequences: " << std::endl;
    for(auto a: vv){
        std::cout << a << std::endl;
    }
    auto ls = Sequence::find_longest_sequence(&v, not_decreasing);
    std::cout << "Longest not decreasing sequence: " << ls << std::endl;
    auto f = VectorUtils<int>::calculate_frequency(&v);
    std::cout << "Frequencies of each number in vector: " << std::endl;
    for(auto a : f){
        std::cout << a.first << ": " << a.second << std::endl;
    }
    return 0;
}
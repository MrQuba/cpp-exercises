#include <iostream>
#include "concepts.hpp"
class Display{
    public:
        template<displayable D>
        constexpr static void display_n_times(const unsigned int n, D content, const bool nline){
            for(unsigned int i = 0; i < n; i++){
                std::cout << content << ((nline) ? "\n" : " ");
            }
        }
};
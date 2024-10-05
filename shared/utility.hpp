#include "concepts.hpp"
template<Arithmetic T>
class Utility{
    public:
        static bool is_even(const T number) {
            return (divisibleBy(number, 2)) ? true : false;
        }
        static bool divisibleBy(const T number, const T divider){
            if(number % divider == 0) return true;
            else return false; 
}
};
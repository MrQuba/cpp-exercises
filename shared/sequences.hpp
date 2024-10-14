#include <vector>
#include "concepts.hpp"
class Sequence{
    public:
        Sequence(){}
        template<Invocable_Sequence F>
        void displayNElementsOfSequence(const std::vector<int>& sequence, const unsigned int n, F sequence_pattern){
            unsigned int i = 0;
            while(i < n){
                sequence_pattern(sequence, &i, n);
                i++;
            }
        }
        ~Sequence(){}  
    private:
};
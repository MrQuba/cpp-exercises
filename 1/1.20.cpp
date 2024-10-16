#include "../shared/vector_utils.hpp"
#include "../shared/utility.hpp"
#include <iostream>
#include <vector>

int main(){
    const std::vector<int> base = VectorUtils<int>::generate_random_vector(10, 1, 100);
    std::vector<int> uneven;
    std::vector<int> even;
    for(auto it = base.begin() = base.begin(); it < base.end(); it++){
        if(Utility<int>::is_even(*it)) even.push_back(*it);
        else uneven.push_back(*it);
    }
    VectorUtils<int>::add_vector_at_the_end_of_other(&even, &uneven);
    std::cout << "Base vector: " << base << "Vector after transformations: " << even;
    return 0;
}
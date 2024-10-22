#include <iostream>
#include <vector>
#include "../shared/vector_utils.hpp"
int main(){
    std::vector<int >v1={1,3,5,7,9}, v2={1,4,7,11,15}, v3={1,2,3,4,5,6,7,8,9,20};
    std::cout <<  "Common part (elements that are in both vectors) of vectors v1 and v2 is: " << VectorUtils<int>::common_part_of_vectors(&v1, &v2) << std::endl;
    
    std::vector<int> sum_of_v1_v2;
    sum_of_v1_v2 += v1 + v2;

    std::cout << "Sum (all elements of vectors without repetitions) of all vectors is: " << sum_of_v1_v2 + v3 << std::endl;
    std::cout << "Difference (elements that exist only in one) of vectors is: " << v3 - sum_of_v1_v2 << std::endl;
    return 0;
}
#include <sys/types.h>
#include <vector>
#include <iostream>
int main(){
    std::vector<int> x = { 2,7,1,1,4,9,3,2,1,4,1,9,6,1,3,0,1,2,3,6,8,5,6,9,
    3,0,8,1,8,8,7,0,7,8,5,0,2,2,3,7,1,7,2,4,7,7,5,9,0,7,7,9,2,2,2,7,
    0,0,5,4,6,3,9,3,5,1,0,0,9,2,9,2,8,5,0,8,5,7,0,9,6,4,9,7,8,8,6,5,
    4,3,2,5,8,9,4,6,8,7,9,9 };
    u_int distance = 0;
    bool nine = false;
    for(auto i = x.begin(); i != x.end(); i++){
        if(!nine && *i == 9){
            nine = true;
            distance = 0;
        }
        else if (nine && *i == 9){
            std::cout << distance-1 << "\n";
            distance = 0;
        }
        distance++;
    }   
    return 0;
}
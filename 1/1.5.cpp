#include <iostream>
#include <string>
#include "../shared/input.hpp"
#include "../shared/log.hpp"
int main()
{   
    Log log;
    Input input;
    float numbers[5];
    log.info("Taking input...");
    for(unsigned int i = 0; i < 5; i++){
        numbers[i] = input.take()->as_float();
    }
    log.info("Checking corectness...");
    if(numbers[4] == 0) {
        log.error("Dividing by 0, aborting...");
        return -1;
    }
    log.info("Calculating result...");
    float result = (((numbers[0] + numbers[1]) * numbers[2]) - numbers[3]) / numbers[4];
    std::cout << "Result is: " << result << "\n";
    return 0;
}
#include <utility>
#include "../shared/input.hpp"
#include "../shared/log.hpp"

std::pair<float, float> add(const float a, const float b){
    return std::make_pair(a + b, b + a);
}
std::pair<float, float> multiply(const float a, const float b){
    return std::make_pair(a * b, b * a);
}
std::pair<float, float> divide(const float a, const float b){
    return std::make_pair(a / b, b / a);
}
std::pair<float, float> subtract(const float a, const float b){
    return std::make_pair(a - b, b - a);
}


int main(){
    Input* input = new Input();
    Log log;
    const std::pair<float, float> numbers = std::make_pair(input->take()->as_float(), input->take()->as_float());
    const char sign_of_operation = input->take("Input sign of operation(+,-,*,/): \n")->as_char();
    std::pair<float, float> result;
    switch(sign_of_operation){
        case '+':
            result = add(numbers.first, numbers.second);
            break;
        case '-':
            result = subtract(numbers.first, numbers.second);
            break;
        case '*':
            result = multiply(numbers.first, numbers.second);
            break;
        case '/':
            if(numbers.first == 0 || numbers.second == 0){
                log.error("Cannot divide by 0. Aborting...");
                return -1;
            }
            result = divide(numbers.first, numbers.second);
            break;
        default:
            log.error("Wrong operation sign. Aborting...");
            return -1;
    }
    if(result.first == result.second)
        std::cout << "Result is: " << result.first << std::endl;
    else 
        std::cout << "Results are: " << result.first << " and " << result.second << std::endl;

    return 0;
}
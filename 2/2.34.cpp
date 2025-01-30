#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include "../shared/files.hpp"
#include "../shared/vector_utils.hpp"
int main(){
    std::string s;
    std::fstream f("34_dane.txt", std::ios_base::in);
    std::cout  << Files<int>::ExtractNumbers(f) << "\n";

    return 0;
}

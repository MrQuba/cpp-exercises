#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include "../shared/files.hpp"
#include "../shared/vector_utils.hpp"
int main(){
    std::string s;
    std::fstream f("33_dane.txt", std::ios_base::in);
    std::cout << Files<int>::ExtractNumbers(f) << "\n";

    return 0;
}
/*
    while(std::getline(f, s)){
        if(s.empty()) continue;
        auto i = s.find_first_of(';') ;
        int a = std::stoi(std::string(s.begin(), s.begin()+i));
        int b = std::stoi(std::string(s.begin()+i+1, s.end()));
        std::cout << a << ";" << b << "\n";
    }
*/
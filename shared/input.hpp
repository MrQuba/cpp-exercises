#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

class Input {
public:
	Input(std::string s) : input(s) {}
	Input() : input("") {}

	Input* take(const std::string textToDisplay = "Input number:  \n") {
		std::cout << textToDisplay;
		std::cin >> input;
		return this;
	}
    float as_float() const{
        return std::stof(input);
    }
	int as_decimal() const {
		return std::stoi(input);
	}
	Input* tolower() {
		// str_tolower comes from here https://en.cppreference.com/w/cpp/string/byte/tolower
    	std::transform(input.begin(), input.end(), input.begin(),
        [](unsigned char c){ return std::tolower(c); }
         );
		return this;
	}
	char as_char() const {
		return input[0];
	}
	void display() const {
		std::cout << input << std::endl;
	}
	std::string get() const {
		return input;
	}
	std::vector<unsigned int> take_n_times_uint(const unsigned int n, std::vector<unsigned int>& numbers) {
		for(int i = n; i > 0; i--)
			numbers.push_back(std::abs(this->take("Input number: \n")->as_decimal()));
		return numbers;
	}
	Input* take_until(std::invocable<Input*> auto && condition, const std::string text = "Input number:  \n"){
		while(true){
			this->take(text);
			if(condition(this)) break;
		}
		return this;
	}
private:
	std::string input;

};
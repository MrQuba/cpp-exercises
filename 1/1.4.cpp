#include <iostream>
#include <cctype>
#include "../shared/characters.hpp"
#include "../shared/input.hpp"
/*
	Take a character from keyboard, check if it is vowel, consonant or a number.
	Include only small english characters and numbers
*/
int main()
{
	Input* input = new Input();
	const char char_to_check = input->take("Input character: \n")->tolower()->as_char();
	delete input;
	if(Characters::characters.find(char_to_check) == Characters::characters.end()) std::cout << char_to_check << " is not a valid character \n";
	else std::cout << char_to_check << " is " << Characters::type_map.at(Characters::characters.at(char_to_check)) << std::endl;

	return 0;
}
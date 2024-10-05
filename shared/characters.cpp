#include "characters.hpp"

const std::unordered_map<char, type> Characters::characters= {
		{'a', type::vowel},
		{'b', type::consonant},
		{'c', type::consonant},
		{'d', type::consonant},
		{'e', type::vowel},
		{'f', type::consonant},
		{'g', type::consonant},
		{'h', type::consonant},
		{'i', type::vowel},
		{'j', type::consonant},
		{'k', type::consonant},
		{'l', type::consonant},
		{'m', type::consonant},
		{'n', type::consonant},
		{'o', type::vowel},
		{'p', type::consonant},
		{'q', type::consonant},
		{'r', type::consonant},
		{'s', type::consonant},
		{'t', type::consonant},
		{'u', type::vowel},
		{'v', type::consonant},
		{'w', type::consonant},
		{'y', type::consonant},
		{'z', type::consonant},
		{'1', type::number},
		{'2', type::number},
		{'3', type::number},
		{'4', type::number},
		{'5', type::number},
		{'6', type::number},
		{'7', type::number},
		{'8', type::number},
		{'9', type::number},
		{'0', type::number}
	};
const std::unordered_map<type, std::string> Characters::type_map = {
		{type::vowel, "vowel"},
		{type::consonant, "consonant"},
		{type::number, "number"}
	};
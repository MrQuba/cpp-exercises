#include <string>
#include <unordered_map>

enum class type {
	vowel,
	consonant,
	number
    };
class Characters{
    public:
	static const std::unordered_map<char, type> characters; 
	static const std::unordered_map<type, std::string> type_map;
};
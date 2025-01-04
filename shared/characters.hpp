#include <array>
#include <string>
#include <unordered_map>
#include <ranges>

enum class type { vowel, consonant, number };
class Characters {
public:
  static const std::unordered_map<char, type> characters;
  static const std::unordered_map<type, std::string> type_map;
  static constexpr auto letter_gen = []() {
    std::array<char, 52> array;
    for (auto l : std::views::iota(0, 26)){
      array[l] = static_cast<char>('A' + l);
      array[l + 26] = static_cast<char>('a' + l);
	}
    return array;
  };
  static constexpr std::array<char, 52> letters = letter_gen();
};
#include <bitset>
#include <iostream>
template <std::size_t s> bool is_bit_palindrom(std::bitset<s> &&b) {
    auto sb = b.to_string();
  return b == std::bitset<s>{std::string{sb.rbegin(), sb.rend()}};
}
int main() {
  std::cout << is_bit_palindrom(std::bitset<8>{0b11100111}) << "\n";             // tak
  std::cout << is_bit_palindrom(std::bitset<8>{0b01100110}) << "\n";             // tak
  std::cout << is_bit_palindrom(std::bitset<8>{0b10011001}) << "\n";             // tak
  std::cout << is_bit_palindrom(std::bitset<8>{0b10011111}) << "\n";             // nie
  std::cout << is_bit_palindrom(std::bitset<8>{0b10111001}) << "\n";             // nie
  std::cout << is_bit_palindrom(std::bitset<8>{0b01111111}) << "\n";             // nie
  std::cout << is_bit_palindrom(std::bitset<16>{0b1110011111100111}) << "\n"; // tak
  std::cout << is_bit_palindrom(std::bitset<16>{0b0110011001100110}) << "\n"; // tak
  std::cout << is_bit_palindrom(std::bitset<16>{0b1001100110011001}) << "\n"; // tak
  std::cout << is_bit_palindrom(std::bitset<16>{0b1001111110111111}) << "\n"; // nie
  std::cout << is_bit_palindrom(std::bitset<16>{0b1011100110011111}) << "\n"; // nie
  std::cout << is_bit_palindrom(std::bitset<16>{0b0111111110011111}) << "\n"; // nie
}
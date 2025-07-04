#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <string>
std::string not_s(const std::string &input) {
  auto n = input | std::views::transform(
                       [](char c) { return ((c == '0') ? '1' : '0'); });
  return std::string{n.begin(), n.end()};
}
bool are_nots(const std::string& l, const std::string& r){
  return (l.size() != r.size()) ? false : l == not_s(r);
}
char add(const char l, const char r, const char c, std::string &res) {
  if (l + r + c == '0' + (2 * '1') || l + r + c == 3 * '0') {
    res.push_back('0');
    return (l + r + c == 3 * '0') ? '0' : '1';
  }
  res.push_back('1');
  return (l + r + c == 3 * '1') ? '1' : '0';
}
char add(const char l, const char r, std::string &res) {
  if (l + r != '0' + '1')
    res.push_back('0');
  else
    res.push_back('1');
  return (l + r == 2 * '1') ? '1' : '0';
}
std::string add(const std::string &l, const std::string &r) {
  std::string result;
  result.reserve(std::max(l.size(), r.size()) + 1);
  using iterator = std::string::const_iterator;
  const std::string *shorter = (l.size() > r.size()) ? &r : &l;
  const std::string *longer = (l.size() > r.size()) ? &l : &r;
  iterator it = (l.size() > r.size()) ? r.begin() : l.begin();
  char carry = '0';
  for (; it != shorter->end(); it++) 
    carry =
        add(*it, (*longer)[std::distance(shorter->begin(), it)], carry, result);

  if (longer->size() != shorter->size()) {
    const std::string rest = std::string{
        longer->begin() + std::distance(shorter->begin(), it), longer->end()};
    iterator it_rest = rest.begin();
    for (; it_rest != rest.end(); it_rest++) {
      carry = add(*it_rest, carry, result);
    }
  }
  if (carry != '0')
    result.push_back(carry);
  return std::string{result.rbegin(), result.rend()};
}
const std::string& greater_string(const std::string& l, const std::string& r){
  if(l.size() != r.size()) return (l.size() > r.size()) ? l : r;
  else if(l == r) return l;
  using iterator = std::string::const_iterator;
  iterator lit = l.begin();
  iterator rit = r.begin();
  char lc='\0', rc = '\0';
  while (lc == rc) {
    lc = *lit;
    rc = *rit;
    ++lit; ++rit;
  }
  return (lc > rc) ? l : r;
}
int main() {
  std::cout << add("00101010111111", "0001111111") << "\n" << "\n";
  std::cout << add("111", "1") << "\n" << "\n";
  std::cout << are_nots("10101", "01010") << "\n\n";
  std::cout << are_nots("111000", "000111") << "\n\n";
  std::cout << are_nots("111000", "111111") << "\n\n";
  std::cout << greater_string("111", "1000") << "\n";
  std::cout << greater_string("111", "111") << "\n";
  std::cout << greater_string("10111", "10011") << "\n";
  return 0;
}
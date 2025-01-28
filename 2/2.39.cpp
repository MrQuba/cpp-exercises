#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>

using l = long long int;
bool is_convertible(const std::string s) {
	return std::all_of(s.begin(), s.end(), ::isdigit) ||
	((s[0] == '-') && std::all_of(s.begin()+1, s.end(), ::isdigit));
}
l stol(const std::string s) {
	if(!is_convertible(s)) return std::numeric_limits<l>::min();
	l a{};
	l d = 0;
	bool n = false;
	for(auto c : std::string(s.rbegin(), s.rend())) {
	    if(c == '-') {
	        n = true;
	        continue;
	    }
		a += (c-'0') * std::pow(10, d);
		d++;
	}
	return -a;
}



int main()
{
	std::cout << stol("-1234") << "\n";
	return 0;
}
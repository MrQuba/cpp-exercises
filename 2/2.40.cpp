#include <iostream>
#include <algorithm>
#include <cmath>

std::string itos (const int i) {
	int a = i;
	std::string r = "";
	bool n =  false;
	if(a < 0) {
		n = true;
		a *= -1;
	}
	while(a > 0) {
		float f = ( float(a / 10.f) - int(a/10)) * 10.f;
		a /= 10;
		r += char(f + '0');
	}
	if(n)
		r.push_back('-');
	std::reverse(r.begin(), r.end());
	return r;
}

int main()
{
	std::cout << itos(-123) << "\n";
	return 0;
}
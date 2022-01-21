#include <iostream>
#include <cmath>

int main()
{
	double r, p, q, h;
	std::cout << "Please, enter R, P and Q(radians): ";
	std::cin >> r >> p >> q;
	h = p * sin(q) / 2;
	if (h >= r) {
		std::cout << "It pass";
	}
	else {
		std::cout << "It not pass";
	}
	return 0;
}
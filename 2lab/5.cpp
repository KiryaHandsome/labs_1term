#include <iostream>

int main()
{
	double a, b, c, d, Z;
	std::cout << "Enter 4 naumbers: ";
	std::cin >> a >> b >> c >> d ;
	if (c >= d && a < d) {
		Z = a + b / c;
	}
	else if (c < d && a >= d) {
		Z = a - b / c;
	}
	else {
		Z = 0;
	}
	std::cout << Z;
	return 0;
}
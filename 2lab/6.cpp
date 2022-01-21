#include <iostream>

int main()
{
	double a, b, c, Y;
	int N;
	std::cout << "Enter 4 numbers: ";
	std::cin >> a >> b >> c >> N;
	switch (N) {

	
		case 2:
			Y = b * c - a * a;
		case 56:
			Y = b * c;
		case 7:
			Y = a * a + c;
		case 3:
			Y = a - b * c;
		default:
			Y = (a + b) * (a + b) * (a + b);
	}
	std::cout << Y;
	return 0;
}
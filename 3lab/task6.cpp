#include <iostream>
#include <cmath>

int main()
{
	double x, y;
	std::cout << "Function f(x) = lg(cosh(x)) - tanh(x) + 0.5, 0 <= x <=2 \n";
	std::cout << "Enter number of parts searching for x (x > 1):\n";
	double parts, min;
	std::cin >> parts;
	min = 5; //random number
	if (parts > 1) {
		double step = 2 / (parts - 1); //step
		for (x = 0; x <= 2; x += step) {
			y = fabs(log10(cosh(x)) - tanh(x) + 0.5);
			if (y < min) {
				min = y;
			}
		}
		for (x = 0; x <= 2; x += step) {
			y = fabs(log10(cosh(x)) - tanh(x) + 0.5);
			if (y == min) {
				std::cout << x << " - root at which the minimum value of the function is reached";
			}
		}
	}
	else {
		std::cout << "invalid input";
	}
	return 0;
}
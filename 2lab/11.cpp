#include <iostream>

int main()
{
	double a, Sa, r, Sr, Pi;
	std::cout << "Please, enter side a and radius r: ";
	std::cin >> a >> r;
	Pi = 3.14159265358979323846;
	Sa = a * a;
	Sr = Pi * r * r;
	if (Sa < Sr) {
		std::cout << "Circle with radius " << r << " has a more area than a square with side " << a;
	}
	else if (Sa == Sr) {
		std::cout << "Circle with radius " << r << " has the same area as a square with side " << a;
	}
	else {
		std::cout << "Square with side " << a << " has a more area than circle with radius " << r;
	}
	return 0;
}
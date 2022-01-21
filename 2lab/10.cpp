#include <iostream>
#include <iomanip>

int main()
{
	double  sinus, cosinus, ln, x, component;
	component = 1;
	std::cout << "Please, enter x: " << std::endl;
	std::cin >> x;
	sinus = sin(x);
	cosinus = cos(x);
	(x < 0 ? x = -x : x = x );
	if (x < 1.285 && x > 1) {
		x = x - 1;
		ln = x;
		component = x;
		for (int i = 2; i < 10; i++) {
			component = component * x * (-1) / i;
			ln += component;
		}
	}
	else if (x < 1) {
		x = x - 1;
		ln = x;
		ln = x - x * x / 2 + x * x * x / 3 - x * x * x * x / 4 + x * x * x * x * x / 5;
	}
	else {
		ln = 10; //random big number
	}
	double minimum;
	if (sinus < cosinus) {
		if (sinus < ln) {
			minimum = sinus;
			std::cout << "minimum=sin" << std::endl;
		}
		else {
			minimum = ln;
			std::cout << "minimum=ln" << std::endl;
		}
	}
	else if (cosinus < ln) {
		minimum = cosinus;
		std::cout << "minimum=cos" << std::endl;
	}
	else {
		minimum = ln;
		std::cout << "minimum=ln" << std::endl;
	}
	std::cout <<std::setprecision(2)<< "minimum=" << minimum;
	return 0;
}
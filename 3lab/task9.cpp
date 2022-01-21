#include <iostream>
#include <cmath>


int main()
{
	double a, sum;
	sum = 0;
	std::cout << "Enter numbers(a1, a2, ..., a(n-1)) to calculate range:a0-2*a1+4*a2-8*a3+...+(2^(n-1))*((-1)^(n-1))*a(n-1)\n";
	std::cout << "If you want stop - enter any letter\n";
	for (int i = 1; i != 0; i++) {
		std::cin >> a;
		sum += a * pow(-2, i - 1);
		if (std::cin.fail()) {
			i = 0;
			break;
		}
	}
	std::cout << sum;
	return 0;
}
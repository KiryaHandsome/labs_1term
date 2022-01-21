#include <iostream>
#include <cmath>

int main()
{
	double x, p, q, d;
	std::cout << "Please, enter p and q: \n";
	std::cin >> p >> q;
	double Q = sqrt(pow(q / 2, 2) + pow(p / 3, 3));
	if (pow(q / 2, 2) + pow(p / 3, 3) < 0) {
		std::cout << "error";
		return 0;
	}
	double st = 1.0/3.0;
	double sl = -q / 2;
	double z1 = pow(sl + Q,st);
	double z2 = pow(sl - Q,st);
	if (sl+Q < 0) {
		z1 = -pow(-sl-Q,st);	
	}
	if (sl-Q < 0) {
		z2 = -pow(Q - sl,st);
	}
	x = z1 + z2;
	std::cout << "x=" << x;
	return 0;
}
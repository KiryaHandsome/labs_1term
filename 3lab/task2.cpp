#include <iostream>

int main()
{
	double sum, n;
	n = 1;
	sum = 0;
	do {
		sum += 1 / (pow(2, n)) + 1 / (pow(3, n));
		n++;
	} while (1 / pow(2, n) + 1 / pow(3, n) > 0.001);
	std::cout << sum << "-sum of range: d ( n ) = 1 / ( 2 ^ n ) + 1 / ( 3 ^ n ) with precision 0.001 ";
	return 0;
}
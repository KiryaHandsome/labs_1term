#include <iostream>

int main()
{
	double x, y, z;
	std::cin >> x >> y >> z;
	if (x + y > z && x + z > y && y + z > x) {
		std::cout << "Triangle with this sides existent";
	}
	else {
		std::cout << "Triangle with this sides nonexistent";
	}
	return 0;
}
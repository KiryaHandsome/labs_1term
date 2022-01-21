#include <iostream>

int main()
{
    double x, y;
    std::cout << "Please, enter 2 numbers: ";
    std::cin >> x >> y;
    bool b1;
    x < y ? b1 = true : b1 = false;
    b1 == 1 ? std::cout<< y : std::cout << x;
    return 0;
}


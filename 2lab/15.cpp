#include <iostream>


int main()
{
    double k, z;
    std::cout << "Enter number of mushrooms: ";
    std::cin >> k;
    if (k < 0) {
        std::cout << "Negative mushrooms?Seriosly?";
    }
    else {
        std::cout << "we found " << k << "mushrooms";
    }
    std::cout << z;
    return 0;
}


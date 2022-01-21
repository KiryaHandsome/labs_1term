#include <iostream>

int main()
{
    setlocale(0, "");
    int x, y;
    std::cout << "Please, enter 2 numbers: ";
    std::cin >> x >> y;
    if (x > y) {
        if (x % y == 0) {
            std::cout << x << " divided by " << y ;
        }
        else {
            std::cout << x << " not divided by " << y ;
        }
    }
    else {
        if (y % x == 0) {
            std::cout << y << " divided by " << x ;
        }
        else {
            std::cout << y << " not divided " << x ;
        }
    }
    return 0;
}

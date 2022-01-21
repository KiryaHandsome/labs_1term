#include <iostream>

int main()
{
    int x, y;
    std::cout << "Please, enter 2 numbers: "<<std::endl;
    std::cin >> x >> y;
    if (x < y) {
        x = 0;
    }
    else if (x == y) {
        x = 0;
        y = 0;
    }
    else {
        y = 0;
    }
    std::cout << x << " " << y << std::endl;

    double a, b, c, k;
    std::cout << "Enter a, b, c, k: "<<std::endl;
    std::cin >> a >> b >> c >> k;

    double max;
    if (a == b && b == c) {
        max = a; //random
        std::cout << "All numbers are equal"<<std::endl;
    }
    else if (a > b) {
        if (a > c) {
            max = a;
        }
        else {
            max = c;
        }
    }
    else if (b > c) {
        max = b;
    }
    else {
        max = c;
    }
    max -=k;
    std::cout << "max - k = " << max;
    return 0;
}
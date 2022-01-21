#include <iostream>

int main()
{
    double a, b, c, x, y;
    std::cout << "Please, enter a, b, c: ";
    std::cin >> a >> b >> c;
    std::cout << "Please, enter x, y: ";
    std::cin >> x >> y;
    double x1, y1;
    if (a > b) {
        if (a > c) {
            x1 = b;
            y1 = c;
        }
        else {
            x1 = b;
            y1 = a;
        }
    }
    else {
        if (b > c) {
            x1 = a;
            y1 = c;
        }
        else {
            x1 = a;
            y1 = b;
        }
    }
    if (x1 <= x && y1 <= y) {
            std::cout << "Brick can get through rectangle.";
    }
    else if (x1 <= y && y1 <= x) {
        std::cout << "Brick can get through rectangle.";
    }
    else {
        std::cout << "Brick cannot get through rectangle.";
    }
    return 0;
}


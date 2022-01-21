#include <iostream>
#include <cmath>

int main()
{
    double a, b, c, d;
    std::cout << "Enter 3 numbers: ";
    std::cin >> a >> b >> c;
    d = pow(b, 2) - 4 * a * c; //дискриминант
    double t1, t2, x1, x2, x3, x4;
    if (d < 0) {
        std::cout << "Discriminant less than 0. No solutions.";
    }
    else if (d == 0) {
        t1= - b / (2 * a);
        if (t1 < 0) {
            std::cout << "No solutions.";
        }
        else {
            x1 = sqrt(t1);
            x2 = -sqrt(t1);
            std::cout << x1 << " " << x2;
        }
    }
    else {
        t1 = (-b - sqrt(d)) / (2 * a);
        t2 = (-b + sqrt(d)) / (2 * a);
        if (t1 >= 0) {
            x1 = sqrt(t1);
            x2 = -sqrt(t1);
            std::cout << x1 << " " << x2 <<std::endl;
        }
        if (t2 >= 0) {
            x3 = sqrt(t2);
            x4 = -sqrt(t2);
            std::cout << x3 << " " << x4;
        }
    }
    return 0;
}

#include <iostream>
#include <cmath>


int main()
{
    double a, b, c, x1, x2, x3, x4;
    std::cout << "Enter 3 numbers: ";
    std::cin >> a >> b >> c;
    double d1 = pow(b, 2) - 4 * (c - 2 * a)*a; //дискриминант
    if (d1 < 0) {
        std::cout << "No solutions.";
    }
    else {
        double d21 = pow(((b + sqrt(d1)) / (2 * a)),2) - 4;
        if (d21 < 0) {

        }
        else {
            x1 = (-(b + sqrt(d1)) / (2 * a) - sqrt(d21)) / 2;
            x2 = (-(b + sqrt(d1)) / (2 * a) + sqrt(d21)) / 2;
            std::cout << "x1 " << x1 << " " <<"x2 " << x2 << std::endl;
        }
        double d22 = pow((b - sqrt(d1)) / (2 * a), 2) - 4;
        if (d22 < 0) {
            
        }
        else {
            x3 = (-(b - sqrt(d1)) / (2 * a) - sqrt(d22)) / 2;
            x4 = (-(b - sqrt(d1)) / (2 * a) + sqrt(d22)) / 2;
            std::cout << "x3 " << x3 << " " <<"x4 " << x4;
        }
    }
    return 0;
    
}


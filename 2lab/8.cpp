#include <iostream>
#include <cmath>

int main()
{
    double a, b, z, y, x;
    int N;
    std::cout << "Enter a, b, z, N:" << std::endl << "1)x=2*x" << std::endl << "2)x=x^3" << std::endl << "3)x = x / 3" << std::endl;
    std::cin >> a >> b >> z >> N ;
    if (z <= 0) {
        x = z * z / 2;
        std::cout << "x = z * z / 2" << std::endl;
    }
    else {
        x = sqrt(z);
        std::cout << "x = sqrt(z)"<<std::endl;
    }
    switch (N) {
    case 1:
        x = 2 * x;
        std::cout << "x = 2 * x" << std::endl;
        break;
    case 2:
        x = pow(x, 3);
        std::cout << "x = x^3" << std::endl;
        break;
    case 3:
        x = x / 3;
        std::cout << "x = x/3" << std::endl;
        break;
    }
    double t = cos(x);
    if (t == 0) {
        std::cout << "Error";
    }
    y = b * x / t + a * log(fabs(tan(x / 2)));
    std::cout << y;
    return 0;
}


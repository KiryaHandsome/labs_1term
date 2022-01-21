#include <iostream>
#include <cmath>

constexpr auto M_PI = 3.141592;

int main()
{
    double A, B, M, H, y, x;
    A = 0;
    B = M_PI / 2;
    M = 20;
    H = (B - A) / M;
    x = 0;
    std::cout << "y = sin( x ) - cos( x ),\nA <= x <= B;\nx = A + i * H;\nH = (B - A)/M;\nM = 20;\nA = 0;\nB = PI / 2;\n";
    for (int i = 1; x <= B; i++) {
        x = A + i * H;
        y = sin(x) - cos(x);
        std::cout <<"i = "<< i <<"; y = " << y << std::endl;
    }
    return 0;
}
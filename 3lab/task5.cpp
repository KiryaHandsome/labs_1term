#include <iostream>
#include <cmath>

const double e = 2.718281828;
int main()
{
    double x, sum, y;
    double n;
    std::cout << "1+2*(x/2)+...+(n^2+1)*(x/2)^n/n!\nEnter n (n - integer, n > 0) and x (0.1 < x < 1):\n";
    std::cin >> n >> x;
    sum = 1;
    if (n > 0 && x > 0.1 && x < 1) {
        if (n == 0) {
            sum = 0;
        }
        else if (n == 1) {
                sum = 1;
        }
        else {
            double comp1, comp2, comp3;
            comp1 = 1;
            comp2 = 1;
            comp3 = 1;
            for (double i = 1; i < n; i++) {
                comp1 = i * i + 1;
                comp2 *= x / 2;
                comp3 *= 1 / i;
                sum += comp1 * comp2 * comp3;
            }
        }
        y = (x * x / 4 + x / 2 + 1) * pow(e, x / 2);
        std::cout << sum << "-sum with range\n";
        std::cout << y << "-sum without range";
        return 0;
    }
    else {
        std::cout << "Invalid input\n";
    }
    return 0;
}

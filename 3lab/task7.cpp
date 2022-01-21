#include <iostream>
#include <cmath>

int main()
{
    for (int number = 10; number < 100; number++) {
        int a = number / 10;
        int b = number % 10;
        int c = pow(a + b, 3);
        int d = pow(number, 2);
        if (c == d) {
            std::cout << number <<"-number cube the sum of its digits equals the square of the number itself.";
        }
    }
    return 0;
}

#include <iostream>
#include <cmath>


int main()
{
    std::cout << "Armstrong numbers(narcissistic numbers)-numbers that are equal to the sum of cubes of its digits.\n";
    std::cout << "Armstrong numbers before 10^6:\n";
    int  number = 153;
    int sum;
    do {
        int a, b, c, d, e, f, z;
        a = number % 10;
        z = number / 10;
        b = z % 10;
        z = z / 10;
        c = z % 10;
        z = z / 10;
        d = z % 10;
        z = z / 10;
        e = z % 10;
        z = z / 10;
        f = z % 10;
        sum = pow(a, 6) + pow(b, 6) + pow(c, 6) + pow(d, 6) + pow(e, 6) + pow(f, 6);
        if (sum == number) {
            std::cout << number << std::endl;
        }
        number++;
    } while (number < 1000000);
    return 0;
}

#include <iostream>
#include <cmath>

int main()
{
    int i, N;
    i = 1;
    N = 0;
    int a, b;
    while (i < 31) {
        if (i % 2 == 0) {
            a = i / 2;
            b = pow(i, 3);
        }
        else {
            a = i;
            b = pow(i, 2);
        }
        N += pow(a - b, 2);
        i++;
    }
    std::cout << N << "-sum of range N = (a(i) - b(i)) ^ 2, i = 1, 2,..., 30;\na(i) = i, if i - odd number \na(i) = i / 2,if i - even number\n";
    std::cout << "b(i) = i ^ 2, if i - odd number \nb(i) = i ^ 3, if i - even number;"; //even - четное, odd -  нечетное
    return 0;
}
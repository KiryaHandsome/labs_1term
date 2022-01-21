#include <iostream>

int main()
{
    int n, sum;
    std::cout << "Enter n(n - integer & n > 0) to calculate sum of even numbers betwen 1 and n:\n";
    std::cin >> n;
    if (n > 0) {
        if (n % 2 == 1) {
        n = n / 2;
        }
        else {
        n = n / 2 ; 
        }
        sum = n * n + n;
        std::cout << "sum=" << sum;
        return 0;
    } 
    else {
        std::cout << "Invalid input\n";
    }
    return 0;
}
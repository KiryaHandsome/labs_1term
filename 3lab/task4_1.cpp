#include <iostream>
#include <conio.h>

int main()
{
    int sum, n, z;
    std::cout << "Enter n(n - integer & n > 0) to calculate sum of even numbers betwen 1 and n:\n";
    std::cin >> n;
    bool b = true;
    do {
        if (n > 0) {
           sum = 0;
           for (int i = 1; i <= n; i++) { //include or not?
                if (i % 2 == 0) {
                    sum += i;
                }
           }
           std::cout << sum << " - sum of even numbers betwen 1 and n:";
           return 0;
        }
        else if (n < 0){
            std::cout << "invalid input\n";
            std::cin >> n;
        }
        else {
            std::cout << "invalid input\n";
            b = false;
        }
    } while (b);
    return 0;
}

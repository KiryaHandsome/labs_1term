#include <iostream>

int main()
{
    int a, b, nod, nok;
    std::cout << "Enter 2 numbers more than 0: "<< std::endl;
    std::cin >> a >> b;
    if (a <= 0 || b <= 0) {
        std::cout << "Error";
        return 0;
    }
    int max, min;
    if (a > b) {
        max = a;

    }
    else {
         max = b;
    }
    for (int i = 1; i > 0; i++) {
        if (max % a == 0 && max % b == 0) {
            i = -1;
        }
        else {
            max += 1;
        }
    }
    nok = max;
    nod = (a * b) / nok;
    std::cout << "nod=" << nod << std::endl << "nok=" << nok;
    return 0;

}


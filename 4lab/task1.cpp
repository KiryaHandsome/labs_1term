#include <iostream>

int main()
{
    const int size = 11; //input
    const int negative_number = 4;
    const int others = 7;
    int a[size];
    int b[negative_number];
    int c[others];
    std::cout << "Enter array of numbers: ";
    for (int i = 0; i < size; i++) {
        std::cin >> a[i];
    }
    std::cout << std::endl;
    int count_b = 0;
    int count_c = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] < 0) {
            b[count_b] = a[i];
            count_b++;
        }
        else {
            c[count_c] = a[i];
            count_c++;
        }
    }
    std::cout << "Negative array: ";
    for (int i = 0; i < negative_number; i++) {
        std::cout << b[i] << " ";
    }
    std::cout << "\nOther array: ";
    for (int i = 0; i < others; i++) {
        std::cout << c[i] << " ";
    }
    return 0;
}
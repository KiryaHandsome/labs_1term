#include <iostream>

int greatDivisor(int a)
{
    if (a > 0) {
        for (int i = a; i > 0; i--) {
            if (i % 2 == 1 && a % i == 0) {         //great odd divisor
                return i;
            }
        }
    }
    else {
        return 0;
    }
}
int correctInput(const char* massege)
{
    char str[10];
    bool isNotNumber;
    do {
        isNotNumber = false;
        std::cout << massege;
        std::cin >> str;
        for (int i = 0; i < strlen(str); i++) {
            if (((int)str[i] < 48 || (int)str[i] > 57) && str[0] != '-') {      //for negative numbers
                std::cout << "\nIts not correct number. Try again.\n";
                isNotNumber = true;
                break;
            }
        }
    } while (isNotNumber);

    return atoi(str);
}
int correctInput()
{
    char str[10];
    bool isNotNumber;
    do {
        isNotNumber = false;
        std::cin >> str;
        for (int i = 0; i < strlen(str); i++) {
            if ((int)str[i] < 48 || (int)str[i] > 57) {
                std::cout << "\nIts not correct number. Try again.\n";      //for positive numbers
                isNotNumber = true;
                break;
            }
        }
    } while (isNotNumber);

    return atoi(str);
}



int main()
{
    int n;
    std::cout << "Enter number of input data sets:"; 
    n = correctInput();
    int* arr = new int[n];
    std::cout << "Enter values:";
    for (int i = 0; i < n; i++) {
        arr[i] = correctInput("");
    }
    int* result = new int[n];
    int sum;
    for (int j = 0; j < n; j++) {
        sum = 0;
        for (int i = 1; i <= arr[j]; i++) {
            sum += greatDivisor(i);
        }
        result[j] = sum;
    }
    for (int i = 0; i < n; i++) {
        std::cout << result[i] << "\n";
    }

    delete[] result;
    delete[] arr;
    return 0;
}


#include <iostream>
#include <cmath>


unsigned long long PowModTEST(unsigned long long mod, unsigned long long number, unsigned long long power)
{
    unsigned long long int p = 1;
    for (int i = 0; i < mod; i++) p *= 10;
    unsigned long long result = 1;
    for (unsigned long long int i = 0; i < power; i++) {
        result *= number;     
        result %= p;
    }
    return result;
}

unsigned long long PowMod(unsigned long long number, unsigned long long power, unsigned long long mod)
{
    if (!power) return 1;

    if (power % 2) return (number * PowMod((number * number) % mod, power / 2, mod)) % mod;

    return PowMod((number * number) % mod, power / 2, mod);
}


unsigned long long int correctInput(const char* massege)
{
    char str[10];
    bool isNotNumber;
    do {
        isNotNumber = false;
        std::cout << massege;
        std::cin >> str;
        for (int i = 0; i < strlen(str); i++) {
            if (((int)str[i] < 48 || (int)str[i] > 57) && str[0] != '-') {
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
                std::cout << "\nIts not correct number. Try again.\n";
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
    std::cout << "Enter number of variety input:";
    n = correctInput();
    unsigned long long int** arr = new unsigned long long int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new unsigned long long int[3];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i][0]; 
        std::cin >> arr[i][1]; 
        std::cin >> arr[i][2]; //input k, n and t
    }
    std::cout << "\n";
    int m = 1;
    for (int i = 0; i < n; i++) {
        m = 1;
        for (int j = 0; j < arr[i][2]; j++) m *= 10;
        if (PowMod(arr[i][0] % m, arr[i][1], m) != 1) {
            std::cout << "Case #" << i + 1 << ":" << PowMod(arr[i][0] % m, arr[i][1], m) << "\n"; //n ^ k mod 10 ^ t; //% m for avoid overflow
        }  
    }
   
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
#include <iostream>

int function(int n)
{
    if (n % 10 > 0) {
        return n % 10;
    }
    else if (n == 0) {
        return 0;    
    }
    else {
        return function(n / 10);
    }
}
double sum(int p, int q)
{
    if (p < 0 && q < 0) {
        return 0;
    }
    else {
        int result = 0;
        for (int i = p; i <= q; i++) {
            result += function(i);
        }
        return  result;
    }
}
int correctInput(const char* massege)       //for negative numbers
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
int correctInput()      //for positive numbers
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
    int p, q, n;
    std::cout << "Enter number of pairs:";
    n = correctInput();
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[2];
    }
    std::cout << "Enter p and q:\n";
    for (int i = 0; i < n; i++) {
        arr[i][0] = correctInput("");
        arr[i][1] = correctInput(""); // enter p and q
    }
    int result;
    int* tmp = new int[n];
    for (int i = 0; i < n; i++) tmp[i] = 0;     //filling 0
    for (int i = 0; i < n; i++) {
        if (arr[i][0] >= 0 && arr[i][1] >= 0) {         //no negative numbers!
            tmp[i] = sum(arr[i][0], arr[i][1]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (tmp[i] != 0) std::cout << tmp[i] << "\n";
    }
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}

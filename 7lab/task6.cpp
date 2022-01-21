#include <iostream>
#include <string>


using namespace std;
int CorrectInput()      //for positive numbers
{
    char str[13];
    bool isNotNumber;
    do {
        isNotNumber = false;
        std::cin >> str;
        for (int i = 0; i < strlen(str); i++) {
            if ((int)str[i] < 48 || (int)str[i] > 57 || atoi(str) > pow(10, 9)) {
                std::cout << "\nInvalid input. Try again.\n";
                isNotNumber = true;
                break;
            }
        }
    } while (isNotNumber);

    return atoi(str);
}

int main()
{
    unsigned int number, t;
    cout << "Enter number of input sets:\n";
    t = CorrectInput();
    unsigned int* arr = new unsigned int[t];
    cout << "Enter your data:\n";
    for (int i = 0; i < t; i++) {
        arr[i] = CorrectInput();
    }
    for (int i = 0; i < t; i++) {
        if (arr[i] % 10 == 9) cout << arr[i] / 10 + 1 << endl;
        else cout << arr[i] / 10 << endl;
    }
    delete[] arr;

    
    return 0;
}

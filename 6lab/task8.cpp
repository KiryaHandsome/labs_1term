#include <iostream>
#include <string>

std::string correctString(const char* massege)                //input for strings
{
    std::string str;
    bool isNotString;
    do {
        isNotString = false;
        std::cout << massege;
        std::cin >> str;
        for (int i = 0; i < str.length(); i++) {
            if (!isalpha(str[i])) {
                std::cout << "\nIts not correct input. Try again.\n";
                isNotString = true;
                break;
            }
        }
    } while (isNotString);
    return str;
}
int correctInputNum()                                   //input for numbers(return int)  
{
    std::string str;
    bool isNotNumber;
    do {
        isNotNumber = false;
        std::cin >> str;
        for (int i = 0; i < str.length(); i++) {
            if ((int)str[i] < 48 || (int)str[i] > 57) {
                std::cout << "\nIts not correct number. Try again.\n";
                isNotNumber = true;
                break;
            }
        }
    } while (isNotNumber);

    return std::stoi(str);
}

int main()
{
    int n;
    std::cout << "Enter number of input sets:";
    n = correctInputNum();
    std::string* str = new std::string[2 * n];
    for (int i = 0; i < 2 * n; i++) {
        if(i % 2 == 0) str[i] = correctString("Enter first string:");
        else str[i] = correctString("Enter second string:");
    }
    int counter;
    for (int k = 0; k < 2 * n - 1; k += 2) {
        counter = 0;
        for (int i = 0; i < str[k].length(); i++) {
            if (str[k + 1][0] == str[k][i]) counter++;      //count number of symbols in 1 string which equals first symbol in 2 string
        }
        int* arr = new int[counter];        //array for sequence number
        counter = 0;
        for (int i = 0; i < str[k].length(); i++) {
            if (str[k + 1][0] == str[k][i]) {
                arr[counter] = i;       //remember sequence number
                counter++;
            }
        }
        int j = 1;
        bool isCorrect = true;

        for (int i = 0; i < counter; i++) {
            j = 1;
            while (str[k + 1][j] == str[k][arr[i] + 1] && arr[i] < str[k].length() - 1) {       //go right 
                arr[i]++;
                j++;
                if (j == str[k + 1].length()) break;
            }
            while (str[k + 1][j] == str[k][arr[i] - 1] && arr[i] > 0) {     //go left
                j++;
                arr[i]--;
                if (j == str[k + 1].length() || arr[i] == 0) break;
            }
            if (j != str[k + 1].length() || str[k][arr[i]] != str[k + 1][j - 1]) {
                isCorrect = false;
            }
            if (isCorrect) break;
        }
        if (isCorrect) std::cout << "YES\n";
        else std::cout << "NO\n";
        delete[] arr;
    }
    delete[] str;

    return 0;
    
    
}

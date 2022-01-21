#include <iostream>
#include <string>


int powMod(int number, int degree, int mod)                //pow with mod
{
    int result = 1;
    for (int i = 0; i < degree; i++) {
        result *= number;
        result %= mod;
    }
    return result;

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
std::string correctInputNum(const char* massege)            //input for numbers (return string)
{
    std::string str;
    bool isNotNumber;
    do {
        isNotNumber = false;
        std::cout << massege;
        std::cin >> str;
        for (int i = 0; i < str.length(); i++) {
            if ((int)str[i] < 48 || (int)str[i] > 57) {
                std::cout << "\nIts not correct number. Try again.\n";
                isNotNumber = true;
                break;
            }
        }
    } while (isNotNumber);

    return str;
}
std::string correctInputStr(const char* massege)                //input for strings
{
    std::string str;
    bool isNotNumber;
    do {
        isNotNumber = false;
        std::cout << massege;
        std::cin >> str;
        for (int i = 0; i < str.length(); i++) {
            if (!isalpha(str[i])) {
                std::cout << "\nIts not correct input. Try again.\n";
                isNotNumber = true;
                break;
            }
        }
    } while (isNotNumber);
    return str;
}

int main()
{
    int n; 
    std::cout << "Enter number of input data sets: ";
    n = correctInputNum();
    std::string** str = new std::string* [n];   //create strings array
    for (int i = 0; i < n; i++) {
        str[i] = new std::string[4];
    }
    for (int i = 0; i < n; i++) {
        std::cout << "Input number [" << i + 1 << "]\n";            //simple input
        str[i][0] = correctInputNum("Enter size of string: ");
        str[i][1] = correctInputNum("Enter divisor m: ");
        str[i][2] = correctInputStr("Enter S1: ");
        str[i][3] = correctInputStr("Enter S2: ");              
    }
    int result;
    for (int i = 0; i < n; i++) {
        
        if (stoi(str[i][0]) > str[i][2].length() + str[i][3].length()) {                                     // if S1 + S2 > L
            result = powMod(26, stoi(str[i][0]) - str[i][2].length() - str[i][3].length(), stoi(str[i][1])) * 2;     //count 26 ^ (L - (S1 + S2)) mod m
        }
        else if (stoi(str[i][0]) < str[i][2].length() + str[i][3].length()) {         //if S1 + S2 < L
            int diff = str[i][2].length() + str[i][3].length() - stoi(str[i][0]);       //S1 + S2 - L
            bool isEqual = true;
            for (int j = 0; j < diff; j++) {
                if (str[i][2][j] != str[i][3][str[i][3].length() - diff + j] && str[i][2][str[i][2].length() - diff + j] != str[i][3][j]) isEqual = false; //compare firsts and lasts elements, if they dont equal: result = 0
            }
            if (isEqual) result = 1;
            else result = 0;
        }  
        else {                                                          //if S1 + S2 = L
            if (str[i][2].length() == str[i][3].length()) {
                bool isEqual = true;
                for (int j = 0; j < str[i][2].length(); j++) {
                    if(str[i][2][j] != str[i][3][j]) isEqual = false;       //if they not equals result = 2,else result = 1
                }
                if (!isEqual) result = 2;
                else result = 1;
            }
            else {
                bool isEqual = true;
                for (int j = 0; j < str[i][2].length(); j++) {
                    for (int k = 0; k < str[i][3].length(); k++) {
                        if (str[i][2][j] != str[i][3][k]) isEqual = false;          //if each symbol s1 = each symbol s2 result = 1
                    }
                }
                if (!isEqual) result = 2;
                else result = 1;
            }
            
        }
        std::cout << result <<"\n";
    }
    


    for (int i = 0; i < n; i++) {
        delete[] str[i];
    }
    delete[] str;
    return 0;
}

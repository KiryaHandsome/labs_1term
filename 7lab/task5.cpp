#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int mySize(std::string str)
{
    int counter = 0;
    while ((int)(str[counter]) > 0 && (int)(str[counter]) < 256) counter++;
    return counter;
}
int myStoi(std::string str)
{
    int result = 0;
    int sign = 1;
    if (str[0] == '-') sign = -1;
    for (int i = 0; i < mySize(str); i++) {
        if (str[i] != '-') result += (int(str[i]) - 48) * pow(10, mySize(str) - 1 - i);
    }
    return sign * result;
}
string RomanNumerals(const string& str)
{
    string roman[] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };  
    int nums[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
    int number = myStoi(str);
    string res;
    for (int i = 12; i >= 0; i--) {  //12 numbers in array higher
        while (number - nums[i] >= 0) {
            res += roman[i];
            number -= nums[i];
        }
    }
    return res;
}
string CorrectInput(const char* massege = "")
{
    cout << massege;
    string str;
    bool isNotNumber;
    do {
        isNotNumber = false;
        cin >> str;
        for (int i = 0; i < mySize(str); i++) {
            if (!isdigit(str[i])) {
                if ((i == 0 && str[i] == '-') && abs(myStoi(str)) < 4000); //do nothing
                else {
                    cout << "\nIts not correct number. Try again.\n";
                    isNotNumber = true;
                    break;
                }
            }
        }
    } while (isNotNumber);

    return str;
}


int main()
{
    cout << "This program convert arabian numbers |x| < 4000 to roman\n";
    string str;
    str = CorrectInput("Enter a number:");
    char sign = ' ';
    if (str[0] == '-') {
        sign = '-';
        str[0] = '0';
    }
    cout << "Your number in roman numerals: " << sign + RomanNumerals(str);
    return 0;
}

#include <iostream>
#include <string>


using namespace std;



int mySize(string str)
{
    int counter = 0;
    while ((int)(str[counter]) > 0 && (int)(str[counter]) < 256) counter++;
    return counter;
}
char toString(int a) //for positive numbers
{
    return (char)(a + 48);
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
void myErase(string& str, const int& start)  //delete 1 element
{
    int tmp = 0;
    for (int i = start; i < mySize(str); i++) {
        tmp = str[i];
        str[i] = str[i + 1];
        str[i + 1] = tmp;
    }
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
                if ((i == 0 && str[i] == '-') || str[i] == 'A'); //do nothing
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
char CorrectOperation(const char* massege = "")
{
    string sign;
    bool isOperation = true;
    do {
        isOperation = true;
        cout << massege;
        cin >> sign;
        for (int i = 0; i < mySize(sign); i++) {
            if ((sign[i] != '+' && sign[i] != '-') || i > 0) {
                isOperation = false;
                cout << "Invalid input.\nThere is just 2 operations: '+' and '-'.\nTry again.\n";
                break;
            }
        }

    } while (!isOperation);

    return sign[0];
}
int oper(string& num1, string& num2, char& operation)
{
    if ((((num1[0] == '-' && num2[0] == '-') || (num1[0] != '-' && num2[0] != '-')) && operation == '+' ) || ((num1[0] != '-' && num2[0] == '-') && operation == '-')) return 1;
    return 0;   //return 1 if result is addiction, return 0 - if result is substraction
}
string sum(string& num1, string& num2)
{
    string result;
    char sign = ' ';
    if (num1[0] == '-') {
        sign = '-';
        myErase(num1, 0);
        myErase(num2, 0);
    }
    if (num2[0] == '-') myErase(num2, 0);
    string ls1 = mySize(num1) < mySize(num2) ? num1 : num2; //little string
    string ls2 = mySize(num1) < mySize(num2) ? num2 : num1;                   //equalize strings
    if (mySize(num1) != mySize(num2)) {
        for (int i = mySize(ls1); i < mySize(ls2); i++) ls1 = '0' + ls1;
    }
    int a = 0, b = 0, f = 0;  //f - remainder
    for (int i = mySize(ls1) - 1; i >= 0 ; i--) {
        if (ls1[i] == 'A') a = 10;
        else a = (int)ls1[i] - 48; //convert to digit
        if (ls2[i] == 'A') b = 10;
        else b = (int)ls2[i] - 48;
        if ((a + b + f) % 11 == 10) result = 'A' + result;
        else result = toString((a + b + f) % 11) + result;
        f = (a + b + f) / 11;
    } 
    return sign + result;
}
string substr(string& num1, string& num2)
{
    if (num1[0] == '-') myErase(num1, 0);
    if (num2[0] == '-') myErase(num2, 0);
    string result;
    int len1 = mySize(num1);
    int len2 = mySize(num2);
    string ls1 = len1 < len2 ? num1 : num2;  //smaller str
    string ls2 = len1 < len2 ? num2 : num1;  //bigger str         //equalize strings
    if (len1 != len2) {
        for (int i = mySize(ls1); i < mySize(ls2); i++) ls1 = '0' + ls1;   //add zeros
    }
    int counter = 0;
    char sign = ' ';
    if (myStoi(num1) - myStoi(num2) < 0) sign = '-'; //check sign of result
    while (counter < mySize(ls1)) {
        if ((int)ls1[counter] < (int)ls2[counter]) {
            swap(ls1, ls2);
            break;       //find greatest |number| and assign it first
        }
        counter++;
    }
    string tmp1, tmp2;
    int a = 0, b = 0, f = 0;  //f - remainder
    for (int i = 0; i < mySize(ls2); i++) {
        tmp1 = ls1[mySize(ls1) - 1 - i];
        tmp2 = ls2[mySize(ls2) - 1 - i];
        if (tmp1[0] == 'A') a = 10 - f;
        else a = myStoi(tmp1) - f;
        if (tmp2[0] == 'A') b = 10;
        else b = myStoi(tmp2);
        if (a - b < 0) {
            a += 11;
            f = 1;
        }
        else f = 0;
        if (a - b == 10) result = 'A' + result;
        else result = toString(a - b) + result;
    }
    if (f != 0) result = toString(f) + result;
    if (result[0] == 0) myErase(result, 0);
    return sign + result;
}


int main()
{
    cout << "This program count addiction and substraction of eleven digits numbers\n";
    string str1, str2;
    char operation = '+';
    operation = CorrectOperation("Choose operation: '+' or '-'\n");
    str1 = CorrectInput("First number:");
    str2 = CorrectInput("Second number:");
    
    if (oper(str1, str2, operation)) cout << sum(str1, str2);
    else cout << substr(str1, str2);

    return 0;
}

#include <ctime>
#include <iostream>
#include <string>




int mySize(std::string str)
{
    int counter = 0;
    while ((int)(str[counter]) > 0 && (int)(str[counter]) < 256) counter++;
    return counter;
}
char toString(int a)
{
    return (char)(a + 48);
}
long long int myStoi(std::string str)
{
    long long int result = 0;
    int sign = 1;
    if (str[0] == '-') sign = -1;
    for (int i = 0; i < mySize(str); i++) {
        if (str[i] != '-') result += (int(str[i]) - 48) * pow(10, mySize(str) - 1 - i);
    }
    return sign * result;
}









std::string ConvToBin(const std::string& number)
{
    register long long int tmp = myStoi(number);
    register std::string result;
    while (tmp != 0) {
        result = toString(tmp % 2) + result;
        tmp /= 2;
    }
    return result;
}
std::string BinCounter(const int &end)  //counter of binary numbers, but we consider them like decimal
{
    std::string result = "0";
    int counter = 0;
    int i = 0;
    std::string tmp;
    while (i < end) {   //until we find need number
        if (result[mySize(result) - 1] == '0') result[mySize(result) - 1] = '1';
        else {
            counter = 0;
            while (counter < mySize(result)) {
                if (result[mySize(result) - 1 - counter] == '0') {
                    result[mySize(result) - 1 - counter] = '1';
                    for (int k = mySize(result) - counter; k < mySize(result); k++) result[k] = '0';
                    break;
                }
                counter++;
            }
            if (counter == mySize(result)){
                for (int j = 0; j < mySize(result); j++) result[j] = '0';
                result = '1' + result;
            }
        }
        tmp = ConvToBin(result);    //convert decimal number in binary
        tmp = tmp.substr(mySize(tmp) - mySize(result), mySize(tmp));
        if (result == tmp) {    //if they equals, add 1
            i++;
        }
    }
    return result;
}
std::string CorrectInput()
{
    std::string str;
    bool isNotNumber;
    do {
        isNotNumber = false;
        std::cin >> str;
        for (int i = 0; i < mySize(str); i++) {
            if (!isdigit(str[i])) {
                if (i == 0 && str[i] == '-'); //do nothing
                else {
                    std::cout << "\nIts not correct number. Try again.\n";
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
    std::cout << "Program find bindecimal number.\nEnter serial number:";
    int test;
    std::cin >> test;
    std::cout << BinCounter(test) << "\n";
    std::cout << clock();
    return 0;
}

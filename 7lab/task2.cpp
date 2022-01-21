#include <iostream>
#include <string>
#include <cmath>



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
double myStod(std::string &num)
{
    int sign = 1;
    if (num[0] == '-') {
        sign = -1;
        myErase(num, 0);
    }
    double result = 0;;
    int point = mySize(num);
    int counter = 0;
    while (counter < mySize(num)) {
        if (num[counter] == '.') {
            point = counter;
            break;
        }
        counter++;
    }
    int power = point - 1;
    for (int i = 0; i < mySize(num); i++) {
        if(num[i] != '.') {
            result += pow(10, power) * ((int)num[i] - 48);
        power--;
        }
    }
    return sign * result;
}





std::string CorrectInput()
{
    std::string str;
    bool isNotNumber;
    do {
        isNotNumber = false;
        std::cin >> str;
        int counter = 0, point = -1;
        while (counter < mySize(str)) {        //find point
            if (str[counter] == '.') {
                point = counter;
                break;
            }
            counter++;
        }
        for (int i = 0; i < mySize(str); i++) {
            if (!isdigit(str[i])) {
                if ((i == 0 && str[i] == '-') || i == point); //do nothing
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
std::string ConvIntDecToBin(int number)
{
    char sign = '0';
    if (number < 0) sign = '1';
    std::string result;
    int tmp = abs(number);
    while (tmp != 0) {
        result += toString(tmp % 2);      //write remainder of division by 2
        tmp /= 2;
    }
    tmp = abs(number); //return value
    char place = '0';
    for (int i = 0; i < mySize(result) / 2; i++) {
        place = result[i];
        result[i] = result[mySize(result) - i - 1];   //inverse array
        result[mySize(result) - i - 1] = place;
    }
    int bit = 4;  //number of need digits
    if (tmp >= 7 && tmp <= 127) bit = 8;
    if (tmp > 127 && tmp < 32767) bit = 16;
    if (tmp >= 32767 && tmp < pow(2, 30)) bit = 32;
    if ((mySize(result) + 1) % bit != 0) {
        std::string zeros;
        for (int i = 0; i < bit - (mySize(result) + 1); i++) { 
            zeros += '0';                                        //filling zeros
        }
        result = zeros + result;
    }
    return sign + result;
}
std::string ConvFractDecToBin(double number)
{
    double num = number;
    std::string result;
    double tmp = 0;
    double fract = modf(num, &tmp);
    for (int i = 0; i < 8; i++) {       //precision 8 digits after point
        fract *= 2;
        fract = modf(fract, &tmp);
        result += toString((int)tmp);
    }

    return '.' + result;
}

int main()
{
    std::string output = "This program convert number from natural form to straight code\n";
    std::cout << output;
    std::string str;
    std::cout << "Enter number in natural form : \n";
    str = CorrectInput();
    double number = myStod(str), integer = 0, fract = abs(modf(number, &integer)); //number, integer and fractional part
    std::cout << "Your number in straight code:\n";
    if (fract != 0) std::cout << ConvIntDecToBin(integer) + ConvFractDecToBin(fract);
    else std::cout << ConvIntDecToBin((int)integer);

    return 0;

}

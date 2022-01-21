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
int myStoi(std::string str)   
{
    int result = 0;
    int sign = 1;
    if (str[0] == '-') sign = -1;
    for (int i = 0; i < mySize(str); i++) {
        if(str[i] != '-') result += (int(str[i]) - 48) * pow(10, mySize(str) - 1 - i);
    }
    return sign * result;
}
int CorrectInput(const char* massege = "")
{
    std::cout << massege;
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

    return myStoi(str);
}
std::string ConvDecToBin(int number)        //convert from decimal system to binary code (straight code)
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
            zeros += '0';
        }
        result = zeros + result;
    }
    return sign + result;
}
std::string ConvStrToAdd(std::string &number)      //convert straight code to additional
{
    if (number[0] == '1') {  //for negative numbers 
        for (int i = 1; i < mySize(number); i++) {         //convert to inverse code 
            if (number[i] == '1') number[i] = '0';
            else number[i] = '1';
        }
        if (number[mySize(number) - 1] == '0') number[mySize(number) - 1] = '1';//this 
        else {                                                                  //part
            int counter = 0;                                                    //add
            while (counter < mySize(number)) {                                  //1
                if (number[mySize(number) - 1 - counter] == '0') {              //to
                    number[mySize(number) - 1 - counter] = '1';                 //inverse
                    break;                                                      //code
                }
                else {
                    number[mySize(number) - 1 - counter] = '0';
                    counter++;
                }
            }
        }
    }
    
    return number;
}

std::string BinarySum(const std::string &num1, const std::string &num2)   //in additional code
{
    std::string result;
    int len1 = mySize(num1);
    int len2 = mySize(num2);
    std::string ls1 = len1 < len2 ? num1 : num2;  
    std::string ls2 = len1 < len2 ? num2 : num1;   //equalize strings
    if (len1 != len2) {
        char sign1 = ls1[0];
        ls1[0] = '0';
        for (int i = mySize(ls1); i < mySize(ls2) - 1; i++) ls1 = '0' + ls1;
        ls1 = sign1 + ls1;
    }
   
    char tmp = '0';
    for (int i = ls1.size() - 1; i >= 0; i--) {
        if (ls1[i] == '0' && ls2[i] == '0') {
            result = tmp + result;
            tmp = '0';
        } 
        if ((ls1[i] == '1' && ls2[i] == '0') || (ls1[i] == '0' && ls2[i] == '1')) {
            if (tmp == '1') {
                result = '0' + result;
                tmp = '1';
            }
            else {
                result = '1' + result;
                tmp = '0';
            }
        }
        if (ls1[i] == '1' && ls2[i] == '1') {
            result = tmp + result;
            tmp = '1';
        } 

    }
    return ConvStrToAdd(result);
}


int main()
{
    std::string output = "This program calculate sum of 2 numbers in natural form in additional code\n";
    std::cout << output;
    int num1, num2;
    std::cout << "Enter numbers in natural form.\n";
    num1 = CorrectInput("First number:");
    num2 = CorrectInput("Second number: ");
    std::string str1 = ConvDecToBin(num1), str2 = ConvDecToBin(num2);
    std::cout << str1 << " " << str2 << " - numbers in straight code(simple binary)\n";
    std::cout << ConvStrToAdd(str1) << " " << ConvStrToAdd(str2) << " - numbers in additional code\n";
    std::cout << BinarySum(str1, str2);
    return 0;
}
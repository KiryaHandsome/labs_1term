#include <iostream>
#include <string>
#include <cmath>






int mySize(std::string str)
{
    int counter = 0;
    while ((int)(str[counter]) > 0 && (int)(str[counter]) < 256) counter++;
    return counter;
}
char toString(int a) //for positive numbers
{
    return (char)(a + 48);
}
int myStoi(std::string str)   //convert only positive numbers
{
    int result = 0;
    for (int i = 0; i < mySize(str); i++) {
        result += (int(str[i]) - 48) * pow(10, mySize(str) - 1 - i);
    }
    return result;
}
void myErase(std::string& str, const int& start)  //from start to end of string
{
    for (int i = start; i < mySize(str); i++) {
        str[i] = NULL;
    }
}
std::string mySubstr(std::string str, int start) //from start to end of string
{
    std::string result;
    for (int i = 0; i < mySize(str) - start; i++) {
        result += str[start + i];
    }
    return result;
}




int NineToTen(const std::string &number)           //convert integer part to 10 digits system
{
    int sign = 1;
    if (number[0] == '-')  sign = -1;
    int* arr = new int[mySize(number)];
    std::string tmp;
    for (int i = 0; i < mySize(number); i++) {
        if (sign == -1 && i == 0) {}
        else{
            tmp = number[i];
            arr[i] = myStoi(tmp);   //convert symbols into digits
        }   
    }
    int result = 0;
    for (int i = 0; i < mySize(number); i++) {
        if (sign == -1 && i == 0) {}
        else {
            result += arr[i] * pow(9, mySize(number) - i - 1);  //result = number(10 digits system)
        }        
    }
    delete[] arr;
    return sign * result;
}
std::string TenToEleven(std::string &num)          //convert integer part to 11 digits system
{
    int number = abs(NineToTen(num));
    std::string sign = { ' ' };     //check sign
    if (num[0] == '-') sign = {'-'};
    int counter = 1;
    while (number / 11 != 0) {     //count number of digits in 11 system
        number /= 11;
        counter++;
    }
    number = abs(NineToTen(num));
    std::string elev;
    for (int i = 0; i < counter; i++) {
        if (number % 11 == 10) elev += 'A';
        else elev += toString(number % 11);
        number /= 11;
    }
    int place = 0;
    for (int i = 0; i < mySize(elev) / 2; i++) {
        place = elev[i];
        elev[i] = elev[mySize(elev) - 1 - i];      //inverse
        elev[mySize(elev) - 1 - i] = place;
    }
    return sign + elev;

}
double FractNineToTen(const std::string &fract) {
    int* arr = new int[mySize(fract)];
    std::string tmp;
    for (int i = 0; i < mySize(fract); i++) {
        tmp = fract[i];
        arr[i] = myStoi(tmp);  //convert  symbols into digits
    }
    double result = 0;
    for (int i = 0; i < mySize(fract); i++) {
        result += (double)arr[i] * pow(9, -i - 1); //result = number(dec system)
    }
    delete[] arr;
    return result;
}
std::string FractTenToEleven(const std::string &num){    //convert fractional part to 11 digits system

    std::string str;
    double fract = FractNineToTen(num);
    double integer = 0;
    for (int i = 0; i < 5; i++) {    //precision 5 digits after point
        if ((int)(11 * fract) % 11 == 10) str += 'A';
        else str += toString((int)(11 * fract));
        fract = modf(11 * fract, &integer);
    }
    return str;
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
            if (!isdigit(str[i]) || str[i] == '9') {
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


int main()
{
    std::cout << "Program convert number from 9 to 11 digits system.\nEnter number in 9 digits system:";
    std::string number;
    number = CorrectInput();
    int point = 0;
    for (int i = 0; i < mySize(number); i++) {  //check its fractional or not
        if (number[i] == '.') point = i;
    }
    if(point != 0){
        std::string fract;
        fract = mySubstr(number, point + 1);
        myErase(number, point);
        std::cout << TenToEleven(number) + '.' + FractTenToEleven(fract) << " -  number in the 11 digit system\n\n";
    }
    else std::cout << TenToEleven(number) << " - number in the 11 digit system\n";
    
    return 0;
}
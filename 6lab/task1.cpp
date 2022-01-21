#include <iostream>

int myAbs(int i)
{
    if (i < 0) i = -i;
    return i;
}
void validInput(char *str)
{
    bool isCorrect;
    do {
        isCorrect = true;
        std::cout << "Enter digits:\n";
        std::cin.getline(str, 80);
        for (int i = 0; i < strlen(str); i++) {
            if ((str[i] < 48 || (int)str[i] > 57) && (int)str[i] != 32 || ((str[myAbs(i - 1)] >= 48 && str[myAbs(i - 1)] <= 57) && (str[i] >= 48 && str[i] <= 57))) {
                std::cout << "Invalid input. Try again.\n";
                isCorrect = false;
                break;
            }
        }
    } while (!isCorrect);
}


int main()
{
    char str[80];
    std::cout << "Program sort digits in ascending order.\n";
    validInput(str);

    char place;

    for (int i = 2; i < strlen(str); i++) {
        for (int j = strlen(str) - 1; j >= i ; j--) {       //bubble sort
            if ((int)str[j - 2] > (int)str[j] && (int)str[i] != 32) {
                place = str[j - 2];
                str[j - 2] = str[j];    //change values
                str[j] = place;
            }  
        }
    }
    for (int i = 0; i < strlen(str); i++) {     //output
        std::cout << str[i];
    }
    
    return 0;
}


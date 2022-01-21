#include <iostream>

int correctInput(const char* massege)
{
    char str[10];
    bool isNotNumber;
    do {
        isNotNumber = false;
        std::cout << massege;
        std::cin >> str;
        for (int i = 0; i < strlen(str); i++) {
            if ((int)str[i] < 48 || (int)str[i] > 57) {
                std::cout << "\nIts not correct number. Try again.\n";
                isNotNumber = true;
                break;
            }
        }
    } while (isNotNumber);

    return atoi(str);
}
void symmetrical(char** str, int size)
{
    int counter;
    for (int i = 0; i < size; i++) {
        counter = 0;  //number of not same symbols
        for (int j = 0; j < strlen(str[i]) / 2; j++) {
            if (str[i][j] != str[i][strlen(str[i]) - j - 1]) counter++;
        }
        if (counter == 0) std::cout << "String number " << i + 1 << " is symmetrical\n";

        if (counter != 0) std::cout << "String number " << i + 1 << " is not symmetrical\n";
    }
}

int main()
{
    std::cout << "Program check string symmetrical or not";
    int size;
    size = correctInput("Enter number of strings: ");
    char** str = new char* [size];      //declare array of strings
    for (int i = 0; i < size; i++) {
        str[i] = new char[255];
    }
    std::cin.ignore();
    for (int i = 0; i < size; i++) {
        std::cin.getline(str[i], 255);      //input strings
    }

    symmetrical(str, size);

    for (int i = 0; i < size; i++) {        //output strings
        std::cout << str[i] << "\n";
    }

    for (int i = 0; i < size; i++) {
        delete[] str[i];
    }
    delete[] str;
    return 0;
}


#include <iostream>

void letter(char* str)
{
    int lowel = 0, consonant = 0;
    for (int i = 0; i < strlen(str); i++) {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 121)) {
            if ((int)str[i] == 65 || (int)str[i] == 69 || (int)str[i] == 73 || (int)str[i] == 79  || (int)str[i] == 85  || (int)str[i] == 89 || (int)str[i] == 97 || (int)str[i] == 101 || (int)str[i] == 105 || (int)str[i] == 111 || (int)str[i] == 117 || (int)str[i] == 121) {
                lowel++;
            }
            else {
                consonant++;
            }
        }
    }
    if (lowel == 0 && consonant == 0) {
        std::cout << "There is no letters";
    }
    else {
        if (lowel > consonant) std::cout << "Lowel letters > consonant letters";
        else if (lowel < consonant) std::cout << "Consonant letters > lowel letters";
        else std::cout << "Lowel letters = consonant letters";
    }
    
}

int main()
{
    setlocale(LC_ALL, "rus");
    std::cout << "Programm count which kind of letter more lowel or consonsant.\n\nEnter text:\n";
    char* str = new char [80];
    std::cin.getline(str, 80);
    letter(str);
    delete[] str;
    return 0;
}

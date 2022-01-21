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
void simpleEnglish(char** text, int strings)
{
    for (int i = 0; i < strings; i++) {
        for (int j = 0; j < 100; j++) {
            if (text[i][j] == 'c' || text[i][j] == 'C') {       //correct 'c'
                if (text[i][j + 1] == 'e' || text[i][j + 1] == 'i' || text[i][j + 1] == 'y') {
                    if (text[i][j] == 'c') text[i][j] = 's';
                    else text[i][j] = 'S';
                }
                else {
                    if (text[i][j] == 'c') text[i][j] = 'k';
                    else text[i][j] = 'K';
                }
            }
            if (text[i][j] == 'q' || text[i][j] == 'Q') {       //correct 'q' 
                if (text[i][j + 1] == 'u') {
                    if (text[i][j] == 'q') {
                        text[i][j] = 'k';
                    }
                    else {
                        text[i][j] = 'k';
                    }
                    text[i][j + 1] = 'v';
                } 
            }
            if (text[i][j] == 'x' || text[i][j] == 'X') {       //correct 'x'
                for (int q = strlen(text[i]) + 1; q > j + 1; q--) {
                    text[i][q] = text[i][q - 1];
                }
                if (text[i][j] == 'x') text[i][j] = 'k';
                else text[i][j] = 'K';
                text[i][j + 1] = 's';
            }
            if (text[i][j] == 'w') text[i][j] = 'v';        //correct 'w'
            if (text[i][j] == 'W') text[i][j] = 'V';
            if ((text[i][j] == 'p' || text[i][j] == 'P') && text[i][j + 1] == 'h') {       //correct 'ph'
                for (int q = j + 1; q < strlen(text[i]); q++) {
                    text[i][q] = text[i][q + 1];
                }
                if (text[i][j] == 'p') text[i][j] = 'f';
                else text[i][j] = 'F'; 
            }
            if ((text[i][j] == 'y' || text[i][j] == 'Y') && text[i][j + 1] == 'o' && text[i][j + 2] == 'u') {       //correct 'you'
                for (int q = j + 1; q < strlen(text[i]); q++) {
                    text[i][q] = text[i][q + 2];
                }
                if (text[i][j] == 'y') text[i][j] = 'u';
                else text[i][j] = 'U';
            }
            if (text[i][j] == 'o' && text[i][j + 1] == 'o') {       //correct 'oo'
                for (int q = j + 1; q < strlen(text[i]); q++) {
                     text[i][q] = text[i][q + 1];
                }
                text[i][j] = 'u';     
            }
            if (text[i][j] == 'e' && text[i][j + 1] == 'e') {       //correct 'ee'
                for (int q = j + 1; q < strlen(text[i]); q++) {
                    text[i][q] = text[i][q + 1];
                }
                text[i][j] = 'i';
            }
            if ((text[i][j] == 't' || text[i][j] == 'T') && text[i][j + 1] == 'h') {       //correct 'th'
                for (int q = j + 1; q < strlen(text[i]); q++) {
                    text[i][q] = text[i][q + 1];
                }
                if (text[i][j] == 't') text[i][j] = 'z';
                else text[i][j] = 'Z';
            }
        }
    }
    for (int i = 0; i < strings; i++) {
        for (int j = 0; j < 100; j++) {
            if (text[i][j] == text[i][j + 1] && (int)text[i][j] != 65 && (int)text[i][j] != 69 && (int)text[i][j] != 73 && (int)text[i][j] != 79 && (int)text[i][j] != 85 && (int)text[i][j] != 89 && (int)text[i][j] != 97 && (int)text[i][j] != 101 && (int)text[i][j] != 105 && (int)text[i][j] != 111 && (int)text[i][j] != 117 && (int)text[i][j] != 121) {
                for (int q = j + 1; q < strlen(text[i]); q++) {     //correct double consonant letters
                    text[i][q] = text[i][q + 1];
                }
            }
        }
    }
}

int main()
{
    std::cout << "Program make SimpleEnglish text.\n";
    int size;
    size = correctInput("Enter number of strings: ");
    char** str = new char* [size];      //declare array of strings
    for (int i = 0; i < size; i++) {
        str[i] = new char[110];
    }
    std::cin.ignore();
    for (int i = 0; i < size; i++) {
        std::cin.getline(str[i], 110);      //input strings
    }

    simpleEnglish(str, size);

    std::cout << "Your SimpleEnglish text:\n";
    for (int i = 0; i < size; i++) std::cout << str[i] << "\n";         //output text

    for (int i = 0; i < size; i++) {
        delete[] str[i];
    }
    delete[] str;
    return 0;
    /*
    Too swift for Theex, too quick for Gallow,
    Too strong for young Prince Joseph to follow.
    */
}


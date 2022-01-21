#include <iostream>
#include <cmath>
#include <string>
int CorrectInput(std::string massege)
{
    std::string input;
    bool isNotNumber;
    do {

        isNotNumber = false;
        std::cout << massege;
        std::cin >> input;
        for (int i = 0; i < input.length(); i++) {
            if (!isdigit(input[i])) {
                std::cout << "\nIts not correct number. Try again.\n";
                isNotNumber = true;
                break;
            }
        }
    } while (isNotNumber);

    return std::stoi(input);
}

int main()
{
    std::cout << "Program find entered number (number > 0) in square which filling by an alghorithm.\n";
    int Elem;
    Elem = CorrectInput("Enter a number:");
    int M = 1 + sqrt(Elem - 1);
    int** matrix = new int* [M];
    for (int i = 0; i < M; i++) {
        matrix[i] = new int[M];
    }
    int iElem = 0, jElem = 0;
    bool isNotFind = true;
    int num = 1;
    int i = 0, I = 0, J = 0;
    do {
        for (int d = i; d >= -i; d--) {
            if (d > 0) {
                I = i - d;
                J = i;
            }//matrix[i - d][i] = num;
            else if (d < 0) {
                I = i;
                J = i + d;
            }//matrix[i][i + d] = num;
            else {
                I = i;
                J = i;
            }
            matrix[I][J] = num;
            if (num == Elem) {
                isNotFind = false;
                iElem = I;
                jElem = J;
            }
            num++;
        }
        i++;
    } while (i < M || isNotFind);
    std::cout << "\n" << "       ";
    for (int i = 0; i < M; i++) printf("%5d", i + 1);
    std::cout << "\n" << "       ";
    for (int i = 0; i < M; i++) printf("%5s", "=====");
    std::cout << "\n";
    for (int i = 0; i < M; i++) {
        printf("%5d||", i + 1);
        for (int j = 0; j < M; j++) {
            if (i == iElem && j == jElem) printf("\033[32m%5d\033[0m", matrix[i][j]);
            else printf("%5d", matrix[i][j]);
        }
        std::cout << std::endl;
    }
    std::cout << "The element " << Elem << ": " << iElem + 1 << " " << jElem + 1;
    for (int i = 0; i < M; i++) {
        delete[] matrix[i];
    }
    return 0;
}


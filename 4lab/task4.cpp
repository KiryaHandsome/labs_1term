#include <iostream>
#include <cmath>
#include <string>
int  CorrectInput()
{
    std::string input;
    bool isNotNumber = true;
    do {
        std::cin >> input;
        for (int i = 0; i < input.length(); i++) {
            if (!isdigit(input[i])) {
                std::cout << "\nIts not correct number. Try again.\n";
                break;
            }
            if (i == input.length() - 1) {
                isNotNumber = false;
            }
        }
    } while (isNotNumber);
    return std::stoi(input);
}



int main()
{
    std::cout << "Program tests find number of local minimum matrix.\n";
    int I, J;
    std::cout << "\nEnter size of matrix: i - rows, j - columns.\n";
    std::cout << "i = ";
    std::string input;
    bool isNotNumber = true;

    I = CorrectInput();
    std::cout << "\nj = ";
    J = CorrectInput();
    int** matrix = new int* [I];
    for (int i = 0; i < I; i++) {
        matrix[i] = new int[J];
    }
    std::cout << "\nEnter elements of matrix a(i)(j); first number - row, second - column\n";
    for (int i = 0; i < I; i++) {
        for (int j = 0; j < J; j++) {
            std::cout << i + 1 << " " << j + 1 << ": ";
            matrix[i][j] = CorrectInput();
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < I; i++) {
        for (int j = 0; j < J; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    int lminimals = 0;
    //int count = 0;
    for (int i = 0; i < I; i++) {
        for (int j = 0; j < J; j++) {
            int a = i + 1;
            int b = j + 1;

            if (a == I) {
                a = i - 1;
            }
            if (b == J) {
                b = j - 1;
            }
            if (matrix[i][b] > matrix[i][j] && matrix[a][b] > matrix[i][j] && matrix[abs(i - 1)][b] > matrix[i][j] && matrix[abs(i - 1)][j] > matrix[i][j] && matrix[a][j] > matrix[i][j] && matrix[i][abs(j - 1)] > matrix[i][j] && matrix[abs(i - 1)][abs(j - 1)] > matrix[i][j] && matrix[a][abs(j - 1)] > matrix[i][j]) {
                lminimals++;
            }
        }
    }
    std::cout << "Number of local minimums: " << lminimals;

    for (int i = 0; i < I; i++) {
        delete[] matrix[i];
    }
    return 0;
}

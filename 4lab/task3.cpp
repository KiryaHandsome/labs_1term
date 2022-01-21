#include <iostream>
#include <string>

int main()
{
    std::cout << "Program tests the matrix for a magic square.\n";
    std::string input;
    std::cout << "\nEnter order of matrix:";
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
    int n = std::stoi(input);
    int** square = new int* [n];
    for (int i = 0; i < n; i++) {
        square[i] = new int[n];
    }
    std::cout << "\nEnter elements of matrix a(i)(j); i - row, j - column\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << i + 1 << " " << j + 1 << ": ";
            std::cin >> square[i][j];
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << square[i][j] << " "; //output matrix
        }
        std::cout << std::endl;
    }
    int sum = 0;
    for (int j = 0; j < n; j++) {
        sum += square[0][j]; //sum of 1 column
    }

    int sum1 = 0, sum2 = 0, j = 0;
    bool isMagic = true;
    for (int i = 0; i < n; i++) {
        sum1 = 0;
        sum2 = 0;
        j = 0;
        for (j; j < n; j++) {
            sum1 += square[i][j];
            sum2 += square[j][i];
        }
        if (sum1 != sum || sum2 != sum) {
            std::cout << "Its not magical square :(";
            j = n; //exit from cycles
            i = n;
            isMagic = false;
        }
    }
    if (isMagic) {
        std::cout << "Its magical square!";
    }
    for (int i = 0; i < n; i++) {
        delete[] square[i];
    }
    return 0;
}


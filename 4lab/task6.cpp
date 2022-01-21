#include <iostream>
#include <iomanip>
#include <string>
int  CorrectInput(std::string massege)
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
    int N, M;
    std::cout << "Enter size of matrix: M - rows, N - columns.\n";
    M = CorrectInput("M = ");
    N = CorrectInput("N = ");

    //creating arrays
    int** matrix = new int* [M];
    for (int i = 0; i < M; i++) {
        matrix[i] = new int[N];
    }

    //input matrix
    std::cout << "\nEnter elements of matrix a(i)(j); first number - row, second - column\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << i + 1 << " " << j + 1 << ": ";
            std::cin >> matrix[i][j];
        }
        std::cout << std::endl;
    }
    //output matrix
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "\n\n";


    for (int i = M - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            for (int a = i; a >= 0; a--) {
                for (int b = j; b >= 0; b--) {
                    if (matrix[a][b] > matrix[i][j]) {
                        matrix[i][j] = matrix[a][b];
                    }
                }
            }
        }
    }
    for (int j = 0; j < N - 1; j++) {
        for (int i = 0; i < M - 1; i++) {
            if (matrix[i][j] > matrix[i + 1][j]) {
                matrix[i][j + 1] = matrix[i][j];
            }
        }
    }

    //output matrix
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    //deleting arrays
    for (int i = 0; i < M; i++) {
        delete[] matrix[i];
    }
    return 0;
}
// COMPLETED
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
    std::cout << "Program make the smooth matrix.\n ";
    int N, M;
    std::cout << "\nEnter size of matrix: M - rows, N - columns.\n";
    M = CorrectInput("M = ");
    N = CorrectInput("\nN = ");
    double** matrix = new double* [M + 2];
    for (int i = 0; i < M + 2; i++) {
        matrix[i] = new double[N + 2];
    }

    //input matrix
    std::cout << "\nEnter elements of matrix a(i)(j); first number - row, second - column\n";
    for (int i = 1; i < M + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            std::cout << i << " " << j << ": ";
            matrix[i][j] = CorrectInput(i + " " + j);
        }
        std::cout << std::endl;
    }

    //filling zeros
    for (int i = 0; i < M + 2; i += M + 1) {
        for (int j = 0; j < N + 2; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int j = 0; j < N + 2; j += N + 1) {
        for (int i = 1; i < M + 2; i++) {
            matrix[i][j] = 0;
        }
    }

    //output matrix
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    double** arr = new double* [M];
    for (int i = 0; i < M; i++) {
        arr[i] = new double[N];
    }

    double sum;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            sum = matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i - 1][j + 1] + matrix[i][j - 1] + matrix[i][j + 1] + matrix[i + 1][j - 1] + matrix[i + 1][j] + matrix[i + 1][j + 1];
            if ((i == 1 && j == 1) || (i == 1 && j == N) || (i == M && j == N) || (i == M && j == 1)) {
                arr[i - 1][j - 1] = sum / 3.0;
            }
            else if (i == 1 || i == M || j == 1 || j == N) {
                arr[i - 1][j - 1] = sum / 5.0;
            }
            else {
                arr[i - 1][j - 1] = sum / 8.0;
            }
        }
    }
    std::cout << "Smooth matrix:\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << std::setprecision(2) << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < M + 2; i++) {
        delete[] matrix[i];
    }
    for (int i = 0; i < M; i++) {
        delete[] arr[i];
    }
    return 0;
}
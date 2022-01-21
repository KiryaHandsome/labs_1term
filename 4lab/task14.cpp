#include <iostream>
#include <iomanip>
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
    std::cout << "Program make field for sapper.\n";
    int N, M;
    std::cout << "\nEnter size of field: M - rows, N - columns.\n";
    M = CorrectInput("M = ");
    N = CorrectInput("N = ");
    char** bomb = new char* [M + 2];
    for (int i = 0; i < M + 2; i++) {
        bomb[i] = new char[N + 2];
    }

    //input matrix
    std::cout << "\nEnter elements of field first number - row, second - column (bomb = '*' , other = '-')\n";
    for (int i = 1; i < M + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            std::cout << i << " " << j << ": ";
            std::cin >> bomb[i][j];
        }
        std::cout << std::endl;
    }

    //filling zeros
    for (int i = 0; i < M + 2; i += M + 1) {
        for (int j = 0; j < N + 2; j++) {
            bomb[i][j] = 0;
        }
    }
    for (int j = 0; j < N + 2; j += N + 1) {
        for (int i = 1; i < M + 2; i++) {
            bomb[i][j] = 0;
        }
    }

    //output matrix
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (bomb[i][j] != '*') {
                std::cout << "- ";
            }
            else {
                std::cout << bomb[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }

    //creating array for field
    char** arr = new char* [M];
    for (int i = 0; i < M; i++) {
        arr[i] = new char[N];
    }

    //check for bomb
    int counter;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            counter = 0;
            if (bomb[i][j] != '*') {
                if (bomb[i - 1][j - 1] == '*') counter++;
                if (bomb[i - 1][j] == '*') counter++;
                if (bomb[i - 1][j + 1] == '*') counter++;
                if (bomb[i][j - 1] == '*') counter++;
                if (bomb[i][j + 1] == '*') counter++;
                if (bomb[i + 1][j - 1] == '*') counter++;
                if (bomb[i + 1][j] == '*') counter++;
                if (bomb[i + 1][j + 1] == '*') counter++;
                arr[i - 1][j - 1] = counter + '0';
            }
            else {
                arr[i - 1][j - 1] = '*';
            }
        }
    }

    std::cout << "\nField for sapper:\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << arr[i][j] << "  ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < M + 2; i++) {
        delete[] bomb[i];
    }
    for (int i = 0; i < M; i++) {
        delete[] arr[i];
    }
    return 0;
}
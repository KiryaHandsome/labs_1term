#include <iostream>
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
    int M, N, K;
    std::cout << "Program multiply 2 matrices." << std::endl;
    std::cout << "Enter size of matrices  M , N and K (M x N & N x K):\n";
    M = CorrectInput("M = ");
    N = CorrectInput("N = ");
    K = CorrectInput("K = ");
    //creating matrix
    int** A = new int* [M];
    for (int i = 0; i < M; i++) {
        A[i] = new int[N];
    }
    int** B = new int* [N];
    for (int i = 0; i < N; i++) {
        B[i] = new int[K];
    }
    int** result = new int* [M];
    for (int i = 0; i < M; i++) {
        result[i] = new int[K];
    }

    //inputing matrix
    std::cout << "\nEnter elements of the first matrix (first number - row, second - column)\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << i + 1 << " " << j + 1 << ": ";
            A[i][j] = CorrectInput("");
        }
        std::cout << std::endl;
    }
    std::cout << "\nEnter elements of the second matrix (first number - row, second - column)\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            std::cout << i + 1 << " " << j + 1 << ": ";
            B[i][j] = CorrectInput("");
        }
        std::cout << std::endl;
    }

    //multiplying matrix
    int sum;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            sum = 0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            result[i][j] = sum;
        }
    }


    //output result-matrix
    std::cout << "Multiplied matrix:\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    //deleting arrays
    for (int i = 0; i < M; i++) {
        delete[] A[i];
        delete[] result[i];
    }
    for (int i = 0; i < N; i++) {
        delete[] B[i];
    }

    return 0;
}


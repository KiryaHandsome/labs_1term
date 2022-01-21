#include <iostream>
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
    std::cout << "Program find diagonal of cube with max sum of numbers";
    int n;
    n = CorrectInput("Enter n(size of cube):");

    //creating an array
    int*** cube = new int** [n];
    for (int i = 0; i < n; i++) {
        cube[i] = new int* [n];
        for (int j = 0; j < n; j++) {
            cube[i][j] = new int[n];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                std::cout << i + 1 << " " << j + 1 << " " << k + 1 << ":";
                cube[i][j][k] = CorrectInput("");
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }


    //sum of diagonals
    int* sum = new int[4];
    for (int i = 0; i < 4; i++) {
        sum[i] = 0;
    }
    for (int a = 0, b = 0, c = 0; a < n; a++, b++, c++) {
        sum[0] += cube[a][b][c];
    }
    for (int a = 0, b = 0, c = n - 1; a < n; a++, b++, c--) {
        sum[1] += cube[a][b][c];
    }
    for (int a = 0, b = n - 1, c = 0; a < n; a++, b--, c++) {
        sum[2] += cube[a][b][c];
    }
    for (int a = n - 1, b = 0, c = 0; a > 0; a--, b++, c++) {
        sum[3] += cube[a][b][c];
    }
    int max = 0;
    for (int i = 0; i < 4; i++) {
        if (sum[i] > max) {
            max = sum[i];
        }
    }
    std::cout << "Max sum of diagonal: " << max;
    //deleting arrays
    delete[] sum;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            delete[] cube[i][j];
        }
        delete[] cube[i];
    }
    return 0;
}

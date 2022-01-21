#include <iostream>


int correctInput()          //for negative numbers
{
    char str[10];
    bool isNotNumber;
    do {
        isNotNumber = false;
        std::cin >> str;
        for (int i = 0; i < strlen(str); i++) {
            if (((int)str[i] < 48 || (int)str[i] > 57) && str[0] != '-') {
                std::cout << "\nIts not correct number. Try again.\n";
                isNotNumber = true;
                break;
            }
        }
    } while (isNotNumber);

    return atoi(str);
}
int correctInput(const char* massege)       //for positive numbers
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
void outputMatrix(int** matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    std::cout << "Program make new array from even elements main diagonal.\nEnter size of matrix(n x k):\n";
    int n, k;
    n = correctInput("n = ");
    k = correctInput("\nk = ");
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int [k];
    }
    for (int i = 0; i < n; i++) {   //input matrix
        for (int j = 0; j < k; j++) {
            std::cout << i + 1 << " " << j + 1 << ":";  
            matrix[i][j] = correctInput();   
        }
        std::cout << "\n";
    }
    std::cout << "Your array:\n";
    outputMatrix(matrix, n, k);
    int counter = 0;
    int tmp = 0;
    while (tmp < n && tmp < k) {
        if (matrix[tmp][tmp] % 2 == 0) {    //count number of even elements of main diagonal
            counter++;
        }
        tmp++;
    }
    if (counter != 0) {
        int* array = new int[counter];
        tmp = 0, counter = 0;
        while (tmp < n && tmp < k) {
            if (matrix[tmp][tmp] % 2 == 0) {    //add even elements of main diagonal to new array
                array[counter] = matrix[tmp][tmp];
                counter++;
            }
            tmp++;
        }
        int mult = 1;
        for (int i = 0; i < counter; i++) {
            mult *= array[i];
        }
        std::cout << "New array:\n";
        for (int i = 0; i < counter; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << "\nResult of multiply new array's elements: " << mult;
        delete[] array;
    }
    else {
        std::cout << "There is no even elements main diagonal :(";
    }
    
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}

#include <iostream>
#include "pch.h"


int main()
{
    std::cout << "Program make transposed matrix and calculate sum of even rows and odd columns matrix A and sum of odd rows and even columns matrix B\n";
    const int n = 10;
    int** matrix = new int* [n];    //create dynamic array
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {   
        for (int j = 0; j < n; j++) {
            if (i <= 5) {
                matrix[i][j] = 2 * i * raiseNumber(j, 2) - 2 * j;   //fill matrix
            }
            else {
                matrix[i][j] = 3 * i * j - 3;
            }
        }
    }
    int** transMatrix = new int* [n];    //create dynamic array for transposed matrix
    for (int i = 0; i < n; i++) {
        transMatrix[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transMatrix[i][j] = matrix[j][i];   //transposing matrix
        }
    }
    int sum1 = sumEvenRowOddCol(matrix, n, n);  //sum of even rows and odd columns matrix A
    int sum2 = sumOddRowEvenCol(transMatrix, n, n); //sum of odd rows and even columns matrix B
    std::cout << "Original matrix:\n";
    outputMatrix(matrix, n, n);
    std::cout << "Transposed matrix:\n";
    outputMatrix(transMatrix, n, n);
    std::cout << "sum of even rows and odd columns matrix A: " << sum1 << "\n";
    std::cout << "sum of odd rows and even columns matrix B: " << sum2;
    for (int i = 0; i < n; i++) {   //deleting arrays
        delete[] transMatrix[i];
    }
    delete[] transMatrix;
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}

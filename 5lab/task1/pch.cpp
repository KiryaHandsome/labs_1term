
#include "pch.h"
#include "framework.h"
#include <iostream>



int raiseNumber(int a, int b) {
	int result = 1;
	for (int i = 0; i < b; i++) {
		result *= a;
	}
	return result;
}
int sumEvenRowOddCol(int** matrix, int rows, int columns) {
	int result = 0;
	for (int i = 0; i < rows; i += 2) {
		for (int j = 1; j < columns; j += 2) {
			result += matrix[i][j];
		}
	}
	return result;
}
int sumOddRowEvenCol(int** matrix, int rows, int columns) {
	int result = 0;
	for (int i = 1; i < rows; i += 2) {
		for (int j = 0; j < columns; j += 2) {
			result += matrix[i][j];
		}
	}
	return result;
}
void outputMatrix(int** matrix, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			printf("%4d", matrix[i][j]);
		}
		printf("\n");
	}
	
}


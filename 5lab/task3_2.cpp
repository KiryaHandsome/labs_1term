#include <iostream>

int correctInput(const char* massege)		//for positive numbers
{
	char str[10];
	bool isNotNumber;
	do {
		isNotNumber = false;
		std::cout << massege;
		std::cin >> str;
		for (int i = 0; i < strlen(str); i++) {
			if (((int)str[i] < 48 || (int)str[i] > 57) ) {
				std::cout << "\nIts not correct number. Try again.\n";
				isNotNumber = true;
				break;
			}
		}
	} while (isNotNumber);

	return atoi(str);
}
int correctInput()			//for negative numbers
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
void outputMatrix(double** matrix, int rows, int columns) {			//for double array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}
void outputMatrix(int** matrix, int rows, int columns) {		   //for integer array reverse
	for (int i = rows - 1; i >= 0; i--) {
		for (int j = columns - 1; j >= 0; j--) {
			printf("%4d", matrix[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	std::cout << "Program find zero elements in matrix and output their locations in reverse array\n";
	int n, m;
	std::cout << "Enter size of array(N x M)\n";
	n = correctInput("N = ");
	m = correctInput("M = ");
	double** matrix = new double* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new double[m];
	}
	int counter = 0;
	std::cout << "Enter elemets of array:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << i + 1 << " " << j + 1 << ":";
			matrix[i][j] = correctInput();
			if (matrix[i][j] == 0) {
				counter++;
			}
		}
	}
	int** zeros = new int* [counter];
	for (int i = 0; i < counter; i++) {
		zeros[i] = new int[2];
	}
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {
				zeros[tmp][0] = i + 1;
				zeros[tmp][1] = j + 1;
				tmp++;
			}
		}
	}
	std::cout << "indexes zero-elements of array:\n";
	outputMatrix(zeros, tmp, 2);
	for (int i = 0; i < counter; i++) {
		delete[] zeros[i];
	}
	delete[] zeros;
	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}
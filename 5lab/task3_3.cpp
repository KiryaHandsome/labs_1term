#include <iostream>



int correctInput(const char* massege)
{
	char str[10];
	bool isNotNumber;
	do {
		isNotNumber = false;
		std::cout << massege;
		std::cin >> str;
		for (int i = 0; i < strlen(str); i++) {
			if (((int)str[i] < 48 || (int)str[i] > 57)) {
				std::cout << "\nIts not correct number. Try again.\n";
				isNotNumber = true;
				break;
			}
		}
	} while (isNotNumber);

	return atoi(str);
}

void initialArray(int** arr, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << i + 1 << " " << j + 1 << ":";
			arr[i][j] = correctInput("");
		}
	}
}

int main()
{
	std::cout << "Program count average ariphmetic array which consist of odd elements in even columns.\n";
	int n, m;
	std::cout << "Enter size of array(N x M)\n";
	n = correctInput("N = ");
	m = correctInput("M = ");
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[m];
	}
	initialArray(matrix, n, m);
	int counter = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < m; j += 2) {	//count number odd elements
			if (matrix[i][j] % 2 == 1) {
				counter++;
			}
		}
	}
	if (counter != 0) {
		int* array = new int[counter];
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m; j += 2) {
				if (matrix[i][j] % 2 == 1) {	//initialize new array
					array[tmp] = matrix[i][j];
					tmp++;
				}
			}
		}
		double average = 0;
		for (int i = 0; i < counter; i++) {		//calcilate sum 
			average += array[i];
		}
		average /= counter;		//calculate average ariphmetic
		std::cout << "Average ariphmetic:" << average;
		delete[] array;
	}
	else {
		std::cout << "Odd elements in even columns not founded";
	}
	

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}

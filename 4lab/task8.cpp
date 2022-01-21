#include <iostream>
#include <cmath>
#include <ctime>
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
	int N;
	std::cout << "Program deletes elements of array which situated between max and min number.\n";
	N = CorrectInput("Enter size of array:");
	int* arr = new int[N];
	bool isSame;
	int r, k;
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		do {
			k = 0;
			r = 1 + rand() % N;
			isSame = false;
			do {
				if (r == arr[k]) {
					isSame = true;
				}
				k++;
			} while (k < i && !isSame);

		} while (isSame);
		arr[i] = r;
		std::cout << r << " ";
	}
	std::cout << std::endl;
	int max = arr[0], min = arr[0];
	int num_max = 0, num_min = N;
	for (int i = 1; i < N; i++) {
		if (arr[i] > max) {
			max = arr[i];
			num_max = i;
		}
		if (arr[i] < min) {
			min = arr[i];
			num_min = i;
		}
	}

	std::cout << "Max = " << max << "\n" << "Min = " << min << std::endl;

	int left, right;
	if (num_min > num_max) {
		left = num_max;
		right = num_min;
	}
	else {
		left = num_min;
		right = num_max;
	}
	int counter = 0;
	for (int i = 0; i < N; i++) {
		if (i > left && i < right) {
			arr[i] = 0;
			counter++;
		}
	}
	if (counter > N / 2) {
		int* second = new int[counter];
		int j = 0;
		for (int i = 0; i < N; i++) {
			second[j] = arr[i];
			if (i == left - 1) {
				i = right + 1;
			}
			j++;
		}
		for (int i = 0; i < N - counter; i++) {
			std::cout << second[i] << " ";
		}
		delete[]second;
	}
	else {
		for (int i = 0; i < N; i++) {
			std::cout << arr[i] << " ";
		}
	}
	delete[] arr;
	return 0;
}

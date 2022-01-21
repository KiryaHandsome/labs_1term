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

int DeleteCopy(int size, int* arr)
{
	int counter = size;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] != NULL && arr[i] == arr[j]) {
				arr[j] = NULL;
				counter--;
			}
		}
	}
	int* second = new int[counter];
	int m = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] != NULL) {
			second[m] = arr[i];
			m++;
		}
	}
	std::cout << "Size of new array: " << counter << std::endl;
	std::cout << "New array: ";
	for (int i = 0; i < counter; i++) {
		std::cout << second[i] << " ";
	}
	std::cout << "\n";
	return size;
	return arr[size];
	delete[] arr;
	delete[] second;
}

int main()
{
	int size;
	size = CorrectInput("Enter size of array: ");
	int* arr = new int[size];
	std::cout << "Enter array: ";
	for (int i = 0; i < size; i++) {
		arr[i] = CorrectInput("");
	}
	DeleteCopy(size, arr);
	return 0;
}

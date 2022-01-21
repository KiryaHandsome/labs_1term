#include <iostream>
#include <string>
#include <cmath>


double func(int* arr, int start, int end){
	int l = end - start;
	int pos = start + l / 3;
	if (l > 0) return func(arr, start, pos) * func(arr, pos + 1, end);
	else return (sin(arr[start]) - cos(arr[start]));
}
int correctInput(std::string messege = "") {
	std::string input;
	bool isNotNumber;
	do {
		isNotNumber = false;
		std::cout << messege;
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


int main(){
	int N = 0;
	bool isCorrect = false;
	while (!isCorrect) {
		N = correctInput("Enter size of array(N > 0):N = ");
		if (N != 0) isCorrect = true;
		else std::cout << "\nIt must be not zero number. Try again.\n";
	}
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		arr[i] = correctInput();
	}
	double multpl = 1;

	multpl = func(arr, 0, N - 1);
	std::cout << multpl << " multiply with function\n";
	double res = 1;
	for (int i = 0; i < N; i++) {
		res *= sin(arr[i]) - cos(arr[i]);
	}
	std::cout << res << " multiply with loop";
	delete[] arr;
	return 0;
	
}


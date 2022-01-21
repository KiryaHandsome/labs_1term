// MathClient.cpp : Client app for MathLibrary DLL.
// #include "pch.h" Uncomment for Visual Studio 2017 and earlier
#include <iostream>
#include <string>
#include "MathLibrary.h"

int main()
{
	int N;
	N = correctInput("Enter size of array(N > 0):N = ");
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		arr[i] = correctInput("");
	}
	double multpl = 1;

	multpl = func(arr, N / 3, 0) * func(arr, N, N / 3);
	std::cout << multpl << " multiply with function\n";
	double res = 1;
	for (int i = 0; i < N; i++) {
		res *= sin(arr[i]) - cos(arr[i]);
	}
	std::cout << res << " multiply with loop";
	delete[] arr;
	return 0;
}
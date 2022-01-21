// MathLibrary.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include <string>
#include <iostream>
#include "MathLibrary.h"

double func(int* arr, int end, int i)
{
	if (i < end) return (sin(arr[i]) - cos(arr[i])) * func(arr, end, i + 1);
	return 1;
}
int correctInput(std::string messege)
{
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


#include <iostream>
#include <string>
#include <cctype>

int main()
{
	std::string number;
	int n = 0;
	int digit;
	std::string w;
	bool isNumber = true;
	std::cout << "Program count the digits and output digit with entered number.\nEnter a number:";
	do {
		std::cin >> number;
		for (int i = 0; i < number.length(); i++) {

			if (!isdigit(number[i])) {
				std::cout << "\nIts not number. Try again.\n";
				break;
			}
			if (i == number.length() - 1) {
				std::cout << "Digits: " << number.length();
				std::cout << "\nEnter number of digit:";
				do {
					std::cin >> w;

					for (int j = 0; j < w.length(); j++) {

						if (!isdigit(w[j])) std::cout << "Its not number. Try again.\n";

						if (j == w.length() - 1) {

							digit = std::stoi(w);

							if (digit < 0 || digit >= number.length()) std::cout << "Invalid input. You missed. Try again.";

							else {
								std::cout << "Its digit " << number[number.length() - digit - 1];
								isNumber = false;
							}
						}
					}
				} while (isNumber);


			}
		}
	} while (isNumber);
	return 0;
}
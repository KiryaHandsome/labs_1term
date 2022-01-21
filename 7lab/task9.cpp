#include <iostream>
#include <string>

using namespace std;





int mySize(string str)
{
	int counter = 0;
	while ((int)(str[counter]) > 0 && (int)(str[counter]) < 256) counter++;
	return counter;
}
char toString(int a) //for positive numbers
{
	return (char)(a + 48);
}
int myStoi(std::string str)
{
	int result = 0;
	int sign = 1;
	if (str[0] == '-') sign = -1;
	for (int i = 0; i < mySize(str); i++) {
		if (str[i] != '-') result += (int(str[i]) - 48) * pow(10, mySize(str) - 1 - i);
	}
	return sign * result;
}
void myErase(string& str, const int& position)  //delete 1 element 
{
	int tmp = 0;
	for (int i = position; i < mySize(str); i++) {
		tmp = str[i];
		str[i] = str[i + 1];
		str[i + 1] = tmp;
	}
}
string ConvToThree(const int &num)
{
	string result;
	int tmp = num;
	while (tmp > 0) {
		result += toString(tmp % 3);
		tmp /= 3;
	}
	int place = 0;
	for (int i = 0; i < mySize(result) / 2; i++) {
		place = result[i];
		result[i] = result[mySize(result) - 1 - i];		//inverse number
		result[mySize(result) - 1 - i] = place;
	}
	return result;
}
string ConvToNewThree(const string &num)
{
	string result = num;
	int counter = 0;
	for (int i = 1; i < mySize(result); i++) {
		if (result[i] == '0') {
			result[i - 1] = char((int)result[i - 1] - 1);
			result[i] = '3';
		}
	}
	for (int i = 0; i < mySize(result); i++) {
		if (result[i] == '0') myErase(result, i);
	}
	return result;
}
int CorrectInput(const char massege[] = "")       //for positive numbers
{
	char str[13];
	bool isNotNumber;
	do {
		cout << massege;
 		isNotNumber = false;
		cin >> str;
		for (int i = 0; i < strlen(str); i++) {
			if ((int)str[i] < 49 || (int)str[i] > 57 || atoi(str) > pow(10, 9)) {
				std::cout << "\nInvalid input. Try again.\n";
				isNotNumber = true;
				break;
			}
		}
	} while (isNotNumber);

	return atoi(str);
}

int main()
{
	cout << "Programm convert number to 1, 2, 3 system.\n";
	int number = 0;
	number = CorrectInput("Enter your number:");
	string result = ConvToNewThree(ConvToThree(number));
	cout << "Your number in 1,2,3 numeral system: " << result;
	return 0;
}
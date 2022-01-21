//Program without arrays
#include <iostream>    
#include <cmath>


using namespace std;


int ConvToDec(const int &a)
{
	int sign = 1;
	if (a < 0) sign = -1;
	int counter = 0, tmp = abs(a);   //counter - number of bits
	while (tmp > 0) {
		tmp /= 10;
		counter++;
	}
	tmp = abs(a);   //return value
	int result = 0;
	for (int i = 0; i < counter; i++) {
		result += pow(9, i) * (tmp % 10);
		tmp /= 10;
	}
	return sign * result;
}
void ConvToEleven(const int &a)
{
	int dec = abs(ConvToDec(a));
	int tmp = dec;
	int rem = 0;  //remainder
	int counter = 0;
	while (tmp > 0) {
		rem = tmp % 11;
		tmp /= 11;
		counter++;
	}
	if (a < 0) cout << '-';
	for (int i = counter - 1; i >= 0; i--) {
		if ((dec / (int)pow(11, i)) % 11 == 10) cout << 'A';  //output digits inverse
		else cout << (dec / (int)pow(11, i)) % 11;
	}
	cout << " - your number in 11 digits system";
}


int main()
{
	cout << "Program convert integer numbers from 9 to 11 digits system.\nEnter number in 9 digits system(there is no 9):";
	int a;
	cin >> a;
	ConvToEleven(a);
	return 0;
}
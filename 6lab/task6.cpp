#include <iostream>


int factorial(int a)
{
    if (a > 1) return a * factorial(a - 1);
    return 1;
}
long long int anagram(char* str)
{
    int* arr = new int[14];
    for (int i = 0; i < 14; i++) {      //fill 1
        arr[i] = 1;
    }
    for (int i = 0; i < strlen(str); i++) {
        for (int j = i + 1; j < strlen(str); j++) {
            if (str[i] == str[j] || (int)str[i] == (int)str[j] + 32 || (int)str[i] + 32 == (int)str[j]) {         //compare with next elements(big and small letters)
                arr[i]++;
            } 
            for (int k = 0; k < i; k++) {   
                if (str[k] == str[i] || str[k] == str[i] + 32 || str[k]  + 32 == str[i]) arr[i] = 1;     //if same elements was back we dont count them
            }
        }
    }
    long long int result = factorial(strlen(str));
    for (int i = 0; i < 14; i++) {
        result /= factorial(arr[i]);    //calculate res = n!/(n1!*n2!*...*nk!), n = number of letters in word, k - number different letters
    }
    return result;
    delete[] arr;
}

int main()
{
    std::cout << "Program count anagrams of input word";
    char* str = new char[16];
    std::cin.getline(str, 16);
    std::cout << anagram(str) << " - number of anagrams";
    delete[] str;
    return 0;
}

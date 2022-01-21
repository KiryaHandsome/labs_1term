
#include <iostream>
#include <string>

int main()
{
    std::cout << "Program calculate sum of numbers in string.\nEnter a string:";
    std::string str;
    getline(std::cin, str, '\n');
    std::string* arr = new std::string[str.length()];   //array for numbers
    int counter;    //counter for string
    int tmp = 0;    //counter for new array
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i])) {
            counter = i;
            while (isdigit(str[counter])) {     //find next not-digit element
                counter++;
            }
            arr[tmp] = str.substr(i, counter);  //cut this number in new array
            tmp++;
            i = counter;   
        }
    }
    int sum = 0;
    for (int i = 0; i < tmp; i++) {
        sum += stoi(arr[i]);    //convert to numbers and calculate sum
    }
    std::cout << sum << " - sum of numbers";
    delete[] arr;
    return 0;
}


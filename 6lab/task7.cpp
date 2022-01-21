#include <iostream>
#include <string>

bool isSolid(std::string str)
{  
    for (int i = 1; i < str.length(); i++) {        //string consist from 1 symbol
        if (str[0] != str[i]) {
            return false;
        }
    }
    return true;
}
bool isPolyndrom(std::string str)           //check polyndrom or not
{
    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i] != str[str.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}


int main()
{
    std::string str;
    std::cin >> str;
    if (!isSolid(str)) {
        if (isPolyndrom(str)) {             
            std::cout << str.length() - 1;  
        }
        else {
            std::cout << str.length();
        }
    }
    else {
        std::cout << -1;
    }
    return 0;
}

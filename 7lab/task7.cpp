#include <iostream>

int add(int num1, int num2) {       
    int res = 0, carry = 0;
    res = num1 ^ num2;
    carry = (num1 & num2) << 1;
    while (carry) {
        int tmp = res;
        res = res ^ carry;
        carry = (tmp & carry) << 1;
    }
    return res;
}
int negative(int& n) {    
    n = ~n;  
    return add(n, 1);
}
int subtraction(int a, int b) {
    return add(a, negative(b));
}




int main()
{
    std::cout << "Program check your number for divisibility by 7, 73 and 109.\n Enter your number:";
    int a;
    std::cin >> a;
    int tmp = abs(a);
    int arr[] = { 7, 73, 109 };
    for (int i = 0; i < 3; i++) {
        tmp = abs(a);
        while (tmp > 0) {
            tmp = subtraction(tmp, arr[i]);
        }
        if (tmp == 0) std::cout << "number divided by " << arr[i] << "\n";
        else std::cout << "number not divided by " << arr[i] << "\n";
    }
    
    return 0;
}


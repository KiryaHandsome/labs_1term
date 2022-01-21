#include <iostream>
using namespace std;

int main()
{
    double a,b,c,x;
    cin >> x;
    c = 23 * x * x;
    a = x * (c + 32);
    b = 3 * c + 8;
    cout << a + b << " " << b - a;
    return 0;
}

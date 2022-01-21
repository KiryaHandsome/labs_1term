#include <iostream>

using namespace std;

int main()
{
    double a1,a100,d,s19;
    cin>>a1>>a100;
    d=(a100-a1)/99;
    s19=(a1+9*d)*19;
    cout<<d<<"-разность прогрессии "<<s19<<"-сумма 19 членов арифметической прогрессии";
    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int h1,min1,h2,min2,a,b,h,min;
    cin>>h1>>min1>>h2>>min2;
    a=h1*60+min1;
    b=h2*60+min2;
    h=(b-a)/60;
    min=(b-a)%60;
    cout<<"Задача заняла "<<h<<" часа(ов) и "<<min<<" минут(ы)";
    return 0;
}
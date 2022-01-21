#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double A,B,C,D,K,Y,p,x,z; 
    cin>>C>>D>>K>>p>>x>>z;
    A=sin(x)-z;
    B=fabs(p-x);
    Y=pow(A+B,2)-K/(C*D);
    cout<<Y;
    return 0;
}


#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double V0,t,a,S;
    cin>>V0>>t>>a;
    S=V0*t+a*pow(t,2)/2;
    cout<<S;
    return 0;
}
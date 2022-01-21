#include <iostream>

using namespace std;

int main()
{
    double b1,s,q;
    cin>>b1;
    q=0.1; //????(как присвоить 1/10)
    s=b1/(1-q);
    cout<<s<<"-сумма членов убывающей геометрической прогрессии";
    return 0;
}
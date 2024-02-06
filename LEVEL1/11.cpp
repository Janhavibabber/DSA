#include <iostream>
using namespace std;

void greatest(int x, int y)
{
    if(x>=y)
        cout<<x;
    else
        cout<<y;
}

int main()
{
    int a;
    cin>>a;
    int b;
    cin>>b;
    greatest(a,b);
    return 0;
}
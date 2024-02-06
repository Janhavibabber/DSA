#include <iostream>
using namespace std;

void swap(int x, int y)
{
    x = x+y;
    y = x-y;
    x = x-y;
    cout << x << y;
}

int main()
{
    int a;
    cin>>a;
    int b;
    cin>>b;
    swap(a,b);
    return 0;
}

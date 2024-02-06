#include<iostream>
using namespace std;

int main()
{
    int n, num=0;
    cin>>n;

    if(n == 0)
        num=1;
    while (n > 0)
    {
        int rem = n%10;
        if(rem == 0)
            rem = 1;
        n = n/10;
        num = num*10+rem;
    }
    cout<<num;
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

bool isPowerofFour(int n)
{
    if(n == 0)
        return false;
    if((n & (n-1)) == 0)
    {
        if((n & 0b01010101010101010101010101010101) == 0)
            return true;
        else
            return false;
    }
    else
        return false;
}
// return (n>0) && ((n & (n-1)) == 0) && ((n & 0b01010101010101010101010101010101) == 0);

int main()
{
    int n;
    cin>>n;
    if(isPowerofFour(n))
        cout<< "Power of 4";
    else
        cout<<"not a power";
    return 0;
}
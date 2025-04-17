#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int i = 0;
    int ans = 0;

    while (n != 0)
    {
        // extract last digit of ip
        int digit = n%10;
        // if it's 1 then do further calculation
        // if it's 0 then do nothing
        if (digit == 1)
        {
            ans = ans + pow(2, i);
        }

        // decrease length of ip
        n = n/10 ;
        i++;
    }
    cout<< ans;
    return 0;
}
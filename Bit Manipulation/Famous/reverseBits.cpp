// Reverse bits of a given 32 bits unsigned integer
#include<bits/stdc++.h>
using namespace std;

int reverse(int n)
{
    int temp = 0;
    int res = 0;
    for (int i = 0; i < 32; i++)
    {
        //  reverse krne k liye
        res = res<<1;
        // last bit extract krne k liye
        temp = n&1;
        // last bit eliminate krne k liye
        n = n>>1;
        // reverse bit result m add krne k liye
        res = temp | res;
    }
    return res;
}

int main()
{
    int res;
    cin>>res;
    cout<<reverse(res);
    return 0;
}
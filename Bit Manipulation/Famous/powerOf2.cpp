// to check if a binary no. is divisible by 2 or not
#include<bits/stdc++.h>
using namespace std;

int power(int n)
{
    return n && !(n & n-1);
}

int main()
{
    cout << power(16) << endl;
    return 0;
}

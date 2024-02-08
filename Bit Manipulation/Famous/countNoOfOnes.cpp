#include<bits/stdc++.h>
using namespace std;

int countOnes(int n)
{
    int count = 0;
    while(n)
    {
        n = n & n-1;
        count++;
    }
    return count;
}

int main()
{
    cout << countOnes(19) << endl;
    return 0;
}

// efficient solution - brain kerighan algo

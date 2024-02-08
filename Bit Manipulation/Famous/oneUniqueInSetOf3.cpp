#include<bits/stdc++.h>
using namespace std;

int getBit(int n, int pos)
{
    return (n & (1 << pos) != 0);
}

int setBit(int n,int pos)
{
    return (n | (1 << pos));
}

int oneUnique(int arr[], int n)
{
    int res;
    for (int i = 0; i < 64; i++)
    {
        int sum = 0;
        
        for (int j = 0; j < n; j++)
        {
            if(getBit(arr[j],i))
                sum++;
        }
        if(sum % 3 != 0)
            res = setBit(res, i);
    }
     return res;
}

int main()
{
    int arr[] = {1,2,3,4,1,2,3,1,2,3};
    cout << oneUnique(arr,10) << endl;
    return 0;
}
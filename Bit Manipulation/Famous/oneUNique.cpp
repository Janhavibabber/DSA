#include<bits/stdc++.h>
using namespace std;

int oneUnique(int arr[], int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum =xorsum ^ arr[i];
    }
    return xorsum;
    
}

int main()
{
    int arr[]= {1,2,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << oneUnique(arr, n);
    return 0;
}
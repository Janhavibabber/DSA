#include<iostream>
using namespace std;

int solve(int *arr, int i, int n){

    if(i == n-1)
        return arr[i];
    
    return max(arr[i], solve(arr, i+1, n));
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout<< solve(arr, 0, n);
}
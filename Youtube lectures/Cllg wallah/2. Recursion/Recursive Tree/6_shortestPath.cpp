#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int i){
    if(i == n-1)
        return 0;
    if(i == n-2)
        return solve(arr, n, i+1)+abs(arr[i]-arr[i+1]);
    return min(solve(arr, n, i + 1) + abs(arr[i] - arr[i + 1]), solve(arr, n, i + 2) + abs(arr[i] - arr[i + 2]));
}

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<< solve(arr, n, 0);

    return 0;
}
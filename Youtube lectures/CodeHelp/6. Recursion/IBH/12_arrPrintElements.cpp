#include<iostream>
using namespace std;

int solve(int *arr, int i, int n){
    if(i == n)
        return arr[i];
    
    cout<<arr[i]<<" ";
    solve(arr, i+1, n);
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    solve(arr, 0, n);
    
    return 0;
}
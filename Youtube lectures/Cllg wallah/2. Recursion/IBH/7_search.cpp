#include<iostream>
using namespace std;

bool solve(int arr[], int n, int x, int i){
    if(i==n)
        return false;
    // return (arr[i]==x) || solve(arr, n, x, i+1);
    return (arr[i] == x)? true: solve(arr, n, x, i + 1);
}

int main()
{
    int n, x;
    cin>>n>>x;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    if(solve(arr, 1, 2, 0))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
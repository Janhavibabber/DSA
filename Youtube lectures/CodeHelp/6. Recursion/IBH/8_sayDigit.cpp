#include<iostream>
using namespace std;

void solve (string arr[], int n){

    if(n==0)
        return;

    solve(arr, n/10);
    cout<<arr[n%10]<<" ";
}

int main()
{
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int n;
    cin>>n;

    solve(arr, n);

    return 0;
}
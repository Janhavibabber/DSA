// 12. Find sum of n no's with alternative sign i.e. 1-2+3-4+5=3
#include<iostream>
using namespace std;

int solve(int n){
    if(n==0) 
        return 0;
    return solve(n-1)+((n%2==0)?-n:n);
}

int main()
{
    int n;
    cin>>n;

    cout << solve(n);
    
    return 0;
}
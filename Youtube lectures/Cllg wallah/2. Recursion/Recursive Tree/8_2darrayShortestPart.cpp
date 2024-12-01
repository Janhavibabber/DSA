#include<iostream>
using namespace std;

int solve(int m, int n, int i, int j){
    if(i==m-1 && j==n-1)
        return 1;
    if(i>=m || j>=n)
        return 0;
    return solve(m, n, i, j+1) + solve(m, n, i+1, j);
}

int main()
{
    int m, n;
    cin>>m>>n;

    cout<<solve(m, n, 0, 0);
    
    return 0;
}
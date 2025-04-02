#include<iostream>
using namespace std;

void solve (int n, int k){
    if(k==0)
        return;
    
    solve(n, k-1);
    cout<<n*k<<" ";
}

int main()
{
    int n, k;
    cin>>n>>k;

    solve(n, k);

    return 0;
}
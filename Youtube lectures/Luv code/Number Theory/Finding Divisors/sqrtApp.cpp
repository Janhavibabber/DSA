// Time - o(sqrt(n))
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ct=0, sum=0;
    for(int i=0; i*i<=n; i++){
        if (n%i ==0)
        {
            cout<<i<<" "<<n/i<<endl;
            ct += 1;
            sum += i;
            if(n/i != i){
                sum += n/i;
                ct += 1;
            }
        }
    }
    cout<<ct<<" "<<sum<<endl;
    return 0;
}
// Time - o(n)
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ct = 0;
    int sum = 0;
    for(int i=0; i<=n; i++){
        if(n%i == 0){
            cout<<i<<endl;
            // count no. of divisors
            ct++;
            // sum of all divisors
            sum += i;
        }
        cout<<ct<<" "<<sum<<endl;
    }
    return 0;
}
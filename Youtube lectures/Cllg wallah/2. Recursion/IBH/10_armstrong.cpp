#include<bits/stdc++.h>
using namespace std;

int solve(int num, int d){
    
    if (num == 0)
        return 0;
    return pow(num % 10, d) + solve(num / 10, d);
}

int main()
{
    int num, d=0;
    cin>>num;

    int n = num;
    while(n!=0){
        n /= 10;
        d++;
    }

    // cout<<d<<" ";
    int res = solve(num, d);
    
    if(res == num){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    
    return 0;
}
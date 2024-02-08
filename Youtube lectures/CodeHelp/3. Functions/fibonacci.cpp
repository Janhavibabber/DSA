#include<iostream>
using namespace std;

int fib(int n){
    // given no. tk series print krna
    // int t1=0, t2=1;
    // int nt;

    // cout<<t1<<" "<<t2<<" ";
    // for (int i = 2; i < n; i++)
    // {
    //     nt = t1+t2;
    //     cout<<nt<<" ";
    //     t1=t2;
    //     t2=nt;
    // }
    
    // series k no. print krna given position input pr
    if(n==0 || n==1){
        return n;
    }

    return fib(n-2) + fib(n-1);    
}

int main()
{
    int n;
    cin >> n;

    int ans = fib(n);
    cout<<fib(n) << endl;
    // fib(n);
    return 0;
}
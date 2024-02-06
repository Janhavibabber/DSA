#include <bits/stdc++.h>
 
using namespace std;
/* Fibonacci Series*/
int fib(int n)
{
    if(n==0 || n==1)
        return n;
    return fib(n-1) + fib(n-2);

}
 

int main()
{
    int num;
    cin >> num;
    for (int i = 0; i <= num; i++)
    {
       cout << fib(i) <<" ";
    }
    // int limit, first=0, second=1, next, num;
    // cout <<“Enter the limit of Fibonacci series”<<endl;
    // // user input
    // cin >> num;   
    // cout << “First “<<num<<” terms of Fibonacci series are :- “<<endl;
    // //loop for printing fibonacci series
    // for(int p=0;p<num;p++)
    // {
    //     if (p <= 1)
    //         next = p;
    //     else
    //     {
    //         next = first + second;
    //         first = second;
    //         second = next;
    //     }
    //     cout<<next<<” “;
    // }
    
    
    getchar();
    return 0;
}
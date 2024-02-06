#include <bits/stdc++.h>
 
using namespace std;
// Factorial of a number
int factorial(int n)
{
    if(n==0 || n==1)
        return 1;
    return n * factorial(n-1);


    // For loop approach 1
    // int res = 1, i;
    // for (i = 2; i <= n; i++)
    //     res *= i;
    // return res;


    // For loop Approach 2
//     for(int i=num;i>0;i–)
//             {
//                 fact*=i;
//             }
//     cout<<“Factorial of “<<num<<” is “<<fact;
}
 

int main()
{
    int num;
    cin >> num;
    cout << factorial(num);
    
    getchar();
    return 0;
}
// Number of times the digit x occurs in the given number.
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; //given number
    int d; //given digit;
    int count = 0; 
    cin>> n>>d;
    while (n)
    {
        int k = n%10;
        n = n/2;
        if(k == d)
            count++;
    }
    cout<< count;
    
    return 0;
}
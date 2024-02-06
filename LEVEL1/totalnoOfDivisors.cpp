#include<iostream>
using namespace std;

int main()
{
    int n, div;
    cin>>n>>div;
    int count1 = 0;     //count1 is to count total number of Numbers with exact divisor
    for (int i = 0; i <= n; i++)
    {
        int count2 = 0;         //count2 checks the total number of divisors
        for (int j = 0; j < i; j++)
        {
            if(i%j == 0)
                count2++; 
        }
        if(count2 == div)
        {    
            count1++;
            cout<<i<<endl;
        }
    }
    cout<<count1;
    

    return 0;
}
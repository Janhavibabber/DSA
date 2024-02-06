#include<iostream>
#include<math.h>
using namespace std;

int convert(long n)
{
    int i=0,decimal =0;
    while (n!=0)
    {
        // to extract binary digit one by one
        int rem = n%10;
        // multiply the remainder with power of two
        int res = rem*pow(2,i);
        // add the no. to the previous sum
        decimal += res;
        i++;
        n /= 10;
    }
    return decimal;
    
}

int main()
{
    long a;
    cin>>a;
    cout<<convert(a);
    return 0;
}
// For example: we have to find the sum of 7/2 and 8/3

// Firstly the LCM of 2 and 3 will be found. Using the LCM we will convert the numerators i.e. 7 and 8 into digits that can be added and sum of those digits is found, lastly normalization is done using the GCD of sum and LCM.
// DOUBT
#include<iostream>
using namespace std;

int findGCD(int n1, int n2)
{
    int gcd;
    for (int i = 0; i <= n1 && i <= n2; i++)
    {
        if(n1 % i == 0 && n2 % i == 0)
            gcd = i;
    }
    return gcd;
}

int main()
{
    int num1, den1, num2, den2;
    cin>>num1>>den1>>num2>>den2;
    int lcm = (den1 * den2)/findGCD(den1,den2);
    int sum = (num1*lcm)/den1 + (num2*lcm)/den2;
    int num = sum/findGCD(sum, lcm);
    lcm = lcm/findGCD(sum,lcm);

    cout<<num1<<"/"<<den1<<" + "<<num2<<"/"<<den2<<" = "<<num<<"/"<<lcm; 

    return 0;
}
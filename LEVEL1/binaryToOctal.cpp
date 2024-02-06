#include<iostream>
#include<math.h>
using namespace std;

int convert(long binary)
{
    int octal=0,i=0,decimal =0,rem;
    // converting from binary to decimal
    while (binary!=0)
    {
        int rem = binary%10;
        int res = rem*pow(2,i);
        decimal += res;
        i++;
        binary /= 10;
    }
    i = 1;      // i denotes the ith place n decimal
    // converting from decimal to octal
    while(decimal!=0)
    {
        // The number is divided by 8 and the remainder is stored.
        rem = decimal % 8;
        octal += rem*i;
        decimal /=8;
        i *=10;
    }
    return octal;
}

int main()
{
    int b;
    cin >> b;
    int octal = convert(b);
    cout<<b<<endl<<octal;
    return 0;
}
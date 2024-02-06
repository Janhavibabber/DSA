#include<iostream>
#include<math.h>
using namespace std;

int convert(int decimal)
{
    int i=1, octal=0;
    while(decimal != 0)
    {
        int rem = decimal % 8;
        decimal /= 8;
        octal += rem * i;
        i *= 10; 
    }
    return octal;
}

int main()
{
    int decimal,octal;
    cin>>decimal;
    octal = convert(decimal);
    cout<<octal;
    return 0;
}
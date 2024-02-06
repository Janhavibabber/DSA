#include<iostream>
#include<math.h>
using namespace std;

int convert(int n)
{
    long binary;
    int rem=0,i=1;
    while(n != 0)
    {
        rem = n%2;
        binary += rem*i; 
        n /= 2;
        i *= 10;
    }
    return binary;
}

int main()
{
    int decimal;
    long binary;
    cout << "Enter a decimal number: ";
        //user input
    cin >> decimal;
    //calling function
    binary = convert(decimal);
    cout << decimal << "in decimal = "<< binary << "in binary"<< endl ;
    return 0;
}
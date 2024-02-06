#include <iostream>
    #include <math.h>
    using namespace std;
    //Function to convert octal to binary
    int convert(int octal)
    {
        int decimal = 0, i = 0;
        //converting octal to decimal
        while(octal != 0)
        {
            int rem = octal%10;
            int res=rem * pow(8,i);
            decimal += res;
            i++;
            octal/=10;
        }
        return decimal;
    }
    //main program
    int main()
    {
        int oct;
        
        //user input
        cin >> oct;
        //function call
        int decimal = convert(oct);
        //printing output
        cout << decimal;
        return 0;
    }
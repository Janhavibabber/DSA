// C++ program to check if a number is
// strong or not.

// Strong Numbers is a number in which the sum of factorial of individual digits of the numbers is equal to the number itself.

// To check for Strong Number, break the number into digits, find and add the factorial of each digit and lastly compare the result to the number. If both are equal then the number is a String Number else not a Strong Number.

// For Example:145

// Sum of factorial of digits of number   = 1! x 4! x 5=  145
#include <bits/stdc++.h>
using namespace std;
// Approach 2
int main()
{
    int ip, sum = 0;
    cout << "Enter the number";
    //user input
        cin>>ip;
        int save=ip;
        //logic to check for Strong Number starts
        while(ip)
        {
            int num=ip%10;
            int fact = 1;
            //finding factorial of each digit of input
            for(int i=num; i>0; i--)
            {
                fact=fact*i;
            }
            sum+=fact;
            ip/=10;
        }
        //checking for Strong Nunber
    if(save = sum)
        cout << "Strong number";
    else
        cout << "Not a Strong num"; 
    return 0;
}





// Approach 2
 
// int f[10];
 
// // Fills factorials of digits from 0 to 9.
// void preCompute()
// {
//     f[0] = f[1] = 1;
//     for (int i = 2; i<10; ++i)
//         f[i] = f[i-1] * i;
// }
 
// // Returns true if x is Strong
// bool isStrong(int x)
// {
//     int factSum = 0;
 
//     // Traverse through all digits of x.
//     int temp = x;
//     while (temp)
//     {
//         factSum += f[temp%10];
//         temp /= 10;
//     }
 
//     return (factSum == x);
// }
 
// // Driver code
// int main()
// {
//     preCompute();
 
//     int x = 145;
//     isStrong(x) ? cout << "Yes\n" : cout << "No\n";
//     x = 534;
//     isStrong(x) ? cout << "Yes\n" : cout << "No\n";
//     return 0;
// }       
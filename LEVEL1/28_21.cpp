// C++ program to check if a number is Harshad
// Number or not.

// A Harshad number is a positive integer which is divisible by the sum of the digits of the integer. It is also called the Niven number.

// To find the Harshad number find and add the digits of the number. If the number is divisible by the sum then the number is a Harshad number else not a Harshad number.

// For Example : 153

// Sum of digits = 1 + 5 + 3= 9

// 153 is divisible by 9 so 153 is a Harshad Number.

#include <bits/stdc++.h>
using namespace std;

//Approach 2
int main()
{
    int num, rem, sum;
    cout << "Enter the number";
    cin >> num;
    int n = num;
    while (num > 0)
    {
        rem = num%10;
        sum += rem;
        num /=10;
    }
    if( n % sum == 0)
        cout << "Harshad number";
    else
        cout << "Not Harshad Number";
    return 0;
    
}
   

// Approach 1   
// function to check Harshad Number
// bool checkHarshad(int n)
// {
//     // calculate sum of digits
//     int sum = 0;
//     for (int temp = n; temp > 0; temp /= 10)
//         sum += temp % 10;
   
//     // Return true if sum of digits is multiple
//     // of n
//     return (n % sum == 0);
// }
   
// // driver program to check above function
// int main()
// {
//     checkHarshad(12) ? cout << "Yes\n" : cout << "No\n";
//     checkHarshad(15) ? cout << "Yes\n" : cout << "No\n";
   
//     return 0;
// }
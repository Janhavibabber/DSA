// C++ program to check if a given number is perfect
// or not

// Perfect Number is a number in which the sum of the proper positive divisors of the number is equal to the number itself.

// To check for Perfect Number find and add the divisors of the number and compare, if both are equal then it is a Perfect Number else it is not a Perfect Number.

// For Example: 28

// Sum of divisors = 1 + 2 + 4 + 7 + 14 = 28

#include<iostream>
using namespace std;

// Approach 1
int main()
{
    int n,div,sum;
    cout << "Enter the number";
    cin >> n;
    for(int i=0; i<n; i++)
    {
        div = n%i;
        if(div == 0)
        sum += i;

    }
    if(sum == n)
        cout << "Perfect Number";
    else
        cout << "not aperfect number";
    return 0;

}




// Approach 2 
 
// // Returns true if n is perfect
// bool isPerfect(long long int n)
// {
//     // To store sum of divisors
//     long long int sum = 1;
  
//     // Find all divisors and add them
//     for (long long int i=2; i*i<=n; i++)
//     {
//         if (n%i==0)
//         {
//             if(i*i!=n)
//                 sum = sum + i + n/i;
//             else
//                 sum=sum+i;
//         }
//     }
//      // If sum of divisors is equal to
//      // n, then n is a perfect number
//      if (sum == n && n != 1)
//           return true;
  
//      return false;
// }
  
// // Driver program
// int main()
// {
//     cout << "Below are all perfect numbers till 10000\n";
//     for (int n =2; n<10000; n++)
//         if (isPerfect(n))
//             cout << n << " is a perfect number\n";
  
//     return 0;
// }

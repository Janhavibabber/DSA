// C++ program to find LCM of two numbers
#include <iostream>
using namespace std;
 
// Recursive function to return gcd of a and b
long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

// Approach 2
int lcm2(int a,int b)
{
  static int fact=a;
  if(fact%a == 0 && fact%b == 0)
    return fact;
  else
  {
    fact += a;
    lcm2(a,b);
  }
  return fact;
}

  
// Driver program to test above function
int main()
{
    int a = 15, b = 20;
    cout <<"LCM of " << a << " and "
         << b << " is " << lcm(a, b)<<endl;
    cout <<"LCM of " << a << " and "
         << b << " is " << lcm2(a, b);
    return 0;
}


// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
int power(int x, int y)
{
 
    // If x^0 return 1
    if (y == 0)
        return 1;
 
    // If we need to find of 0^y
    if (x == 0)
        return 0;
 
    // For all other cases
    return x * power(x, y - 1);
}
 
// Driver Code
int main()
{
    int x = 2;
    int y = 3;
 
    cout << (power(x, y));
}

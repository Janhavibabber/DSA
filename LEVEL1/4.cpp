// C++ implementation of the above approach
#include<bits/stdc++.h>
using namespace std;
 
void check(char ch)
{
 
    if (ch >= 'A' && ch <= 'Z')
        cout<< ch << " is an UpperCase character\n";
 
    else if (ch >= 'a' && ch <= 'z')
    cout<< ch << " is an LowerCase character\n";
             
 
    else
        cout<< ch << " is not an aplhabetic character\n";
             
}
 
// Driver Code
int main()
{
    char ch;
 
    // Get the character
    ch = 'A';
 
    // Check the character
    check(ch);
 
    // Get the character
    ch = 'a';
 
    // Check the character
    check(ch);
 
    // Get the character
    ch = '0';
 
    // Check the character
    check(ch);
 
    return 0;
}
// Pallindrome number
#include<iostream>
using namespace std;

int main()
{
    int n,rev,rem;
    cout<< "Ener the number";
    cin>>n;
    int org = n;
    while(n > 0)
    {
        rem = n%10;
        rev = (rev *10) + rem;
        n = n/10;
    }
    if(org == rev)
        cout<<"Pallindrome";
    else 
        cout<<"Not a pallindrome";

    return 0;
}
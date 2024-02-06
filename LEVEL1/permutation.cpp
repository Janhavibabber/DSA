#include<iostream>
using namespace std;

int fact(int n)
{
    int f = 1;
    for (int i = 1; i <= n; i++)
    {
        f *= i;
    }
    return f;
}

int main()
{
    int n,r;
    cout<<"Enter the no of people";
    cin>>n;
    cout<<"Enter the no of seats";
    cin>>r;
    if(r<n)
        {
            cout<<"Cannot adjust "<<n<<" people on "<<r<<"seats";
            return 0;
        }
    int perm = fact(r)/ fact(r-n);
    cout<< perm;
    return 0;
}
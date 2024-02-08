#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    //specific position- O(n-i)
    // int pos, x;
    // cin>>pos>>x;
    // for (int i = n-1; i >= pos-1; i--)
    // {
    //     a[i+1] = a[i];
    // }
    // a[pos-1] = x;
    // n++;

    //begining- O(n)
    // int x;
    // cin >> x;
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     a[i + 1] = a[i];
    // }
    // a[0] = x;
    // n++;

    // end - O(1)
    // int x;
    // cin >> x;
    // a[n] = x;
    // n++;5

    // in unsorted array - O(1)
    int pos, x;
    cin >> pos >> x;
    a[n] = a[pos-1];
    a[pos-1] = x;
    n++;

    for (int i = 0; i < n; i++)
    {
        cout<< a[i] <<" ";
    }
    return 0;
}
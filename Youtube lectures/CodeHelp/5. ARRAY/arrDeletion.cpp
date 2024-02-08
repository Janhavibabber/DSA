#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    // specific position- O(n-i)
    // int pos;
    // cin >> pos;
    // for (int i = pos - 1; i < n; i++)
    // {
    //     a[i] = a[i+1];
    // }
    // n--;

    // begining- O(n)
    // for (int i = 0; i < n; i++)
    // {
    //     a[i] = a[i+1];
    // }
    // n--;

    // end - O(1)
    // n--;


    // in unsorted array - O(1)
    // int pos;
    // cin >> pos;
    // a[n-1] = a[pos - 1];
    // n--;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
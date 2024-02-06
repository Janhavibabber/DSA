// Sum of Digits
#include<iostream>
using namespace std;

int main()
{
    int d,n, sum=0;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        d = n%10;
        sum +=d; // sum += n%10;
        n = n/10;
    }
    cout << sum;
    return 0;
}
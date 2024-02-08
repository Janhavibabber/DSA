// Time - o(1)
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ct = 0, sum = 0;
    for (int i = 0; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " " << n / i << endl;
            
        }
    }
    cout << ct << " " << sum << endl;
    return 0;
}
#include<iostream>
using namespace std;

int mySqrt(int x)
{
    int s = 1, e = x;
    int ans = 0;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (mid * mid <= x)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;

    cout << mySqrt(n);

    return 0;
}
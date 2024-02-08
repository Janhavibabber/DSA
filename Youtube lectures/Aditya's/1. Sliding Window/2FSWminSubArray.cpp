//fixed siliding window to find minimum window with given sum k
#include <bits/stdc++.h>
using namespace std;

// long long solve(vector<int> &v, int k)
// {
//     int i = 0, j = 0;
//     long long sum = 0;
//     long long res = INT_MAX;
//     while (j < v.size())
//     {
//         sum += v[i];
//         if (j - i + 1 < k)
//         {
//             j++;
//         }
//         else if (j - i + 1 == k)
//         {
//             res = min(res, sum);
//             sum -= v[i];
//             i++;
//             j++;
//         }
//     }
//     return res;
// }

int solve(int arr[], int n, int k)
{
    int i = 0, j = 0;
    int sum = 0;
    int res = INT_MAX;
    while (j < n)
    {
        sum += arr[j];
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            res = min(res, sum);
            sum -= arr[i];
            i++;
            j++;
        }
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    // vector<int> v;
    // for (int i = 0; i < v.size(); i++)
    // {
    //     int x;
    //     cin>>x;
    //     v.push_back(x);
    // }
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout << solve(arr, n, k);

    return 0;
}
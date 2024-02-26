#include<bits/stdc++.h>
using namespace std;

bool pairDiff(int arr[], int n, int x){
    int i = 0, j = 0;
    while (i < n && j<n)
    {
        if (abs(arr[i] - arr[j]) == x)
        {
            return 1;
            i++;
            j++;
        }
        else if (abs(arr[i] - arr[j]) < x)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return 0;
}

int main()
{
    int n, x;
    cin >> n>>x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // cin >> x;
    // // int arr[] = {1, 2, 3};
    // // int x = 9;

    // int f = pairSum(arr, 3, x);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    if (pairDiff(arr, n, x))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
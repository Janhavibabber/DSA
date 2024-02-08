 
 // fixed sliding window to find the maximum window with the given sum k
#include<bits/stdc++.h>
using namespace std;

// long maximumSumSubarray(int k, vector<int> &arr , int n){
//     // code here 
//     long long int sum=0;
//      for(int i=0;i<k;i++)
//      {
//          sum=sum+arr[i];
//      }
//      long long int maxsum=sum;
//      for(int i=k;i<n;i++)
//      {
//          sum=sum+arr[i]-arr[i-k];
//           maxsum=max(sum,maxsum);

//      }
//      return maxsum;
 // }

// int sum = 0;
// for(int index = 0; index < k; index++){
//     sum += arr[index];
// }
// int i=0, max=Integer.MIN_VALUE;
// for(int j = k; j < arr.length; i++, j++){
//     sum += arr[j] - arr[i];
//     max = Integer.max(max, sum);
// }
// return max;

// One simple way of code 
// First obtain the sum till window 

// For(int i=0;i<k;i++){
// Sum+=arr[i];

// }

// Maxsum=max(Maxsum,Sum);

// Now traverse from k to n 
// And compute sum by subtracting i-k and adding i


// For(int i=k;i<n;i++){
// Sum+=arr[i]-arr[i-k];
// Maxsum=max(Maxsum,Sum);
// }


// In last return m
// Maxsum

// long long solve(vector<int> &v, int k){
//     int i = 0, j = 0, 
//     long long sum = 0;
//     long long res = INT_MIN;
//     int n = v.size();
//     while (j < n)
//     {
//         sum = sum + v[j];
//         if (j-i+1 < k){
//             j++;
//         }
//         else if(j-i+1 == k){
//             res = max(res, sum);
//             sum = sum - v[i];
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
    int res = INT_MIN;
    while (j < n)
    {
        sum += arr[j];
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            res = max(res, sum);
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
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << solve(arr, n, k);

    return 0;
}


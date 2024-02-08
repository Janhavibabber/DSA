/*for postive + negative element. here we use prefix sum concept
/*
A[] = {10, 5, 2, 7, 1, 9}
K = 15
int main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for(auto &i:arr)
    cin>>i;
    map<long long,int>m;
    int s=0,mx=0;
    for(int i=0;i<n;i++)
    {
        s+=arr[i];
        if(s==k)
            mx=max(mx,i+1);
        int rem=s-k;
        if(m.find(rem)!=m.end())
        {
            int l=i-m[rem]; 
            mx=max(mx,l);
        }
        //edge case when : arr[]=[ 2,0,0,0,3] for this we have store sum only once in map.Insort if sum is already exist in map we should not update in map.(it's index)
        if(m.find(s)==m.end())// we check that the sum is not present before
        m[s]=i;
    }
    cout<<mx;
}
// for only positive elemenet : two pointer approch
int main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for(auto &i:arr)
    cin>>i;
    int l=0,r=0,s=arr[0],mx=0;
    while(r<n)
    {
        while(l<=r&&s>k)
        {
            s-=arr[l];
            l++;
        }
        if(s==k)
        {
            mx=max(mx,r-l+1);
        }
        r++;
        if(r<n)
        s+=arr[r];
    }
    cout<<mx;
}

For Negative number we can use map as Aditya bro said.

int lenOfLongSubarr(int arr[],  int n, int k) 
    {   
        //map to store the first index of any sum that's calculated

        unordered_map<int,int> mp;
        int max=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];

            //check if sum is equal to given target sum k
            //since this sum will be from 0 to i, we check
            //if i+1 ( the length of that subarray is 
            //greater than max)

            if(sum==k) { 
                if(i+1>max) 
                    max=i+1;
            }

            // sum(i,j)=sum(0,j)-sum(0,i), 
            //where sum(i,j) represents the sum of 
            //all the elements from index i to j-1.i<=j 
            //we check if sum(0,i) is present or not if it is,
            //then we take the subbarray length and check if its,
            //greater than max or not

            if(mp.find(sum-k)!=mp.end()) {
                int len=i-mp[sum-k];
                if(len>max) max=len;
            }

            /*here came a lot of confusion, first I just simply
            add first index of each sum to map (mp[sum]=i) but there came
            problem when we had element 0 as the sum before encountering 0
            is same as after encountering 0, so i put and if condition to check if
            arr[i]!=0 only then add index to map,but that also failed, beacause there 
            are negative numbers,so for eg if sum 5 happens at index 4 then due to -ve and +ve
            number it again sums at 5 at index 8 then i for that sum will be 8 instead of 4
            as we need the first occurence of sum because that will give us maximum length,so
            I put a if to check if the calculated sum is not in the map then only add index i to
            corresponding map,otherwise dont, the if can be removed in case of smallest or minimum
            subbarray length of with sum k*/
            
//             if(mp.find(sum)==mp.end())
//             mp[sum]=i;
// }
// return max;
// }

// code 1: using map<int,int> T.C == O(N *LOGN); S.C ~ O(N) (for unique elements) best solution coz numbers are +ve, 0 and -ve as well.
// TC- 1. Unordered map--> O(N) and O(N^2)--> worst case
//     2. Ordered map--> O(NlogN)
// code 2: using map<long long,int> T.C == O(N *LOGN); S.C ~ O(N) (for unique elements)
// code 3: using map<long long,int> T.C == O(N *LOGN); S.C ~ O(N) (for unique elements)
// code 4: using map<long long,int> T.C == O(N *LOGN); S.C ~ O(N) (for unique elements)
// code 5: using map<int,int> T.C == O(N *LOGN); S.C ~ O(N) (for unique elements)
// code 6: using unordered map = Good explanation
// code 7: using map<int,int> T.C == O(N *LOGN); S.C ~ O(N) (for unique elements)
// code 8: using unordered map using count instead of find function
// code 9: using unordered map
// code 10: using sliding window appoach(for only +ve no.'s)
// code 11: using map<int,int> T.C == O(N *LOGN); S.C ~ O(N) (for unique elements)

//code 1
// int lenOfLongSubarr(int A[], int N, int K)
// {
//     // Complete the function
//     int maxLength = 0;
//     int sum = 0;
//     map<int, int> mpp;

//     for (int i = 0; i < N; i++)
//     {
//         sum += A[i];
//         if (sum == K)
//         {
//             maxLength = i + 1;
//         }
//         if (mpp.find(sum - K) != mpp.end())
//         {
//             maxLength = max(maxLength, i - mpp[sum - K]);
//         }
//         if (mpp.find(sum) == mpp.end())
//         {
//             mpp[sum] = i;
//         }
//     }

//     return maxLength;
// }

// code 2
//  long long sum = 0, rem = 0;

// int len = 0;

// map<long long, int> presummap;

// for (int i = 0; i < nums.size(); i++)
// {

//     sum += nums[i];

//     if (sum == k)
//         len = i + 1;

//     rem = sum - k;

//     if (presummap.find(rem) != presummap.end())
//         len = max(len, i - presummap[rem]);

//     if (presummap.find(sum) == presummap.end())
//         presummap[sum] = i;
// }

// return len;

// T.C == O(N *LOGN)

// S.C ~ O(N) (for unique elements)

// code 3
//  #include <bits/stdc++.h>

// int getLongestSubarray(vector<int> &nums, int k)
// {

//     map<long long, int> prefixSum;

//     int len = 0;

//     long long sum = 0;

//     for (int i = 0; i < nums.size(); i++)
//     {

//         sum += nums[i];

//         if (sum == k)
//         {

//             len = max(len, i + 1);
//         }

//         long long rem = sum - k;

//         if (prefixSum.find(rem) != prefixSum.end())
//         {

//             int l = i - prefixSum[rem];

//             len = max(len, l);
//         }

//         if (prefixSum.find(sum) == prefixSum.end())
//         {

//             prefixSum[sum] = i;
//         }
//     }

//     return len;
// }

// best solution coz numbers are +ve, 0 and -ve as well.

// TC- 1. Unordered map--> O(N) and O(N^2)--> worst case

//     2. Ordered map--> O(NlogN)

// code 4
//  #include <bits/stdc++.h>
//  int getLongestSubarray(vector<int> &nums, int k)
//  {
//      // Write your code here
//      map<long long, int> presumMap;
//      long long sum = 0;
//      int mx = 0;
//      for (int i = 0; i < nums.size(); i++)
//      {
//          sum += nums[i];
//          if (sum == k)
//              mx = max(mx, i + 1);
//          long long remaining = sum - k;
//          if (presumMap.find(remaining) != presumMap.end())
//          {
//              int len = i - presumMap[remaining];
//              mx = max(mx, len);
//          }
//          if (presumMap.find(sum) == presumMap.end())
//              presumMap[sum] = i;
//      }
//      return mx;
//  }

// code 5
// #include <bits/stdc++.h>

// int getLongestSubarray(vector<int> &a, int k)
// {
//     map<int, int> preSumMap;
//     int sum = 0;
//     int maxLen = 0;
//     for (int i = 0; i < a.size(); i++)
//     {
//         sum += a[i];
//         if (sum == k)
//         {
//             maxLen = i + 1;
//         }
//         int rem = sum - k;
//         if (preSumMap.find(rem) != preSumMap.end())
//         {
//             int len = i - preSumMap[rem];
//             maxLen = max(len, maxLen);
//         }
//         if (preSumMap.find(sum) == preSumMap.end())
//         {
//             preSumMap[sum] = i;
//         }
//     }
//     return maxLen;
// }

// code 6
// Approach:

// Initialize sum to keep track of the running sum of elements, maxLength to store the length of the longest subarray, and prefixSum as an unordered map to store the prefix sums encountered.

// Iterate through the elements of the nums vector from left to right using a for loop.

// In each iteration, update the sum by adding the current element nums[i] to it, representing the current prefix sum.

// Check if the current sum is equal to k. If it is, update maxLength to i + 1 because the subarray from the beginning to the current index has a sum equal to k.

// Calculate remainder as sum - k, representing the difference between the current prefix sum and the target sum k.

// Check if the remainder exists in the prefixSum map. If it does, it means that there is a subarray between the current index and the index stored in prefixSum[remainder] that has a sum equal to k. Calculate the length of this subarray as i - prefixSum[remainder] and update maxLength if this length is greater.

// Finally, store the current sum and its index i in the prefixSum map if sum doesn't already exist in it.

// Continue this process for all elements in the nums vector.

// After the loop, maxLength will contain the length of the longest subarray with a sum equal to k. Return maxLength as the result. #include <bits/stdc++.h>

// // Function to find the length of the longest subarray with sum equal to 'k' int getLongestSubarray(vector<int>& nums, int k) {    int sum = 0, maxLength = 0;    unordered_map<int, int> prefixSum; // To store prefix sums

//    for (int i = 0; i < nums.size(); i++)
// {
//     sum += nums[i]; // Calculate the current prefix sum

//     // If the current prefix sum is equal to 'k', update maxLength        if (sum == k) {            maxLength = i + 1;        }

//     int remainder = sum - k; // Calculate the remainder needed for the target 'k'

//     // Check if the remainder exists in the prefixSum map        if (prefixSum.find(remainder) != prefixSum.end()) {            int len = i - prefixSum[remainder]; // Calculate the length of the subarray            maxLength = max(maxLength, len); // Update maxLength if needed        }

//     // Store the current prefix sum and its index in the map        if (prefixSum.find(sum) == prefixSum.end()) {            prefixSum[sum] = i;        }    }

//     return maxLength;
// }

// // Store the current prefix sum and its index in the map        if (prefixSum.find(sum) == prefixSum.end()) {            prefixSum[sum] = i;        }    }

// return maxLength;
// }

// for
// index 0 how can we store the sum and its inex in the prefixSum because the condition is false

//     It is correct but please explain how the 1st index we store

// code 7
// #include <bits/stdc++.h>

// int getLongestSubarray(vector<int> &nums, int k)
// {

//     int sum = 0;

//     int maxLen = 0;

//     map<int, int> mpp;

//     for (int i = 0; i < nums.size(); i++)
//     {

//         sum += nums[i];

//         if (sum == k)
//         {

//             maxLen = max(maxLen, i + 1);
//         }

//         int rem = sum - k;

//         if (mpp.find(rem) != mpp.end())
//         {

//             int len = i - mpp[rem];

//             maxLen = max(maxLen, len);
//         }

//         if (mpp.find(sum) == mpp.end())
//         {

//             mpp[sum] = i;
//         }
//     }

//     return maxLen;
// }

// code 8
// int lenOfLongSubarr(int a[], int n, int k)
// {
//     unordered_map<int, int> m;
//     m[0] = -1;
//     int sum = 0, maxi = 0;
//     for (int i = 0; i < n; i++)
//     {
//         sum += a[i];
//         if (m.count(sum - k))
//             maxi = max(maxi, i - m[sum - k]);
//         if (!m.count(sum))
//             m[sum] = i;
//     }
//     return maxi;
// }

// code 9
// int lenOfLongSubarr(int A[], int N, int K)
// {
//     // Complete the function
//     unordered_map<int, int> mp;

//     int sum = 0;
//     int mx = 0;
//     for (int i = 0; i < N; i++)
//     {
//         sum += A[i];
//          // when you got the desired sum
//         if (sum == K)
//         {
//             mx = max(mx, i + 1);
//         }
//         if (mp.find(sum - K) != mp.end())
//         {
//             mx = max(mx, i - mp[sum - K]);
//         }
//          // if there is no value present then insert it in the map 
//         if (mp.find(sum) == mp.end())
//             mp[sum] = i;
//     }
//     return mx;
// }

// code 10
// // This is valid for only positive values......
// class Solution
// {
// public:
//     int lenOfLongSubarr(int A[], int N, int K)
//     {

//         int start = 0;
//         int last = 0;
//         int sum = 0;
//         int maxLength = 0;

//         while (last < N)
//         {
//             sum += A[last];

//             if (sum < K)
//                 last++;

//             else if (sum == K)
//             {
//                 maxLength = max(maxLength, last - start);
//                 last++;
//             }
//             else
//             {
//                 while (sum > K)
//                 {
//                     sum -= A[start];
//                     start++;
//                 }
//             }
//         }
//         return maxLength;
//     }
// };

// code 11
// int lenOfLongSubarr(int A[], int N, int K)
// {
//     // Complete the function
//     int maxLength = 0;
//     int sum = 0;
//     map<int, int> mpp;

//     for (int i = 0; i < N; i++)
//     {
//         sum += A[i];
//         if (sum == K)
//         {
//             maxLength = i + 1;
//         }
//         if (mpp.find(sum - K) != mpp.end())
//         {
//             maxLength = max(maxLength, i - mpp[sum - K]);
//         }
//         if (mpp.find(sum) == mpp.end())
//         {
//             mpp[sum] = i;
//         }
//     }

//     return maxLength;
// }

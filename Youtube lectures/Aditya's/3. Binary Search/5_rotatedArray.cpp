// Find how many times an array is rotated? = the index of min. element
// No. of rotation in clockwise direction = len(Array) - index of minimum element
// Error = it is not able to print minimum element index using vector - // check vector input
#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums){
    int n= nums.size();
    // int ans = 0;
    int start = 0;
    int end = n-1;
    if (nums[start] <= nums[end])
    {
        return 0;
    }
    while (start <= end) // error
    {
        int mid = start + (end - start) / 2;
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;
        // nums[mid]<=nums[prev] - can only be checked i.e. if element at mid is greater than it's prev is sufficient to verfiy if mid is the min element or not. Comparing mid to next element is unnecessary.
        //&& mid-1>=0 && mid+1<nums.size()
        if (nums[mid]<=nums[prev] && nums[mid]<=nums[next])
        {
            return mid;
        }
        if (nums[mid]<=nums[end])
        {
            end = mid-1;
        }
        else if (nums[start]<=nums[mid])
        {
            start = mid+1;
        }
    }
    // f array is completely sorted in the increasing order, then return nums[0] else if it is sorted in decreasing order return nums[num.size()-1]
    // error
    // if (nums[end] <= nums[start])
    // {
    //     return end;
    // }
    return -1;
}


int main()
{
    
    vector<int> v;
    v = {11, 12, 15, 18, 2, 5, 6, 8};
    cout<<"Array is rotated "<<findMin(v) <<" no. of times."; 

    return 0;
}
// Suppose you have a sorted array of infinite numbers, how would you search an element in the array ?
// Since array is sorted,the first thing clicks into mind is binary search, but the problem here is that we don’t know size of array.If the array is infinite, that means we don’t have proper bounds to apply binary search.So in order to find position of key, first we find bounds and then apply binary search algorithm.
// Let low be pointing to 1st element and high pointing to 2nd element of array,Now compare key with high index element,
// -if it is greater than high index element then copy high index in low index and double the high index.
// - if it is smaller, then apply binary search on high and low indices found.

#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int x, int l, int h){
    int res=-1;
    while(l<=h){
        int mid = l+(h-l)/2;

        if(arr[mid]==x){
            res=mid;
        }
        if(arr[mid] > x){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return res;
}

int main()
{
    int n, x;
    cin>>n>>x;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int l=0;
    int h=l+1;

    // find low and high range for a given key in an infinite array
    while(x>arr[h]){
        l=h;
        h=h*2;
    }

    int ans = binarySearch(arr, x, l, h);
    cout<< ans;
    
    return 0;
}
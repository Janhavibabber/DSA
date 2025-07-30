// Given a sorted array, find the element in the array which has minimum difference with the given number.
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int x){
    int s=0, e=n-1;
    while(s<=e){
        int mid = s+ (e-s)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]< x){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }

    int floor = abs(x - arr[e]);
    int ceil = abs(arr[s] - x);

    // cout<<floor<<" "<<ceil;

    return (floor < ceil)? e: s;
}

int main()
{
    int n, x;
    cin>>n>>x;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = binarySearch(arr, n, x);
    // cout<<endl;
    cout<<ans;

    return 0;
}
#include<iostream>
using namespace std;

int ceilBS(int arr[], int n, int x){
    int s=0;
    int e=n-1;
    int res=-1;

    while(s<=e){
        int mid = s+(e-s)/2;

        if(arr[mid]==x){
            res= mid;
        }
        else if(arr[mid]>=x){
            res = mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }

    return x<arr[0]?0:res;
}

int main()
{
    int n, x;
    cin>>n>>x;

    int arr[n];
    for(int i=0; i<=n; i++){
        cin>>arr[i];
    }

    int ans = ceilBS(arr, n, x);
    cout<< ans;

    return 0;
}
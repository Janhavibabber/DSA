// Apply BS to search an element in an array that is sorted in descending order 
#include<iostream>
using namespace std;

int descBS(int arr[], int n, int start, int end, int x){
    int mid = start + (end - start)/2;
    while(start<=end){
        if(arr[mid] == x){
            return mid;
        }
        else if(arr[mid]>x){
            start = mid+1;
            // descBS(arr, mid + 1, end, x);
        }
        else if(arr[mid]<x){
            end = mid-1;
            // descBS(arr, start, mid - 1, x);
        }
    }
    return -1;
}

int main()
{
    int n, x;
    cin>>n;
    int arr[n];
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"Enter the element to be searched: ";
    cin>>x;
    cout<<descBS(arr, n, 0, n-1, x);

    return 0;
}
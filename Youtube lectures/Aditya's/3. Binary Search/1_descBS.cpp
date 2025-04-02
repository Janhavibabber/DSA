// Apply BS to search an element in an array that is sorted in descending order

// Let's suppose that we have an array sorted in descending order and we want to find index of an element e within this array. Binary search in every step picks the middle element (m) of the array and compares it to e. If these elements are equal, than it returns the index of m. If e is greater than m, than e must be located in the left subarray. On the contrary, if m greater than e, e must be located in the right subarray. At this moment binary search repeats the step on the respective subrarray.
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
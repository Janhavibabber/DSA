//Search given element in a rotated array
#include<iostream>
using namespace std;

int binary_search(int arr[], int s, int e, int data){
    while (s<=e){
        int mid = s+(e-s)/2;

        if (arr[mid] == data)
            return mid;
        
        else if(data>arr[mid])
            s=mid+1;
        
        else if(data<arr[mid])
            e=mid-1;
    }
    return -1;
}

int findMinEle(int arr[], int n){
    int s=0, e =n-1;
    // if array sorted in ascending order
    if(arr[s]<=arr[e])
        return 0;
    
    while(s<=e){
        // if first element is mid or last element is mid then simply use modulo so it never goes out of bound.
        int mid = s+ (e-s)/2;
        int prev = (mid-1+n)%n;
        int next = (mid+1)%n;

        if(arr[mid] <= arr[prev] && arr[mid] <= arr[next])
            return mid;
        else if (arr[mid] <= arr[e]){
            e= mid-1;
        }
        else if(arr[mid]>=arr[s])
            s = mid+1;
    }
    return -1;
}

int searchInRotatedSorted(int arr[], int n, int index, int data){
    int left_search =  binary_search(arr, 0, index-1, data);
    int right_search =  binary_search(arr, index, n-1, data);
    if(left_search == -1 && right_search == -1){
        return -1;
    }
    else if(left_search!=-1){
        return left_search;    
    }
    else{
        return right_search;
    }

}

int main()
{
    int arr[] = {11, 12, 15, 18, 2, 5, 6, 8};
    int size = sizeof(arr)/sizeof(arr[0]);
    int min_ele_index = findMinEle(arr, size);
    cout<<min_ele_index;
    int data;
    cout<<"Enter data to be searched in rotated sorted array: ";
    cin>>data;
    int ans = searchInRotatedSorted(arr, size, min_ele_index, data);
    if(ans == -1){
        cout<<data<<" is not present in rotated sorted array.";
    }
    else{
        cout<<data<<"found at index: "<<ans;
    }

    return 0;
}
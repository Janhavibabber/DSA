#include<bits/stdc++.h>
using namespace std;

void merge(int *arr, int l, int r, int mid){
    int n = mid-l+1;
    int m = r-mid;

    int a[n];
    int b[m];
    
    // initially dividing main array to first half
    for(int i=0; i<n; i++){
        a[i] = arr[i+l];
    }

    // initially dividing main array to second half
    for(int j=0; j<m; j++){
        b[j] = arr[mid+1+j];
    }

    // add elements in a sorted manner
    int i=0, j=0, k=l;
    while(i<n && j<m){
        if(a[i]<b[j]){
            arr[k++] = a[i++];
        }
        else{
            arr[k++] = b[j++];
        }
    }

    //if elements are left in a array
    while(i<n){
        arr[k++] = a[i++];
    }

    // if elements are left in b array
    while(j<m){
        arr[k++] = b[j++];
    }
}

void mergeSort(int *arr, int l, int r){
    if(l>=r)
        return;
    int mid = (l+r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, r, mid);
}

int main()
{
    int arr[5];
    
    for(int i=0; i<5; i++){
        cin>>arr[i];
    }

    mergeSort(arr, 0, 5);

    for (int i = 0; i < 5; i++)
    {   
        cout<<arr[i]<<" ";
    }

    return 0;
}
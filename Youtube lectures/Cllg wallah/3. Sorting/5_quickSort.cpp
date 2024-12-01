#include<iostream>
using namespace std;

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i=l;
    for (int j = l; j < r; j++)
    {
        if(arr[j]<pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

void quickSort(int arr[], int l, int r){
    if(l>=r)
        return;
    int idx = partition(arr, l, r);
    quickSort(arr, l, idx-1);
    quickSort(arr, idx+1, r);
}



int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    quickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
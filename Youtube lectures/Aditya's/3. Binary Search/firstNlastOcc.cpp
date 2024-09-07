// To find first and last occurence of an elment in the given sorted array
#include<iostream>  
using namespace std;

int fcount(int arr[], int n, int x){
    int start = 0;
    int end = n - 1;
    int mid = start + (end-start)/2;
    int res = -1;
    while(start<end){
        if (arr[mid] == x)
        {
            res = mid;
            end = mid-1;
        }
        else if (arr[mid] > x)
        {
            end = mid-1;
        }
        else if (arr[mid] < x)
        {
            start = mid+1;
        }
    }
    return res;
}

int scount(int arr[], int n, int x)
{
    int start = 0;
    int end = n-1;
    int mid = start + (end - start) / 2;
    int res = -1;
    while (start < end)
    {
        if (arr[mid] == x)
        {
            res = mid;
            start = mid + 1;
        }
        else if (arr[mid] > x)
        {
            end = mid - 1;
        }
        else if (arr[mid] < x)
        {
            start = mid + 1;
        }
    }
    return res;
}

int main()
{
    int n,x;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the element to be searched: ";
    cin >> x;
    //output m ye nii
    
    cout << "First Count: " << fcount(arr, n, x);
    // cout << "last Count: " << scount(arr, n, x);

    return 0;
}
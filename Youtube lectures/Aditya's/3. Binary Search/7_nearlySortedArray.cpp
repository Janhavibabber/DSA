#include<iostream>
using namespace std;

// Linear search function that returns the
// index of x if found, otherwise -1
// int linearSearch(const vector<int> &arr, int x)
// {
//     for (int i = 0; i < arr.size(); i++)
//     {
//         if (arr[i] == x)
//             return i;
//     }
//     return -1;
// }

int searchElement(int arr[], int n, int x){
    int s=0, e=n-1;
    int ans = -1;

    while(s<=e){
        int mid = e - (s+e)/2;
        if(arr[mid] == x){
            ans = mid;
        }
        else if(s<=mid-1 && arr[mid-1] == x){
            ans = mid-1;
        }
        else if(mid+1<=e && arr[mid+1] == x){
            ans = mid+1;
        } 
        else if(x <= arr[mid]){
            e=mid-2;
        }
        else{
            s=mid+2;
        }
    }

    return ans;
}

int main()
{
    int n, x;
    cin>>n>>x;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int ans = searchElement(arr, n, x);
    cout<<ans;

    return 0;
}
// Given a sorted array of numbers, find if a given number ‘key’ is present in the array.Though we know that the array is sorted, we don’t know if it’s sorted in ascending or descending order.
#include<iostream>
using namespace std;

int solveBS(int arr[], int n, int x, bool flag){
    int s=0;
    int e=n-1;

    while(s<=e){
        int mid = s+((e-s)/2);
        // cout<<s<<" "<<e<<endl;
        // cout<<mid<<endl;
        if(arr[mid]==x){
            return mid;
        }
        // asc order + search ele greater OR desc order + search ele smaller
        else if ((arr[mid] < x && flag == 0) || (arr[mid] > x && flag == 1))
        {
            s=mid+1;
        }
        // desc order + search ele greater OR asc order + search ele smaller
        else if ((arr[mid] < x && flag == 1) || (arr[mid] > x && flag == 0))
        {
            e=mid-1;
        }
        // cout << s << " " << e << endl;
    }
    return -1;
}

int main()
{
    int n, x;
    cin >> n >> x;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // cout << "Enter the element to be searched: ";
    // cin >> x;

    bool flag=0; //asc order

    if(arr[0]>arr[1]){
        //desc order
        flag=1;
    }
    cout << solveBS(arr, n, x, flag);
    return 0;
}
#include<iostream>
using namespace std;

int binarySearch(int a[], int start, int end, int x){
    int mid = (start+end)/2;
    if(a[mid] == x)
        return mid;
    else if(a[mid]>x)
        binarySearch(a, start, mid-1, x);
    else
        binarySearch(a, mid+1, end, x);
    return -1;
}

int main()
{
    int n, x;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the elements to be searched" << endl;
    cin >> x;
    cout<< binarySearch(a,0,n,x);
    return 0;
}
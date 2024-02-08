#include<iostream>
using namespace std;

void insertionSort(int a[], int n){
    for (int i = 1; i < n; i++)
    {
        int temp=a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] =temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int arr[] = {70, 40, 30, 20, 10, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    
    
    return 0;
}
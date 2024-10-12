#include<iostream>
using namespace std;

void insertionSort(int *arr, int n){
    for(int i=1; i<n; i++){
        int curr = arr[i];
        int j=i-1;
        while(j>=0 && curr<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1] = curr;
    }
}

int main()
{
    int arr[10];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    insertionSort(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
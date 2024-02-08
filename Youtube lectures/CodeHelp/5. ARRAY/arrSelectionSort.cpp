#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        int min = i;
        for (int j = i+1; j< n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            
        }
        if(min != i)
        {
            swap(arr[i],arr[min]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] <<" ";
    }
    
}

int main()
{
    int arr[] = {5, 4, 10, 1, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);

    return 0;
}
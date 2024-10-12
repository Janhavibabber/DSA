#include<bits/stdc++.h>
using namespace std;

void selectionSort(int *arr, int n){
    for(int i=0; i<n; i++){
        int min_ele = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min_ele]){
                min_ele = j;
            }
        }
        if (min_ele != i)
        {
            swap(arr[i], arr[min_ele]);
        }
    }

}

int main()
{
    int arr[10];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    selectionSort(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
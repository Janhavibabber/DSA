#include<iostream>
using namespace std;

void bubbleSort(int *arr, int n){
    for(int i=0; i<n-1; i++){
        // optimization:  n -> n-i+1 -> flag=false
        int flag=false;
        for(int j=0; j<n-i+1; j++){
            if(arr[j]>arr[j+1]){
                flag=true;
                swap(arr[j], arr[j+1]);
            }
            if (!flag)
            {
                break;
            }
        }
    }
}

int main()
{
    int arr[10];
    for(int i=0; i<5; i++){
        cin>>arr[i];
    }

    bubbleSort (arr, 5);

    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
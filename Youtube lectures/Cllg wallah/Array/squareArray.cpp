#include<iostream>
using namespace std;

void squareArr(int arr[], int n){
    int res[n];
    int i=0, j=n-1, k=n-1;
    while(i<=j && k>=0){
        if(abs(arr[i])<abs(arr[j])){
            res[k--] = arr[j]*arr[j];
            j--;
        }
        else{
            res[k--]=arr[i]*arr[i];
            i++;
        }
    }

    for(int i=0; i<n; i++){
        cout<<res[i]<<" ";
    } 
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    squareArr(arr, n);

    return 0;
}
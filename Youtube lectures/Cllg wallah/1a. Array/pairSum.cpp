//1. check if there exists a pair for the given sum in the array
//2. count the number of pairs exist in the for the given sum
//3. print the pairs exist in the array for the given sum
#include<bits/stdc++.h>
using namespace std;

int pairSum(int arr[], int n, int x){
    int flag=0;
    int i=0, j=n;
    while(i<j){
        if(arr[i]+arr[j]==x){
            flag=1;
            i++;
            j++;
        }
        else if (arr[i] + arr[j]<x){
            i++;
        }
        else{
            j++;
        }
    }
    return flag;
}

// bool pairDiff(int arr[], int n, int x){
//     int i = 0, j = n;
//     while (i < j)
//     {
//         if (abs(arr[i] - arr[j]) == x)
//         {
//             return 1;
//             i++;
//             j++;
//         }
//         else if (abs(arr[i] - arr[j]) < x)
//         {
//             j++;
//         }
//         else
//         {
//             i++;
//         }
//     }
//     return 0;
// }

int main()
{
    // int arr[]={-1,0,1,2,3};
    // int x=2;

    int n,x;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>x;
    // int arr[] = {1, 2, 3};
    // int x = 9;

    int f = pairSum(arr, 3, x);

    if(f){
        cout<<"YES";
    }
    else{
        cout << "NO";
    }
    
    return 0;
}
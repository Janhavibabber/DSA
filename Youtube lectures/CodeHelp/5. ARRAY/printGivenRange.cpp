#include<bits/stdc++.h>
using namespace std;

void range(int len, int arr, int maxi, int mini)
{
    for (int i=0; i<len; i++)
    {
       if (arr[i]>=mini && arr[i]<=maxi)
       {
          cout<<arr[i];
       }
       
    }
    
}

int main()
{
    int len, arr, maxi, mini;
    cin>>len;
    for(int i=0; i<len; i++)
    {
        cin>>arr[i];
    }
    cin>>maxi>>mini;
    range(len,arr,maxi,mini);

    return 0;

}
#include<bits/stdc++.h>
using namespace std;

int getBit(int n, int pos)
{
    return (n & (1 << pos) != 0);    
}

void twoUniques(int arr[],int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum ^= arr[i];
    }
    int tempxor = xorsum;
    int setbit = 0;
    int pos = 0;
    while (setbit != 1)
    {
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }
    
    int newxorsum = 0;
    for (int i = 0; i < n; i++)
    {
       if(getBit(arr[i],pos))
        {
            newxorsum ^= arr[i];
        }
    }
    cout<<newxorsum<<endl;
    cout<<(newxorsum^tempxor);
}

int main()
{
   int arr[] = {1,2,3,1,2,3,5,7};
   twoUniques(arr, 8);

   return 0;
}
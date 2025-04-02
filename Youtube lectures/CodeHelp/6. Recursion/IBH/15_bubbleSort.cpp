#include<bits/stdc++.h>
using namespace std;

void bSort(vector<int> &v, int n){

    if (n == 0 || n == 1)
    {
        return;
    }

    for(int i=0; i<n-1; i++){
        if(v[i] > v[i+1]){
            swap(v[i], v[i+1]);
        }
        // v.pop_back();
        bSort(v, n-1);
    }
}

int main()
{
    vector<int> v = {2,1,4,5,3};
    int n=5;
    // cin>>n;

    // for(int i=0; i<n; i++){
    //     int x;
    //     cin>>x;
    //     v.push_back(x);
    // }

    bSort(v, n);

    // for (int i = 0; i <n; i++)
    // {
    //     cout<<v[i]<<" ";
    // }

    return 0;
}
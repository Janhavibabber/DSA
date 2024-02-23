// mwerge 2 sorted array in ascending order/ union of 2 sorted arrays with duplicates and different length
#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int n, int b[], int m){
    int i=0, j=0, k=0;
    vector<int> ans;
    // int ans[n+m];
    while(i<n && j<m){
        if(a[i]==b[j]){
            // ans[k++]=a[i++];
            ans.push_back(a[i]);
            ans.push_back(b[j]);
            i++;
            j++;
        }
        else if(a[i]<b[j]){
            // ans[k++] = a[i++];
            ans.push_back(a[i]);
            i++;
        }
        else{
            // ans[k++] = b[j++];
            ans.push_back(b[j]);
            j++;
        }
    }
    
    while(i<n){
        // ans[k++] = a[i++];
        ans.push_back(a[i]);
        i++;
    }

    while (j < m){
        // ans[k++] = b[j++];
        ans.push_back(b[j]);
        j++;
    }

    for (int k = 0; k <ans.size(); k++){
        cout<<ans[k]<<" ";
    }
}

int main()
{
    int arr1[]={1,2,3};
    int arr2[]={1,4,5,6};

    int n=3, m=4;
    // int n, m;
    // cin >> n >> m;

    // int arr1[n];
    // for(int i=0; i>n; i++){
    //     cin>>arr1[i];
    // }

    // int arr2[m];
    // for (int j = 0; j > m; j++)
    // {
    //     cin >> arr2[j];
    // }

    merge(arr1, n, arr2, m);

    

    return 0;
}
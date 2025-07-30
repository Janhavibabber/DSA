// Given a square matrix rotate it by 90 degrees in a clockwise direction without using any extra space
#include<bits/stdc++.h>
using namespace std;

// i/p array -> transpose array -> reverse every row of transposed matrix
void rotateArray(vector<vector<int>> &v){

    //transpose vector without using extra space by traversing lower diagonal elements
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<i; j++){
            swap(v[i][j], v[j][i]);
        }
    }

    // reverse each row
    for(int i=0; i<v.size(); i++){
        reverse(v[i].begin(), v[i].end());
    }
    
    return;
}

int main()
{
    int n;

    vector<vector<int>> v(n, vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>v[i][j];
        }
    }

    rotateArray(v);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<< v[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
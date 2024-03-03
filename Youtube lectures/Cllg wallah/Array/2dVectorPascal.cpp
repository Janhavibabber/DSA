#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> pascal(n);

    for(int i=0; i<n; i++){
        //resizing ith vector of pascal vector as we are taking 0 based indexing but 0th row of pascal triangle will contain 1 element
        pascal[i].resize(i+1);
        for(int j=0; j<i+1; j++){
            if(j==0 || j==i){
                pascal[i][j]=1;
            }
            else{
                pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
            }
        }
    }
    return pascal;
}

int main()
{
    int n;
    cin>>n;

    vector<vector<int>>ans;
    ans=pascalTriangle(n);

    for(int i=0; i<ans.size(); i++){
        //pt1: refering to ith element of ans vector
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}
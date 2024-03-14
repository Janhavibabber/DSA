// Given a matrix 'a' of dimension n*m and 2 coordinates (l1, r1) and (l2, r2). return the sum of the rectangle from (l1, r1) to (l2, r2)
#include<iostream>
#include<vector>
using namespace std;


int rectangleSum(vector<vector<int>> &v, int l1, int r1, int l2, int r2){
    // App1: Brute force
    int sum=0;

    // for(int i=l1; i<=l2; i++){
    //     for(int j=r1; j<=r2; j++){
    //         sum += v[i][j];
    //     }
    // }

    //App2: Using PrefixSum array row-wise
    //calculating row-wise prefix sum
    for(int i=0; i<v.size(); i++){
        for(int j=1; j<v[0].size(); j++){
            v[i][j] += v[i][j-1];
        }
    }

    // printing prefixSum matrix row-wise
    cout << "Row-wise PrefixSum matrix" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    // for(int i=l1; i<=l2; i++){
    //     if(r1!=0){
    //         sum += (v[i][r2]-v[i][r1-1]); 
    //     }
    //     else{
    //         sum += v[i][r2];
    //     }
    // }

    //App3: Using prefix Array sum both row-wise and column-wise
    //calculating row-wise column prefix sum
    // for(int i=0; i<v.size(); i++){
    //     for(int j=1; j<v[0].size(); j++){
    //         v[i][j]+=v[i][j-1];
    //     }
    // }

    // calculating column-wise prefix sum
    for(int i=1; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            v[i][j] += v[i-1][j];
        }
    }

    //printing prefix sum
    cout << "Row-wise and col-wise PrefixSum matrix" << endl;
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    int top_sum=0, left_sum=0, topLeft_sum=0;
    if(l1!=0)
        top_sum = v[l1-1][r2];
    if(r1!=0)
        left_sum = v[l2][r1-1];
    if(l1!=0 && r1!=0)
        topLeft_sum = v[l1-1][r1-1];

    // cout<<top_sum<<" "<<left_sum<<" "<<topLeft_sum<<endl;
    sum = v[l2][r2] - top_sum - left_sum + topLeft_sum;

    return sum;
}

int main()
{
    int n, m;
    cin>>n>>m;

    vector<vector<int>> v(n, vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
        }
    }

    int l1,r1,l2,r2;
    cin>>l1>>r1;
    cin>>l2>>r2;

    cout<<"Input matrix"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<< v[i][j]<<" ";
        }
        cout<<endl;
    }

    int sum = rectangleSum(v, l1, r1, l2, r2);
    cout<<"Sum is:"<<sum<<endl;

    return 0;
}
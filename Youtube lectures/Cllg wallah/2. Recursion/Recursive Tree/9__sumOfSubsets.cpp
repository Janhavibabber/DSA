#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& ip, vector<int>& op, int i, int sum){

    // base condition
    if (i == ip.size())
    {
        op.push_back(sum);
        return;
    }
    int val=0;

    // exclude
    solve(ip, op, i + 1, sum);

    // include
    solve(ip, op, i + 1, sum+ip[i]);
}

int main()
{
    int n;
    cin>>n;
    vector<int> ip;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        ip.push_back(x);
    }
    // vector<vector<int>> ans;
    vector<int> op;
    solve(ip, op, 0, 0);
    sort(op.begin(), op.end());
    for(int i=0; i<op.size(); i++){
        cout<<op[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
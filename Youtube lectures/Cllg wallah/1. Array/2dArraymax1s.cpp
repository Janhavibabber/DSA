#include<iostream>
#include<vector>
using namespace std;

// app2: by counting no. of 1 using formula
int maximumOneRow(vector<vector<int>> &v){

    int maxOne=-1;
    int maxOneRow=-1;
    int cols=v[0].size()-1;

    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            if(v[i][j] == 1){
                int c=cols-j;
                if(c>maxOne){
                    maxOne=c;
                    maxOneRow=i;
                }
                break;
            }
        }
    }
    return maxOneRow;
}

//app3: check the left most one by traversing each row of vector from end
int leftMostOneRow(vector<vector<int>> &v){

    int leftmostOne=-1;
    int maxOneRow = -1;
    int j = v[0].size() - 1;

    //finding leftmost One in 0th row
    while(j>=0 && v[0][j] == 1){
        leftmostOne=j;
        maxOneRow=0;
        j--;
    }

    // check in rest of the row if we can find a one left to the leftmostOne
    for(int i=1; i<v.size(); i++){
        while (j >= 0 && v[i][j] == 1)
        {
            leftmostOne = j;
            maxOneRow = i;
            j--;
        }
    }
    return maxOneRow;
}

int main()
{
    int n, m;
    cin>>n>>m;

    vector<vector <int>> v(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
        }
    }

    // int res = maximumOneRow(v);
    // cout<<res<<endl;

    int res = leftMostOneRow(v);
    cout << res << endl;

    return 0;
}
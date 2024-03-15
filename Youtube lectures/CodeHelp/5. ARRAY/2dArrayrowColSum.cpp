#include<iostream>
#include<vector>
using namespace std;

void rowSum(vector<vector<int>> &v, int n, int m){
    int maxSum=0, row=-1;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=0; j<m; j++){
            sum += v[i][j];
        }
        cout<<sum<<" ";
        //largest rowSum
        if(maxSum < sum){
            maxSum=sum;
            row=i;
        }
    }
    cout<<endl;
    cout<<"largest sum:"<<maxSum<<endl;
    cout<<"row is:"<<row<<endl;
}

void colSum(vector<vector<int>> &v, int n, int m){
    for(int i=0; i<m; i++){
        int sum=0;
        for(int j=0; j<n; j++){
            sum += v[j][i];
        }
        cout<<sum<<" ";
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> v(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
        }
    }

    rowSum(v, n, m);
    colSum(v, n, m);
    
    return 0;
}
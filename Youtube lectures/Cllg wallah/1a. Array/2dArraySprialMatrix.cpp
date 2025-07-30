#include<iostream>
#include<vector>
using namespace std;

void spiralOrder(vector<vector<int>> &matrix){

    int left=0;
    int right = matrix[0].size() - 1;
    int top=0;
    int bottom = matrix.size() - 1;

    int direction=0;
    while(left<=right && top<=bottom){
        if(direction == 0){
            for(int c=left; c<=right; c++){
                cout<<matrix[top][c]<<" ";
            }
            top++;
        }
        else if(direction == 1){
            for(int r=top; r<=bottom; r++){
                cout << matrix[r][right] << " ";
            }
            right--;
        }
        else if (direction == 2)
        {
            for (int c = right; c >= left; c--)
            {
                cout << matrix[bottom][c] << " ";
            }
            bottom--;
        }
        else 
        {
            for (int r = bottom; r >= top; r--)
            {
                cout << matrix[r][left] << " ";
            }
            left++;
        }
        direction = (direction+1)%4;
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

    spiralOrder(v);

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout<< v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}
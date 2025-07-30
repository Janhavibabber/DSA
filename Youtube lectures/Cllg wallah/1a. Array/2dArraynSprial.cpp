#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> createSprial(int n){
    
    vector<vector<int>> ans(n, vector<int>(n));

    int left=0;
    int right=ans[0].size()-1;
    int top=0;
    int bottom = ans.size()-1;

    int direction = 0;
    int val=1;

    while(left<=right && top<=bottom){
        if(direction ==0){
            for(int c=left; c<=right; c++){
                ans[top][c]= val++;
            }
            top++;
        }
        else if (direction == 1)
        {
            for (int r = top; r <= bottom; r++)
            {
                ans[r][right] = val++;
            }
            right--;
        }
        else if (direction == 2)
        {
            for (int c = right; c >= left; c--)
            {
                ans[bottom][c] = val++;
            }
            bottom--;
        }
        else 
        {
            for (int r = bottom; r >= top; r--)
            {
                ans[r][left] = val++;
            }
            left++;
        }
        direction = (direction+1)%4;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<vector<int>> v(n, vector<int>(n));

    v = createSprial(n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    
    
    return 0;
}
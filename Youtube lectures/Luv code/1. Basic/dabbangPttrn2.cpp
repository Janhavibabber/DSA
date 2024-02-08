// Next Pattern- Lec 4
#include<iostream>
using namespace std;

// star pattern -> right pattern(optional) -> values

// int solve(int n){
//     int c=0;
//     while(n!=0){
//         if(n&1){
//             c++;
//         }  
//         n<<1;
//     }
//     return c;  
// }

int main()
{
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        for (int j = 1; j<=i; j++)
        {
            cout<<n-j+1<<" ";
        }
        for (int j = 1; j <= n-i; j++)
        {
            cout << n - i + 1 << " ";
        }
        for (int j = i; j < n; j++)
        {
            cout << n - i + 1 << " ";
        }
        for (int j = i; j >1; j--)
        {
            cout << n - j + 2 << " ";
        }
        cout << endl;
    }
    // cout<<endl;
    for (int i = n-1; i >= 1; i--)
    {
        for (int j = 1; j < i; j++)
        {
            cout << n - j + 1 << " ";
        }
        for (int j = 1; j <= n - i; j++)
        {
            cout << n - i + 1 << " ";
        }
        for (int j = i; j <= n; j++)
        {
            // cout << n - j + 1;
            cout << n - i + 1 << " ";
        }
        for (int j = i; j > 1; j--)
        {
            cout << n - j + 2 << " ";
            // cout << "*";
        }
        cout << endl;
    }
    

        return 0;
    }
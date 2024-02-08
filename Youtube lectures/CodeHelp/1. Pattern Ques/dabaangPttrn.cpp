#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int i=1;
    while (i<=n)
    {
        // 1st triangle
        int j=1;
        while (j<=(n-i+1))
        {
            cout<<j;
            j++;
        }
        

        // 2nd triangle
        int star = 2*(i-1);
        int k=1;
        while (k<=star)
        {
            cout<<"*";
            k++;
        }
        

        // 3rd triangle
        // int l = 1;
        // int val = n - i + 1;
        // while (l <= (n - i + 1))
        // {
        //     cout << val;
        //     val--;
        //     l++;
        // }
        int start = j - 1;
        while (start)
        {
            cout << start;
            start = start - 1;
        }

        cout<<endl;
        i++;
    }
    
    return 0;
}
// print fibonacci series upto n terms 
#include<iostream>
using namespace std;

int main()
{
    int n=10;
    // cout << "Enter the number of terms: ";
    // cin>>n;

    int a=0;
    int b=1;

    cout<<a<<" "<<b<<" ";
    for(int i=1; i<=n; i++){
        int next_num=a+b;
        cout<<next_num<<" ";

        a=b;
        b=next_num;
    }
    return 0;
}
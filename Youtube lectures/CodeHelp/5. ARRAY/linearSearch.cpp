#include<iostream>
using namespace std;

void linearSearch(int a[], int n, int x){
    int flag=0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x){
            cout << "Element found";
            cout << index;
            flag = 1;
            break;
        }
    }
    if(flag == 0)
        cout<<"not found";
    
}

int main()
{
    int n,x;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the elements to be searched" << endl;
    cin >> x;
    linearSearch(a,n,x);
    return 0;
}
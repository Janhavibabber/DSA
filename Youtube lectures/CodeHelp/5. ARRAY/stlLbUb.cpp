#include<bits/stdc++.h>
using namespace std;

int main(){

    //1. upper & lower bound in case of arrays
    // int n;
    // cin>>n;
    // int a[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>a[i];
    // }
    // sort(a, a+n);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i];
    // }
    // cout<<endl;
    // // int *ptr = lower_bound(a, a+n, 26);
    // // int *ptr = lower_bound(a, a+n, 5);
    // // int *ptr = upper_bound(a, a+n, 26);
    // int *ptr = upper_bound(a, a + n, 5);
    // // int *ptr = upper_bound(a+4, a + n, 5);
    // cout<< *ptr;
    // if(ptr == (a+n)){
    //     cout<<"Not found";
    //     return 0;
    // }

    //2. upper & lower bound in case of vectors
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        cout << a[i]<<" ";
    }
    cout << endl;
    auto it = lower_bound(a.begin(), a.end(), 26);
    // auto it = upper_bound(a.begin(), a.end(), 5);

    cout << *it;
    if (it == a.end())
    {
        cout << "Not found";
        return 0;
    }

    //1. upper & lower bound in case of sets
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    auto it = s.lower_bound(x);
    auto it = s.upper_bound(x);
    cout<<*it;

    return 0;
}
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    //1. Declaration
    // basic declaration
    // vector<int> vb;
    // declaration with size
    // vector<int> v1(10);
    // declaration with variable size
    // vector<int> v(n);

    // 2. initialization
    //  declaration with size and common values
    // vector<int> v2(10, 3);
    // taking input from user
    // for (int i = 0; i < vb.size(); i++)
    // {
    //     int x;
    //     cin>>x;
    //     vb.push_back(x);
    // }
    // // taking input from user with size
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    // 3. display values
    cout<<v.size()<<" ";
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i];
    }
    cout<< endl;
    // 4. deleting value from end
    v.pop_back();
    v.erase(v.begin()+1);
    v.erase(v.begin()+2, v.begin()+4);

    // insert
    vector<int> v(2,100);
    v.insert(v.begin(), 300);
    v.insert(v.begin()+1, 2, 10);

    //swap
    v1.swap(v2);

    // // 5. Coping values of one vector to another
    // // By value - it creates the copy of original vector
    // vector<int> v3 = v;
    // // By reference - it allows to access the values of original vector
    vector<int> &v4 = v;
    cout << v.size() << " ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
    cout << endl;
    cout << v4.size() << " ";
    for (int i = 0; i < v4.size(); i++)
    {
        cout << v4[i];
    }
    cout << endl;
    return 0;
}
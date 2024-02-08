#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main()
{

    // 1. sort function
    //  int n;
    //  cin>>n;
    //  int a[n];
    //  // vector<int> a(n);
    //  for (int i = 0; i < n; i++)
    //  {
    //      cin>>a[i];
    //  }
    //  // sort(a, a+n);
    //  sort(a+2, a+n);

    // // sort(a.begin(), a.end());
    // // sort(a.begin()+2, a.end());
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i];
    // }
    // cout<<endl;

    // 2. Compatator functon
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        cout << a[i].first << ":" << a[i].second << " ";
    }
    cout << endl;

    return 0;
}
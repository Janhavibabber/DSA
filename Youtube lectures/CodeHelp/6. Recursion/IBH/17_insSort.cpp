#include <bits/stdc++.h>
using namespace std;

void insSort(vector<int> &v, int n, int i)
{

    if (n == 0 || n == 1)
    {
        return;
    }

    int curr = v[i];
    int j = i - 1;

    while (curr < v[j] && j>=0){
        v[j + 1] = v[j];
        j--;
    }
    v[j + 1] = curr;
    insSort(v, n-1, i+1);
}

int main()
{
    vector<int> v;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    insSort(v, n, 1);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
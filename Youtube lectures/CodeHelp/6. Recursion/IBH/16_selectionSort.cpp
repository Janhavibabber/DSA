#include<bits/stdc++.h>
using namespace std;

void selSort(vector<int> &v, int n, int i)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    
    int min=i;
    for(int j=i+1; j<n-1; j++){
        if (v[j] < v[min])
        {
            min = j;
        }
    }
    if(min!=i){
        swap(v[min], v[i]);
    }
    selSort(v, n-1, i+1);
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

    selSort(v, n, 0);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
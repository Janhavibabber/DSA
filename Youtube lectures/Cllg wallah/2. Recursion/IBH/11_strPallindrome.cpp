#include<bits/stdc++.h>
using namespace std;

bool solve(string str, int i, int j){
    if(i>j)
        return true;

    if(str[i]!=str[j])
        return false;
    else
        return solve(str, i+1, j-1);
}

// optimize = n-i-1;

int main()
{
    string s;
    cin>>s;

    if (solve(s, 0, s.length() - 1))
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}
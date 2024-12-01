// 8. remove occurenece of char 'a'
#include<bits/stdc++.h>
using namespace std;

string solve(string &s, int idx, int n){
    
    if(idx == n){
        return "";
    }
    string curr = "";
    curr += s[idx];
    return ((s[idx] == 'a')?"":curr + solve(s, idx+1, n));

}

int main()
{
    string s;
    cin>>s;

    int n=s.length();

    solve(s, 0, n);

    cout<<s<<endl;
    
    return 0;
}
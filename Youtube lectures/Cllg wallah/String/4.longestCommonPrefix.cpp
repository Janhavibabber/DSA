#include<iostream>
#include<string>
#include<vector>
using namespace std;

//using sorting: tc->O(nlogn*m)
// string lcp(vector<string> &str){
//     sort(str.begin(), str.end());
//     string ans="";

//     string s1=str[0];
//     string s2=str[str.size()-1];
//     int i=0, j=0;

//     while(i<s1.size() && j<s2.size()){
//         if(s1[i]==s2[j]){
//             ans+=s1[i];
//             i++;
//             j++;
//         }
//         else{
//             break;
//         }
//     }
//     return ans;
// }

// using comparsion: tc->O(nlogn*m)
string lcp(vector<string> &str)
{
    //keeping first string as constant
    string s1=str[0];
    int ans_len=s1.size();

    //start comparing from str[1]
    for(int i=1; i<str.size(); i++){
        int j=0;
        //comparing other string to first string
        while (j<s1.size() && j<str[i].size() && s1[j]==str[i][j]){
            j++;
        }
        //storing the min len
        ans_len=min(ans_len,j);
    }
    //printing the character from first string
    string ans=s1.substr(0, ans_len);
    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<string> str(n);
    for(int i=0; i<n; i++){
        cin>>str[i];
    }

    cout<<lcp(str);

    return 0;
}
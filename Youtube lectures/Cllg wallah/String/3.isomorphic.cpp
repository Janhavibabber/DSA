//isomorphic: when 2 strings are mapped to each other.
#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isomorphic(string s1, string s2){
    // 2 frequency vector for 2 strings
    vector<int> v1(128, -1);
    vector<int> v2(128, -1);

    if(s1.size()!=s2.size()){
        return false;
    }

    for(int i=0; i<s1.size(); i++){
        if(v1[s1[i]]!=v2[s2[i]]){   // initially value will be -1 else it will contain the value same index of both strings for chars needs to be mapped. 
            return false;
        }
        //if char has -1 initially update it with 
        v1[s1[i]]=v2[s2[i]]=i;
    }
    return true;
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;

    if(isomorphic(s1, s2)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

    return 0;
}
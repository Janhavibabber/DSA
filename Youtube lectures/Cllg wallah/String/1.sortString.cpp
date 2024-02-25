#include<iostream>
#include<string>
#include<vector>
using namespace std;

string countSort(string &str){
    vector<int> freq(26,0);
    for(int i=0; i<str.size(); i++){
        freq[str[i]-'a']++;
    }

    int j=0;
    for(int i=0; i<26; i++){
        while (freq[i]--)
        {
            str[j++]=i+'a';
        }
        
    }
    return str;
}

int main()
{
    //using count sort
    string s;
    cin>>s;

    // string ans = countSort(s);
    cout << countSort(s) << endl;

    return 0;
}
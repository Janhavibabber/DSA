#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool anagram(string s1, string s2)
{
    vector<int> freq(26, 0);

    if(s1.length()!=s2.length()){
        return false;
    }
    for (int i = 0; i < s1.size(); i++)
    {
        freq[s1[i] - 'a']++;
        freq[s2[i]-'a']--;
    }

    int j = 0;
    for (int i = 0; i < 26; i++)
    {
        if(freq[i]!=0){
            return false;
        }
    }
    return true;
}

int main()
{
    // using count sort
    string s1, s2;
    cin>>s1>>s2;

    if(anagram(s1, s2)){
        cout<<"YES"<< endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}
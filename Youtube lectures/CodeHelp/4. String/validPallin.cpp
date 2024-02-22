#include<bits/stdc++.h>
using namespace std;

char valid(char ch){
    if((ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
        return ch;
    }
    else{
        return ch-'A'+'a';
    }
}

bool pallin(string str){
    // int flag = 1;
    // check Pallindrome
    int s = 0, e = str.size() - 1;
    while (s < e)
    {
        if (str[s++] != str[e--])
        {
            return 0;
        }
    }
    return 1;
    
}

int main()
{
    string str;
    cin>>str;
    // cin.getline(str);

    // removing all non-alphanumeric characters
    // converting characters to lowercase
    for(int i=0; i<str.size(); i++){
        str[i] = valid(str[i]);
    }

    // cout<<s;
    // cout<< pallin(str);
    if (pallin(str))
    {
        cout << "Pallindrome";
    }
    else
    {
        cout << "Not Pallindrome";
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int len(string str){
    int i=0;
    while (i<str.length())
    {
        i++;
    }
    return i;
}

string revStr(string str){

    // 1. In-built func
    //  TC-O() ; SC-O(1)
    // cout << "In-built func: " << endl;
    // reverse(str.begin(), str.end());
    // return str;

    // 2. Print in Reverse - best
    //  TC-O(n) ; SC-O(1)
    // cout << "Print in Reverse: " << endl;
    // int n = str.length()-1;
    // for (int i=n; i>=0; i--)
    // {
    //     cout<<str[i];
    // }
    // cout<<endl;

    // 3. Additional string - doubt
    //  TC-O(n) ; SC-O(1)
     cout << "Additional String: " << endl;
     string rev="";
     int j = str.length()-1;
     for (int i = 0; i <str.length(); i++){
         rev[i] = str[j];
         j--;
     }
     return rev;

    // 4. Using stack
    // TC-O(n) ; SC-O(n)
    // cout<<"Using Stack: "<<endl;
    // stack<char> st;
    // // traverse string and push into stack
    // for(int i=0; i<str.size(); i++){
    //     st.push(str[i]);
    // }
    // //clear the given string
    // str.clear();
    // //traverse stack push value in string
    // for (int i = 0; st.size(); i++)
    // {
    //     str.push_back(st.top());
    //     st.pop();
    // }
    // //print the string 
    // for (int i=0; i<str.size(); i++)
    // {
    //     cout<<str[i];
    // }

    // 5. Swapping
    // int start = 0, end = str.length() - 1;

    // cout<<"Using Swapping in-built func: "<<endl;
    // while (start<end)
    // {
    //     swap(str[start], str[end]);
    //     start++;
    //     end--;
    // }

    // cout<<"Using Swapping third Variable: OR Using two pointer approach to Swap:"<<endl;
    // while (start < end)
    // {
    //     char temp = str[start];
    //     str[start]=str[end];
    //     str[end]=temp;
    //     start++;
    //     end--;
    // }

    // cout<<"Using index to Swap: "<<endl;
    // int n = str.length();
    // for (int i = 0; i < n/2; i++)
    // {
    //     char temp = str[i];
    //     str[i] = str[n-i-1];
    //     str[n-i-1] = temp;
    // }
    // return str;
}

// With Extra Constraints - to check valid characters and convert themto lowercase
bool is_valid()
{
}

char to_lowerCase(char ch)
{
}

bool isStrPallin(string str){

    // 1. Using Reverse of string
    string rev = revStr(str);
    if(str == rev){
        // cout<<"Pallindrome";
        return false;
    }
    else{
        // cout<<"Not a Pallindrome";
        return true;
    }

    // 2. Using two pointer approach
    int start=0, end=str.length();
    while (start<end)
    {
        if(str[start++] != str[end--]){
            return false;
        }
    }
    return true;

    // 3. Valid Lowercase check with pallindrome
    // by writing ur own function
    int i=0, j = str.length() - 1;
    while (i<j)
    {
        while(i<=j && !isalnum(str[i])){
            i++;
        }
        while (i <= j && !isalnum(str[j]))
        {
            j--;
        }
        if(i<=j){
            if(to_lowerCase(str[i]) != to_lowerCase(str[j])){
                return false;
            }
            i++;
            j--;
        }
    }
    return true;

    // by using built-in func
    
    
}

int main()
{
    string s="hello";

    // length of string
    cout<<len(s)<<endl;

    // reverse string
    string ans = revStr(s);
    cout << ans << endl;
    // revStr(s);

    //Pallindrome
    cout<<isStrPallin(s)<<endl;


    return 0;
}
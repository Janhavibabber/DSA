#include<iostream>
using namespace std;

int main()
{
    string s;
    cin>>s;
    string rev;

    // reverse string
    for(int i= s.size()-1; i>=0; i--){
        rev.push_back(s[i]);
    }
     cout<<rev;

    // pallindrome or not
    if(s == rev){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }

    // pallindrome string or not 

    //method 1;
    // int start = 0;
    // int end = s.size()-1;
    // while(start < end){
    //     if(s[start++] != s[end--]){
    //         cout<<"not pallindrome";
    //     }
    // }

    // method 2
    // int n = s.size();
	// for(int i=0; i<n; i++){
	// 	if(s[i] != s[n-i-1]){
	// 		cout<<"NO";
	// 		return 0;
	// 	}
	// }
	// cout<<"YES";

    return 0;
}
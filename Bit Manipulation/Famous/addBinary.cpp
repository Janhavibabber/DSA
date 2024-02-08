// sum of binary strings
// AscII (0-48......9-57)
// to convert into integer: '0'-48 = 0; '1'- 48
#include<bits/stdc++.h>
using namespace std;

string addBinary(string a, string b)
{
    int i = a.size()-1;
    int j = b.size()-1;
    string result = " ";

    int sum = 0;
    int d1,d2;
    int carry=0;

    while(i>=0||j>0)
    {
        d1 = i>=0?a[i]-'0':0;
        d2 = j>=0?b[i]-'0':0;
        sum = (d1+d2+carry)%2;
        carry = (d1+d2+carry)/2;
        result = to_string(sum)+result;
        i--;
        j--;
    }

    // to discard last carry
    if(carry != 0)
        result = to_string(carry)+result;
    return result;

}

int main()
{
    string a,b;
    cin>> a>>b;
    // string a = "10";
    // string b = "11";
    cout<< addBinary(a,b);
    return 0;

}


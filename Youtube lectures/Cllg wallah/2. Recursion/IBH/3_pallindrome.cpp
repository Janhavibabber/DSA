#include<iostream>
using namespace std;

bool solve(int n, int *temp){
    if(n>=0 and n<=9){
        int lastDigit = (*temp)%10;
        (*temp)/=10;
        return (n == lastDigit);
    }
    bool res = (solve(n/10, temp) and (n%10)==(*temp%10));
    (*temp)/=10;
    return res;
}

int main()
{
    int n;
    cin>>n;
    int *temp = &n;
    cout<<solve(n, temp);
    
    return 0;
}
#include<iostream>
using namespace std;

//ip: 2no.'s(a=2->10,b=3->11)   op: 3 
// dec to bin convert -> iterate last se count the no. of set bits -> return count

int solve(int n){
    return 3*n+7;
}

int main()
{
    int n;
    cin >> n;

    int ans = solve(n);
    cout << "Answer is " << ans << endl;

    return 0;
}
#include<iostream>
using namespace std;

bool isEven(int n){
    if(n&1){
        //odd
        return 0;
    }
    //even
    return 1;
}

int main()
{
    int n;
    cin>>n;

    int ans = isEven(n);
    cout << "Answer is " << ans << endl;

    return 0;
}
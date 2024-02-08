#include<iostream>
using namespace std;

bool isPrime(int n){

    for(int i=1; i<=n; i++){
        if(n%i == 0){
            return 0;
        }
    }

    return 1;
}

int main()
{
    int n;
    cin >> n;

    int ans = isPrime(n);
    cout << "Answer is " << ans << endl;

    return 0;
}
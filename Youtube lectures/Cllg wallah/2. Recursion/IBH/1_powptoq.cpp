#include<iostream>
using namespace std;

int power(int p, int q){
    if(q==0)
        return 1;
    if(q%2 == 0){
        int res = power(p, q/2);
        return res*res;
    }
    else{
        int res = power(p, (q-1)/2);
        return p*res*res;
    }
}

int main()
{
    int p, q;
    cin>>p>>q;

    cout<< power(p, q);
    
    return 0;
}
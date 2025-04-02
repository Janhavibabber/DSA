#include<iostream>
using namespace std;

int power(int p, int q){
    // normal code
    if(q==0)
        return 1;
    
    return power(p, q-1) *p;

    // optimized code 1
    // if (q == 0)
    //     return 1;

    // if (q % 2 == 0)
    // {
    //     int res = power(p, q / 2);
    //     return res * res;
    // }
    // else
    // {
    //     int res = power(p, (q-1) / 2);
    //     return p * res * res;
    // }

    // optimized code 2
    // if(q==0)
    //     return 1;

    // if (q == 1)
    //     return p;

    // int res = power(p, q/2);
    
    // if(q%2 == 0){
    //     return res*res;
    // }
    // else{
    //     return p*res*res;
    // }

    // optimized code 3
    // if(q==0)
    //     return 1;

    // int res = power(p, q/2);

    // if(q%2 == 0){
    //     return res*res;
    // }
    // else{
    //     return p*res*res;
    // }
}

int main()
{
    int p, q;
    cin>>p>>q;

    cout<< power(p,q);
    
    return 0;
}
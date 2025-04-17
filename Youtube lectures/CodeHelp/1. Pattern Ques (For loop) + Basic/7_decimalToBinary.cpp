#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Approach 2
    int n; 
    cin>>n;
    int ans=0, i=0;

    while(n!=0){
        // take the last decimal digit => n&1 = n%2
        int bit = n&1;
        // cout << "before: "<< i<<" "<<bit<<" "<<ans << endl;

        // set the bit in the answer which will be stored in reverse order=> ans = ans + (bit * 10^i)
        // ans = (bit * pow(10,i)) + ans --> prints no. in reverse order of digits/bits it gets e.g. 1,2,3 = 321
        // ans = (ans * pow(10,i)) + bit --> prints no. in reverse order of digits it gets e.g. 1,2,3 = 123
        float p = pow(10, i);
        ans += (bit * p);
              
        // cout << "after: " << i << " " << bit << " " << ans << endl;
        // right shift the number = Divide it by 2 => n>>1 = n/2
        n = n>>1;
        i++;
    }
    cout<<ans<<endl;

    return 0;
}
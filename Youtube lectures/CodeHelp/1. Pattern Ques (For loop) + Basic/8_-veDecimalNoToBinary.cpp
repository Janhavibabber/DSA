#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    // cout << "Enter any number: ";
    cin >> num;
    int n = num*-1;
    int one = (~n); // 1's complement
    int carry = 1;
    int two = 0, i = 0;
    while (n) // until n becomes 0
    {
        int sum = (one ^ carry);        // to calculate the sum of lsb(least significant bit) of carry and 1's complement
        carry = carry & one;            // to calculate the carry in binary addition
        int bit = (sum & 1);            // to calculate the current bit
        two = (bit * pow(10, i)) + two; // 2's complement
        n = n >> 1;
        one = one >> 1;
        i++;
    }
    cout <<"Print 2's complement stored in memory: "<<two;
    return 0;
}
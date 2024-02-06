// C++ program to check whether a mumber
// is prime or nots
#include<iostream>
using namespace std;

int main()
{
    int num;
    int div = 0;
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        // if the given number has a divisor
        if(num % i == 0)
        {
            div++;
        }
    }
    // if a number has two divisor itself n 1
    if(div == 2)
    {
        cout <<"Prime number";
    }
    else
    {
        cout <<"Not a Prime number";
    }
    return 0;
}
// find the sum of no.s in agiven range
#include<iostream>
using namespace std;

int main(){
    int low, high;
    int sum =0;
    cin >> low >> high;
    for (int i = low; i <= high; i++)
    {
        sum += i;
    }
    cout<< sum;
}
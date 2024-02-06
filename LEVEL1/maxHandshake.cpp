#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the no. of people in the room";
    cin>>n;
    int total_Handshakes = n*(n-1)/2;
    cout<<total_Handshakes;
    return 0;
}
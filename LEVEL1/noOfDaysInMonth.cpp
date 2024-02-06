#include<iostream>
using namespace std;

int main()
{
    int month,yr;
    cout<<"Enter the month: ";
    cin>> month;
    cout<<"Enter thr year: ";
    cin>>yr;
    if(month == 2 && (yr%4 == 0) || (yr % 100 == 0) && (yr%400 == 0))
        cout<<"numbers of Days is 29";
    else if(month == 2)
        cout<<"numbers of Days is 28";
    else if(month == 1|| month == 3||month == 5||month == 7||month == 8||month == 10||month == 12)
        cout<<"numbers of Days is 30";
    else
        cout<<"numbers of Days is 31";
    return 0;
}
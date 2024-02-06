// leap year
#include<iostream>
using namespace std;

int main(){
    int yr;
    cin>>yr;
    if(((yr%4==0) && (yr%100 != 0)) || yr%400 == 0)
    {
        cout<<"leap year";
    }
    else
    {
        cout<< " not leap year";
    }
    return 0;
}
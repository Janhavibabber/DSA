#include<iostream>
using namespace std;

int main()
{
    // use of break keyword - print 1 to n
    int i=1;
    for( ; ; ){
        if(i<=n){
            cout<<i<<endl;
        }
        else{
            break;
        }
        i++;
    }


    // use of continue keyword

    for(int i=0; i<5; i++){
        cout<<"before continue"<<endl;
        continue;
        cout<<"after continue"<<endl;
    }


    return 0;
}
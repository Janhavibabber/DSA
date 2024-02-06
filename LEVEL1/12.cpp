#include <iostream>
using namespace std;

void greatest(int x, int y, int z)
{
    int big = x;
    if(x<y)
    {   
        big = y;
        if(y<z)
            big = z;
    }
    else if(x<z)
    {   
        big = z;
    }
     cout << big;
}

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    
    greatest(a,b,c);
    return 0;
}
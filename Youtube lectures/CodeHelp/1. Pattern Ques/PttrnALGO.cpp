#include<iostream>
using namespace std;

// 1. steps
// 2. steps + col condition for last value printed
// 3. steps + starting value formula

int main()
{
    //1. I/p of rows n col
    int n;
    cin>>n;

    //2. row initialization
    int i = 1;

    // 3. Extra variable initialization (optional)
    //  char ch = 'A';

    //4. no. of rows condition
    while (i <= n)
    {   //5. SPACE PRINT(1st triangle)
        // 5.a space initialization(if needed)
        int space = n-i;

        // 5.b space print loop(if needed)
        while (space)
        {
            cout<<" ";
            space=space-1;
        }
        

        //PATTERN PRINT(2nd triangle)
        // 6. col initialization
        int j = 1;

        // 7. Extra variable initialization OR starting OR All value formula(optional)
        // char ch = 'A' + i -1;

        // 8. no. of cols condition
        while (j<=i)
        {
            // 8.a All value formula OR type chasting(optional)
            // char ch = 'A' + i - 1;

            //8.b print value
            cout<<j;

            // 8.c Extra variable increment(optional)
            //  ch = ch+1;

            // 8.d col increment
            j++;
        }

        //9. 3rd triangle(if needed)
        int start = i-1;
        while (start)
        {
            cout<<start;
            start = start -1;
        }
        cout<<endl;

        // 10. row increment
        i++;
    }
    

    

    return 0;
}
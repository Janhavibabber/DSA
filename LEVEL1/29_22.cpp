//C++ Program
    //Abundant Number or not

// Abundant number is an number in which the sum of the proper divisors of the number is greater than the number itself.

// To check for Abundant number, find and add the proper divisors of the number , compare the sum with the number if the sum is greater than the number than the number is an Abundant number else not an Abundant number. 

// eg: 12                  exp: 1 x 12= 12         Divisors: 1,2,3,4,5,6
//                             2 X 6 = 12          12 is a abundant number
//                             3 X 4 = 12
//                             1+2+3+4+5+6 =16>12

    #include<iostream>
    using namespace std;
    //main Program
    int main ()
    {  
        int  div, num, sum=0;
        cout << "Enter the number to check : ";
        //user input
        cin >> num;
        //loop to find the sum of divisors
        for (int i=1; i < num; i++)
        {
        div = num % i;
            if (div == 0)
            sum += i;
        }
        //checking for Abundant number
        if (sum > num)
            cout<< num <<"is an Abundant number. ";
        else
            cout<< num <<" is not an Abundant number.";
        return 0;
    }

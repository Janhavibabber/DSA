//C++ Program
//Armstrong number number or not
// Armstrong number is the number in which the sum of cubes of the individual digits of the number equals to the number itself.

// To check for Armstrong number first break the number into digits, find and add the cubes of the individual digits, Compare the result with the number itself. If equal then the number is an Armstrong Number else not an Armstrong number.

// For example:153 = 13 + 53 +33
    #include<iostream>
    #include<math.h>
    using namespace std;
    //main Program
    int main()
    {
        int num, digit, sum = 0;
        cout << "Enter a positive  integer:  ";
        //user input
        cin >> num;
        int store = num;
        //find sum of cubes of individual digits
        do
        {
            digit = num % 10;
            sum = sum + pow(digit,3);
            num = num / 10;
        }while(num != 0);
        //checking for ArmStrong number
        if(sum == store)    
            cout << store << "is an Armstrong number.";
        else
            cout << store << "is not an Armstrong number. ";
        return 0;
    }

// Amicable numbers are two different numbers related in a way such that the sum of the proper divisors of each is equal to the other number. A proper divisor is a positive factor of that number other than the number itself ,for Example proper divisors of 6 are 1, 2, and 3.

// The smallest pair of amicable numbers is (220, 284). They are amicable because the sum of proper divisors of 220 (1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110) is 284; and the sum of proper divisors of 284 (1, 2, 4, 71 and 142) is 220.


#include<iostream>
using namespace std;

int main()
{
	//fill the code
	int num1, num2;
	cin >> num1;
	cin >> num2;
	int sum1 = 0, sum2 = 0;
	for(int i = 1; i < num1; i++)
	{
		if(num1 % i == 0)
		{
			sum1 = sum1 + i;
		}
	}
	for(int i = 1; i < num2; i++)
	{
		if(num2 % i == 0)
		{
			sum2 = sum2 + i;
		}
	}
	if(sum1 == num1 && sum2 == num2)
		cout << "Friendly Pair" ;
	else
		cout << "Not Friendly Pair";
	return 0;
}
// C++ program to check if a number is Authomorphic
// An automorphic number is a number in which the last digits of the square of the number is equal to the number itself.

// To check for Automorphic number, first find the square of the number. Then compare the last digits of the square by the number digit by digit and then are equal then it’s an Automorphic number else not.

// Example: 25
// Square of 25 = 625
// As we can see the last digits of square equals to the number, so 25 is an Automorphic number.

#include <iostream>
using namespace std;

// in order to perform this operation in main u need to considersome extra varible such as count
  
// Function to check Automorphic number
bool isAutomorphic(int N)
{
    // Store the square
    int sq = N * N;
  
    // Start Comparing digits
    while (N > 0) {
        // Return false, if any digit of N doesn't
        // match with its square's digits from last
        if (N % 10 != sq % 10)
            return false;
  
        // Reduce N and square
        N /= 10;
        sq /= 10;
    }
  
    return true;
}
  
// Driver code
int main()
{
    int N = 5;
  
    isAutomorphic(N) ? cout << "Automorphic"
                     : cout << "Not Automorphic";
  
    return 0;
}

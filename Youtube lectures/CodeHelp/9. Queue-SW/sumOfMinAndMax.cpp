#include<bits/stdc++.h>
using namespace std;

// Returns sum of min and max element of all subarrays
// of size k
int SumOfKsubArray(vector<int> arr, int k)
{
    int sum = 0;  // Initialize result

    // The queue will store indexes of useful elements
    // in every window
    // In deque 'G' we maintain decreasing order of
    // values from front to rear
    // In deque 'S' we  maintain increasing order of
    // values from front to rear
    deque< int > S(k), G(k);

    // Process first window of size K
    int i = 0, j=0;

    while(j<arr.size()){
        // jth Calc

        // Remove all previous greater elements
        // that are useless.
        while ( (!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back(); // Remove from rear

        // Remove all previous smaller that are elements
        // are useless.
        while ( (!G.empty()) && arr[G.back()] <= arr[i])
            G.pop_back(); // Remove from rear

        // Add current element at rear of both deque
        G.push_back(i);
        S.push_back(i);

        if(j-i+1 == k){
            // store ans
            sum += arr[S.front()] + arr[G.front()];

            // Remove ith calc 
            // Remove all elements which are out of this
            // window
            if ( !S.empty() && S.front() == i - k)
                S.pop_front();
            if ( !G.empty() && G.front() == i - k)
                G.pop_front();

            i++;
        }
        j++;
    }
    return sum;
}

int main(){
    vector<int> arr = {2, 5, -1, 7, -3, -1, -2};
    int k=4;

    cout<<SumOfKsubArray(arr, 4);
}


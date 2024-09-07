#include<bits/stdc++.h>
using namespace std;

// 1. main condition k == 1 or s.size() == k
// 2. recursion function with int 
// 3. int val = st.top();st.pop(); OR val = st.pop();

// App 1
//  #include <bits/stdc++.h>
//  using namespace std;

// int middle(stack<int> &st , int center ){
//     if(st.empty()){
//         return -1;
//     }

//     if(st.size() == center){
//         return st.top();
//     }

//     int temp = st.top();
//     st.pop();
//     int beechka =  middle(st , center);
//     st.push(temp);
//     return beechka;
// }

// int main() {
//   stack<int> st;
//   st.push(1);
//       st.push(4);
//   st.push(3);
//   st.push(2);

//   int mid= (st.size()/2) + 1;

//   cout<<middle(st,mid);
//      return 0;
// }

// App 2
void solve(stack<int> &s, int k)
{
    if (s.size() == k)
    {
        s.pop();
        return;
    }
    int val = s.top();
    s.pop();
    solve(s, k);
    s.push(val);
}
void deleteMid(stack<int> &s, int sizeOfStack)
{
    if (sizeOfStack == 0)
    {
        return;
    }
    int mid = floor((sizeOfStack + 1) / 2);
    solve(s, mid);
}

//App 3
// Approach to Find Middle Element from Stack
// If the stack has N elements , then we need to somehow store N/2 elements of the stack and then delete (N/2 + 1)-th element of the stack . Then we can push the top N/2 elements that we have stored . To store N/2 elements we have two methods: either we can go for an interactive approach and use a temporary stack or we can go for a recursive approach and use a recursive stack . Let’s try to understand both .

// Algorithm for Iterative Approach
// Create an empty temporary stack temp.
// Pop N/2 elements from the given stack and Push it into the temp stack.
// Pop top of the given stack , this is the targeted middle element.
// Pop all elements from the temp stack and Push it into the given stack.
// This will be the final stack after deleting the middle element.
// Algorithm for Recursive Approach
// Create a recursive function which will accept the current stack and initial size of the input stack.
// In each call we first check if N/2 elements have already been deleted , then the top of stack will be the targeted middle element , we will pop it and stop the recursive call.
// Else we pop the top of stack and store it into a variable x , and do the recursive call for the current stack after popping.
// Once the recursive call completes, push x into the stack.
// The stack obtained at the end of the call is the final required stack.
// Code Implementation
// #include <bits/stdc++.h>
// using namespace std;

// void deleteMid(stack<int> &st, int N)
// {
//     int popped_elements = N - st.size();
//     if (popped_elements == (N / 2))
//     {
//         st.pop();
//         return;
//     }
//     int x = st.top();
//     st.pop();
//     deleteMid(st, N);
//     st.push(x);
// }

// void deleteMidElement(stack<int> &st)
// {
//     int N = st.size();
//     deleteMid(st, N);
// }

// int main()
// {
//     stack<int> st;
//     st.push(6);
//     st.push(5);
//     st.push(4);
//     st.push(3);
//     st.push(2);
//     st.push(1);
//     deleteMidElement(st);
//     while (!st.empty())
//     {
//         cout << st.top() << " ";
//         st.pop();
//     }
//     return 0;
// }
// Time Complexity : O(N)
// Space Complexity : O(N)

//App 4
// Approach 1st using Recursion :-
// first for the finding mid element we are calling the deleteMid() function;
// for this we will take a variable for traversing means poping the element untill to be equal to the sizeOfStack/2;
// for
//     storing the element we will take a variable which stores the value of top element in every calling, when the mid element will be find and remove the mid element then the system stack gives the value 1 by 1;
// then the element of the stack will be removed;

// C++ Code : -class Solution
// {
// public:
//     // Function to delete middle element of a stack.
//     int count = 0;
//     void deleteMid(stack<int> &s, int sizeOfStack)
//     {
//         if (count == sizeOfStack / 2)
//         {
//             s.pop(); //<--mid element
//         }
//         else
//         {
//             int top = s.top();
//             s.pop();
//             count++;
//             deleteMid(s, sizeOfStack); // calling untill count is equal to the mid index
//             s.push(top);
//         }
//     }
// };

// ? ? ? ? Approach 2nd using Addition data structure : -first we will find the mid element : for this we can do 'sizeOfStake/2';
// then we will poping the element of stack and store in vector till(sizeOfStack / 2) - 1;
// finally then we will remove or pop the mid element;
// then will push the all stored element in the stack;
// Time Complexity :-
// time complexity for poping the element till sizeOfStack/2 is - O(n/2);
// time complexity for pushing the element which is stored in vector array is - O(n/2);
// Total Time Complexity - n / 2 + n / 2 = O(n);
// Total Time Taken : 0.09 seconds;
// // for both approaches
// Space Complexity :-
// space Complexity for the store element in vector array is - O(n/2);
// Total Space Complexity - O(n / 2) it means O(n).
//                          // for both approaches

//                          C++ Code : -class Solution
// {
// public:
//     // Function to delete middle element of a stack.
//     void deleteMid(stack<int> &s, int sizeOfStack)
//     {
//         vector<int> store;
//         int n = (sizeOfStack) / 2; // half of size which will give mid index
//         while (n--)
//         {
//             store.push_back(s.top());
//             s.pop();
//         }
//         s.pop(); //<--mid element
//         for (int i = store.size() - 1; i >= 0; i--)
//         {
//             s.push(store[i]);
//         }
//     }


//app 5
// TOTAL TIME TAKEN : 0.2 ????
// The task is to delete the middle element of a stack without using any additional data structure!!

// Basic Algorithm To Solve This Problem(using recursion):
// 1. At first check if the size of the stack is zero. If it is zero, it means there is no middle element to delete, so just return.

// 2. Next calculate the middle index (I did it in my code as mid = sizeOfStack // 2 ) to get the index of the middle element of the stack. 

// 3. After that create a recursive function( in my code I named it as deleteMiddle )that takes the stack and the current index as parameters then checks if the current index is equal to the middle index. If it is, simply pop the element from the stack and return.

// 4. In case if the current index is not equal to the middle index, just pop the top element of the stack and  call the ( deleteMiddle ) function recursively with the updated stack and the current index incremented by 1.

// 5. After the recursive call, append the top element back to the stack so that the order of the remaining elements is maintained.

// 6. Just call the ( deleteMiddle ) function with the stack and an initial current index of 0.

// 7. The function will modify the stack by deleting the middle element.

// CODE:

// class Solution:
    
//     def deleteMid(self, s, sizeOfStack):
        
//         if sizeOfStack == 0:
//             return

//         mid = sizeOfStack // 2

//         def deleteMiddle(stack, current):

//             if current == mid:
//                 stack.pop()
//                 return

//             top = stack.pop()
//             deleteMiddle(stack, current + 1)

//             stack.append(top)

//         deleteMiddle(s, 0)
// Deep Explaination of The Code :
// 1. The deleteMid function takes stack s and the size of the stack sizeOfStack as input parameters.

// 2. It first checks if the size of the stack is zero or not. If it is zero there are no elements in the stack, So it simply returns.

// 3. When the size of the stack is not zero, it calculates the middle index as mid = sizeOfStack // 2. To get the index of the middle element of the stack.

// 4. Then the function defines a helper function called deleteMiddle inside it. This a recursive function that takes the stack stack and the current index current as input parameters.

// 5. Inside the deleteMiddle function, At first it checks if the current index is equal to the middle index or not. If it is equal to the middle, it means it had reached the middle element. In this case, it pops the element from the stack using stack.pop() function and returns.

// 6. If the current index is not equal to the middle index, it means the middle element is not reached yet. In this case, it pops the top element from the stack using stack.pop() function and assigns it to the top variable.

// 7. After popping the top element, it recursively calls the deleteMiddle function with the value of updated stack and the value of current index incremented by 1. This is actually moving the current index towards the middle of the stack.

// 8. It continues until the current index reached the middle index. After it reached the middle element it deletes the element from the stack using stack.pop().

// 9. When the recursive call finally returns it appends the top element back to the stack using stack.append(top) to maintain the order of the remaining elements in the stack.

// 10. Finally, in the deleteMid function, it calls the deleteMiddle function with the original stack s and the initial current index as 0. This starts the process of deleting the middle element.

// 11. The deleteMiddle function modifies the stack by deleting the middle element.

// Break Down of Time Complexity:
// O(N)
// 1. Initially checking of  if sizeOfStack == 0 takes constant time, O(1).

// 2. Calculating the middle index mid = sizeOfStack // 2 also takes constant time, O(1).

// 3. Inside the deleteMiddle function, popping an element from the stack using stack.pop() also takes constant time, O(1).

// 4. The recursive function deleteMiddle it is called recursively for each element in the stack except the middle element. So, in the worst case, it will be called N-1 times, where N is the size of the stack, it generates the time complexity of O(N).

// 5. Appending the top element back to the stack using stack.append(top) also takes constant time, O(1).

// Overall, the time complexity of the code is O(N) because the main recursive function deleteMiddle will be called N-1 times in the worst case.

// Break Down of The Space Complexity:
// O(N)

// 1. The space required to store the stack is O(N), where N is the size of the stack.

// 2. The space required for the recursive function deleteMiddle  depends on the number of recursive calls are made. In the worst case, the number of recursive calls is N-1, where N is the size of the stack. Therefore, the space required for the call stack is O(N) in the worst case.

// 3. Apart from the stack and the recursive call stack, there are no other data structures used in the code. The top variable is a temporary variable holding a single element and is not enough to contribute to the overall space complexity.

// Overall, the space complexity of the code is O(N) due to the space required for the stack and the call stack.


//App 6
// public
// void deleteMid(Stack<Integer> s, int sizeOfStack)
// {
//     // code here
//     int mid = (sizeOfStack + 1) / 2;
//     mid = mid - 1;

//     s.remove(mid);
// }
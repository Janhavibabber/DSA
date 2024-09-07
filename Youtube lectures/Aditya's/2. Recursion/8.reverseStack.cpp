#include <bits/stdc++.h>
using namespace std;

//app 1
//  Approach 1 

// Using a Queue for Recursion In this approach, you are using a queue to store the elements of the stack during the recursive call. The base case of the recursion is when the stack becomes empty, and in that case, you start pushing back the elements from the queue into the stack. This process essentially reverses the stack.

// Intuition:

//  1. Start the recursion by pushing the top element of the stack into the queue and then popping it from the stack.

//      2. Recursively call the function to process the remaining elements of the stack.

//      3. Once the recursion reaches the base case (the stack is empty),
//      you start pushing back the elements from the queue into the stack.

//      4. This process reverses the stack.

//      Time Complexity:

// - The recursive function is called for each element in the stack, which takes O(n) time.


// - While reversing the stack, you have to pop all elements from the queue and push them back into the stack, which takes an additional O(n) time.


// - Therefore, the overall time complexity is O(n^2).

// Space Complexity:


// - The recursive function uses a queue to store the elements temporarily, which takes O(n) space.


// - Therefore, the space complexity is O(n).

// Code here :-

// class Solution
// {
// public:
//     queue<int> ans;
//     void Reverse(stack<int> &St)
//     {

//         if (!St.empty())
//         {
//             ans.push(St.top());
//             St.pop();
//         }
//         else
//         {
//             return;
//         }

//         Reverse(St);

//         while (!ans.empty())
//         {
//             St.push(ans.front());
//             ans.pop();
//         }
//     }
// };

// Approach 2 : Using an Additional Vector

//                  In this approach,
//              you use an additional vector to store the elements of the stack.You pop elements from the stack and push them into the vector until the stack becomes empty.Then,
//              you push the elements from the vector back into the stack,
//              effectively reversing the stack.

//              Intuition :

//              1. Start by popping elements from the stack and pushing them into the vector until the stack becomes empty.

//              2. The elements are now stored in the vector in reversed order.

//              3. Push back the elements from the vector into the stack,
//              which effectively reverses the stack.

//                  Time Complexity :

//     -Popping elements from the stack and pushing them into the vector takes
//     O(n) time.

//                  - Pushing back elements from the vector into the stack also takes O(n) time.

//                  - Therefore,
//              the overall time complexity is O(n).

//              Space Complexity :

//     -The additional space used in this approach is the vector to temporarily store the elements of the stack,
//              which takes O(n) space.

//                  - Therefore,
//              the space complexity is O(n).

//              Code here : -

//                          class Solution
// {
// public:
//     void Reverse(stack<int> &St)
//     {
//         vector<int> arr;
//         while (!St.empty())
//         {
//             arr.push_back(St.top());
//             St.pop();
//         }
//         int n = arr.size();
//         for (int i = 0; i < n; i++)
//         {
//             St.push(arr[i]);
//         }
//     }
// };
// "If you have another approach, please share it. Exploring different approaches helps develop our minds and enables us to perceive problems more adeptly."

//app 2
// void insertAtBottom(stack<int> &st, int item)
// {
//     if (st.empty())
//     {
//         st.push(item);
//         return;
//     }
//     int top = st.top();
//     st.pop();
//     insertAtBottom(st, item);
//     st.push(top);
// }

// void Reverse(stack<int> &st)
// {
//     if (st.size() == 1)
//         return;
//     if (st.empty())
//         return;

//     int temp = st.top();
//     st.pop();
//     Reverse(st);
//     insertAtBottom(st, temp);

//     return;
// }

// app 3
// Approach : -The intution behind this question is very easy

//                Let's understand steps of the code execution:

//            Step 1 : Initial Stack[1, 2, 3, 4, 5]
// ``` 5 < -Top 4 3 2 1 < -Bottom
// ``` Step 2 : Reverse() function is called

//               Step 3 : Recursive call to Reverse() with[4, 3, 2, 1]

//                        Step 4 : Recursive call to Reverse() with[3, 2, 1]

//                                 Step 5 : Recursive call to Reverse() with[2, 1]

//                                          Step 6 : Recursive call to Reverse() with[1]

//                                                   Step 7 : Reverse() reached the base case (empty stack) and
//     starts returning

//     Step 8:
// insertAtBottom(St, 1)
// ``` 1 < -Top
// ```

//          Step 9 : insertAtBottom(St, 2)
// ``` 1 < -Top
//          2 < -Bottom
// ``` Step 10 : insertAtBottom(St, 3)
// ``` 1 < -Top
//          2 3 < -Bottom
// ```

//                Step 11 : insertAtBottom(St, 4)
// ``` 1 < -Top
//          2 3 4 < -Bottom
// ```

//                  Step 12 : insertAtBottom(St, 5)
// ``` 1 < -Top
//          2 3 4 5 < -Bottom
// ```

//                    Step 13 : Final Reversed Stack[5, 4, 3, 2, 1]
// ``` 1 < -Top
//          2 3 4 5 < -Bottom
// ```

//                     The recursion works in a way that each element is popped from the original stack and then inserted at the bottom of the stack using the `insertAtBottom()` function.This process continues until all the elements are reversed,
//     and we end up with the reversed stack.

//         Time Complexity : O(N) where N is the number of elements in the stack.Each element needs to be processed once,
//     and the recursion goes through all the elements.

//         Space Complexity : O(N) due to the recursion stack.The recursion depth can go up to the number of elements in the stack,
//     hence the space complexity is linear with respect to the number of elements in the stack.

//     // User function Template for C++

//     class Solution
// {
// public:
//     void insertAtBottom(stack<int> &st, int ele)
//     {
//         if (st.empty())
//         {
//             st.push(ele);
//             return;
//         }
//         int top = st.top();
//         st.pop();
//         insertAtBottom(st, ele);
//         st.push(top);
//     }
//     void Reverse(stack<int> &St)
//     {
//         if (St.empty())
//         {
//             return;
//         }
//         int ele = St.top();
//         St.pop();
//         Reverse(St);
//         insertAtBottom(St, ele);
//     }
// };

//app 4
// vector<int> ans;

// vector<int> Reverse(stack<int> &St)
// {
//     if (St.empty())
//         return ans;
//     ans.push_back(St.top());
//     St.pop();
//     return Reverse(St);
// }

//app 5
// void bottom(stack<int> &st, int x)
// {
//     if (st.empty())
//     {
//         st.push(x);
//         return;
//     }
//     int num = st.top();
//     st.pop();
//     bottom(st, x);
//     st.push(num);
// }

// void rev(stack<int> &st)
// {
//     if (st.empty())
//     {
//         return;
//     }
//     int num = st.top();
//     st.pop();
//     rev(st);
//     bottom(st, num);
// }
// vector<int> Reverse(stack<int> st)
// {
//     vector<int> vc;
//     rev(st);
//     int n = st.size();
//     while (!st.empty())
//     {
//         vc.push_back(st.top());
//         st.pop();
//     }
//     reverse(vc.begin(), vc.end());
//     return vc;
// }

// app 6
// void insert(stack<int> &St, int temp)
// {
//     if (St.size() == 0)
//     {
//         St.push(temp);
//         return;
//     }
//     int val = St.top();
//     St.pop();
//     insert(St, temp);
//     St.push(val);
// }
// void Reverse(stack<int> &St)
// {
//     if (St.size() == 1)
//     {
//         return;
//     }
//     int temp = St.top();
//     St.pop();
//     Reverse(St);
//     insert(St, temp);
// }

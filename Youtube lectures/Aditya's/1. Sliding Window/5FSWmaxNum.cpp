//Find the maximum number in a maximum of all subarrays of size K
#include <bits/stdc++.h>
using namespace std;

// #include <list>
// vector<int> Solution::slidingMaximum(const vector<int> &A, int B)
// {
//     vector<int> ans;
//     list<int> l;
//     int i{0}, j{0};

//     while (j < A.size())
//     {
//         while (l.size() > 0 && l.back() < A[j])
//         {
//             l.pop_back();
//         }
//         l.push_back(A[j]);

//         if (j - i + 1 < B)
//         {
//             j++;
//         }
//         else
//         {
//             ans.push_back(l.front());
//             if (A[i] == l.front())
//             {
//                 l.pop_front();
//             }
//             i++;
//             j++;
//         }
//     }
//     return ans;
// }


// vector<int> Solution::slidingMaximum(const vector<int> &nums, int k)
// {

//     deque<int> dq;

//     vector<int> res;

//     int l = 0;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         while (!dq.empty() && nums[i] > dq.back())
//         {
//             dq.pop_back();
//         }

//         dq.push_back(nums[i]);

//         if (i >= k - 1)
//         {
//             res.push_back(dq.front());

//             if (dq.front() == nums[l])
//             {
//                 dq.pop_front();
//             }

//             l++;
//         }
//     }

//     return res;
// }

// vector<int> max_of_subarrays(vector<int> arr, int n, int k)
// {
//     // your code here
//     deque<int> q;
//     int i = 0, j = 0;
//     vector<int> res;
//     while (j < n)
//     {
//         while (!q.empty() && q.back() < arr[j])
//             q.pop_back();
//         q.push_back(arr[j]);
//         if (j - i + 1 < k)
//             j++;
//         else if (j - i + 1 == k)
//         {
//             res.push_back(q.front());
//             if (q.front() == arr[i])
//                 q.pop_front();
//             i++;
//             j++;
//         }
//     }
//     return res;
// }

// vector<int> maxSlidingWindow(vector<int> &nums, int k)
// {

//     vector<int> output;
//     int i = 0;
//     int j = 0;
//     list<int> l;
//     while (j < nums.size())
//     {
//         if (l.empty())
//         {
//             l.push_back(nums[j]);
//         }
//         else
//         {
//             while (!l.empty() && l.back() < nums[j])
//                 l.pop_back();
//             l.push_back(nums[j]);
//         }
//         if (j - i + 1 < k)
//             ++j;
//         else if (j - i + 1 == k)
//         {
//             output.push_back(l.front());
//             if (nums[i] == l.front())
//                 l.pop_front();
//             ++i;
//             ++j;
//         }
//     }
//     return output;
// }

// vector<int> maxSlidingWindow(vector<int> &nums, int k)
// {
//     list<int> li;
//     vector<int> ans;
//     int i = 0, j = 0;

//     while (j < nums.size())
//     {

//         while (li.size() > 0 && li.back() < nums[j])
//         {
//             li.pop_back();
//         }
//         li.push_back(nums[j]);

//         if (j - i + 1 < k)
//             j++;

//         else if (j - i + 1 == k)
//         {
//             ans.push_back(li.front());

//             if (nums[i] == li.front())
//             {
//                 li.pop_front();
//             }
//             i++;
//             j++;
//         }
//     }
//     return ans;
// }

// vector<int> Solution::slidingMaximum(const vector<int> &arr, int k)
// {
//     vector<int> v;
//     int n = arr.size();
//     deque<int> q;
//     int i = 0, j = 0;
//     // 3 -1  -3
//     if (n == 1 && k == 1)
//     {
//         v.push_back(arr[0]);
//         return v;
//     }
//     if (k > n)
//     {
//         v.push_back(*max_element(arr.begin(), arr.end()));
//         return v;
//     }
//     while (j < n)
//     {
//         if (q.empty())
//         {
//             q.push_back(arr[j]);
//         }
//         else
//         {
//             while (q.back() < arr[j] && !q.empty())
//             {
//                 q.pop_back();
//             }
//             q.push_back(arr[j]);
//         }

//         if (j - i + 1 < k)
//         {
//             j++;
//         }
//         else if (j - i + 1 == k)
//         {
//             v.push_back(q.front());
//             if (arr[i] == q.front())
//             {
//                 q.pop_front();
//             }
//             i++;
//             j++;
//         }
//     }
//     return v;
// }

    // vector<int> solve(vector<int> &arr, int n, int k)
    // {
    //     int i = 0, j = 0;
    //     list<int> l;
    //     vector<int> ans;
    //     while (j < n)
    //     {
    //         while(l.size()>0 && l.back() < arr[j]){
    //             l.pop_back();
    //         }
    //         l.push_back(arr[j]);
    //         if (j - i + 1 < k)
    //         {
    //             j++;
    //         }
    //         else if (j - i + 1 == k)
    //         {
    //             ans.push_back(l.front());
    //             if(l.front() == arr[i]){
    //                 l.pop_front();
    //             }
    //             i++;
    //             j++;
    //         }
    //         if(k > n){
    //             ans.push_back(*max_element(arr.begin(), arr.end()));
    //             return ans;
    //         }
    //     }
    //     return ans;
    // }

    // int main()
    // {
    //     int n, k;
    //     cin >> n >> k;
    //     vector<int> arr;
    //     for (int i = 0; i < n; i++)
    //     {
    //         int x;
    //         cin >> x;
    //         arr.push_back(x);
    //     }

    //     vector<int> res = solve(arr, n, k);
    //     for (int i = 0; i < n; i++)
    //     {
    //         cout << res[i] << " ";
    //     }

    //     return 0;
    // }

    // 7 code above

    // code 1: using list o/p vector
    // code 2: using deque o/p vector 
    // code 3: using queue o/p vector
    // code 4: using vector o/p vector
    // code 5: using map o/p vector
    // code 6: using multiset o/p vector
    // code 7: using priority queue o/p vector



    // code 1
    // vector<int> maxSlidingWindow(vector<int> &nums, int k)
    // {
    //     list<int> li;
    //     vector<int> ans;
    //     int i = 0, j = 0;

    //     while (j < nums.size())
    //     {

    //         while (li.size() > 0 && li.back() < nums[j])
    //         {
    //             li.pop_back();
    //         }
    //         li.push_back(nums[j]);

    //         if (j - i + 1 < k)
    //             j++;

    //         else if (j - i + 1 == k)
    //         {
    //             ans.push_back(li.front());

    //             if (nums[i] == li.front())
    //             {
    //                 li.pop_front();
    //             }
    //             i++;
    //             j++;
    //         }
    //     }
    //     return ans;
    // }

    // code 2
    // vector<int> maxSlidingWindow(vector<int> &A, int B)
    // {
    //     vector<int> ans;
    //     if (A.size() < B)
    //     {
    //         ans.push_back(*max_element(A.begin(), A.end()));
    //         return ans;
    //     }
    //     deque<int> Q;
    //     int i = 0, j = 0;
    //     while (j < A.size())
    //     {
    //         while (!Q.empty() && Q.back() < A[j])
    //         {
    //             Q.pop_back();
    //         }
    //         Q.push_back(A[j]);
    //         if (j - i + 1 < B)
    //         {
    //             j++;
    //         }

    //         else if (j - i + 1 == B)
    //         {
    //             ans.push_back(Q.front());
    //             if (A[i] == Q.front())
    //             {
    //                 Q.pop_front();
    //             }
    //             i++;
    //             j++;
    //         }
    //     }
    //     return ans;
    // }

    // code 3
    // Maximum of all Subarray of size k
    // #include <bits/stdc++.h>
    // using namespace std;
    // vector<int> MaxAllSubarr(int *arr, int n, int k)
    // {
    //     vector<int> ans;
    //     int i = 0, j = 0;
    //     queue<int> pq;
    //     while (j < n)
    //     {
    //         // cal
    //         if (pq.empty())
    //         {
    //             pq.push(arr[j]);
    //         }
    //         else
    //         {
    //             while (!pq.empty() && pq.front() < arr[j])
    //             {
    //                 pq.pop();
    //                 pq.push(arr[j]);
    //             }
    //         }
    //         if (j - i + 1 < k)
    //         {
    //             j++;
    //         }
    //         else if (j - i + 1 == k)
    //         {
    //             // cal
    //             ans.push_back(pq.front());
    //             if (arr[i] == pq.front())
    //             {
    //                 pq.pop();
    //             }
    //             i++;
    //             j++;
    //         }
    //     }
    //     return ans;
    // }
    // int main()
    // {
    //     int n, k;
    //     cin >> n >> k;
    //     int *arr = new int[n];
    //     for (int i = 0; i < n; i++)
    //     {
    //         cin >> arr[i];
    //     }
    //     vector<int> ans = MaxAllSubarr(arr, n, k);
    //     for (int i = 0; i < ans.size(); i++)
    //     {
    //         cout << ans.at(i) << " ";
    //     }
    //     delete[] arr;
    //     return 0;
    // }

    // code 4 -
//     TestCase - Easy  Failed
// Your submission failed for the following input
// A : [ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 ]
// B : 1

// The expected return value: 
// 10 9 8 7 6 5 4 3 2 1 
// Your function returned the following: 
// 10 10 10 10 10 10 10 10 10 10 
    // #include <bits/stdc++.h>
    //     using namespace std;

    // int main()
    // {

    //     int len, window, max1 = INT_MIN, max2 = INT_MIN, input, i = 0, j = 0;
    //     cin >> len;
    //     vector<int> v, ans;
    //     for (int i = 0; i < len; i++)
    //     {
    //         cin >> input;
    //         v.push_back(input);
    //     }
    //     cin >> window;
    //     if (window > len)
    //     {
    //         ans.push_back(*max_element(v.begin(), v.end()));
    //     }
    //     else
    //         while (j < len)
    //         {

    //             max1 = max(max1, v[j]);
    //             max2 = min(max1, v[j]);

    //             if (j - i + 1 < window)
    //                 j++;
    //             else
    //             {
    //                 ans.push_back(max1);
    //                 if (v[i] == max1)
    //              // resetting max1 with minimum value
    //                     max1 = max2;
    //                 ++i;
    //                 ++j;
    //             }
    //         }

    //     for (auto x : ans)
    //         cout << x << " ";

    //     return 0;
    // }

// code 5
// vector<int> Solution::slidingMaximum(const vector<int> &A, int B)
// {

//     vector<int> res;

//     if (B == 0)
//         return res;

//     map<int, int> m;

//     int n = A.size();

//     int maxi = INT_MIN;

//     for (int i = 0; i < B; i++)
//     {

//         m[A[i]]++;

//         maxi = max(maxi, A[i]);
//     }

//     res.push_back(maxi);

//     for (int i = 1; i <= n - B; i++)
//     {

//         m[A[i - 1]]--;

//         if (m[A[i - 1]] == 0)
//         {

//             m.erase(A[i - 1]);
//         }

//         m[A[B + i - 1]]++;

//         auto it = m.rbegin();

//         res.push_back(it->first);
//     }

//     return res;
// }
// It’s actually O(N *log(B))

// code 6
// vector<int> Solution::slidingMaximum(const vector<int> &A, int B)
// {
//     multiset<int> s;
//     vector<int> v;
//     int i = 0, j = 0;
//     int n = A.size();
//     while (j < n)
//     {
//         s.insert(A[j]);
//         if (j - i + 1 < B)
//         {
//             j++;
//         }
//         else if (j - i + 1 == B)
//         {
//             auto ele = --s.end();
//             v.push_back(*ele);
//             auto it = s.find(A[i]);
//             if (it != s.end())
//             {
//                 s.erase(it);
//             }
//             i++;
//             j++;
//         }
//     }
//     return v;
// }

// code 7
// vector<int> Solution::slidingMaximum(const vector<int> &A, int B)
// {
//     priority_queue<pair<int, int>> p;
//     int n = A.size();
//     int i = 0;
//     for (i = 0; i < B; i++)
//     {
//         p.push({A[i], i + 1});
//     }
//     vector<int> ans;
//     ans.push_back(p.top().first);
//     int x = 1;
//     while (i < n)
//     {
//         p.push({A[i], i + 1});
//         while ((p.top()).second - x <= 0)
//         {
//             p.pop();
//         }
//         ans.push_back((p.top()).first);
//         i++;
//         x++;
//     }
//     return ans;
// }

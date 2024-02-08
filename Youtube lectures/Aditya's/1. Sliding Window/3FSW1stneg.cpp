//Find the 1st -ve no. in each window of the array - 6 combo with ds

// code 2, 7 - bit different then regular

// code 1: vector<long long> with deque<long long> + i/p-long long int array; o/p-vector
// if (A[start] < 0)
//    ans.pop_front();
// code 2: vector<int> with queue<int> + i/p-int vector; o/p-vector -index k through logic kre h - with index
// code 3: vector<long long> with queue<long long> + i/p-long long int array; o/p-vector
// if (q.empty())
//                 ans.push_back(0);
//             else
//             {
//                 ans.push_back(q.front());
//                 if (q.front() == A[i])
//                     q.pop();
//             }
// code 4: vector<long long> with deque<long long> + i/p-long long int array; o/p-vector
// if (!list.empty())
//                 ans.push_back(list.front());
//             else
//                 ans.push_back(0);
//             if (A[i] < 0)
//                 list.pop_front();
//             i++;
// code 5: vector<int> with queue<int> + i/p-int vector; o/p-vector
// if (q.empty())
//             {
//                 cout << 0 << " ";
//                 i++;
//             }
//             else
//             {
//                 cout << q.front() << " ";
//                 if (vec[i] == q.front())
//                     q.pop();
//                 i++;
//             }
// code 6: #define ll long long vector<ll> with queue<ll> + i/p-long long int array; o/p-vector
// if (q.size() == 0)
//                 sol.push_back(0);
//             else
//             {
//                 sol.push_back(q.front());
//                 if (A[i] == q.front())
//                     q.pop();
//             }
// code 7: vector<int> with vector<int> + i/p-int vector; o/p-vector - different pttrn over all
// bool l = true;
//             while (!neg.empty() && p < neg.size())
//             {
//                 if (arr[neg[p]] < 0 && neg[p] >= i)
//                 {
//                     ans.push_back(arr[neg[p]]);
//                     break;
//                 }
//                 else if (neg[p] < i)
//                     p++;
//             }
//             if (neg.empty() || p >= neg.size())
//                 ans.push_back(0);
//             ++i;
// code 8: vector<int> with list<int> + int main - i/p-int array; o/p-vector(working)
// code 9: vector<int> with list<int> + int main - i/p-int vector; o/p-vector(Not working)

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int arr[], int n, int k){
    int i=0, j=0;
    list<int> l;
    vector<int> v;
    while(j<n){
        if(arr[j] < 0){
            l.push_back(arr[j]);
        }
        if(j-i+1 < k){
            j++;
        }
        else if(j-i+1 == k){
            if(l.size() == 0){
                v.push_back(0);
            }
            else{
                v.push_back(l.front());
                if(arr[i] == l.front()){
                    l.pop_front();
                }
                i++;
                j++;
            }
        }
    }

    return v;
}

// code 1
// vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
// {
//     int start = 0, end = 0;
//     deque<long long> ans;
//     vector<long long> res;
//     while (end < N)
//     {
//         if (A[end] < 0)
//         {
//             ans.push_back(A[end]);
//         }
//         if (end - start + 1 < K)
//         {
//             end++;
//         }
//         else if (end - start + 1 == K)
//         {
//             if (ans.size() == 0)
//             {
//                 res.push_back(0);
//             }
//             else
//             {
//                 res.push_back(ans.front());
//                 if (A[start] < 0)
//                     ans.pop_front();
//             }
//             start++;
//             end++;
//         }
//     }
//     return res;
// }

// code 2
// vector<int> firstNegative(vector<int> arr, int n, int k)
// {

//     queue<int> q;
//     vector<int> ans;
//     int i = 0, j = 0;
//     while (j < n)
//     {
//         if (arr[j] < 0)
//             q.push(j);
//         if (j - i + 1 < k)
//             j++;
//         else if (j - i + 1 == k)
//         {
//             if (q.empty())
//                 ans.push_back(0);
//             else
//             {
//                 ans.push_back(arr[q.front()]);
//                 if (i == q.front())
//                     q.pop();
//             }
//             i++;
//             j++;
//         }
//     }
//     return ans;
// }

// code 3
// vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
// {
//     queue<long long> q;
//     vector<long long> ans;
//     long long i = 0, j = 0;

//     while (j < N)
//     {
//         if (A[j] < 0)
//             q.push(A[j]);
//         if (j - i + 1 < K)
//         {
//             j++;
//         }
//         else
//         {
//             if (q.empty())
//                 ans.push_back(0);
//             else
//             {
//                 ans.push_back(q.front());
//                 if (q.front() == A[i])
//                     q.pop();
//             }
//             i++;
//             j++;
//         }
//     }
//     return ans;
// }

// code 4
// vector<long long> printFirstNegativeInteger(long long int A[],
//                                             long long int N, long long int K)
// {
//     vector<long long> ans;
//     deque<long long> list;
//     long long i = 0, j = 0;
//     while (j < N)
//     {
//         if (A[j] < 0)
//             list.push_back(A[j]);
//         if (j - i + 1 < K)
//         {
//             j++;
//             continue;
//         }
//         else if (j - i + 1 == K)
//         {
//             if (!list.empty())
//                 ans.push_back(list.front());
//             else
//                 ans.push_back(0);
//             if (A[i] < 0)
//                 list.pop_front();
//             i++;
//         }
//         j++;
//     }
//     return ans;
// }

// code 5
// void negetive(vector<int> &vec, int k)
// {
//     int i = 0;
//     int j = 0;
//     queue<int> q;
//     while (j < vec.size())
//     {
//         if (vec[j] < 0)
//             q.push(vec[j]);
//         if (j - i + 1 == k)
//         {
//             if (q.empty())
//             {
//                 cout << 0 << " ";
//                 i++;
//             }
//             else
//             {
//                 cout << q.front() << " ";
//                 if (vec[i] == q.front())
//                     q.pop();
//                 i++;
//             }
//         }
//         j++;
//     }
// }

// code 6
// #define ll long long
//     vector<long long>
//     printFirstNegativeInteger(long long int A[],
//                               long long int N, long long int k)
// {

//     queue<ll> q;
//     ll i = 0, j = 0;
//     vector<ll> sol;
//     while (j <= N - 1)
//     {
//         if (A[j] < 0)
//             q.push(A[j]);
//         if (j + 1 >= k)
//         {
//             if (q.size() == 0)
//                 sol.push_back(0);
//             else
//             {
//                 sol.push_back(q.front());
//                 if (A[i] == q.front())
//                     q.pop();
//             }
//             i++;
//         }
//         j++;
//     }
//     return sol;
// }

//code 7
// vector<int> negative1stReturn(vector<int> arr, int k)
// {
//     int i = 0, j = 0, p = 0;
//     vector<int> neg{}, ans{};
//     while (j < arr.size())
//     {
//         if (arr[j] < 0)
//         {
//             neg.push_back(j);
//         }
//         if (j - i + 1 == k)
//         {
//             bool l = true;
//             while (!neg.empty() && p < neg.size())
//             {
//                 if (arr[neg[p]] < 0 && neg[p] >= i)
//                 {
//                     ans.push_back(arr[neg[p]]);
//                     break;
//                 }
//                 else if (neg[p] < i)
//                     p++;
//             }
//             if (neg.empty() || p >= neg.size())
//                 ans.push_back(0);
//             ++i;
//         }
//         j++;
//     }
//     return ans;
// }

// code 8
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> NegativeInteger(int *a, int n, int k)
// {
//     int i = 0, j = 0;
//     list<int> l;
//     vector<int> res;
//     while (j < n)
//     {
//         // Calculation
//         if (a[j] < 0)
//             l.push_back(a[j]);

//         if (j - i + 1 < k)
//             j++;

//         else if (j - i + 1 == k)
//         {
//             // Checking the edge Case.
//             if (l.size() == 0)
//                 res.push_back(0);
//             else
//             {
//                 res.push_back(l.front());

//                 if (a[i] == l.front())
//                 {
//                     l.pop_front();
//                 }
//             }
//             j++;
//             i++;
//         }
//     }
//     return res;
// }
int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int k;
        cin >> k;

        vector<int> res = solve(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    // }
    return 0;
}

// int main()
// {
//     int n;
//     cin>>n;

//     long long int arr[n];
//     for(int i=0; i<n; i++){
//         cin>>arr[i];
//     }

//     int k;
//     cin>>k;

//     vector<int> res = NegativeInteger(arr, n, k);
//     for(int i=0; i<res.size(); i++){
//         cout << res[i]<< " ";
//     }

//     return 0;
// }

// vector<long long> printFirstNegativeInteger(long long int A[],
//                                             long long int N, long long int K)
// {
//     // METHOD 1
//     vector<long long> res;
//     deque<long long> store;

//     long long i = 0, j = 0;

//     while (j < N)
//     {
//         if (A[j] < 0)
//         {
//             store.push_back(A[j]);
//         }
//         if (j - i + 1 < K)
//         {
//             j++;
//             continue;
//         }
//         else if (j - i + 1 == K)
//         {
//             if (store.size() == 0)
//             {
//                 res.push_back(0);
//             }
//             else
//             {
//                 res.push_back(store.front());
//                 if (A[i] == store.front())
//                 {
//                     store.pop_front();
//                 }
//                 // if(A[i] < 0){
//                 //     store.pop_front();
//                 // }
//             }
//             i++;
//             j++;
//         }
//     }
//     return res;

    // METHOD 2
    // queue<long long> q;
    // vector<long long> ans;
    // int i = 0, j = 0;
    // while (j < N)
    // {
    //     if (A[j] < 0)
    //         q.push(j);
    //     if (j - i + 1 < K)
    //         j++;
    //     else if (j - i + 1 == K)
    //     {
    //         if (q.empty())
    //             ans.push_back(0);
    //         else
    //         {
    //             ans.push_back(A[q.front()]);
    //             if (i == q.front())
    //                 q.pop();
    //         }
    //         i++;
    //         j++;
    //     }
    // }
    // return ans;

    // METHOD 3
    // int i = 0, j = 0;
    // list<long long> l;
    // vector<long long> res;
    // while (j < N)
    // {
    //     // Calculation
    //     if (A[j] < 0)
    //         l.push_back(A[j]);

    //     if (j - i + 1 < K)
    //         j++;

    //     else if (j - i + 1 == K)
    //     {
    //         // Checking the edge Case.
    //         if (l.size() == 0)
    //             res.push_back(0);
    //         else
    //         {
    //             res.push_back(l.front());

    //             if (A[i] == l.front())
    //             {
    //                 l.pop_front();
    //             }
    //         }
    //         j++;
    //         i++;
    //     }
    // }
    // return res;
// }
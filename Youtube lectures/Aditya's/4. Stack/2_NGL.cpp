#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    // int arr[] = {1, 3, 2, 4};
    // NGL = {-1, -1, 3, -1}; = start from right(originally) - left(code)
    // NSL = {-1, 1, 1, 2}; = start from right(originally) - left(code)
    int arr[] = {3, 5, 4, 2, 2, 5, 5, 4, 2, 5};
    // NSL = {-1, 3, 3, -1, -1, 2, 2, 2, -1, 2}; = start from left(originally) - right(code)
    int n = sizeof(arr) / sizeof(arr[0]);

    // vector<int> v;
    // stack<int> s;
    // for (int i = 0; i < n; i++)
    // {
    //     // stack k size zero hojae tw
    //     if (s.size() == 0)
    //     {
    //         v.push_back(-1);
    //     }
    //     // Agr stack k top grater h ith element se
    //     else if (s.size() > 0 && s.top() > arr[i])
    //     {
    //         v.push_back(s.top());
    //     }
    //     // Agr element bada nhi h
    //     else if (s.size() > 0 && s.top() <= arr[i])
    //     {
    //         while (s.size() > 0 && s.top() <= arr[i])
    //         {
    //             s.pop();
    //         }
    //         if (s.size() == 0)
    //         {
    //             v.push_back(-1);
    //         }
    //         else
    //         {
    //             v.push_back(s.top());
    //         }
    //     }
    //     // current element ko process krke stack m push krdo
    //     s.push(arr[i]);
    // }

    // ALgo 2: NGL while pushing element into stack
    // vector<int> v(n, -1);
    // stack<int> s;
    // for(int i=0; i<n; i++){
    //     while(!s.empty() && s.top()<=arr[i]){
    //         s.pop();
    //     }
    //     if(!s.empty()){
    //         v[i] = s.top();
    //     }
    //     s.push(arr[i]);
    // }

    // ALgo 3: NGR while pushing index into stack
    // vector<int> v(n, -1);
    // stack<int> s;
    // for (int i = n-1; i>=0; i--)
    // {
    //     while (!s.empty() && arr[s.top()] <= arr[i])
    //     {
    //         v[s.top()] = arr[i];
    //         s.pop();
    //     }
    //     s.push(i);
    // }

    for (int i = 0; i < n; i++)
    { 
        cout<<v[i]<<" ";
    }

        return 0;
    }
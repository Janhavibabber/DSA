#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> v;
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        // stack k size zero hojae tw
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        // Agr stack k top grater h ith element se
        else if (s.size() > 0 && s.top() < arr[i])
        {
            v.push_back(s.top());
        }
        // Agr element bada nhi h
        else if (s.size() > 0 && s.top() >= arr[i])
        {
            while (s.size() > 0 && s.top() >= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
        }
        // current element ko process krke stack m push krdo
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());

    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}
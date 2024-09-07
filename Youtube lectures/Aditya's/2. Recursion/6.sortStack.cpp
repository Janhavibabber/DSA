#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int temp)
{
    // s.top() <= temp: sort in asc order - print in desc order
    // s.top() >= temp: sort in desc order - print in asc order
    if (s.size() == 0 || s.top() <= temp)
    {
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s, temp);
    s.push(val);
    return;
}

void Sort(stack<int> &s)
{
    if (s.size() == 1)
    {
        return;
    }
    // separating last element for sorting
    int temp = s.top();
    s.pop();
    // hypothesis
    Sort(s);
    // induction step
    insert(s, temp);
}

int main()
{
    stack<int> s;
    s.push(5); // The values pushed in the stack should be of the same data which is written during declaration of stack
    s.push(0);
    s.push(1);
    s.push(2);
    Sort(s);

    while (!s.empty()) {
        cout << s.top() <<" ";
        s.pop();
    }

    return 0;
}
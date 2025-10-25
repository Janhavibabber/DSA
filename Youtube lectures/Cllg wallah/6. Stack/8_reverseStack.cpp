#include <iostream>
#include <stack>
using namespace std;

// App1: Iterative = take 2 stacks to reverse the orginal stack. TC->O(n); SC->O(n)
/*void reverseStack(stack<int> &s)
{
    stack<int> t1, t2; // temporary stack

    while (!s.empty())
    {
        int curr = s.top();
        s.pop();
        t1.push(curr);
    }

    while (!t1.empty())
    {
        int curr = t1.top();
        t1.pop();
        t2.push(curr);
    }

    while (!t2.empty())
    {
        int curr = t2.top();
        t2.pop();
        s.push(curr);
    }
}*/

// App2: Recursive = take temp or call stack then insert at bottom to original stack. TC->O(n^2); SC->O(n)
/*void insertAtBottom(stack<int> &s, int x)
{
    stack<int> temp; // temporary stack

    while (!s.empty())
    {
        int curr = s.top();
        s.pop();
        temp.push(curr);
    }

    s.push(x);

    while (!temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        s.push(curr);
    }
}

void recReverseStack(stack<int> &s)
{
    // using call stack of recursion
    if (s.empty())
    {
        return;
    }

    int curr = s.top();
    s.pop();

    recReverseStack(s);
    insertAtBottom(s, curr);
}*/

void reverse(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    cout << s.top() << " ";
    s.pop();
    reverse(s);
}

int main()
{
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(7);
    s.push(6);
    reverse(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
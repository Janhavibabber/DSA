#include <iostream>
#include <stack>
using namespace std;

void insertAtAnyPos(stack<int> &s, int x, int pos)
{
    stack<int> temp; // temporary stack
    int n = s.size();
    int ele_pop = n-pos; // number of elements to pop from the stack

    int i=0;
    while(i<ele_pop && !s.empty())
    {
        int curr = s.top();
        s.pop();
        temp.push(curr);
        i++;
    }

    s.push(x);

    while (!temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        s.push(curr);
    }
}

/*void recInsertAtBottom(stack<int> &s, int x)
{
    // using call stack of recursion
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int curr = s.top();
    s.pop();

    recInsertAtBottom(s, x);

    s.push(curr);
}*/

int main()
{
    // stack is using 0 based indexing
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    insertAtAnyPos(s, 60, 2);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
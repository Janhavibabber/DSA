#include <iostream>
#include <stack>
using namespace std;

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
}*/

void recInsertAtBottom(stack<int> &s, int x)
{
    // using call stack of recursion
    if(s.empty()){
        s.push(x);
        return;
    }
    
    int curr = s.top();
    s.pop();
    
    recInsertAtBottom(s, x);

    s.push(curr);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    recInsertAtBottom(s, 100);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }


    return 0;
}
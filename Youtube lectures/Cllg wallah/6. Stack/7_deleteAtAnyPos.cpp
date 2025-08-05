#include <iostream>
#include <stack>
using namespace std;

void deleteAtAnyPos(stack<int> &s, int pos){
    stack<int> temp; // temporary stack
    int n = s.size();
    int ele_pop = n - pos-1; // number of elements to pop from the stack

    int i = 0;
    while (i < ele_pop && !s.empty())
    {
        int curr = s.top();
        s.pop();
        temp.push(curr);
        i++;
    }

    s.pop();

    while (!temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        s.push(curr);
    }
}

/*void recDeletetAtBottom(stack<int> &s)
{
    // using call stack of recursion
    if (s.size() == 1)
    {
        s.pop(); // remove the last element
        return;
    }

    int curr = s.top();
    s.pop();

    recDeletetAtBottom(s);

    s.push(curr);
}*/

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    deleteAtAnyPos(s, 2);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
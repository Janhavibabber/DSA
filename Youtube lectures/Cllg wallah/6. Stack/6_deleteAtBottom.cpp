#include<iostream>
#include<stack>
using namespace std;

/*void deleteAtBottom(stack<int> &s){
    stack<int> temp; //temporary stack

    while(s.size() != 1){
        int curr = s.top();
        s.pop();
        temp.push(curr);
    }

    s.pop();

    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        s.push(curr);
    }
}*/

void recDeletetAtBottom(stack<int> &s)
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
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    recDeletetAtBottom(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
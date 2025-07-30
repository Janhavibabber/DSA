#include<iostream>
#include<stack>
using namespace std;

// using extra temporary stack to store the values
/*stack<int> copyStack(stack<int> &ip){
    stack<int> temp;
    while(!ip.empty()){
        int curr = ip.top();
        ip.pop();
        temp.push(curr);
    }

    stack<int> res;
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        res.push(curr);
    }

    return res;
}*/

// using recursive call stack to store the values
stack<int> copyStack(stack<int> &ip)
{
    if(ip.empty())
        return stack<int>();

    int curr = ip.top();
    ip.pop();
    stack<int> temp = copyStack(ip);    
    temp.push(curr);
    return temp;
}

int main()
{
    stack<int> ip;
    ip.push(1);
    ip.push(2); 
    ip.push(3);
    ip.push(4);
    stack<int> op = copyStack(ip);

    while(!op.empty()){
        cout<<op.top()<<" ";
        op.pop();
    }

    return 0;
}
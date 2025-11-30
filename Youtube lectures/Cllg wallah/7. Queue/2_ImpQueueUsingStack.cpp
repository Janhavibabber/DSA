#include<bits/stdc++.h>
using namespace std;

// App1: Using PUSH effecient approach
class Queue{
    stack<int> st;
    public:
    Queue() {}

    void push(int x){
        this->st.push(x);     
    }

    int pop(){
        if(isEmpty()){
            return -1;
        }
        stack<int> tmp;
        while(this->st.size()>1){
            tmp.push(this->st.top());
            this->st.pop();
        }
        // store the last ele
        int res = this->st.top();

        while(!tmp.empty()){
            this->st.push(tmp.top());
            tmp.pop();
        }
        return res;
    }

    bool isEmpty(){
        return this->st.empty();
    }
};

int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout<<q.pop()<<endl;
    q.push(50);
    cout<<q.pop()<<endl;
    
    return 0;
}
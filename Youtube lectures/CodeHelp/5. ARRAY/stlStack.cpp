#include<iostream>
#include<stack>
using namespace std;

int main()
{
    // declaring stack
    stack<int> st;
    // inserting elements in stack
    st.push(1);
    st.push(4);
    st.push(2);
    st.push(3);
    st.emplace(3);

    // peeking the top element
    cout << st.top() << endl;

    st.pop();
    cout<<st.size()<<endl;
    cout << st.empty() << endl;
    cout << st.top() << endl;

    // for (int i : st)
    // {
    //     cout<<i;
    // }
    

    // stack<int> st1, st2;
    // st1.swap(st2);

    return 0;
}
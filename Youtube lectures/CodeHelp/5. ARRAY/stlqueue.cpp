#include<bits/stdc++.h>
using namespace std;

void show(queue<int> q){
    queue<int> temp;
    while(!temp.empty()){
        cout<<temp.front()<<" ";
        temp.pop();
    }
}

int main(){
    //1. declare a queue
    queue<int> q;

    //2. insert
    q.push(3);
    q.push(5);
    q.push(7);
    q.push(9);

    cout<<"Front of queue is: "<<q.front()<<endl;
    cout<<"our queue is: "<<endl;
    show(q);

    //use to delete element from front
    q.pop();

    cout<<"our queue after pop is: "<<endl;
    show(q);

    cout<<"size of queue is: "<<q.size()<<endl;
    if(q.empty()){
        cout<<"Queue is empty"<< endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }


    return 0;
}
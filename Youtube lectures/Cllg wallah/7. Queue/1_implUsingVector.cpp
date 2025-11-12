#include<bits/stdc++.h>
using namespace std;

class Queue{
    int front;
    int rear;
    vector<int> v;

public:
    Queue(){
        this->front = -1;
        this->rear = -1;
    }

    bool isEmpty(){
        return this->front == -1;
    }

    int getFront(){
        if(this->front == -1){
            return -1;
        }
        return v[this->front];
    }

    void enqueue(int data){
        this->v.push_back(data);
        this->rear++;
        if(this->rear == 0){
            this->front = 0;
        }
    }

    int dequeue(){
        if(this->front == this->rear){
            this->front = -1;
            this->rear = -1;
            this->v.clear();
            return -1;
        }

        int ans = v[this->front];
        this->front++;
        return ans;
    }


};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout<<q.getFront()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.getFront()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    q.enqueue(200);
    if(q.isEmpty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }
    

    
    return 0;
}
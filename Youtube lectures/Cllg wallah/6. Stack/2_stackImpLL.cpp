#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class Stack{
    Node* head;
    int capacity;
    int currSize;
    public:
        Stack(int c){
            this->capacity = c;
            this->currSize = 0;
            head = NULL;
        }

    bool isEmpty(){
        return this->head == NULL;
    }

    bool isFull(){
        return this->currSize == this->capacity;
    }

    void push(int data){
        if(this->isFull()){
            cout<<"Overflow\n";
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        this->currSize++;
    }

    int pop(){
        if(isEmpty()){
            cout<<"Underflow\n";
            return INT32_MIN;
        }

        Node* new_head = this->head->next;
        this->head->next = NULL;
        Node* NodeToBeRemoved = this->head;
        int poppedData = NodeToBeRemoved->data;
        delete NodeToBeRemoved;
        this->head = new_head;
        return poppedData;
    }

    int top(){
        if (isEmpty())
        {
            cout << "Underflow\n";
            return INT32_MIN;
        }
        return this->head->data;    
    }

    int size(){
        return this->currSize;
    }
};


int main()
{
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.top() << endl;
    st.push(4);
    st.push(5);
    cout << st.top() << endl;
    st.push(8);
    st.pop();
    st.pop();
    cout << st.top() << endl;
    return 0;
}
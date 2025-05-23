#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
    }
};

class LinkedList{
public:
    Node* head;

    LinkedList(){
        head = NULL;
    }

    void insertAtTail(int val){
        Node* new_node = new Node(val);
        if(head == NULL){
            head = new_node;
            return;
        }

        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

// App1: to detect loop using map DS
bool detectLoop(Node* head){
    if(head == NULL){
        return false;
    }

    Node* temp = head;
    unordered_map<Node*, bool> visited;

    while(temp!=NULL){
        if(visited[temp] == true){
            return true;
        }
        visited[temp] =true;
        temp = temp->next;
    }
    return false;
}

// App2: to detect loop using floyd's algo
bool detectLoopFloyd(Node* head){
    if(head == NULL){
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }
    return false;
}

int main()
{
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2); 
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);

    // Creating a loop for testing
    ll.head->next->next->next->next = ll.head->next;

    // ll.display();

    if(detectLoopFloyd(ll.head)){
        cout<<"Loop detected"<<endl;
    }
    else{
        cout<<"No loop detected"<<endl;
    }

    return 0;
}
#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head = NULL;
    }

    void insertAtTail(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

void deleteVal(Node* &head, int val){
    if(head == NULL) return;
    if(head->val == val){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* curr = head;
    while(curr!=NULL && curr->next!=NULL){
        if(curr->next->val == val){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        curr = curr->next;
    } 
}

int main()
{
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.display();

    deleteVal(ll.head, 1);
    ll.display();

    return 0;
}
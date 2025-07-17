#include<iostream>
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
        head=NULL;
    }

    // insert node at tail
    void inserAtTail(int val){
        Node* new_node = new Node(val);
        if(head == NULL){
            head = new_node;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }

    // display linked list
    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

void deleteAlternateNode(Node* &head){
    Node* curr_node = head;
    while(curr_node!=NULL && curr_node->next!=NULL){
        Node* temp = curr_node->next;
        curr_node->next = curr_node->next->next;
        free(temp);
        curr_node = curr_node->next;
    }
}

int main()
{
    LinkedList ll;
    ll.inserAtTail(1);
    ll.inserAtTail(2);
    ll.inserAtTail(3);  
    ll.inserAtTail(4);
    ll.inserAtTail(5);
    ll.display();
    deleteAlternateNode(ll.head);
    cout<<"After deleting alternate nodes: ";
    ll.display();

    
    return 0;
}
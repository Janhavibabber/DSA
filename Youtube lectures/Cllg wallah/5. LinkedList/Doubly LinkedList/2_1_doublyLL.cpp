#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* prev;
    Node* next;

    Node(int data){
        val = data;
        prev=NULL;
        next=NULL;
    }
};

class DoublyLL{
    public:
    Node* head;
    Node* tail;

    DoublyLL(){
        head=NULL;
        tail=NULL;
    }

    void displayHeadToTail(){
        Node* temp = head;
        while(temp!=NULL){
            cout << temp->val << "<->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void displayTailToHead()
    {
        Node *temp = tail;
        while (temp != NULL)
        {
            cout << temp->val <<"<->";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    void insertAtHead(int data){
        Node* new_node = new Node(data);
        // first node
        if(head == NULL){
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return;
    }

    void insertAtTail(int data){

        Node* new_node = new Node(data);
        //  first Node
        if(tail == NULL){
            head = new_node;
            tail=new_node;
            return;
        }
        
        tail->next=new_node;
        new_node->prev = tail;
        tail=new_node;
        return;
    }

    void insertAtPosition(int data, int k){
        if(k==1){
            insertAtHead(data);
            return; 
        }

        Node* temp = head;
        int pos =1;
        while(pos<k-1){
            temp=temp->next;
            pos++;
        }

        // insert at last
        if(temp->next == NULL){
            insertAtTail(data);
            return;
        }

        // temp pointing to (k-1)th position
        Node* new_node = new Node(data);
        // set next ptr
        new_node->next = temp->next;
        temp->next = new_node;
        // set prev pointer
        new_node->prev = temp;
        new_node->next->prev = new_node;
        return;
    }

    void deleteAtHead(){
        if(head == NULL){
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        Node* temp = head;
        head=head->next;
        if(head!=NULL){
            head->prev = NULL;
        }
        else{
            tail = NULL;
        }
        free(temp);
        return;
    }

    void deleteAtTail(){
        if(head == NULL){
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        Node* temp = tail;
        tail=tail->prev;
        if(tail == NULL){
            head = NULL;
        }
        else{
            tail->next = NULL;
        }
        free(temp);
        return;
    }

    void deleteAtPosition(int k){
        if(k==1){
            deleteAtHead();
            return;
        }

        Node* temp = head;
        int pos = 1;
        while(pos<k && temp!=NULL){
            temp=temp->next;
            pos++;
        }

        // if k is greater than the length of the list
        if(temp == NULL){
            cout << "Position out of bounds." << endl;
            return;
        }

        // if k is equal to the length of the list
        if(temp->next == NULL){
            deleteAtTail();
            return;
        }

        // deleting at kth position
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }

};

int main()
{
    // 1. Implementation of doubly LL
    Node* new_node = new Node(3);
    cout<< "Node created with value: " << new_node->val << endl;

    DoublyLL dll;
    dll.head = new_node;
    dll.tail = new_node;
    cout<< "Node value: " << dll.head->val << endl;

    // 2. Insert at head
    dll.insertAtHead(2);
    dll.insertAtHead(1);

    // 3. Display head to tail
    cout << "Doubly Linked List after inserting at head (head to tail): " << endl;
    dll.displayHeadToTail();
    // 4. Display tail to head
    cout << "Doubly Linked List after inserting at head (tail to head): " << endl;
    dll.displayTailToHead();

    // 5. Insert at tail
    cout << "Doubly Linked List after inserting at tail (head to tail): " << endl;
    dll.insertAtTail(4);
    dll.displayHeadToTail();
    dll.insertAtTail(5);
    dll.displayHeadToTail();
    // 6. Insert at kth position
    dll.insertAtPosition(6, 3);
    cout << "Doubly Linked List after inserting at position 3 (head to tail): " << endl;    
    dll.displayHeadToTail();

    // 7. Delete at first position
    dll.deleteAtHead();
    cout << "Doubly Linked List after deleting at head (head to tail): " << endl;   
    dll.displayHeadToTail();
    // 8. Delete at last position
    dll.deleteAtTail(); 
    cout << "Doubly Linked List after deleting at tail (head to tail): " << endl;
    dll.displayHeadToTail();
    // 9. Delete at kth position
    dll.deleteAtPosition(2);
    cout << "Doubly Linked List after deleting at position 4 (head to tail): " << endl;
    dll.displayHeadToTail();

    return 0;
}
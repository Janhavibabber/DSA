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

class CircularLL{
    public: Node* head;
    CircularLL(){
        head = NULL;
    }

    void display(){
        Node* temp = head;
        do{
            cout << temp->val << "->";
            temp = temp->next;
        }while(temp!=head);
        cout << "NULL" << endl;
    }

    void insertAtHead(int d)
    {
        Node* newNode = new Node(d);
        if(head == NULL){
            head = newNode;
            newNode->next = head; // Point to itself
            return;
        }
        Node* tail = head;
        while(tail->next!=head){
            tail = tail->next;
        }

        // tail will point to last node
        tail->next = newNode;
        newNode->next = head;
        head=newNode;
    }

    void insertAtTail(int d)
    {
        Node *newNode = new Node(d);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head; // Point to itself
            return;
        }
        Node *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }

        // tail will point to last node
        tail->next = newNode;
        newNode->next = head;
    }

    void DeleteAtHead()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        Node *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }

        // tail will point to last node
        head = head->next;
        tail->next = head;
        free(temp);
    }

    void DeleteAtTail()
    {
        if (head == NULL)
        {
            return;
        }
        
        Node *tail = head;
        while (tail->next->next != head)
        {
            tail = tail->next;
        }

        // tail will point to second last node
        Node *temp = tail->next;
        tail->next = head;
        free(temp);
    }
};


int main()
{
    CircularLL cll;
    // 1. Insertion at the start of LL
    cll.insertAtHead(10);
    cll.insertAtHead(20);
    cll.display();
    // 2. Insertion at the end of LL
    cll.insertAtTail(30);
    cll.insertAtTail(40);
    cll.display();
    // 3. Insertion at a given position in LL
    
    // 5. Deletion of a node from the start of LL
    cll.DeleteAtHead();
    cll.display();
    // 6. Deletion of a node from the end of LL
    cll.DeleteAtTail();
    cll.display();
    // 7. Deletion of a node from a given position in LL

    return 0;
}
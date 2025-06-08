#include<iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;

    Node(int data)
    {
        val = data;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLL
{
public:
    Node *head;
    Node *tail;

    DoublyLL()
    {
        head = NULL;
        tail = NULL;
    }

    void displayHeadToTail()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void insertAtTail(int data)
    {

        Node *new_node = new Node(data);
        //  first Node
        if (tail == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        return;
    }
};

void deleteSameNeighbourNode(Node* &head, Node* &tail){
    if(head == NULL || head->next == NULL){
        return;
    }
    // second last node
    Node* curr = tail->prev;
    while(curr!=head){
        Node* prevptr = curr->prev;
        Node* nextptr = curr->next;
        if(prevptr->val == nextptr->val){
            prevptr->next = nextptr;
            nextptr->prev = prevptr;
            free(curr);
        }
        curr=prevptr;
    }
}

int main()
{
    DoublyLL dll;
    
    dll.insertAtTail(2);    
    dll.insertAtTail(1);    
    dll.insertAtTail(1);    
    dll.insertAtTail(2);
    dll.insertAtTail(1);
    dll.displayHeadToTail();

    deleteSameNeighbourNode(dll.head, dll.tail);
    dll.displayHeadToTail();


    return 0;
}
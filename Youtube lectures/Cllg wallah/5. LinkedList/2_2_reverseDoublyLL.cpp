#include <iostream>
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
            cout << temp->val << "<->";
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

void reverseDLL(Node* &head, Node* &tail){
    Node* curr=head;
    while(curr){
        Node* nextptr = curr;
        curr->next = curr->prev;
        curr->prev = nextptr;
        curr = nextptr;
    }

    // swap head and tail
    Node* newHead = tail;
    tail = head;
    head = newHead;
}

int main()
{
    DoublyLL dll;
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(3);
    dll.insertAtTail(4);
    dll.insertAtTail(5);
    cout << "Original Doubly Linked List (Head to Tail): " << endl;
    dll.displayHeadToTail();

    reverseDLL(dll.head, dll.tail);
    cout << "Reversed Doubly Linked List (Head to Tail): " << endl;
    dll.displayHeadToTail();

    return 0;
}
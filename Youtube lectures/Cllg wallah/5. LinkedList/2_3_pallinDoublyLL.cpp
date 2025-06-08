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

bool isPallin(Node* head, Node* tail){
    if(head == NULL || head->next == NULL){
        return true;
    }
    while(head!=tail && tail!=head->prev){
        if(head->val!=tail->val){
            return false;
        }
        head=head->next;
        tail=tail->prev;
    }
    return true;
}



int main()
{
    DoublyLL dll;
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(3);
    dll.insertAtTail(2);
    dll.insertAtTail(1);
    // cout << "Original Doubly Linked List (Head to Tail): " << endl;
    dll.displayHeadToTail();

    cout<<isPallin(dll.head, dll.tail);
    
    // cout << "Is the Doubly Linked List a palindrome? " << (isPallin(dll.head, dll.tail) ? "Yes" : "No") << endl;

    return 0;
}

#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }

    // insert node at tail
    void inserAtTail(int val)
    {
        Node *new_node = new Node(val);
        if (head == NULL)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    // display linked list
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

Node* reverseLLApp1(Node *&head)
{
    Node* prev = NULL;
    Node* curr = head;
    while(curr!=NULL){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr=next;
    }
    //  prev ptr pointing to the last node which is new head
    Node* new_head = prev;
    return new_head;
}

//  App2: Using recursion
Node* reverseLLApp2(Node *&head)
{
    if(head == NULL || head->next==NULL){
        return head;
    }
    Node* new_head = reverseLLApp2(head->next);
    head->next->next = head;
    // head must be pointing to the last node
    head->next = NULL;
    return new_head;
}

int main()
{
    LinkedList ll;
    ll.inserAtTail(1);
    ll.inserAtTail(2);
    ll.inserAtTail(3);
    ll.inserAtTail(4);
    ll.inserAtTail(5);
    ll.inserAtTail(6);
    ll.display();
    cout << "Reversed linked list: ";
    // ll.head=reverseLLApp1(ll.head);
    ll.head = reverseLLApp2(ll.head);
    ll.display();

    return 0;
}
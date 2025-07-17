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

Node* reorderLL(Node *&head)
{
    //  check if linked list has atleast 3 nodes
    if(head==NULL || head->next==NULL || head->next->next==NULL){
        return head;
    }

    // step 1: find the middle of the linked list
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    // step 2: reverse the second half of the linked list
    Node* prev = slow; // slow is pointing to middle element
    Node* curr = slow->next;
    slow->next = NULL; // break the linked list into two halves
    while(curr){
        Node* nextPtr = curr->next;
        curr->next = prev;
        prev=curr;
        curr=nextPtr;
    }

    // step 3: merge the two halves
    Node* ptr1 = head; // pointer for first half    
    Node* ptr2 = prev; // pointer for second half (reversed)
    // after reversing second half, there will be 1 node to which both halves will pointing
    while(ptr1!=ptr2){
        Node* temp = ptr1->next;
        ptr1->next=ptr2;
        ptr1=ptr2;
        ptr2=temp;
    }
    return head;
}

int main()
{
    LinkedList ll1;
    ll1.inserAtTail(1);
    ll1.inserAtTail(2);
    ll1.inserAtTail(3);
    ll1.inserAtTail(4);
    ll1.inserAtTail(5);
    ll1.inserAtTail(6);
    ll1.display();

    ll1.head = reorderLL(ll1.head);
    ll1.display();

    return 0;
}
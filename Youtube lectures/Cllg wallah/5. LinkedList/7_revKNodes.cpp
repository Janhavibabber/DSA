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

Node* revKNodes(Node *&head, int k)
{
    Node* prev = NULL;
    Node* curr = head;

    // Reverse first k nodes
    int count = 0;
    while(curr!=NULL && count<k){
        Node* next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }

    //  curr will give (K+1)th node
    if(curr!=NULL){
        Node* new_head = revKNodes(curr, k);
        head->next = new_head;
    }
    // prev will be the new head of the reversed list
    return prev;
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
    cout << "Print LL in kth reverse order: ";
    ll.head = revKNodes(ll.head, 2);
    ll.display();

    return 0;
}
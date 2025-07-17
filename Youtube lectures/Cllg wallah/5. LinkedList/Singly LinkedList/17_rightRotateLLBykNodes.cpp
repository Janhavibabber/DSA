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

Node* rotateByK(Node* &head, int k){
    int len=0;
    Node* tail = head;
    while(tail->next){
        len++;
        tail=tail->next;
    }
    len++; // to count the last node
    k = k % len; // to handle cases where k > len
    if(k==0)
        return head;

    // Link tail to head
    tail->next = head;

    // traverse till (n-k)th node
    Node* temp = head;
    for(int i=1; i<(len-k); i++){
        temp = temp->next;
    } 

    // temp pointing to (n-k)th node
    Node* newHead = temp->next; // new head will be (n-k+1)th node
    temp->next = NULL; // break the link to make it a circular linked list
    return newHead; // return the new head of the rotated linked list
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

    ll1.head = rotateByK(ll1.head, 3);
    ll1.display();

    return 0;
}
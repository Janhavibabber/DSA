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

Node* middleElement(Node* head){
    // floyd's algo
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    LinkedList ll1;
    ll1.inserAtTail(1);
    ll1.inserAtTail(2);
    ll1.inserAtTail(3);
    ll1.inserAtTail(4);
    ll1.inserAtTail(5);
    ll1.display();

    LinkedList ll2;
    ll2.inserAtTail(1);
    ll2.inserAtTail(2);
    ll2.inserAtTail(3);
    ll2.inserAtTail(4);
    ll2.inserAtTail(5);
    ll2.inserAtTail(6);
    ll2.display();

    cout << "Middle element of ll1(odd no. of nodes): " << middleElement(ll1.head)->val << endl;
    cout<<"Middle element of ll2(even no. of nodes): " << middleElement(ll2.head)->val << endl;

    return 0;
}
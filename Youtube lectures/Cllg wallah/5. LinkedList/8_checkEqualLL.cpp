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

bool checkEqual(Node *head1, Node *head2)
{
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    while(ptr1!= NULL && ptr2!=NULL){
        if(ptr1->val!=ptr2->val){
            return false;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return(ptr1==NULL && ptr2 == NULL);
    
}

int main()
{
    LinkedList ll1;
    ll1.inserAtTail(1);
    ll1.inserAtTail(2);
    ll1.inserAtTail(3);
    ll1.inserAtTail(4);
    ll1.display();

    LinkedList ll2;
    ll2.inserAtTail(1);
    ll2.inserAtTail(2);
    ll2.inserAtTail(3);
    ll2.inserAtTail(4);
    ll2.inserAtTail(5);
    ll2.inserAtTail(6);
    ll2.display();

    LinkedList ll3;
    ll3.inserAtTail(1);
    ll3.inserAtTail(2);
    ll3.inserAtTail(3);
    ll3.inserAtTail(4);
    ll3.display();

    cout << "Check if ll1 and ll2 are equal: " << checkequal(ll1.head, ll2.head) << endl;
    cout << "Check if ll1 and ll3 are equal: " << checkequal(ll1.head, ll3.head) << endl;
    cout << "Check if ll2 and ll3 are equal: " << checkequal(ll2.head, ll3.head) << endl;

    return 0;
}
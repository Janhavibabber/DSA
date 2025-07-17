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

Node *oddEvenLL(Node *&head)
{
    if (!head)
    {
        return head;
    }

    Node *evenHead = head->next;
    Node *odd = head;
    Node *even = evenHead;

    while (even && even->next)
    {
        //  change Link
        odd->next = odd->next->next;
        even->next = even->next->next;
        //  move to next node
        odd = odd->next;
        even = even->next;
    }

    odd->next = evenHead; // link last odd node to first even node
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

    ll1.head = oddEvenLL(ll1.head);
    ll1.display();

    return 0;
}

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

// App1: Count 0s, 1s, 2s and by replacing data of LL
Node *sortList(Node *&head)
{
    int zerocnt = 0;
    int onecnt = 0;
    int twocnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->val == 0)
        {
            zerocnt++;
        }
        else if (temp->val == 1)
        {
            onecnt++;
        }
        else if (temp->val == 2)
        {
            twocnt++;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (zerocnt != 0)
        {
            temp->val = 0;
            zerocnt--;
        }
        else if (onecnt != 0)
        {
            temp->val = 1;
            onecnt--;
        }
        else if (twocnt != 0)
        {
            temp->val = 2;
            twocnt--;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    LinkedList ll;
    ll.inserAtTail(1);
    ll.inserAtTail(0);
    ll.inserAtTail(2);
    ll.inserAtTail(1);
    ll.inserAtTail(2);
    ll.inserAtTail(0);
    ll.display();

    ll.head = sortList(ll.head);
    ll.display();

    return 0;
}
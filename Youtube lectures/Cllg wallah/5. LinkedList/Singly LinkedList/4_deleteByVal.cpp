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

void deleteByVal(Node *&head, int val)
{
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->next->val == val)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        }
        curr = curr->next;
    }
}

int main()
{
    LinkedList ll;
    ll.inserAtTail(1);
    ll.inserAtTail(2);
    ll.inserAtTail(8);
    ll.inserAtTail(4);
    ll.inserAtTail(5);
    ll.display();

    deleteByVal(ll.head, 8);
    cout << "After deleting nodes with val: "<<endl;
    ll.display();

    return 0;
}
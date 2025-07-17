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

class CircularLL
{
public:
    Node *head;
    Node *tail;
    CircularLL()
    {
        head = NULL;
        tail=NULL;
    }

    void display()
    {
        Node *temp = head;
        do
        {
            cout << temp->val << "->";
            temp = temp->next;
        } while (temp != head);
        cout << "NULL" << endl;
    }

    void insertAtTail(int d)
    {
        Node *newNode = new Node(d);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head; // Point to itself
            return;
        }
        Node *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }

        // tail will point to last node
        tail->next = newNode;
        newNode->next = head;
    }

};

bool isCircularLL(Node* head){
    if(head == NULL){
        return true;
    }
    Node* temp = head->next;
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }
    if(temp == head){
        return true;
    }
    return false;
}

int main()
{
    CircularLL cll;

    cll.insertAtTail(10);
    cll.insertAtTail(20);
    cll.insertAtTail(30);
    cll.insertAtTail(40);
    cll.display();

    cout<<cll.head->val << endl; // Displaying tail value for verification
    cll.head->next->next->next->next = cll.head; // Making it circular for testing
    cll.display();
    
    if (isCircularLL(cll.head))
    {
        cout << "The linked list is circular." << endl;
    }
    else
    {
        cout << "The linked list is not circular." << endl;
    }
}
#include <iostream>
#include<map>
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

void deleteDuplicates(Node* &head){
    if(head == NULL)
        return;
    map<Node*, bool> visited;
    Node* curr = head;
    Node* prev = NULL;
    
    while(curr!=NULL){
        if(visited[curr] == true){
            prev->next = curr->next;
            free(curr);
            return;
        }
        visited[curr] = true;
        prev = curr;
        curr=curr->next;
    }
}

int main()
{
    LinkedList ll;
    ll.inserAtTail(4);
    ll.inserAtTail(2);
    ll.inserAtTail(5);
    ll.inserAtTail(4);
    ll.inserAtTail(2);
    ll.inserAtTail(2);
    ll.display();

    deleteDuplicates(ll.head);
    ll.display();

    return 0;
}
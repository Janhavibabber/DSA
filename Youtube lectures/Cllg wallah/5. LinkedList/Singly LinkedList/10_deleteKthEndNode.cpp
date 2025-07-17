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

void removekthNode(Node* &head, int k){
    Node* ptr1=head;
    Node* ptr2=head;

    // set ptr2 by k steps ahead
    int count=k;
    while(count--){
        ptr2 = ptr2->next;
    }
    // if k is equal to length of linked list that is we have to delete head node
    if(ptr2 == NULL){
        Node* temp = head;
        head=head->next;
        free(temp);
        return;
    }

    // when ptr2 is at NULL(end of the list), ptr1 will be at node to be deleted(kth node) as ptr2 is k steps ahead of ptr1
    while(ptr2->next!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    } 

    // now ptr1 is pointing to the (k+1)th node from end
    Node* temp = ptr1->next;
    ptr1->next=ptr1->next->next;
    free(temp);

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

    removekthNode(ll.head, 3);
    ll.display();

    return 0;
}
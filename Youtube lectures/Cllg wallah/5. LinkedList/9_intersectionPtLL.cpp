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

int getLength(Node* head){
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

Node* moveHeadByk(Node* head, int k){
    Node* ptr=head;
    while(k--){
        ptr=ptr->next;
    }
    return ptr;
}

Node* getIntersection(Node *head1, Node *head2)
{
    // step 1: get the length of both linked lists
    int l1 = getLength(head1);
    int l2 = getLength(head2);
    // cout<<L1<<" "<<l2;

    // step 2: Find K difference between linked list and move longer linked list ptr by K steps
    Node *ptr1, *ptr2;
    if(l1>l2){
        int k=l1-l2;
        ptr1=moveHeadByk(head1, k);
        ptr2=head2;
    }
    else{
        int k=l2-l1;
        ptr1=head1;
        ptr2=moveHeadByk(head2, k);
    }

    // step 3: Move both pointers until they meet
    while(ptr1){
    // while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1 == ptr2){
            return ptr1;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return NULL;
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
    ll2.inserAtTail(6);
    ll2.inserAtTail(7);
    ll2.head->next->next = ll1.head->next->next; // 7 points to 3
    ll2.display();

    LinkedList ll3;
    ll3.inserAtTail(1);
    ll3.inserAtTail(2);
    ll3.inserAtTail(3);
    ll3.inserAtTail(4);
    ll3.display();

    // Node *intersect = getIntersection(ll1.head, ll2.head);
    Node *intersect = getIntersection(ll2.head, ll3.head);
    if(intersect != NULL){
        cout << "Intersection Point: " << intersect->val << endl;
    }
    else{
        cout << "No Intersection Point" << endl;
    }

    return 0;
}
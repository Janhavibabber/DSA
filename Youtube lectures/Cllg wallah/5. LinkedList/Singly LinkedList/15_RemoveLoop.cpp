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
    void insertAtTail(int val)
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

Node* detectLoopFloyd(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}

// get starting node of loop
Node * getStartOfLoop(Node* head){
    if(head == NULL){
        return NULL;
    }

    // move fast ptr to head
    Node* fast = head;
    Node* slow = detectLoopFloyd(head);
    
    // move both pointer one step ahead
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }

    //when common node is found
    return slow;

}

void removeLoop(Node* &head){
    if(head == NULL){
        return;
    }

    Node* startLoop = getStartOfLoop(head);
    Node* temp = startLoop;

    while(temp->next!=startLoop){
        temp = temp->next;
        // cout<<temp->val<<"->";
    }

    temp->next = NULL;
}

void removeLoopcombo(Node* &head){
    // assuming loop exists
    Node* fast = head;
    Node* slow = head;

    // detect if loop is present
    do{
        slow = slow->next;
        fast= fast->next->next;
    }while(slow!=fast);

    // Find node before starting of loop
    fast = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    // remove loop
    slow->next = NULL;
}

int main()
{
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);

    cout<<"Before inserting loop: ";
    ll.display();

    // Creating a loop for testing
    Node* endOfLL = ll.head->next->next->next->next;
    // cout<< "End of LL: "<<endOfLL->next<<endl; 
    endOfLL->next = ll.head->next;
    // ll.display();

    Node* firstCommonIntersection = detectLoopFloyd(ll.head);
    cout<< "Common intersection point: "<<firstCommonIntersection->val<<endl;

    Node *startOfLoop = getStartOfLoop(ll.head);
    cout<< "Start of Loop: "<<startOfLoop->val << endl;

    // removeLoop(ll.head);
    removeLoopcombo(ll.head);
    cout << "After removing loop: ";
    ll.display();

    return 0;
}
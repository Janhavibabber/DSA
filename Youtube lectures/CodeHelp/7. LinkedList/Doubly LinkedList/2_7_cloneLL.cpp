#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

class Node
{
public:
    int val;
    Node *arb;
    Node *next;

    Node(int data)
    {
        val = data;
        arb = NULL;
        next = NULL;
    }
};

class DoublyLL
{
public:
    Node *head;
    Node *tail;

    DoublyLL()
    {
        head = NULL;
        tail = NULL;
    }

    void displayNxtPtr()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void displayArbPtr()
    {
        Node *temp = head;
        do
        {
            cout << temp->val << "->";
            temp = temp->arb;
        } while(temp != NULL);
        cout << "NULL" << endl;
    }

    // void insertAtTail(int data)
    // {

    //     Node *new_node = new Node(data);
    //     //  first Node
    //     if (tail == NULL)
    //     {
    //         head = new_node;
    //         tail = new_node;
    //         return;
    //     }

    //     tail->next = new_node;
    //     // new_node->prev = tail;
    //     tail = new_node;
    //     return;
    // }
    void insertAtTail(int d)
    {
        Node *newNode = new Node(d);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
};

void inserAtTailclone(Node* &head, Node* &tail, int d){
    Node* newNode = new Node(d);
    if(head == NULL){
        head=newNode;
        tail=newNode;
    }
    else{
        tail->next = newNode;
        tail=newNode;
    }
}

// App2: By using a map DS:-
Node* copyList(Node* head){
    // step1: create a clone list
    Node* cloneHead  = NULL;
    Node* cloneTail = NULL;
    Node* temp = head;
    while(temp!=NULL){
        inserAtTailclone(cloneHead, cloneTail, temp->val);
        temp = temp->next;
    }

    // step2: create mapping between original and clone nodes
    unordered_map<Node*, Node*> oldToNewNode;
    Node* originalNode = head;
    Node* cloneNode = cloneHead;
    while(originalNode!= NULL){
        oldToNewNode[originalNode] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    } 

    // step3: set the random pointer
    originalNode = head;
    cloneNode = cloneHead;
    while(originalNode!= NULL){
        cloneNode->arb = oldToNewNode[originalNode->arb];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }
    return cloneHead;
}

// App2: Without using a map DS:-
// Node* copyList(Node* head){
//     // ste1: Create a clone linked list
//     Node* cloneHead = NULL;
//     Node *cloneTail = NULL;
//     Node *temp = NULL;
//     while (temp != NULL)
//     {
//         inserAtTail(cloneHead, cloneTail, temp->data);
//         temp=temp->data;
//     }

//     //  step2: Add cloneNodes in between of original Linked list nodes
//     Node* originalNode = head;
//     Node* cloneHead = cloneHead;
//     while(originalNode!=NULL){
//         Node*next = originalNode->next;
//         originalNode->next = cloneNode;
//         originalNode = next;
//         Next = cloneNode->next;
//         cloneNode->next = originalNode;
//         cloneNode=next;
//     }

//     //  step3: Copy Random pointer
//     Node* temp = head;
//     while(temp!=NULL){
//         if(temp->next!=NULL){
//             temp->next->arb = temp->arb? temp->arb->next: temp->arb;
//         }
//         temp = temp->next->next;
//     }

//     //  step4: Revert changes done in step2.
//     originalNode = head;
//     cloneNode=cloneHead;
//     while(originalNode!=NULL && cloneNode!=NULL){
//         originalNode->next = cloneNode->next;
//         originalNode = originalNode->next;
//         if(originalNode!=NULL){
//             cloneNode->next = originalNode->next;
//         }
//         cloneNode=cloneNode->next;
//     }
//     return cloneHead;
// }


int main()
{
    //  working with random pointer is difficult
    DoublyLL dll;
    dll.insertAtTail(3);
    dll.insertAtTail(5);
    dll.insertAtTail(7);
    dll.insertAtTail(9);
    
    cout << "Original Doubly Linked List (Head to Tail): " << endl;
    dll.displayNxtPtr();

    dll.head -> arb = dll.head->next->next; // 3 -> 7
    dll.head->next->arb = dll.head; // 5 -> 3
    dll.head->next->next->arb = dll.tail; // 7 -> 9
    dll.tail->arb = dll.head->next; // 9 -> 5

    cout << "Next Pointer: ";
    // dll.displayNxtPtr();
    cout << "Arb Pointer: ";
    // dll.displayArbPtr();

    Node* clonedList = copyList(dll.head);
    cout << "Cloned Doubly Linked List (Head to Tail): " << endl;   
    DoublyLL clonedDll;
    clonedDll.head = clonedList;    
    clonedDll.displayNxtPtr();
    cout << "Cloned Doubly Linked List (Arb Pointer): " << endl;
    // clonedDll.displayArbPtr();

    return 0;
}   
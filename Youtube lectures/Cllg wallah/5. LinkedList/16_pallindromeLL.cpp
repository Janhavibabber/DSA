#include <iostream>
#include<vector>
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
// App1: Using array DS
bool isPallindrome1(Node* head){
    vector<int> arr;

    Node* temp = head;
    while(temp!=NULL){
        arr.push_back(temp->val);
        temp = temp->next;
    }

    // check pallindrome of an array
    int s=0, e=arr.size()-1;
    while(s<=e){
        if(arr[s]!=arr[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}

Node* getReverse(Node* head){
    Node* curr=head;
    Node* prev=NULL;
    Node* next_node=NULL;

    while(curr!=NULL){
        next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }

    return prev;
}

// App2: Reverse and compare
bool isPallindrome2(Node *head)
{

    // step1: Find the middle element where slow will be pointing to the middle element
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* middle = slow;

    // step2: reverse the second half of the linked list
    
    Node* temp = middle->next;
    middle->next = getReverse(temp);

    // step3: compare the first half and the second half
    Node* first = head;
    Node* second = middle->next;

    while(second!=NULL){
        if(first->val!=second->val){
            return false;
        }
        first = first->next;
        second = second->next;
    }

    // step4: reverse the second half again to restore the original linked list
    temp=middle->next;
    middle->next = getReverse(temp);
    return true;
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
    ll2.inserAtTail(1);
    ll2.inserAtTail(2);
    ll2.inserAtTail(3);
    ll2.inserAtTail(3);
    ll2.inserAtTail(2);
    ll2.inserAtTail(1);
    ll2.display();

    bool check = isPallindrome2(ll2.head);
    if (check)
    {
        cout << "Linked List is Pallindrome" << endl;
    }
    else
    {
        cout << "Linked List is not Pallindrome" << endl;
    }

    return 0;
}
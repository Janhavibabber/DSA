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

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next = prev;
        prev = curr;
        curr=next;
    }
    return prev;
}

void inserAtTailTempLL(Node* &head, Node* &tail, int val)
{
    Node *temp = new Node(val);
    if(head == NULL){
        head = temp;
        tail=temp;
        return;
    }
    else{
        tail->next=temp;
        tail = temp;
    }
}

Node* add(Node* first, Node* second){
    int carry = 0;
    Node* ansHead=NULL;
    Node* ansTail = NULL;
    while(first!=NULL || second!=NULL || carry != 0){
        int val1 = 0;
        if(first!=NULL){
            val1=first->val;
        }
        int val2 = 0;
        if (second != NULL)
        {
            val2 = second->val;
        }
        int sum = carry + val1+val2;
        int digit = sum%10;
        inserAtTailTempLL(ansHead, ansTail, digit);
        carry=sum/10;
        if (first != NULL)
        {
            first = first->next;
        }
        if (second != NULL)
        {
            second = second->next;
        }
    }
    return ansHead;
}

Node* addTwoLists(Node* first, Node* second){

    // step 1: Reverse both LL
    first = reverse(first);
    second = reverse(second);


    // step2: Add both LL
    Node* ans = add(first, second);

    // step 3: reverse the ans LL
    ans = reverse(ans);
    return ans;
}


int main()
{
    LinkedList ll1;
    ll1.inserAtTail(3);
    ll1.inserAtTail(4);
    ll1.inserAtTail(5);
    ll1.display();

    LinkedList ll2;
    ll2.inserAtTail(4);
    ll2.inserAtTail(5);
    ll2.display();

    LinkedList ll3;
    ll3.head = addTwoLists(ll1.head, ll2.head);
    ll3.display();

    return 0;
}
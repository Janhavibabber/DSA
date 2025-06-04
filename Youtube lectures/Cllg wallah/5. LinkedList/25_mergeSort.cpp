#include<iostream>
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

Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while(fast !=NULL && fast->next!=NULL){
        slow = slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right){
    if(left == NULL){
        return right;
    }

    if(right == NULL){
        return left;
    }

    Node* ans = new Node(-1);
    Node* temp = ans;
    while(left!=NULL && right!=NULL){
        if(left->val < right->val){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left!=NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while(right!=NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next; // skip the dummy node
    return ans;
}

Node* mergeSort(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    //  Step1: Find the mid of the linked list
    Node *mid = findMid(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    // Step2: Recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Step3: Merge the sorted halves
    Node * res = merge(left, right);
    return res;
}

int main()
{
    LinkedList ll;
    ll.inserAtTail(2);
    ll.inserAtTail(1);
    ll.inserAtTail(5);
    ll.inserAtTail(4);
    ll.inserAtTail(3);
    ll.display();

    ll.head = mergeSort(ll.head);
    ll.display();

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
    }
};

class LinkedList{
public:
    Node* head;

    LinkedList(){
        head=NULL;
    }

    void insertAtTail(int val){
        Node *new_node = new Node(val);
        // first node 
        if(head == NULL){
            head = new_node;
            return;         
        }
        // other node
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }

        temp->next = new_node;    
    }

    void display(){

        Node* temp = head;

        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;    
        }
        cout<<"NULL"<<endl;
    }

};

// merge 2 sorted logic
Node *mergeLL(Node *&head1, Node *&head2)
{
    Node *dummyHead = new Node(-1);
    Node *ptr1 = head1;
    Node *ptr2 = head2;
    Node *ptr3 = dummyHead;
    while (ptr1 && ptr2)
    {
        if (ptr1->val < ptr2->val)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }

    if (ptr1)
    {
        ptr3->next = ptr1;
    }
    else
    {
        ptr3->next = ptr2;
    }
    return dummyHead->next;
}

// merge k sorted linked list
Node* mergeKLinkedList(vector<Node*> &lists){
    // no LL exists
    if(lists.size() == 0){
        return NULL;
    }

    // more that 1 LL exists
    while(lists.size()>1){
        // merge 2 LL at a time
        Node* mergeHead = mergeLL(lists[0], lists[1]);
        lists.push_back(mergeHead);
        // remove merged LL from lists
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists[0];
}

int main()
{
    LinkedList l1;
    l1.insertAtTail(1);     
    l1.insertAtTail(7);
    l1.insertAtTail(8);
    l1.display();

    LinkedList l2;
    l2.insertAtTail(2);     
    l2.insertAtTail(4);
    l2.insertAtTail(5);
    l2.display();

    LinkedList l3;
    l3.insertAtTail(3);
    l3.insertAtTail(6);
    l3.display();

    vector<Node*> lists;
    lists.push_back(l1.head);
    lists.push_back(l2.head);       
    lists.push_back(l3.head);

    LinkedList mergedLL;
    mergedLL.head = mergeKLinkedList(lists);
    mergedLL.display();


    return 0;
}
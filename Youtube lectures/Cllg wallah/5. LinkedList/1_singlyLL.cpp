#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;      
            next = NULL;
        }
        // Node(int data)
        // {
        //     this->data = data;
        //     this->next = NULL;
        // }
};

void print(Node* &head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp=temp->next;    
    }
    cout<<endl;
}

void insertAtHead(Node* &head, int val){
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

void inserAtTail(Node* &head, int val){
    Node* new_node = new Node(val);
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
}

void insertAtPosition(Node* &head, int val, int pos){
    // if position is 0 insert at head
    if(pos == 0){
        insertAtHead(head, val);
        return;
    }

    Node* new_node = new Node(val);
    Node* temp=head;

    // moving curr ptr to kth position
    int curr_pos=0;
    while(curr_pos!=pos-1){
        temp=temp->next;
        curr_pos++;
    }

    // if position is last insert at tail
    if(temp->next == NULL){
        inserAtTail(head, val);
        return;                 
    }

    // temp is pointing to node at pos-1 and insert at newnode
    new_node->next = temp->next;
    temp->next = new_node;
}

void updateDataAtPosition(Node* &head, int val, int k){
    Node* temp = head;

    int curr_pos=0;
    while(curr_pos!=k){
        temp=temp->next; 
        curr_pos++;
    }

    //  update val at kth position
    temp->data=val;
}

void deleteAtHead(Node* &head){
    Node* temp=head;
    head=head->next;
    free(temp);
}

void deleteAtTail(Node* &head){
    Node* second_last = head;
    while(second_last->next->next!=NULL){
        second_last = second_last->next;
    }

    Node* temp = second_last->next;
    second_last->next=NULL;
    free(temp);
}

void deleteAtPosition(Node* &head, int pos){
    if(pos == 0){
        deleteAtHead(head);
        return;
    }

    Node* prev = head;
    int curr_pos=0;
    while(curr_pos!=pos-1){
        prev=prev->next;
        curr_pos++;
    }

    // prev is pointing to node at pos-1
    Node* temp=prev->next;  // node to be deleted
    prev->next = prev->next->next;
    free(temp);
}

int main()
{
    // 1. Creating a node using constructor
    Node* node1 = new Node(3);
    cout<<node1->data<<" "<<node1->next<<endl;

    // 2. Creating print function
    Node* head = node1;
    print(head);

    // 3. Inserting a node at the start/head
    insertAtHead(head, 2);
    print(head);
    insertAtHead(head, 1);
    print(head);
    // 4. Inserting a node at the end/tail
    inserAtTail(head, 4);
    print(head);
    // 5. Inserting a node at the ith position
    insertAtPosition(head, 5, 2); // inserting at 2nd position
    print(head);

    // 6. Updating data of node at ith position
    updateDataAtPosition(head, 10, 2); // updating data at 2nd position
    print(head);

    // 7. Deleting a node at the start
    deleteAtHead(head);
    print(head);
    // 8. Deleting a node at the end
    deleteAtTail(head);
    print(head);
    // 9. Deleting a node at the ith position
    deleteAtPosition(head, 2); // deleting node at 2nd position
    print(head);

    return 0;
}
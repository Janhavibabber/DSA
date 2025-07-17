#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;

    Node(int data)
    {
        val = data;
        prev = NULL;
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

    void displayHeadToTail()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "<->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void insertAtTail(int data)
    {

        Node *new_node = new Node(data);
        //  first Node
        if (tail == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        return;
    }
};

bool isCriticalPoint(Node* &currNode){
    if(currNode->prev->val < currNode->val && currNode->next->val < currNode->val){
        return true;
    }
    if(currNode->prev->val > currNode->val && currNode->next->val > currNode->val){
        return true;
    }
    return false;
}

vector<int> distanceBetweenCriticalPts(Node* head, Node* tail){
    vector<int> ans(2, INT_MAX);
    int firstCP = -1, lastCP=-1;

    Node* currNode = tail->prev;
    if(currNode == NULL){
        ans[0]=ans[1]=-1;
        return ans;
    }

    int currPos = 0;
    while(currNode->prev!=NULL){
        if(isCriticalPoint(currNode)){
            if(firstCP == -1){
                firstCP = lastCP = currPos;
            }
            else{
                ans[0]=min(ans[0], currPos-lastCP);
                ans[1]=currPos - firstCP;
                lastCP = currPos;
            }
        }
        currPos++;
        currNode = currNode->prev;
    }
    if(ans[0] == INT_MAX){
        ans[0]=ans[1]=-1;
    }
    return ans;
}

int main()
{
    DoublyLL dll;
    dll.insertAtTail(1);
    dll.insertAtTail(5);
    dll.insertAtTail(2);
    dll.insertAtTail(6);
    dll.insertAtTail(3);
    // cout << "Original Doubly Linked List (Head to Tail): " << endl;
    dll.displayHeadToTail();

    vector<int> ans = distanceBetweenCriticalPts(dll.head, dll.tail);
    cout<<ans[0]<<" "<<ans[1]<<endl;

    return 0;
}

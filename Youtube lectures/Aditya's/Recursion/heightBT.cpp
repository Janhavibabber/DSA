// to find height of Binary tree using recursion
#include<iostream>
using namespace std;

//Node can be created using structure or class
struct Node{
    int data;
    struct Node*left;
    struct Node*right;

    Node(int val){
        data = val;
        left=NULL;
        right=NULL;
    }
};

int height(Node*root){
    if(root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1+ max(lh,rh);
}

int main()
{
    //data can be entered by user or can be given in prog itself
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->left->left = new Node(9);

    cout<<height(root);

    return 0;
}
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value){
    Node* newnode = new Node();
    newnode->data=value;
    newnode->left=newnode->right=nullptr;
    return newnode;
}
Node* insert(Node* root, int value)
{
    if(root==nullptr){return createNode(value);}
    if(value<root->data){
        root->left=insert(root->left,value);
    }else{
        root->right=insert(root->right,value);
    }
    return root;
}
void inorder(Node* root){
    if(root==nullptr){return;}
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main() {
    Node* root = nullptr;

    // Insert values
    root = insert(root, 40);
    root = insert(root, 20);
    root = insert(root, 60);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    inorder(root);

    return 0;
}
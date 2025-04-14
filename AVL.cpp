#include<iostream>
using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
    int height;
};

int getHeight(node* n)
{
    if(n==nullptr)
    {
        return 0;
    }
    else
    {
        return n->height;
    }
}

int max(int a,int b)
{
    return a>b?a:b;
}

struct node *createNode(int key){
    struct node* newnode = new node;
    newnode->left=newnode->right=nullptr;
    newnode->key=key;
    newnode->height=1;
    return newnode;
}

int getBalanceFactor(struct node *n)
{
    if(n==nullptr)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct node *rightRotate(struct node* y)
{
    struct node* x = y->left;
    struct node* T2 = x->right;
    x->right=y;
    y->left=T2;
    y->height=max(getHeight(y->right), getHeight(y->left))+1;
    x->height=max(getHeight(x->right), getHeight(x->left))+1;

    return x;
}

struct node *leftRotate(struct node* x)
{
    struct node* y = x->right;
    struct node* T2 = y->left;
    y->left=x;
    x->right=T2;
    y->height=max(getHeight(y->right), getHeight(y->left))+1;
    x->height=max(getHeight(x->right), getHeight(x->left))+1;

    return y;
}
struct node* insert(struct node* root, int key) {
    if (root == nullptr) {
        return createNode(key);
    }

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;  // Duplicate keys not allowed

    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Get balance factor
    int bf = getBalanceFactor(root);

    // Left Left Case
    if (bf > 1 && key < root->left->key)
        return rightRotate(root);

    // Right Right Case
    if (bf < -1 && key > root->right->key)
        return leftRotate(root);

    // Left Right Case
    if (bf > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (bf < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preorder(struct node *root)
{
    if(root != nullptr){
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    struct node *root = nullptr;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,3);
    preorder(root);
    return 0;
}
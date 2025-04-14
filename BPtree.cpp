#include <iostream>
using namespace std;

#define MAX 2  // Max keys in a node

struct Node {
    int keys[MAX + 1];     // One extra for overflow
    Node* next;            // For leaf link
    bool isLeaf;
    int n;                 // Number of keys
    Node* child[MAX + 2];  // One extra pointer for split
};

Node* root = nullptr;

// Create a new node
Node* createNode(bool isLeaf) {
    Node* node = new Node;
    node->isLeaf = isLeaf;
    node->n = 0;
    node->next = nullptr;
    for (int i = 0; i < MAX + 2; i++) node->child[i] = nullptr;
    return node;
}

// Insert key into B+ Tree
void insert(int key) {
    if (!root) {
        root = createNode(true);
        root->keys[0] = key;
        root->n = 1;
        return;
    }

    Node* leaf = root;
    Node* parent = nullptr;

    // Go to leaf
    while (!leaf->isLeaf) {
        parent = leaf;
        int i = 0;
        while (i < leaf->n && key >= leaf->keys[i]) i++;
        leaf = leaf->child[i];
    }

    // If space in leaf
    if (leaf->n < MAX) {
        int i = leaf->n - 1;
        while (i >= 0 && leaf->keys[i] > key) {
            leaf->keys[i + 1] = leaf->keys[i];
            i--;
        }
        leaf->keys[i + 1] = key;
        leaf->n++;
    }
    else {
        // Split leaf
        Node* newLeaf = createNode(true);
        int temp[MAX + 1];
        for (int i = 0; i < MAX; i++) temp[i] = leaf->keys[i];
        temp[MAX] = key;

        // Sort keys
        for (int i = 0; i < MAX + 1; i++)
            for (int j = i + 1; j < MAX + 1; j++)
                if (temp[i] > temp[j]) swap(temp[i], temp[j]);

        leaf->n = (MAX + 1) / 2;
        newLeaf->n = MAX + 1 - leaf->n;

        for (int i = 0; i < leaf->n; i++) leaf->keys[i] = temp[i];
        for (int i = 0; i < newLeaf->n; i++) newLeaf->keys[i] = temp[i + leaf->n];

        newLeaf->next = leaf->next;
        leaf->next = newLeaf;

        if (leaf == root) {
            Node* newRoot = createNode(false);
            newRoot->keys[0] = newLeaf->keys[0];
            newRoot->child[0] = leaf;
            newRoot->child[1] = newLeaf;
            newRoot->n = 1;
            root = newRoot;
        } else {
            // Simple parent update (not recursive for brevity)
            parent->keys[parent->n] = newLeaf->keys[0];
            parent->child[parent->n + 1] = newLeaf;
            parent->n++;
        }
    }
}

// Search key
void search(int key) {
    Node* curr = root;
    while (curr && !curr->isLeaf) {
        int i = 0;
        while (i < curr->n && key >= curr->keys[i]) i++;
        curr = curr->child[i];
    }
    if (!curr) {
        cout << "Tree is empty.\n";
        return;
    }
    for (int i = 0; i < curr->n; i++) {
        if (curr->keys[i] == key) {
            cout << "Found: " << key << endl;
            return;
        }
    }
    cout << "Not found: " << key << endl;
}

// Print all keys in leaves
void printTree() {
    Node* curr = root;
    while (curr && !curr->isLeaf) curr = curr->child[0];
    cout << "Leaf keys: ";
    while (curr) {
        for (int i = 0; i < curr->n; i++) cout << curr->keys[i] << " ";
        curr = curr->next;
    }
    cout << endl;
}

// ==== MAIN ====
int main() {
    insert(10); insert(20); insert(5); insert(15);
    insert(25); insert(30); insert(1);

    printTree();

    search(15);
    search(100);

    return 0;
}

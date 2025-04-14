#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN_DEGREE 3 // Minimum degree of the B-tree (order of the tree)

class BTreeNode {
public:
    vector<int> keys;  // Vector to store keys
    vector<BTreeNode*> children;  // Vector to store child pointers
    bool leaf;  // True if leaf node, false otherwise

    BTreeNode(bool isLeaf);
    void insertNonFull(int key);
    void splitChild(int i, BTreeNode* y);
};

class BTree {
private:
    BTreeNode* root;

public:
    BTree();
    void insert(int key);
    void traverse(BTreeNode* node);
    BTreeNode* getRoot();
};

BTreeNode::BTreeNode(bool isLeaf) {
    leaf = isLeaf;
}

void BTreeNode::insertNonFull(int key) {
    int i = keys.size() - 1;

    if (leaf) {
        // Find the location where the key should be inserted
        while (i >= 0 && keys[i] > key) {
            i--;
        }

        // Insert the new key at the appropriate position
        keys.insert(keys.begin() + i + 1, key);
    }
    else {
        // Find the child to insert into
        while (i >= 0 && keys[i] > key) {
            i--;
        }
        i++;

        // If the child is full, split it first
        if (children[i]->keys.size() == (2 * MIN_DEGREE) - 1) {
            splitChild(i, children[i]);

            // After split, the middle key of children[i] goes up, so we need to compare with the parent again
            if (keys[i] < key) {
                i++;
            }
        }

        // Now insert the key into the appropriate child
        children[i]->insertNonFull(key);
    }
}

void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->leaf);
    int mid = MIN_DEGREE - 1;

    // Move the last MIN_DEGREE - 1 keys of y to z
    for (int j = 0; j < MIN_DEGREE - 1; j++) {
        z->keys.push_back(y->keys[j + MIN_DEGREE]);
    }

    // If y is not a leaf, move the last MIN_DEGREE children of y to z
    if (!y->leaf) {
        for (int j = 0; j < MIN_DEGREE; j++) {
            z->children.push_back(y->children[j + MIN_DEGREE]);
        }
    }

    // Insert the middle key into the current node
    keys.insert(keys.begin() + i, y->keys[mid]);

    // Insert the new child pointer into the current node
    children.insert(children.begin() + i + 1, z);

    // Remove the last MIN_DEGREE keys and children from y
    y->keys.resize(mid);
    y->children.resize(MIN_DEGREE);
}

BTree::BTree() {
    root = new BTreeNode(true);  // Create a new root node that is a leaf
}

void BTree::insert(int key) {
    // If the root is full, split it
    if (root->keys.size() == (2 * MIN_DEGREE) - 1) {
        BTreeNode* s = new BTreeNode(false); // Create a new root
        s->children.push_back(root);  // Old root becomes child of new root
        s->splitChild(0, root);  // Split the old root
        root = s;  // Make the new root
    }

    // Insert the key into the root
    root->insertNonFull(key);
}

void BTree::traverse(BTreeNode* node) {
    // Print all keys in this node
    for (int i = 0; i < node->keys.size(); i++) {
        cout << node->keys[i] << " ";
    }

    // Recur for all children of the current node
    if (!node->leaf) {
        for (int i = 0; i < node->children.size(); i++) {
            traverse(node->children[i]);
        }
    }
}

BTreeNode* BTree::getRoot() {
    return root;
}

int main() {
    BTree btree;

    // Insert keys into the B-tree
    btree.insert(10);
    btree.insert(20);
    btree.insert(5);
    btree.insert(6);
    btree.insert(12);
    btree.insert(30);
    btree.insert(7);
    btree.insert(17);

    // Traverse and display the B-tree
    cout << "B-tree traversal: ";
    btree.traverse(btree.getRoot());
    cout << endl;

    return 0;
}
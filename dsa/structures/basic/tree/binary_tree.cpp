#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

struct BinaryTree {
    Node* root;

    BinaryTree() : root(nullptr) {}

    void insertHelper(Node*& node, int val) {
        if (!node) {
            node = new Node(val);
            return;
        }
        if (val < node->data) {            
            insertHelper(node->left, val);
        } else {
            insertHelper(node->right, val);
        }
    }

    void insert(int val) {
        insertHelper(root, val);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

void run_binary_tree() {
    cout << "\nBinary Tree \n";

    BinaryTree tree;

    int treeNodes[] = {5, 3, 7, 2, 4, 6, 8};
    int treeNodesLength = sizeof(treeNodes) / sizeof(treeNodes[0]);

    for (int i = 0; i < treeNodesLength; ++i) {
        tree.insert(treeNodes[i]);
    }

    cout << "In order: ";
    tree.display();
}

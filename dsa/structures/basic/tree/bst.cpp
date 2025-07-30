#include <iostream>
using namespace std;

class BSTNode {
public:
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    BSTNode* root;

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRec(root, value);
    }

    BSTNode* insertRec(BSTNode* node, int value) {
        if (!node) {
            return new BSTNode(value);
        }

        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    void inorderRec(BSTNode* node) {
        if (node) {
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
        }
    }

    ~BinarySearchTree() {
        deleteTree(root);
    }

    void deleteTree(BSTNode* node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }
};

void run_bst() {
    cout << "\nBST (Binary Search Tree)\n";

    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    cout << "In-order traversal: ";
    bst.inorder();  // 20 30 40 50 70
}

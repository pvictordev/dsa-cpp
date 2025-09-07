#include <iostream>
using namespace std;

template <typename T>
class BSTNode {
public:
    T data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree {
private:
    BSTNode<T>* root;

    BSTNode<T>* insertRec(BSTNode<T>* node, T value) {
        if (!node) {
            return new BSTNode<T>(value);
        }

        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    void inorderRec(BSTNode<T>* node) {
        if (node) {
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
        }
    }

    void deleteTree(BSTNode<T>* node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(T value) {
        root = insertRec(root, value);
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    ~BinarySearchTree() {
        deleteTree(root);
    }
};

void run_bst() {
    cout << "\nBST (Binary Search Tree)\n";

    BinarySearchTree<int> bst;  

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    cout << "In-order traversal: ";
    bst.inorder(); 
}

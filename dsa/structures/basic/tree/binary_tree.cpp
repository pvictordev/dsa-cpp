#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;

     Node(const T& value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
struct BinaryTree {
    Node<T>* root;

    BinaryTree() : root(nullptr) {}

    void insertHelper(Node<T>*& node, const T& val) {
        if (!node) {
            node = new Node<T>(val);
            return;
        }
        if (val < node->data) {
            insertHelper(node->left, val);
        } else {
            insertHelper(node->right, val);
        }
    }

    void insert(const T& val) {
        insertHelper(root, val);
    }

    void inorder(Node<T>* node) const {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void display() const {
        inorder(root);
        cout << endl;
    }

    ~BinaryTree() {
        destroy(root);
    }

private:
    void destroy(Node<T>* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
};

// Example usage
void run_binary_tree() {
    cout << "\nBinary Tree \n";

    BinaryTree<int> tree;

    int treeNodes[] = {5, 3, 7, 2, 4, 6, 8};
    int treeNodesLength = sizeof(treeNodes) / sizeof(treeNodes[0]);

    for (int i = 0; i < treeNodesLength; ++i) {
        tree.insert(treeNodes[i]);
    }

    cout << "In order: ";
    tree.display();  // Output: 2 3 4 5 6 7 8
}

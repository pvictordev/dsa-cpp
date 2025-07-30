#include <iostream>
using namespace std;

class BinaryTree {
    private:
        struct Node {
            int data;
            Node* left;
            Node* right;
            
            Node(int val) : data(val), left(nullptr), right(nullptr) {}
        };
        
        Node* root;
        
        void insert(Node* &node, int val) {
            if (!node) {
                node = new Node(val);
                return;
            }
            
            if (val < node->data) {
                insert(node->left, val);
            } else {
                insert(node->right, val);
            }
        }
        
        void inorder(Node* node) {
            if (!node) return;
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    
    public:
        BinaryTree() : root(nullptr) {}
        
        void insert(int val) {
            insert(root, val);
        }
        
        void display() {
            inorder(root);
            cout << endl;
        }
};


void run_binary_tree() {
    cout << "\nBinary Tree \n";

    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    
    cout << "Inorder traversal: ";
    tree.display();
}
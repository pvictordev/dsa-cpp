#include <iostream>
using namespace std;

class Node {

public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr; 
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (tail) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            head = tail = newNode;
        }
    }

    void print() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

void run_doubly_linked_list() {
    cout << "\nDoubly Linked List\n";

    DoublyLinkedList list;

    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.print();
}

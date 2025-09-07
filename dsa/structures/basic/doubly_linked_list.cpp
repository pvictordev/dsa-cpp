#include <iostream>
using namespace std;

template <typename T>
class Node {

public:
    int data;
    Node<T>* next;  
    Node<T>* prev;  

    Node(const T& value) {
        data = value;
        next = nullptr;
        prev = nullptr; 
    }
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (tail) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            head = tail = newNode;
        }
    }

    void print() const {
        Node<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

void run_doubly_linked_list() {
    cout << "\nDoubly Linked List\n";

    DoublyLinkedList<int> list;

    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.print();
}

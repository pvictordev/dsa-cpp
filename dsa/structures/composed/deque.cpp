#include <iostream>
using namespace std;

// Node structure for doubly-linked list
struct Node {
    int value;
    Node* prev;
    Node* next;
    
    Node(int val) : value(val), prev(nullptr), next(nullptr) {}
};

class Deque {
private:
    Node* front;  // Pointer to front of deque
    Node* rear;   // Pointer to rear of deque
    int size;     // Current size of deque

public:
    // Constructor
    Deque() : front(nullptr), rear(nullptr), size(0) {}
    
    // Destructor to free memory
    ~Deque() {
        while (!isEmpty()) {
            removeFront();
        }
    }
    
    // Check if deque is empty
    bool isEmpty() {
        return size == 0;
    }
    
    // Insert at front
    void insertFront(int value) {
        Node* newNode = new Node(value);
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
    }
    
    // Insert at rear
    void insertRear(int value) {
        Node* newNode = new Node(value);
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        size++;
    }
    
    // Remove from front
    void removeFront() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        
        Node* temp = front;
        front = front->next;
        
        if (front == nullptr) {
            rear = nullptr;
        } else {
            front->prev = nullptr;
        }
        
        delete temp;
        size--;
    }
    
    // Remove from rear
    void removeRear() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        
        Node* temp = rear;
        rear = rear->prev;
        
        if (rear == nullptr) {
            front = nullptr;
        } else {
            rear->next = nullptr;
        }
        
        delete temp;
        size--;
    }
    
    // Print deque from front to rear
    void print() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        
        Node* current = front;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

void run_deque() {
    cout << "\nDeque (Double Ended Queue) Implementation from Scratch\n";

    Deque deque;

    deque.insertFront(10);
    deque.insertRear(20);
    deque.insertFront(5);

    cout << "Deque after inserts: ";
    deque.print();  // 5 10 20

    deque.removeRear();
    cout << "Deque after removing rear: ";
    deque.print();  // 5 10

    deque.removeFront();
    cout << "Deque after removing front: ";
    deque.print();  // 10
}
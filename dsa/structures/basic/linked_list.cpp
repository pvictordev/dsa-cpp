#include <iostream>
using namespace std;

template <typename T>
class Node {
    
public:
    T data;         
    Node<T>* next;  

    Node(const T& value) {
        data = value;
        next = nullptr;
    }
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    void print() const {
        Node<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void sort() {
        if (!head) return;

        bool swapped;
        do {
            swapped = false;
            Node<T>* current = head;

            while (current->next) {
                if (current->data > current->next->data) { 
                    T temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }

    ~LinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Demo
void run_linked_list() {
    cout << "\n\nLinked List\n";

    LinkedList<int> list;

    list.insert(10);
    list.insert(20);
    list.insert(30);

    cout << "Initial list: ";
    list.print();

    list.sort();
    cout << "Sorted list: ";
    list.print();
}

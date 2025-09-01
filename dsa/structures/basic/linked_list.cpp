#include <iostream>
using namespace std;

class Node {

public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {

private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void print() {
        Node* current = head;
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
            Node* current = head;

            while (current->next) {
                if (current->data > current->next->data) {
                    int temp = current->data;
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
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

void run_linked_list() {
    cout << "\n\nLinked List\n";

    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);

    cout << "Initial list: ";
    list.print(); // [head] → [30] → [20] → [10] → nullptr


    list.sort();

    cout << "\nSorted list: ";
    list.print(); 
}

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

    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    void print() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    Node* getHead() {
        return head;
    }

    void setHead(Node* node) {
        head = node;
    }

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

Node* merge_linked_list(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node* result = nullptr;

    if (head1->data < head2->data) {
        result = head1;
        result->next = merge_linked_list(head1->next, head2);
    } else {
        result = head2;
        result->next = merge_linked_list(head1, head2->next);
    }

    return result;
}

void run_merge_linked_list() {
    cout << "\n\nLinked List Merge\n";

    LinkedList list1, list2;

    list1.append(1);
    list1.append(3);
    list1.append(5);

    list2.append(2);
    list2.append(4);
    list2.append(6);

    cout << "List1: "; list1.print();
    cout << "List2: "; list2.print();

    Node* mergedHead = merge_linked_list(list1.getHead(), list2.getHead());

    LinkedList mergedList;
    mergedList.setHead(mergedHead);

    cout << "Merged: "; mergedList.print(); // [1 2 3 4 5 6]
}

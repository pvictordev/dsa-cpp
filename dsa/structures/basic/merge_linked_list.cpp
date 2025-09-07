#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

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

    void append(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    void print() const {
        Node<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    Node<T>* getHead() const {
        return head;
    }

    void setHead(Node<T>* node) {
        head = node;
    }

    ~LinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

template <typename T>
Node<T>* merge_linked_list(Node<T>* head1, Node<T>* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node<T>* result = nullptr;

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

    LinkedList<int> list1, list2;

    list1.append(1);
    list1.append(3);
    list1.append(5);

    list2.append(2);
    list2.append(4);
    list2.append(6);

    cout << "List1: "; list1.print();
    cout << "List2: "; list2.print();

    Node<int>* mergedHead = merge_linked_list(list1.getHead(), list2.getHead());

    LinkedList<int> mergedList;
    mergedList.setHead(mergedHead);

    cout << "Merged: "; mergedList.print();  // [1 2 3 4 5 6]
}

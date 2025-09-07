#include <iostream>
using namespace std;

template <typename T>
class DNode {
public:
    T data;
    DNode* next;
    DNode* prev;

    DNode(const T& value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class DoublyLinkedList {
private:
    DNode<T>* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void append(const T& value) {
        DNode<T>* newNode = new DNode<T>(value);
        if (!head) {
            head = newNode;
            return;
        }
        DNode<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    void printForward() const {
        DNode<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void printBackward() const {
        if (!head) return;
        DNode<T>* current = head;
        while (current->next) { 
            current = current->next;
        }
        while (current) { 
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    DNode<T>* getHead() const {
        return head;
    }

    void setHead(DNode<T>* node) {
        head = node;
    }

    ~DoublyLinkedList() {
        DNode<T>* cur = head;
        while (cur) {
            DNode<T>* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }
};

template <typename T>
DNode<T>* merge_doubly_linked_list(DNode<T>* head1, DNode<T>* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    DNode<T>* result = nullptr;

    if (head1->data < head2->data) {
        result = head1;
        result->next = merge_doubly_linked_list(head1->next, head2);
        if (result->next) result->next->prev = result;
    } else {
        result = head2;
        result->next = merge_doubly_linked_list(head1, head2->next);
        if (result->next) result->next->prev = result;
    }

    return result;
}

void run_merge_doubly_linked_list() {
    cout << "\n\nDoubly Linked List Merge\n";

    DoublyLinkedList<int> list1, list2;

    list1.append(1);
    list1.append(3);
    list1.append(5);

    list2.append(2);
    list2.append(4);
    list2.append(6);

    cout << "List1 (forward): "; list1.printForward();
    cout << "List2 (forward): "; list2.printForward();

    DNode<int>* mergedHead = merge_doubly_linked_list(list1.getHead(), list2.getHead());

    DoublyLinkedList<int> mergedList;
    mergedList.setHead(mergedHead);

    cout << "Merged (forward): "; mergedList.printForward();
    cout << "Merged (backward): "; mergedList.printBackward();
}

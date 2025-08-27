#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;

    DNode(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    DNode* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void append(int value) {
        DNode* newNode = new DNode(value);
        if (!head) {
            head = newNode;
            return;
        }
        DNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    void printForward() {
        DNode* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void printBackward() {
        if (!head) return;
        DNode* current = head;
        while (current->next) { 
            current = current->next;
        }
        while (current) { 
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    DNode* getHead() {
        return head;
    }

    void setHead(DNode* node) {
        head = node;
    }
};


DNode* merge_doubly_linked_list(DNode* head1, DNode* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    DNode* result = nullptr;

    if (head1->data < head2->data) {
        result = head1;
        result->next = merge_doubly_linked_list(head1->next, head2);
        if (result->next) {
            result->next->prev = result;
        }
    } else {
        result = head2;
        result->next = merge_doubly_linked_list(head1, head2->next);
        if (result->next) {
            result->next->prev = result;
        }
    }

    return result;
}


void run_merge_doubly_linked_list() {
    cout << "\n\nDoubly Linked List Merge\n";

    DoublyLinkedList list1, list2;

    list1.append(1);
    list1.append(3);
    list1.append(5);

    list2.append(2);
    list2.append(4);
    list2.append(6);

    cout << "List1 (forward): "; list1.printForward();
    cout << "List2 (forward): "; list2.printForward();

    DNode* mergedHead = merge_doubly_linked_list(list1.getHead(), list2.getHead());

    DoublyLinkedList mergedList;
    mergedList.setHead(mergedHead);

    cout << "Merged (forward): "; mergedList.printForward();
    cout << "Merged (backward): "; mergedList.printBackward(); 
}


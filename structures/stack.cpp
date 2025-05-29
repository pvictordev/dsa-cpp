#include <iostream>
#include <stdexcept>
using namespace std;

class Stack {

private:
    int* data;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        data = new int[capacity];
        top = -1;
    }

    void push(int value) {
        if (top == capacity - 1) {
            throw overflow_error("Stack overflow");
        }
        data[++top] = value;
    }

    int pop() {
        //* remove items from the top until you access the last item 
        if (top == -1) {
            throw underflow_error("Stack underflow");
        }
        return data[top--];
    }

    bool isEmpty() {
        return top == -1;
    }

    int peek() {
        if (top == -1) {
            throw underflow_error("Stack underflow");
        }
        return data[top];
    }

    int search(int value) {
        for (int i = top; i >= 0; --i) {
            if (data[i] == value) {
                return top - i; 
            }
        }
        return -1; 
    }

    ~Stack() {
        delete[] data;
    }
};

void run_stack() {
    cout << "\nStack\n";

    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;  
    cout << "Popped element: " << s.pop() << endl;

    int index = s.search(10);
    if (index != -1)
        cout << "Element 10 found at position (from top): " << index << endl;
    else
        cout << "Element 10 not found" << endl;
}

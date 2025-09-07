#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack {

private:
    T* data;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        data = new T[capacity];
        top = -1;
    }

    void push(const T& value) {
        if (top == capacity - 1) {
            throw overflow_error("Stack overflow");
        }
        data[++top] = value;
    }

    T pop() {
        //* remove items from the top until you access the last item 
        if (top == -1) {
            throw underflow_error("Stack underflow"); // stack empty
        }
        return data[top--];
    }

    bool isEmpty() const {
        return top == -1;
    }

    T peek() const {
        if (top == -1) {
            throw underflow_error("Stack underflow");
        }
        return data[top];
    }

    int search(const T& value) const {
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

    Stack<int> s(5);

    s.push(10); // 0
    s.push(20); // 1
    s.push(30); // 2

    cout << "Top element: " << s.peek() << endl;  
    cout << "Popped element: " << s.pop() << endl;

    int index = s.search(10);
    if (index != -1)
        cout << "Element 10 found at position (from top): " << index << endl;
    else
        cout << "Element 10 not found" << endl;
}

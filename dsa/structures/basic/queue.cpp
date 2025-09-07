#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue {

private:
    T* data;
    int front, rear, capacity;

public:
    Queue(int size) {
        capacity = size;
        data = new T[capacity];
        front = 0;
        rear = 0;
    }

    void enqueue(const T& value) {
        if (rear == capacity) {
            throw overflow_error("Queue overflow");
        }
        // push the item
        data[rear++] = value;
    }

    T dequeue() {
        if (front == rear) {
            throw underflow_error("Queue underflow");
        }
        // return first item and increment the front by 1 (on next deque the front is gonna be the second item)
        return data[front++];
    }

    bool isEmpty() {
        return front == rear;
    }

    T peek() const {
        if (front == rear) {
            throw underflow_error("Queue underflow");
        }
        return data[front];
    }

    ~Queue() {
        delete[] data;
    }
};

void run_queue() {
    cout << "\nQueue\n";

    Queue<int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl;  
    cout << "Dequeued element: " << q.dequeue() << endl; 
}

#include <iostream>
#include <stdexcept>
using namespace std;

class Queue {

private:
    int* data;
    int front, rear, capacity;

public:
    Queue(int size) {
        capacity = size;
        data = new int[capacity];
        front = 0;
        rear = 0;
    }

    void enqueue(int value) {
        if (rear == capacity) {
            throw overflow_error("Queue overflow");
        }
        data[rear++] = value;
    }

    int dequeue() {
        if (front == rear) {
            throw underflow_error("Queue underflow");
        }
        return data[front++];
    }

    bool isEmpty() {
        return front == rear;
    }

    int peek() {
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

    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl;  
    cout << "Dequeued element: " << q.dequeue() << endl;  
}

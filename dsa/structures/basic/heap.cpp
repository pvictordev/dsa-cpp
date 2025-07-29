#include <iostream>
#include <stdexcept>
using namespace std;

class MinHeap {
private:
    int* heapArray;
    int capacity;
    int currentSize;

    // Helper methods
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int index) {
        while (index != 0 && heapArray[parent(index)] > heapArray[index]) {
            swap(heapArray[index], heapArray[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < currentSize && heapArray[left] < heapArray[smallest])
            smallest = left;

        if (right < currentSize && heapArray[right] < heapArray[smallest])
            smallest = right;

        if (smallest != index) {
            swap(heapArray[index], heapArray[smallest]);
            heapifyDown(smallest);
        }
    }

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

public:
    MinHeap(int size) {
        capacity = size;
        heapArray = new int[capacity];
        currentSize = 0;
    }

    void insert(int value) {
        if (currentSize == capacity) {
            throw overflow_error("Heap is full");
        }

        // Insert at the end
        heapArray[currentSize] = value;
        currentSize++;

        // Fix the heap property
        heapifyUp(currentSize - 1);
    }

    int extractMin() {
        if (currentSize <= 0) {
            throw underflow_error("Heap is empty");
        }

        if (currentSize == 1) {
            currentSize--;
            return heapArray[0];
        }

        // Store the minimum value
        int root = heapArray[0];

        // Move last element to root
        heapArray[0] = heapArray[currentSize - 1];
        currentSize--;

        // Heapify down
        heapifyDown(0);

        return root;
    }

    int getMin() {
        if (currentSize <= 0) {
            throw underflow_error("Heap is empty");
        }
        return heapArray[0];
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    int size() {
        return currentSize;
    }

    ~MinHeap() {
        delete[] heapArray;
    }
};

void run_heap() {
    cout << "\nMin-Heap\n";

    MinHeap heap(10);

    heap.insert(30);
    heap.insert(20);
    heap.insert(10);
    heap.insert(5);
    heap.insert(15);

    cout << "Min element: " << heap.getMin() << endl;
    cout << "Extracted min: " << heap.extractMin() << endl;
    cout << "New min: " << heap.getMin() << endl;

    cout << "Heap contents (in order): ";
    while (!heap.isEmpty()) {
        cout << heap.extractMin() << " ";
    }
    cout << endl;
}
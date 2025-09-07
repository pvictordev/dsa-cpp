#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class MinHeap {

private:
    T* heapArray;
    int capacity;
    int currentSize;

    // Helper methods
    void swap(T& a, T& b) {
        T temp = a;
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
        heapArray = new T[capacity];
        currentSize = 0;
    }

    void insert(T value) {
        if (currentSize == capacity) {
            throw overflow_error("Heap is full");
        }
        heapArray[currentSize] = value;
        currentSize++;
        heapifyUp(currentSize - 1);
    }

    T extractMin() {
        if (currentSize <= 0) {
            throw underflow_error("Heap is empty");
        }
        if (currentSize == 1) {
            currentSize--;
            return heapArray[0];
        }
        T root = heapArray[0];
        heapArray[0] = heapArray[currentSize - 1];
        currentSize--;
        heapifyDown(0);
        return root;
    }

    T getMin() {
        if (currentSize <= 0) {
            throw underflow_error("Heap is empty");
        }
        return heapArray[0];
    }

    bool isEmpty() { return currentSize == 0; }
    int size() { return currentSize; }

    ~MinHeap() {
        delete[] heapArray;
    }
};

// Example usage
void run_heap() {
    cout << "\nMin-Heap\n";
    MinHeap<int> heap(10);  
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
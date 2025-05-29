#include <iostream>
using namespace std;

class Vector {

private:
    int* data;
    int size;
    int capacity;

public:
    Vector() {
        size = 0;
        capacity = 1;
        data = new int[capacity];
    }

    void push_back(int value) {
        // reallocating the memory
        // * we should do this because C++ do not allow us to increase the size of a fixed size array allocated with: new int[size]
        if (size == capacity) {
            capacity *= 2;  
            int* new_data = new int[capacity];
            for (int i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
        }
        data[size++] = value;
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    int getSize() {
        return size;
    }

    ~Vector() {
        delete[] data;
    }
};


void run_vector() {
    cout << "\nVector\n";

    Vector v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(0);
    v.push_back(0);

    for (int i = 0; i < v.getSize(); ++i) {
        cout << v.get(i) << " ";
    }
}

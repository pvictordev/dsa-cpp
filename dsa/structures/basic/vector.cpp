#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Vector {

private:
    T* data;
    int size;
    int capacity;

public:
    Vector() {
        size = 0;
        capacity = 1;
        data = new T[capacity];
    }

    void push_back(const T& value) {
        if (size == capacity) {
            capacity *= 2;
            T* new_data = new T[capacity];
            for (int i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
        }
        data[size++] = value;
    }

    T get(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    int getSize() const {
        return size;
    }

    ~Vector() {
        delete[] data;
    }
};

// Example usage
void run_vector() {
    cout << "\nVector<int>\n";
    Vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(0);
    v.push_back(0);

    for (int i = 0; i < v.getSize(); ++i) {
        cout << v.get(i) << " ";
    }
    cout << "\n";
}

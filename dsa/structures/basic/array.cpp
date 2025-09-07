#include <iostream>
using namespace std;

template <typename T>
class Array {
    
private:
    T* arr;
    int size;

public:
    Array(const T& s) {
        size = s;
        arr = new T[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = 0;
        }
    }

    void set(const T& index, const T& value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        }
    }

    int get(const T& index) const {
        return (index >= 0 && index < size) ? arr[index] : -1;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Array() {
        delete[] arr;
    }
};

void run_array() {
    cout << "Array \n";

    Array arr(5);

    arr.set(0, 10);
    arr.set(1, 20);
    arr.display();
}

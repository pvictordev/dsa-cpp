#include <iostream>
using namespace std;

class Array {
    
private:
    int* arr;
    int size;

public:
    Array(int s) {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; ++i)
            arr[i] = 0;
    }

    void set(int index, int value) {
        if (index >= 0 && index < size)
            arr[index] = value;
    }

    int get(int index) {
        return (index >= 0 && index < size) ? arr[index] : -1;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
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

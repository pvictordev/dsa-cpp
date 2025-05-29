#include <iostream>
#include <stdexcept>
using namespace std;

class HashTable {
private:
    int* table;
    int capacity;
    int size;

    int hash(int key) {
        return key % capacity;  
    }

public:
    HashTable(int cap) : capacity(cap), size(0) {
        table = new int[capacity];
        for (int i = 0; i < capacity; ++i) {
            table[i] = -1;  
        }
    }

    void insert(int key) {
        if (size == capacity) {
            throw overflow_error("Hash table is full");
        }

        int index = hash(key);
        while (table[index] != -1) {  
            index = (index + 1) % capacity;
        }

        table[index] = key;
        ++size;
    }

    bool search(int key) {
        int index = hash(key);
        int start_index = index;
        while (table[index] != -1) {
            if (table[index] == key) {
                return true; 
            }
            index = (index + 1) % capacity;
            if (index == start_index) {
                break;  
            }
        }
        return false;  
    }

    void remove(int key) {
        int index = hash(key);
        int start_index = index;
        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -1;  
                --size;
                return;
            }
            index = (index + 1) % capacity;
            if (index == start_index) {
                break; 
            }
        }
        throw runtime_error("Key not found");
    }

    ~HashTable() {
        delete[] table;
    }
};

void run_hash_table() {
    cout << "\n\nHash Table\n";
    HashTable ht(10);

    ht.insert(5);
    ht.insert(15);
    ht.insert(25);

    cout << "Found 15: " << ht.search(15) << endl;  
    cout << "Found 10: " << ht.search(10) << endl;  

    ht.remove(15);
    cout << "Found 15 after removal: " << ht.search(15) << endl;
}

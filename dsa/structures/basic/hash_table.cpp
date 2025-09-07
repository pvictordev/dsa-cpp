#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class HashTable {
    
private:
    T* table;
    int capacity;
    int size;

    int hash(const T& key) const {
        return key % capacity;  
    }

public:
    HashTable(int cap) {
        capacity = cap;
        size = 0;
        table = new T[capacity];

        for (int i = 0; i < capacity; ++i) {
            table[i] = -1;  // mark each bucket/slot in the hash table as empty
        }
    }

    void printTable() const {
        cout << "Hash Table Contents:\n";
        for (int i = 0; i < capacity; ++i) {
            cout << "[" << i << "]: ";
            if (table[i] == -1) {
                cout << "EMPTY";
            } else {
                cout << table[i];
            }
            cout << endl;
        }
    }

    void insert(const T& key) {
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

    bool search(const T& key) const {
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

    void remove(const T& key) {
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

//
void run_hash_table() {
    cout << "\nHash Table\n";
    HashTable<int> ht(5);

    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    ht.printTable(); 

    cout << "Found 10: " << ht.search(15) << endl;  
    cout << "Found 20: " << ht.search(10) << endl;  

    ht.remove(30);
    cout << "Found 30 after removal: " << ht.search(30) << endl;

}

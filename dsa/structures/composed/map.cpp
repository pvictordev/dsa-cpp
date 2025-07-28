#include <iostream>
#include <string>
using namespace std;

// Node structure for key-value pairs
struct MapNode {
    int key;
    string value;
    MapNode* next;
    
    MapNode(int k, const string& v) : key(k), value(v), next(nullptr) {}
};

class Map {
private:
    static const int TABLE_SIZE = 10;  // Size of the hash table
    MapNode** table;  // Array of pointers to MapNode
    
    // Simple hash function
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }
    
public:
    // Constructor
    Map() {
        table = new MapNode*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }
    
    // Destructor to free memory
    ~Map() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            MapNode* current = table[i];
            while (current != nullptr) {
                MapNode* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
    
    // Insert or update a key-value pair
    void insert(int key, const string& value) {
        int index = hashFunction(key);
        
        // Check if key already exists
        MapNode* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;  // Update existing value
                return;
            }
            current = current->next;
        }
        
        // Insert new node at beginning of chain
        MapNode* newNode = new MapNode(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }
    
    // Get value by key
    string get(int key) {
        int index = hashFunction(key);
        MapNode* current = table[index];
        
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        
        return "Not found";
    }
    
    // Remove a key-value pair
    void remove(int key) {
        int index = hashFunction(key);
        MapNode* current = table[index];
        MapNode* prev = nullptr;
        
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    // Remove head of chain
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    
    // Print all key-value pairs
    void print() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            MapNode* current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

void run_map() {
    cout << "\nMap Implementation from Scratch\n";

    Map map;

    map.insert(1, "Apple");
    map.insert(2, "Banana");
    map.insert(3, "Orange");
    map.insert(11, "Grape");  // Will collide with 1 (using hashFunction)

    cout << "Value for key 2: " << map.get(2) << endl;  // Banana
    cout << "Value for key 11: " << map.get(11) << endl; // Grape
    map.print();

    map.remove(2);
    cout << "\nAfter removing key 2:" << endl;
    map.print();
}
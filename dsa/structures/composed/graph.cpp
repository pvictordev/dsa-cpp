#include <iostream>
using namespace std;

// Node structure for the adjacency list
struct AdjListNode {
    int dest;
    AdjListNode* next;
    
    AdjListNode(int d) : dest(d), next(nullptr) {}
};

// Structure to represent an adjacency list
struct AdjList {
    AdjListNode* head;  // Pointer to head node of list
};

// Graph class using adjacency list representation
class Graph {
private:
    int vertices;
    AdjList* array;  // Array of adjacency lists

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        array = new AdjList[v];  // Create an array of adjacency lists
        
        // Initialize each adjacency list as empty
        for (int i = 0; i < v; ++i) {
            array[i].head = nullptr;
        }
    }
    
    // Destructor to free memory
    ~Graph() {
        for (int i = 0; i < vertices; ++i) {
            AdjListNode* current = array[i].head;
            while (current != nullptr) {
                AdjListNode* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] array;
    }
    
    // Add an edge from src to dest (and vice versa for undirected graph)
    void addEdge(int src, int dest) {
        // Add edge from src to dest
        AdjListNode* newNode = new AdjListNode(dest);
        newNode->next = array[src].head;
        array[src].head = newNode;
        
        // Since graph is undirected, add edge from dest to src too
        newNode = new AdjListNode(src);
        newNode->next = array[dest].head;
        array[dest].head = newNode;
    }
    
    // Print the adjacency list representation of graph
    void printGraph() {
        for (int i = 0; i < vertices; ++i) {
            AdjListNode* current = array[i].head;
            cout << "Vertex " << i << ": ";
            while (current != nullptr) {
                cout << current->dest << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

void run_graph() {
    cout << "Graph Implementation from Scratch\n";

    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(3, 4);

    g.printGraph();
}
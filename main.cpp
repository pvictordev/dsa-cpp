#include <iostream>
using namespace std;

// Data Structures
void run_array();
void run_vector();
void run_linked_list();
void run_doubly_linked_list();
void run_stack();
void run_queue();
void run_binary_tree();
void run_hash_table();

// Composed data structures
void run_graph(); 
void run_map(); 
void run_deque(); 
void run_polynom(); 

int main() {
    // Data Structures
    cout << "Data Structures \n\n";

    run_array(); 
    run_vector();
    run_linked_list(); 
    run_doubly_linked_list(); 
    run_stack(); 
    run_queue(); 
    run_binary_tree();
    run_hash_table(); 

    // Composed data structures
    cout << "Composed Data Structures \n\n";

    run_graph(); 
    run_map(); 
    run_deque(); 
    run_polynom(); 
    
    return 0;
}

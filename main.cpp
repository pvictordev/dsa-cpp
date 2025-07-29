#include <iostream>
using namespace std;

// Data structures
void run_array();
void run_vector();
void run_linked_list();
void run_doubly_linked_list();
void run_stack();
void run_queue();
void run_binary_tree();
void run_hash_table();
void run_heap(); 

// Composed data structures
void run_graph(); 
void run_map(); 
void run_deque(); 
void run_polynom();

void display_menu() {
    cout << "\n===== Data Structure Demonstrations =====\n";
    cout << "1. Basic Data Structures\n";
    cout << "2. Composed Data Structures\n";
    cout << "3. Run All Demonstrations\n";
    cout << "0. Exit\n";
    cout << "=======================================\n";
    cout << "Enter your choice: ";
}

void basic_structures_menu() {
    cout << "\n===== Basic Data Structures =====\n";
    cout << "1. Array\n";
    cout << "2. Vector\n";
    cout << "3. Linked List\n";
    cout << "4. Doubly Linked List\n";
    cout << "5. Stack\n";
    cout << "6. Heap\n";
    cout << "7. Queue\n";
    cout << "8. Binary Tree\n";
    cout << "9. Hash Table\n";
    cout << "10. Run All Basic Structures\n";
    cout << "0. Back to Main Menu\n";
    cout << "================================\n";
    cout << "Enter your choice: ";
}

void composed_structures_menu() {
    cout << "\n===== Composed Data Structures =====\n";
    cout << "1. Graph\n";
    cout << "2. Map\n";
    cout << "3. Deque\n";
    cout << "4. Polynom\n";
    cout << "5. Run All Composed Structures\n";
    cout << "0. Back to Main Menu\n";
    cout << "===================================\n";
    cout << "Enter your choice: ";
}

void run_all_basic() {
    run_array();
    run_vector();
    run_linked_list();
    run_doubly_linked_list();
    run_stack();
    run_queue();
    run_binary_tree();
    run_hash_table();
    run_heap(); 
}

void run_all_composed() {
    run_graph();
    run_map();
    run_deque();
    run_polynom();
}

int main() {
    int main_choice, sub_choice;
    
    do {
        display_menu();
        cin >> main_choice;
        
        switch(main_choice) {
            case 1: // Basic Data Structures
                do {
                    basic_structures_menu();
                    cin >> sub_choice;
                    
                    switch(sub_choice) {
                        case 1: run_array(); break;
                        case 2: run_vector(); break;
                        case 3: run_linked_list(); break;
                        case 4: run_doubly_linked_list(); break;
                        case 5: run_stack(); break;
                        case 6: run_heap(); break;
                        case 7: run_queue(); break;
                        case 8: run_binary_tree(); break;
                        case 9: run_hash_table(); break;
                        case 10: run_all_basic(); break;
                        case 0: break;
                        default: cout << "Invalid choice!\n";
                    }
                } while (sub_choice != 0);
                break;
                
            case 2: // Composed Data Structures
                do {
                    composed_structures_menu();
                    cin >> sub_choice;
                    
                    switch(sub_choice) {
                        case 1: run_graph(); break;
                        case 2: run_map(); break;
                        case 3: run_deque(); break;
                        case 4: run_polynom(); break;
                        case 5: run_all_composed(); break;
                        case 0: break;
                        default: cout << "Invalid choice!\n";
                    }
                } while (sub_choice != 0);
                break;
                
            case 3: // Run All
                run_all_basic();
                run_all_composed();
                break;
                
            case 0:
                cout << "Exiting program...\n";
                break;
                
            default:
                cout << "Invalid choice!\n";
        }
    } while (main_choice != 0);
    
    return 0;
}
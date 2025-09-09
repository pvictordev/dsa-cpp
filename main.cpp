#include <iostream>
#include <fstream>
#include <string>
#include <optional>
#include <filesystem>

using namespace std;
// Data structures
void run_array();
void run_vector();
void run_linked_list();
void run_doubly_linked_list();
void run_merge_linked_list();
void run_merge_doubly_linked_list();
void run_stack();
void run_queue();
void run_binary_tree();
void run_hash_table();
void run_heap();
void run_matrix();
// tree
void run_bst();

// Composed data structures
void run_graph();
void run_map();
void run_deque();
void run_polynom();

// algos
void run_evaluate_postfix();
// sorting
void run_quick_sort();
void run_merge_sort();
void run_bubble_sort();

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
    run_bst();
}

void run_all_composed() {
    run_graph();
    run_map();
    run_deque();
    run_polynom();
}

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

struct AppState {
    int main_choice = -1;
    int sub_choice = -1;
    // If true, start at main menu next launch; if false, auto-resume the cached selection next launch
    bool back_to_main = true;
};

static const char* STATE_FILE = "state.cache";

optional<AppState> load_state() {
    if (!std::filesystem::exists(STATE_FILE)) return nullopt;
    ifstream in(STATE_FILE);
    AppState s{};
    int back_flag = 1;
    if (in >> s.main_choice >> s.sub_choice >> back_flag) {
        s.back_to_main = (back_flag != 0);
        return s;
    }
    return nullopt;
}

void save_state(const AppState& s) {
    ofstream out(STATE_FILE, ios::trunc);
    // store: main_choice sub_choice back_flag
    out << s.main_choice << " " << s.sub_choice << " " << (s.back_to_main ? 1 : 0) << "\n";
}

void reset_state() {
    std::error_code ec;
    std::filesystem::remove(STATE_FILE, ec);
}

void run_basic_item(int sub_choice) {
    switch (sub_choice) {
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
        default: cout << "Invalid choice!\n"; break;
    }
}

void run_composed_item(int sub_choice) {
    switch (sub_choice) {
        case 1: run_graph(); break;
        case 2: run_map(); break;
        case 3: run_deque(); break;
        case 4: run_polynom(); break;
        case 5: run_all_composed(); break;
        default: cout << "Invalid choice!\n"; break;
    }
}

int main(int argc, char** argv) {
    // Optional: allow user to wipe cache quickly
    if (argc > 1 && std::string(argv[1]) == "--reset") {
        reset_state();
        cout << "State reset.\n";
    }

    AppState state = load_state().value_or(AppState{});

    if (!state.back_to_main) {
        if (state.main_choice == 1) {
            // Basic: if we have a sub_choice cached, run it; otherwise show submenu
            if (state.sub_choice >= 1) {
                cout << "[Auto-resume] Basic Data Structures -> choice " << state.sub_choice << "\n";
                run_basic_item(state.sub_choice);
                return 0;
            }
        } else if (state.main_choice == 2) {
            if (state.sub_choice >= 1) {
                cout << "[Auto-resume] Composed Data Structures -> choice " << state.sub_choice << "\n";
                run_composed_item(state.sub_choice);
                return 0;
            }
        } else if (state.main_choice == 3) {
            cout << "[Auto-resume] Run All Demonstrations\n";
            run_all_basic();
            run_all_composed();
            return 0;
        }
        // Fall-through if something was off
    }

    // Interactive mode (also used when state said "Back to main")
    int main_choice = -1;
    int sub_choice = -1;

    do {
        display_menu();
        if (!(cin >> main_choice)) return 0;

        switch (main_choice) {
            case 1: {
                state.main_choice = 1;
                state.sub_choice = -1;
                state.back_to_main = false;
                save_state(state);

                do {
                    basic_structures_menu();
                    if (!(cin >> sub_choice)) return 0;

                    if (sub_choice == 0) {
                        state.back_to_main = true;
                        save_state(state);
                        break;
                    }

                    state.sub_choice = sub_choice;
                    state.back_to_main = false;
                    save_state(state);

                    run_basic_item(sub_choice);

                } while (sub_choice != 0);
                break;
            }

            case 2: {
                state.main_choice = 2;
                state.sub_choice = -1;
                state.back_to_main = false;
                save_state(state);

                do {
                    composed_structures_menu();
                    if (!(cin >> sub_choice)) return 0;

                    if (sub_choice == 0) {
                        state.back_to_main = true;
                        save_state(state);
                        break;
                    }

                    state.sub_choice = sub_choice;
                    state.back_to_main = false;
                    save_state(state);

                    run_composed_item(sub_choice);

                } while (sub_choice != 0);
                break;
            }

            case 3: 
                state.main_choice = 3;
                state.sub_choice = -1;
                state.back_to_main = false; 
                save_state(state);

                run_all_basic();
                run_all_composed();
                break;

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (main_choice != 0);

    return 0;
}
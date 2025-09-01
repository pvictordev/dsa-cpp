#include <iostream>
using namespace std;

void bubbleSort(int arr[], int arrLength) {
    for (int i = 0; i < arrLength - 1; i++) {
        
        for (int j = 0; j < arrLength - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }

    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void run_bubble_sort() {
    int arr[] = {5, 3, 8, 4, 2};
    int arrLength = sizeof(arr) / sizeof(arr[0]);

    cout << "Initial array: ";
    printArray(arr, arrLength);

    bubbleSort(arr, arrLength);

    cout << "Sorted array: ";
    printArray(arr, arrLength);
}

// 1 - 3, 5, 4, 2, 8
// 2 - 3, 4, 2, 5, 8
// 3 - 3, 2, 4, 5, 8
// 4 - 2, 3, 4, 5, 8
// 5 - stop
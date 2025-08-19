#include <iostream>
using namespace std;

void merge(int* leftArray, int leftSize, int* rightArray, int rightSize, int* array) {

    int i = 0; // destination idx
    int l = 0; // leftArray idx
    int r = 0; // rightArray idx

    // merge both parts
    while (l < leftSize && r < rightSize) {
        if (leftArray[l] < rightArray[r]) {
            array[i++] = leftArray[l++];
        } else {
            array[i++] = rightArray[r++];
        }
    }

    while (l < leftSize) {
        array[i++] = leftArray[l++];
    }
    while (r < rightSize) {
        array[i++] = rightArray[r++];
    }
}

void mergeSort(int* array) = delete;

void mergeSort(int* array, int length) {
    if (length <= 1) return;

    int middle = length / 2;

    int* leftArray  = new int[middle];
    int* rightArray = new int[length - middle];

    int i = 0; // left idx
    int j = 0; // right idx
    for (int k = 0; k < length; ++k) {
        if (k < middle) {
            leftArray[i++] = array[k];
        }      
        else {            
            rightArray[j++] = array[k];
        }
    }

    mergeSort(leftArray, middle);
    mergeSort(rightArray, length - middle);

    merge(leftArray, middle, rightArray, length - middle, array);

    delete[] leftArray;
    delete[] rightArray;
}

void run_merge_sort() {
    int array[] = {8, 2, 5, 3, 4, 7, 6, 1};
    int arrayLength = sizeof(array) / sizeof(array[0]); // 8

    mergeSort(array, arrayLength);

    for (int i = 0; i < arrayLength; ++i) {
        cout << array[i] << (i + 1 < arrayLength ? ' ' : '\n');
    }
}

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &vec, int start, int end) {
    int i = (start - 1);

    for (int j = start; j <= end - 1; j++) {
        if (vec[j] <= vec[end]) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    swap(vec[i + 1], vec[end]);

    return (i + 1);
}

void quickSort(vector<int> &vec, int start, int end) {
    if (start < end) { 
        int pi = partition(vec, start, end); 

        quickSort(vec, start, pi - 1);
        quickSort(vec, pi + 1, end);
    }
}

void run_quick_sort() {
    vector<int> vec = {10, 7, 8, 9, 1, 5};

    int vecSize = vec.size();

    cout << "Initial array : ";
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << "\n";

    quickSort(vec, 0, vecSize - 1); 

    cout << "Sorted array : ";
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << "\n";

}
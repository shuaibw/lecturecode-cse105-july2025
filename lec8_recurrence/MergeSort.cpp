#include <iostream>

using namespace std;

void mergesort(int* ara, int start, int end) {
    if (end - start <= 1) {
        return;
    }
    int mid = start + (end - start) / 2;
    mergesort(ara, start, mid);
    mergesort(ara, mid, end);
    int* merged = new int[end - start];
    int i = start, j = mid, k = 0;
    while (i < mid && j < end) {
        if (ara[i] < ara[j]) {
            merged[k] = ara[i];
            i++;
        } else {
            merged[k] = ara[j];
            j++;
        }
        k++;
    }
    while (i < mid) {
        merged[k] = ara[i];
        i++;
        k++;
    }
    while (j < end) {
        merged[k] = ara[j];
        j++;
        k++;
    }
    for (int idx = 0; idx < end - start; idx++) {
        ara[start + idx] = merged[idx];
    }
    delete[] merged;  // Also free the memory
}

void printArray(int* arr, int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

bool isSorted(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    // take n from command line, create array of size n with random integers
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <num_elements>" << endl;
        return 1;
    }
    int n = atoi(argv[1]);
    int* arr = new int[n];
    srand(123);  // deterministic seed
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (n / 10);  // random integers in [0, n/10)
    }
    
    cout << "Before sorting (n=" << n << "):" << endl;
    if (n <= 20) {
        printArray(arr, n);
    } else {
        cout << "First 10: ";
        printArray(arr, 10);
    }
    
    mergesort(arr, 0, n);
    
    cout << "\nAfter sorting:" << endl;
    if (n <= 20) {
        printArray(arr, n);
    } else {
        cout << "First 10: ";
        printArray(arr, 10);
    }
    
    if (isSorted(arr, n)) {
        cout << "\n✓ Array is correctly sorted!" << endl;
    } else {
        cout << "\n✗ ERROR: Array is NOT sorted!" << endl;
    }
    
    delete[] arr;
    return 0;
}
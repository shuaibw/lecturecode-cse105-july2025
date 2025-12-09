#include<stdio.h>
#include<stdlib.h>


int size = 0, capacity = 10;
int* arr;
// Initialize the dynamic array to the given capacity
void initialize(int initialCapacity) {
    capacity = initialCapacity;
    arr = (int*)malloc(sizeof(int) * capacity);
    size = 0;
}

// Insert the value at the end of the array
void insertItem(int value){
    if(size == capacity){
        // printf("Resizing array from capacity %d to %d\n", capacity, capacity * 2);
        capacity *= 2;
        arr = (int*)realloc(arr, sizeof(int) * capacity);
    }
    arr[size++] = value;
}

// Remove an element from the end of the array and return its value
int removeItem(){
    if(size == 0){
        printf("Array is empty, cannot remove element.\n");
        return -1; // Indicate error
    }
    int data = arr[--size];
    if(size <= capacity / 4 && capacity > 2){
        // printf("Halving array from capacity %d to %d\n", capacity, capacity / 2);
        capacity /= 2;
        arr = (int*)realloc(arr, sizeof(int) * capacity);
    }
    return data;
}

void printArray(){
    printf("[");
    for(int i=0;i<size;i++){
        printf("%d", arr[i]);
        if(i < size - 1) printf(", ");
    }
    printf("]\n");
}

int main(int argc, char** argv){
    if(argc < 2){
        printf("Usage: %s <num_elements>\n", argv[0]);
        return 1;
    }
    int numElements = atoi(argv[1]);
    initialize(2);
    for(int i=0;i<numElements;i++){
        insertItem(i);
    }
    printf("Array after inserting %d elements:\n", numElements);
    // printArray();
    for(int i=0;i<numElements;i++){
        int removedValue = removeItem();
        // printf("Removed: %d\n", removedValue);
    }
    printf("Array after removing all elements:\n");
    // printArray();
    free(arr);
    return 0;

}
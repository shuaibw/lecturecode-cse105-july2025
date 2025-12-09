#include <stdio.h>
#include <stdlib.h>

// Function that creates an array and returns it
int* createArray(int size) {
    int *arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }
    
    return arr;  // Caller MUST remember to free this!
}

// Common mistake: returning stack-allocated memory
int* dangerousFunction() {
    int arr[5] = {1, 2, 3, 4, 5};
    return arr;  // BUG! This memory will be invalid after function returns!
}

int main() {
    int *numbers = createArray(5);
    
    if (numbers == NULL) {
        printf("Allocation failed!\n");
        return 1;
    }
    
    printf("Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    // Caller's responsibility to free!
    free(numbers);
    
    // Using the dangerous function would cause undefined behavior
    // int *bad = dangerousFunction();  // Don't do this!
    
    return 0;
}

/*
RETURNING DATA IN C:
1. Must return heap-allocated memory (malloc) if returning arrays.
2. Stack memory (local arrays) becomes invalid after function returns.
3. Caller must know to free the returned memory - easy to forget!
4. No automatic tracking of who "owns" the memory.
5. Documentation must specify who is responsible for freeing.
*/

#include <stdio.h>
#include <stdlib.h>

// Reverse an array in place using pointer arithmetic
void reverseArray(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;
    
    while (start < end) {
        // Swap elements
        int temp = *start;
        *start = *end;
        *end = temp;
        
        start++;
        end--;
    }
}

int main() {
    int size = 6;
    int *numbers = malloc(size * sizeof(int));
    
    if (numbers == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Initialize array
    for (int i = 0; i < size; i++) {
        numbers[i] = (i + 1) * 10;
    }
    
    printf("Original: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    reverseArray(numbers, size);
    
    printf("Reversed: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    free(numbers);
    
    return 0;
}

/*
POINTER ARITHMETIC IN C:
1. Can manipulate memory addresses directly with +, -, ++, --.
2. Powerful but dangerous - no bounds checking!
3. Easy to go past array bounds and corrupt memory.
4. Dereferencing (*) wrong addresses causes crashes.
5. Must manually track array size - no built-in length.

This is powerful for systems programming, but error-prone
for application development and learning algorithms!
*/

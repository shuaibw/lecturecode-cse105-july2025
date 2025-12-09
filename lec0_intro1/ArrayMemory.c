#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate array of 5 integers on the heap
    int *numbers = malloc(5 * sizeof(int));
    
    if (numbers == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Fill the array
    for (int i = 0; i < 5; i++) {
        numbers[i] = i * 10;
    }
    
    // Print the array
    printf("Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    // MUST free the memory!
    free(numbers);
    
    // What if we want to resize the array?
    // We'd need to:
    // 1. Allocate new larger array
    // 2. Copy old data to new array
    // 3. Free old array
    // This is tedious and error-prone!
    
    return 0;
}

/*
ARRAYS IN C:
1. Fixed size - determined at allocation time.
2. No built-in way to know array size.
3. No bounds checking - can access out of bounds!
4. Must manually manage memory (malloc/free).
5. Resizing requires manual reallocation and copying.
*/

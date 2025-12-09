#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // In C, we must manually allocate memory for strings
    char *greeting = malloc(20 * sizeof(char));
    
    if (greeting == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    strcpy(greeting, "Hello, CSE 105!");
    printf("%s\n", greeting);
    
    // MUST remember to free memory or we have a memory leak!
    free(greeting);
    
    return 0;
}

/*
MEMORY MANAGEMENT IN C:
1. You must manually allocate memory using malloc().
2. You must check if allocation succeeded (NULL check).
3. You must manually free memory using free().
4. Forgetting to free causes memory leaks.
5. Using freed memory causes crashes (dangling pointers).
6. This is YOUR responsibility - the compiler won't help!
*/

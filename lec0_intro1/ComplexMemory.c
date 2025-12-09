#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Imagine we want to store multiple strings
// In C, this gets complicated fast!

int main() {
    // Array of string pointers
    char **words = malloc(3 * sizeof(char *));
    
    if (words == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Allocate memory for each string
    words[0] = malloc(10 * sizeof(char));
    words[1] = malloc(10 * sizeof(char));
    words[2] = malloc(10 * sizeof(char));
    
    // Check each allocation (verbose!)
    if (words[0] == NULL || words[1] == NULL || words[2] == NULL) {
        printf("Memory allocation failed!\n");
        // Should free already allocated memory here...
        return 1;
    }
    
    // Copy strings
    strcpy(words[0], "Java");
    strcpy(words[1], "is");
    strcpy(words[2], "easier");
    
    // Print them
    for (int i = 0; i < 3; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
    
    // Free each string
    for (int i = 0; i < 3; i++) {
        free(words[i]);
    }
    // Free the array of pointers
    free(words);
    
    return 0;
}

/*
COMPLEX DATA IN C:
1. Multiple levels of pointers (char ** for array of strings).
2. Multiple malloc() calls - each can fail!
3. Must track all allocations to free them properly.
4. Easy to make mistakes: memory leaks, double frees, etc.
5. No safety net - errors cause crashes or security bugs.
*/

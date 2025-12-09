#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

static inline long long now_ns() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ((long long) ts.tv_sec * 1000000000LL) + ts.tv_nsec;
}

// Comparator for qsort
int intcmp(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);  
}

// Generate sorted random array of size n
int* create_array(int n) {
    int* A = malloc(sizeof(int) * n);
    if (!A) { perror("malloc"); exit(1); }

    srand(123);  // deterministic seed
    for (int i = 0; i < n; i++) {
        A[i] = rand();
    }

    qsort(A, n, sizeof(int), intcmp);
    return A;
}

// Quadratic duplicate finder
int dup1(int* A, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j]) count++;
        }
    }
    return count;
}

// Linear duplicate finder
int dup2(int* A, int n) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        if (A[i] == A[i+1]) count++;
    }
    return count;
}

double run_dup1(int n) {
    int* A = create_array(n);
    long long start = now_ns();
    dup1(A, n);
    long long end = now_ns();
    free(A);
    return (end - start) / 1e6;   // ms
}

// dup2 is too fast → repeat many times to get measurable time
double run_dup2(int n, int reps) {
    int* A = create_array(n);
    long long start = now_ns();
    for (int r = 0; r < reps; r++) dup2(A, n);
    long long end = now_ns();
    free(A);
    return (end - start) / 1e6 / reps;  // average ms per run
}

int main(int argc, char** argv) {
    // take cli args as size of array and name of function (dup1 or dup2)
    
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <size> <dup1|dup2>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    char* func = argv[2];
    if (n <= 0) {
        fprintf(stderr, "Size must be positive integer\n");
        return 1;
    }
    if (strcmp(func, "dup1") == 0) {
        double t = run_dup1(n);
        printf("dup1 with n=%d took %.3f ms\n", n, t);
    } else if (strcmp(func, "dup2") == 0) {
        // choose reps so that total time is about 100ms
        int reps = 100000000 / n;
        if (reps < 1) reps = 1;
        double t = run_dup2(n, reps);
        printf("dup2 with n=%d (averaged over %d reps) took %.3f ms\n", n, reps, t);
    } else {
        fprintf(stderr, "Unknown function: %s. Use dup1 or dup2.\n", func);
        return 1;
    }
    return 0;
}

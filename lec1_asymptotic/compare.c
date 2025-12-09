#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

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

int main() {
    int tests[] = {2000, 4000, 8000, 16000, 32000, 64000, 128000, 256000};
    int T = sizeof(tests) / sizeof(tests[0]);

    printf("===== DUP1 (Quadratic) =====\n");
    double prev = -1;
    for (int i = 0; i < T; i++) {
        int n = tests[i];
        double t = run_dup1(n);
        if (prev > 0)
            printf("n=%6d   time = %4.3f ms   ratio=%.2f\n", n, t, t/prev);
        else
            printf("n=%6d   time = %.3f ms\n", n, t);
        prev = t;
    }

    printf("\n===== DUP2 (Linear) =====\n");
    prev = -1;
    for (int i = 0; i < T; i++) {
        int n = tests[i];
        double t = run_dup2(n, 20000);  // 20k reps so timing isn't zero
        if (prev > 0)
            printf("n=%6d   time = %.6f ms   ratio=%.2f\n", n, t, t/prev);
        else
            printf("n=%6d   time = %.6f ms\n", n, t);
        prev = t;
    }

    return 0;
}

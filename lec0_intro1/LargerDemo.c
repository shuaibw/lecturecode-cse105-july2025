#include <stdio.h>

/** Returns the larger of x and y. */
int larger(int x, int y) {
    if (x > y) {
        return x;
    }
    return y;
}

int main() {
    printf("%d\n", larger(3, 10));
    return 0;
}

/*
1. In C, functions can be defined outside of any class/struct.
2. We don't need "public static" - just the return type.
3. All parameters must have a declared type.
4. The return value must have a declared type.
5. Functions return only one value (but can modify pointers).
*/

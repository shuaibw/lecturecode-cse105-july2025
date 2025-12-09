#include <stdio.h>

int main() {
    int x = 0;
    while (x < 10) {
        printf("%d\n", x);
        x = x + 1;
    }
    
    // x = "horse";  // This won't compile - type mismatch!
    return 0;
}

/*
1. Like Java, C variables must be declared before use.
2. C variables must have a specific type.
3. C variable types can never change.
4. However, C's type checking is weaker than Java's.
   Java catches more errors at compile time.
*/

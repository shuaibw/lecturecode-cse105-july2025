package lec1_intro1;

public class StringMemory {
    public static void main(String[] args) {
        // In Java, memory is automatically managed!
        String greeting = "Hello, CSE 105!";
        System.out.println(greeting);
        
        // No need to free memory - Java's garbage collector does it for you!
    }
}

/*
MEMORY MANAGEMENT IN JAVA:
1. Memory is automatically allocated when you create objects.
2. No need to check if allocation succeeded - Java handles it.
3. No need to manually free memory - garbage collector does it!
4. The garbage collector finds and frees unused objects.
5. You can't accidentally use freed memory (no dangling pointers).
6. This makes Java safer and easier, but slightly slower than C.
*/

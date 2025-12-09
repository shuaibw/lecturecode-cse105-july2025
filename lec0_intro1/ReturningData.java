package lec1_intro1;

public class ReturningData {
    // Function that creates and returns an array
    public static int[] createArray(int size) {
        int[] arr = new int[size];
        
        for (int i = 0; i < size; i++) {
            arr[i] = i * 2;
        }
        
        return arr;  // Safe! Java manages the memory.
    }
    
    // This is also safe in Java
    public static int[] safeFunction() {
        int[] arr = {1, 2, 3, 4, 5};
        return arr;  // Perfectly fine! Java keeps this memory alive.
    }
    
    public static void main(String[] args) {
        int[] numbers = createArray(5);
        
        System.out.print("Array: ");
        for (int i = 0; i < 5; i++) {
            System.out.print(numbers[i] + " ");
        }
        System.out.println();
        
        // No need to worry about freeing memory!
        // Garbage collector will clean up when no longer needed.
        
        int[] safe = safeFunction();
        System.out.print("Safe array: ");
        for (int i = 0; i < 5; i++) {
            System.out.print(safe[i] + " ");
        }
        System.out.println();
    }
}

/*
RETURNING DATA IN JAVA:
1. Can return arrays without worrying about stack vs heap.
2. Java automatically manages memory lifetime.
3. No concept of "dangling pointers" or "use after free".
4. Garbage collector tracks what's still in use.
5. Much simpler mental model - focus on logic, not memory!

KEY TAKEAWAY:
In C, you constantly think: "Where is this memory? Who frees it?"
In Java, you just use the data - Java handles the rest!
*/
